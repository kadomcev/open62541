/*
 * This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information.
 */
#include <time.h>
#include "ua_types.h"

#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#define __USE_XOPEN2K
#include <pthread.h>

// provided by the open62541 lib
#include "ua_server.h"

// provided by the user, implementations available in the /examples folder
#include "logger_stdout.h"
#include "networklayer_tcp.h"

/*************************/
/* Read-only data source */
/*************************/
static UA_StatusCode readTimeData(const void *handle, UA_DataValue *value) {
    UA_DateTime *currentTime = UA_DateTime_new();
    if(!currentTime)
        return UA_STATUSCODE_BADOUTOFMEMORY;
    *currentTime = UA_DateTime_now();
    value->value.type = &UA_TYPES[UA_TYPES_DATETIME];
    value->value.arrayLength = 1;
    value->value.dataPtr = currentTime;
    value->value.arrayDimensionsSize = -1;
    value->value.arrayDimensions = NULL;
    value->hasVariant = UA_TRUE;
    return UA_STATUSCODE_GOOD;
}

static void releaseTimeData(const void *handle, UA_DataValue *value) {
    UA_DateTime_delete((UA_DateTime*)value->value.dataPtr);
}

/**************************/
/* Read/write data source */
/**************************/
UA_Int32 deviceStatus = 0;
pthread_rwlock_t deviceStatusLock;

static void printDeviceStatus(UA_Server *server, void *data) {
    printf("Device Status: %i\n", deviceStatus);
}

static UA_StatusCode readDeviceStatus(const void *handle, UA_DataValue *value) {
    /* In order to reduce blocking time, we could alloc memory for every read
       and return a copy of the data. */
    pthread_rwlock_rdlock(&deviceStatusLock);
    value->value.type = &UA_TYPES[UA_TYPES_INT32];
    value->value.arrayLength = 1;
    value->value.dataPtr = &deviceStatus;
    value->value.arrayDimensionsSize = -1;
    value->value.arrayDimensions = NULL;
    value->hasVariant = UA_TRUE;
    value->sourceTimestamp = UA_DateTime_now();
    value->hasSourceTimestamp = UA_TRUE;
    return UA_STATUSCODE_GOOD;
}

static void releaseDeviceStatus(const void *handle, UA_DataValue *value) {
    /* If we allocated memory for a specific read, free the content of the
       variantdata. */
    value->value.arrayLength = -1;
    value->value.dataPtr = NULL;
    pthread_rwlock_unlock(&deviceStatusLock);
}

static UA_StatusCode writeDeviceStatus(const void *handle, const UA_Variant *data) {
    pthread_rwlock_wrlock(&deviceStatusLock);
    if(data->dataPtr)
        deviceStatus = *(UA_Int32*)data->dataPtr;
    pthread_rwlock_unlock(&deviceStatusLock);
    return UA_STATUSCODE_GOOD;
}

UA_Boolean running = 1;

static void stopHandler(int sign) {
    printf("Received Ctrl-C\n");
	running = 0;
}

int main(int argc, char** argv) {
	signal(SIGINT, stopHandler); /* catches ctrl-c */
    pthread_rwlock_init(&deviceStatusLock, 0);

	UA_Server *server = UA_Server_new();
    UA_Server_addNetworkLayer(server, ServerNetworkLayerTCP_new(UA_ConnectionConfig_standard, 16664));

    // add node with the datetime data source
    UA_DataSource dateDataSource = (UA_DataSource)
        {.handle = NULL,
         .read = readTimeData,
         .release = releaseTimeData,
         .write = NULL};
    UA_QualifiedName dateName;
    UA_QUALIFIEDNAME_ASSIGN(dateName, "the time");
    UA_Server_addDataSourceVariableNode(server, dateDataSource, &UA_NODEID_NULL, &dateName,
                                        &UA_NODEID_STATIC(0, UA_NS0ID_OBJECTSFOLDER),
                                        &UA_NODEID_STATIC(0, UA_NS0ID_ORGANIZES));

    // print the status every 2 sec
    UA_WorkItem work = {.type = UA_WORKITEMTYPE_METHODCALL,
                        .work.methodCall = {.method = printDeviceStatus, .data = NULL} };
    UA_Server_addRepeatedWorkItem(server, &work, 20000000, NULL);

    // add node with the device status data source
    UA_DataSource deviceStatusDataSource = (UA_DataSource)
        {.handle = NULL,
         .read = readDeviceStatus,
         .release = releaseDeviceStatus,
         .write = writeDeviceStatus};
    UA_QualifiedName statusName;
    UA_QUALIFIEDNAME_ASSIGN(statusName, "device status");
    UA_Server_addDataSourceVariableNode(server, deviceStatusDataSource, &UA_NODEID_NULL, &statusName,
                              &UA_NODEID_STATIC(0, UA_NS0ID_OBJECTSFOLDER),
                              &UA_NODEID_STATIC(0, UA_NS0ID_ORGANIZES));

    UA_StatusCode retval = UA_Server_run(server, 1, &running);
	UA_Server_delete(server);
    pthread_rwlock_destroy(&deviceStatusLock);

	return retval;
}
