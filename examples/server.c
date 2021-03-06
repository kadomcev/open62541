/*
 * This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information.
 */
#include <time.h>
#include "ua_types.h"

#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <errno.h> // errno, EINTR

// provided by the open62541 lib
#include "ua_server.h"

// provided by the user, implementations available in the /examples folder
#include "logger_stdout.h"
#include "networklayer_tcp.h"

UA_Boolean running = 1;

static void stopHandler(int sign) {
    printf("Received Ctrl-C\n");
	running = 0;
}

static UA_ByteString loadCertificate(void) {
    UA_ByteString certificate = UA_STRING_NULL;
	FILE *fp = NULL;
	//FIXME: a potiential bug of locating the certificate, we need to get the path from the server's config
	fp=fopen("localhost.der", "rb");

	if(!fp) {
        errno = 0; // we read errno also from the tcp layer...
        return certificate;
    }

    fseek(fp, 0, SEEK_END);
    certificate.length = ftell(fp);
    certificate.data = malloc(certificate.length*sizeof(UA_Byte));
	if(!certificate.data)
		return certificate;

    fseek(fp, 0, SEEK_SET);
    if(fread(certificate.data, sizeof(UA_Byte), certificate.length, fp) < (size_t)certificate.length)
        UA_ByteString_deleteMembers(&certificate); // error reading the cert
    fclose(fp);

    return certificate;
}

static void testCallback(UA_Server *server, void *data) {
       printf("testcallback\n");
}

int main(int argc, char** argv) {
	signal(SIGINT, stopHandler); /* catches ctrl-c */

	UA_Server *server = UA_Server_new();
    UA_Server_setServerCertificate(server, loadCertificate());
    UA_Server_addNetworkLayer(server, ServerNetworkLayerTCP_new(UA_ConnectionConfig_standard, 16664));

    UA_WorkItem work = {.type = UA_WORKITEMTYPE_METHODCALL, .work.methodCall = {.method = testCallback, .data = NULL} };
    UA_Server_addRepeatedWorkItem(server, &work, 20000000, NULL); // call every 2 sec

	// add a variable node to the adresspace
    UA_Int32 *myInteger = UA_Int32_new();
    *myInteger = 42;
    UA_Variant *myIntegerVariant = UA_Variant_new();
    UA_Variant_setValue(myIntegerVariant, myInteger, &UA_TYPES[UA_TYPES_INT32]);
    UA_QualifiedName myIntegerName;
    UA_QUALIFIEDNAME_ASSIGN(myIntegerName, "the answer");
    UA_Server_addVariableNode(server, myIntegerVariant, &UA_NODEID_NULL, &myIntegerName,
                              &UA_NODEID_STATIC(0, UA_NS0ID_OBJECTSFOLDER),
                              &UA_NODEID_STATIC(0, UA_NS0ID_ORGANIZES));
    
#ifdef BENCHMARK
    UA_UInt32 nodeCount = 500;
    char str[15];
    for(UA_UInt32 i = 0;i<nodeCount;i++) {
        UA_Int32 *data = UA_Int32_new();
        *data = 42;
        UA_Variant *variant = UA_Variant_new();
        UA_Variant_setValue(variant, data, &UA_TYPES[UA_TYPES_INT32]);
        UA_QualifiedName *nodeName = UA_QualifiedName_new();
        sprintf(str,"%d",i);
        UA_QualifiedName_copycstring(str, nodeName);
        UA_Server_addVariableNode(server, variant, &UA_NODEID_NULL, nodeName,
                                  &UA_NODEID_STATIC(0, UA_NS0ID_OBJECTSFOLDER),
                                  &UA_NODEID_STATIC(0, UA_NS0ID_ORGANIZES));
    }
#endif

    UA_StatusCode retval = UA_Server_run(server, 1, &running);
	UA_Server_delete(server);

	return retval;
}
