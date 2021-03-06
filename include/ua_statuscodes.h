/* This file shall only be included in ua_types.h */
#ifdef UA_TYPES_H_
#ifndef OPCUA_STATUSCODES_H_
#define OPCUA_STATUSCODES_H_

enum UA_StatusCode {
	UA_STATUSCODE_GOOD = (UA_Int32) 0x00,
	UA_STATUSCODE_BADUNEXPECTEDERROR = (UA_Int32) 0x80010000, // An unexpected error occurred.
	UA_STATUSCODE_BADINTERNALERROR = (UA_Int32) 0x80020000, // An internal error occurred as a result of a programming or configuration error.
	UA_STATUSCODE_BADOUTOFMEMORY = (UA_Int32) 0x80030000, // Not enough memory to complete the operation.
	UA_STATUSCODE_BADRESOURCEUNAVAILABLE = (UA_Int32) 0x80040000, // An operating system resource is not available.
	UA_STATUSCODE_BADCOMMUNICATIONERROR = (UA_Int32) 0x80050000, // A low level communication error occurred.
	UA_STATUSCODE_BADENCODINGERROR = (UA_Int32) 0x80060000, // Encoding halted because of invalid data in the objects being serialized.
	UA_STATUSCODE_BADDECODINGERROR = (UA_Int32) 0x80070000, // Decoding halted because of invalid data in the stream.
	UA_STATUSCODE_BADENCODINGLIMITSEXCEEDED = (UA_Int32) 0x80080000, // The message encoding/decoding limits imposed by the stack have been exceeded.
	UA_STATUSCODE_BADREQUESTTOOLARGE = (UA_Int32) 0x80b80000, // The request message size exceeds limits set by the server.
	UA_STATUSCODE_BADRESPONSETOOLARGE = (UA_Int32) 0x80b90000, // The response message size exceeds limits set by the client.
	UA_STATUSCODE_BADUNKNOWNRESPONSE = (UA_Int32) 0x80090000, // An unrecognized response was received from the server.
	UA_STATUSCODE_BADTIMEOUT = (UA_Int32) 0x800a0000, // The operation timed out.
	UA_STATUSCODE_BADSERVICEUNSUPPORTED = (UA_Int32) 0x800b0000, // The server does not support the requested service.
	UA_STATUSCODE_BADSHUTDOWN = (UA_Int32) 0x800c0000, // The operation was cancelled because the application is shutting down.
	UA_STATUSCODE_BADSERVERNOTCONNECTED = (UA_Int32) 0x800d0000, // The operation could not complete because the client is not connected to the server.
	UA_STATUSCODE_BADSERVERHALTED = (UA_Int32) 0x800e0000, // The server has stopped and cannot process any requests.
	UA_STATUSCODE_BADNOTHINGTODO = (UA_Int32) 0x800f0000, // There was nothing to do because the client passed a list of operations with no elements.
	UA_STATUSCODE_BADTOOMANYOPERATIONS = (UA_Int32) 0x80100000, // The request could not be processed because it specified too many operations.
	UA_STATUSCODE_BADTOOMANYMONITOREDITEMS = (UA_Int32) 0x80db0000, // The request could not be processed because there are too many monitored items in the subscription.
	UA_STATUSCODE_BADDATATYPEIDUNKNOWN = (UA_Int32) 0x80110000, // The extension object cannot be (de)serialized because the data type id is not recognized.
	UA_STATUSCODE_BADCERTIFICATEINVALID = (UA_Int32) 0x80120000, // The certificate provided as a parameter is not valid.
	UA_STATUSCODE_BADSECURITYCHECKSFAILED = (UA_Int32) 0x80130000, // An error occurred verifying security.
	UA_STATUSCODE_BADCERTIFICATETIMEINVALID = (UA_Int32) 0x80140000, // The Certificate has expired or is not yet valid.
	UA_STATUSCODE_BADCERTIFICATEISSUERTIMEINVALID = (UA_Int32) 0x80150000, // An Issuer Certificate has expired or is not yet valid.
	UA_STATUSCODE_BADCERTIFICATEHOSTNAMEINVALID = (UA_Int32) 0x80160000, // The HostName used to connect to a Server does not match a HostName in the Certificate.
	UA_STATUSCODE_BADCERTIFICATEURIINVALID = (UA_Int32) 0x80170000, // The URI specified in the ApplicationDescription does not match the URI in the Certificate.
	UA_STATUSCODE_BADCERTIFICATEUSENOTALLOWED = (UA_Int32) 0x80180000, // The Certificate may not be used for the requested operation.
	UA_STATUSCODE_BADCERTIFICATEISSUERUSENOTALLOWED = (UA_Int32) 0x80190000, // The Issuer Certificate may not be used for the requested operation.
	UA_STATUSCODE_BADCERTIFICATEUNTRUSTED = (UA_Int32) 0x801a0000, // The Certificate is not trusted.
	UA_STATUSCODE_BADCERTIFICATEREVOCATIONUNKNOWN = (UA_Int32) 0x801b0000, // It was not possible to determine if the Certificate has been revoked.
	UA_STATUSCODE_BADCERTIFICATEISSUERREVOCATIONUNKNOWN = (UA_Int32) 0x801c0000, // It was not possible to determine if the Issuer Certificate has been revoked.
	UA_STATUSCODE_BADCERTIFICATEREVOKED = (UA_Int32) 0x801d0000, // The Certificate has been revoked.
	UA_STATUSCODE_BADCERTIFICATEISSUERREVOKED = (UA_Int32) 0x801e0000, // The Issuer Certificate has been revoked.
	UA_STATUSCODE_BADUSERACCESSDENIED = (UA_Int32) 0x801f0000, // User does not have permission to perform the requested operation.
	UA_STATUSCODE_BADIDENTITYTOKENINVALID = (UA_Int32) 0x80200000, // The user identity token is not valid.
	UA_STATUSCODE_BADIDENTITYTOKENREJECTED = (UA_Int32) 0x80210000, // The user identity token is valid but the server has rejected it.
	UA_STATUSCODE_BADSECURECHANNELIDINVALID = (UA_Int32) 0x80220000, // The specified secure channel is no longer valid.
	UA_STATUSCODE_BADINVALIDTIMESTAMP = (UA_Int32) 0x80230000, // The timestamp is outside the range allowed by the server.
	UA_STATUSCODE_BADNONCEINVALID = (UA_Int32) 0x80240000, // The nonce does appear to be not a random value or it is not the correct length.
	UA_STATUSCODE_BADSESSIONIDINVALID = (UA_Int32) 0x80250000, // The session id is not valid.
	UA_STATUSCODE_BADSESSIONCLOSED = (UA_Int32) 0x80260000, // The session was closed by the client.
	UA_STATUSCODE_BADSESSIONNOTACTIVATED = (UA_Int32) 0x80270000, // The session cannot be used because ActivateSession has not been called.
	UA_STATUSCODE_BADSUBSCRIPTIONIDINVALID = (UA_Int32) 0x80280000, // The subscription id is not valid.
	UA_STATUSCODE_BADREQUESTHEADERINVALID = (UA_Int32) 0x802a0000, // The header for the request is missing or invalid.
	UA_STATUSCODE_BADTIMESTAMPSTORETURNINVALID = (UA_Int32) 0x802b0000, // The timestamps to return parameter is invalid.
	UA_STATUSCODE_BADREQUESTCANCELLEDBYCLIENT = (UA_Int32) 0x802c0000, // The request was cancelled by the client.
	UA_STATUSCODE_GOODSUBSCRIPTIONTRANSFERRED = (UA_Int32) 0x002d0000, // The subscription was transferred to another session.
	UA_STATUSCODE_GOODCOMPLETESASYNCHRONOUSLY = (UA_Int32) 0x002e0000, // The processing will complete asynchronously.
	UA_STATUSCODE_GOODOVERLOAD = (UA_Int32) 0x002f0000, // Sampling has slowed down due to resource limitations.
	UA_STATUSCODE_GOODCLAMPED = (UA_Int32) 0x00300000, // The value written was accepted but was clamped.
	UA_STATUSCODE_BADNOCOMMUNICATION = (UA_Int32) 0x80310000, // Communication with the data source is defined, but not established, and there is no last known value available.
	UA_STATUSCODE_BADWAITINGFORINITIALDATA = (UA_Int32) 0x80320000, // Waiting for the server to obtain values from the underlying data source.
	UA_STATUSCODE_BADNODEIDINVALID = (UA_Int32) 0x80330000, // The syntax of the node id is not valid.
	UA_STATUSCODE_BADNODEIDUNKNOWN = (UA_Int32) 0x80340000, // The node id refers to a node that does not exist in the server address space.
	UA_STATUSCODE_BADATTRIBUTEIDINVALID = (UA_Int32) 0x80350000, // The attribute is not supported for the specified Node.
	UA_STATUSCODE_BADINDEXRANGEINVALID = (UA_Int32) 0x80360000, // The syntax of the index range parameter is invalid.
	UA_STATUSCODE_BADINDEXRANGENODATA = (UA_Int32) 0x80370000, // No data exists within the range of indexes specified.
	UA_STATUSCODE_BADDATAENCODINGINVALID = (UA_Int32) 0x80380000, // The data encoding is invalid.
	UA_STATUSCODE_BADDATAENCODINGUNSUPPORTED = (UA_Int32) 0x80390000, // The server does not support the requested data encoding for the node.
	UA_STATUSCODE_BADNOTREADABLE = (UA_Int32) 0x803a0000, // The access level does not allow reading or subscribing to the Node.
	UA_STATUSCODE_BADNOTWRITABLE = (UA_Int32) 0x803b0000, // The access level does not allow writing to the Node.
	UA_STATUSCODE_BADOUTOFRANGE = (UA_Int32) 0x803c0000, // The value was out of range.
	UA_STATUSCODE_BADNOTSUPPORTED = (UA_Int32) 0x803d0000, // The requested operation is not supported.
	UA_STATUSCODE_BADNOTFOUND = (UA_Int32) 0x803e0000, // A requested item was not found or a search operation ended without success.
	UA_STATUSCODE_BADOBJECTDELETED = (UA_Int32) 0x803f0000, // The object cannot be used because it has been deleted.
	UA_STATUSCODE_BADNOTIMPLEMENTED = (UA_Int32) 0x80400000, // Requested operation is not implemented.
	UA_STATUSCODE_BADMONITORINGMODEINVALID = (UA_Int32) 0x80410000, // The monitoring mode is invalid.
	UA_STATUSCODE_BADMONITOREDITEMIDINVALID = (UA_Int32) 0x80420000, // The monitoring item id does not refer to a valid monitored item.
	UA_STATUSCODE_BADMONITOREDITEMFILTERINVALID = (UA_Int32) 0x80430000, // The monitored item filter parameter is not valid.
	UA_STATUSCODE_BADMONITOREDITEMFILTERUNSUPPORTED = (UA_Int32) 0x80440000, // The server does not support the requested monitored item filter.
	UA_STATUSCODE_BADFILTERNOTALLOWED = (UA_Int32) 0x80450000, // A monitoring filter cannot be used in combination with the attribute specified.
	UA_STATUSCODE_BADSTRUCTUREMISSING = (UA_Int32) 0x80460000, // A mandatory structured parameter was missing or null.
	UA_STATUSCODE_BADEVENTFILTERINVALID = (UA_Int32) 0x80470000, // The event filter is not valid.
	UA_STATUSCODE_BADCONTENTFILTERINVALID = (UA_Int32) 0x80480000, // The content filter is not valid.
	UA_STATUSCODE_BADFILTEROPERATORINVALID = (UA_Int32) 0x80c10000, // An unregognized operator was provided in a filter.
	UA_STATUSCODE_BADFILTEROPERATORUNSUPPORTED = (UA_Int32) 0x80c20000, // A valid operator was provided, but the server does not provide support for this filter operator.
	UA_STATUSCODE_BADFILTEROPERANDCOUNTMISMATCH = (UA_Int32) 0x80c30000, // The number of operands provided for the filter operator was less then expected for the operand provided.
	UA_STATUSCODE_BADFILTEROPERANDINVALID = (UA_Int32) 0x80490000, // The operand used in a content filter is not valid.
	UA_STATUSCODE_BADFILTERELEMENTINVALID = (UA_Int32) 0x80c40000, // The referenced element is not a valid element in the content filter.
	UA_STATUSCODE_BADFILTERLITERALINVALID = (UA_Int32) 0x80c50000, // The referenced literal is not a valid value.
	UA_STATUSCODE_BADCONTINUATIONPOINTINVALID = (UA_Int32) 0x804a0000, // The continuation point provide is longer valid.
	UA_STATUSCODE_BADNOCONTINUATIONPOINTS = (UA_Int32) 0x804b0000, // The operation could not be processed because all continuation points have been allocated.
	UA_STATUSCODE_BADREFERENCETYPEIDINVALID = (UA_Int32) 0x804c0000, // The operation could not be processed because all continuation points have been allocated.
	UA_STATUSCODE_BADBROWSEDIRECTIONINVALID = (UA_Int32) 0x804d0000, // The browse direction is not valid.
	UA_STATUSCODE_BADNODENOTINVIEW = (UA_Int32) 0x804e0000, // The node is not part of the view.
	UA_STATUSCODE_BADSERVERURIINVALID = (UA_Int32) 0x804f0000, // The ServerUri is not a valid URI.
	UA_STATUSCODE_BADSERVERNAMEMISSING = (UA_Int32) 0x80500000, // No ServerName was specified.
	UA_STATUSCODE_BADDISCOVERYURLMISSING = (UA_Int32) 0x80510000, // No DiscoveryUrl was specified.
	UA_STATUSCODE_BADSEMPAHOREFILEMISSING = (UA_Int32) 0x80520000, // The semaphore file specified by the client is not valid.
	UA_STATUSCODE_BADREQUESTTYPEINVALID = (UA_Int32) 0x80530000, // The security token request type is not valid.
	UA_STATUSCODE_BADSECURITYMODEREJECTED = (UA_Int32) 0x80540000, // The security mode does not meet the requirements set by the Server.
	UA_STATUSCODE_BADSECURITYPOLICYREJECTED = (UA_Int32) 0x80550000, // The security policy does not meet the requirements set by the Server.
	UA_STATUSCODE_BADTOOMANYSESSIONS = (UA_Int32) 0x80560000, // The server has reached its maximum number of sessions.
	UA_STATUSCODE_BADUSERSIGNATUREINVALID = (UA_Int32) 0x80570000, // The user token signature is missing or invalid.
	UA_STATUSCODE_BADAPPLICATIONSIGNATUREINVALID = (UA_Int32) 0x80580000, // The signature generated with the client certificate is missing or invalid.
	UA_STATUSCODE_BADNOVALIDCERTIFICATES = (UA_Int32) 0x80590000, // The client did not provide at least one software certificate that is valid and meets the profile requirements for the server.
	UA_STATUSCODE_BADIDENTITYCHANGENOTSUPPORTED = (UA_Int32) 0x80c60000, // The Server does not support changing the user identity assigned to the session.
	UA_STATUSCODE_BADREQUESTCANCELLEDBYREQUEST = (UA_Int32) 0x805a0000, // The request was cancelled by the client with the Cancel service.
	UA_STATUSCODE_BADPARENTNODEIDINVALID = (UA_Int32) 0x805b0000, // The parent node id does not to refer to a valid node.
	UA_STATUSCODE_BADREFERENCENOTALLOWED = (UA_Int32) 0x805c0000, // The reference could not be created because it violates constraints imposed by the data model.
	UA_STATUSCODE_BADNODEIDREJECTED = (UA_Int32) 0x805d0000, // The requested node id was reject because it was either invalid or server does not allow node ids to be specified by the client.
	UA_STATUSCODE_BADNODEIDEXISTS = (UA_Int32) 0x805e0000, // The requested node id is already used by another node.
	UA_STATUSCODE_BADNODECLASSINVALID = (UA_Int32) 0x805f0000, // The node class is not valid.
	UA_STATUSCODE_BADBROWSENAMEINVALID = (UA_Int32) 0x80600000, // The browse name is invalid.
	UA_STATUSCODE_BADBROWSENAMEDUPLICATED = (UA_Int32) 0x80610000, // The browse name is not unique among nodes that share the same relationship with the parent.
	UA_STATUSCODE_BADNODEATTRIBUTESINVALID = (UA_Int32) 0x80620000, // The node attributes are not valid for the node class.
	UA_STATUSCODE_BADTYPEDEFINITIONINVALID = (UA_Int32) 0x80630000, // The type definition node id does not reference an appropriate type node.
	UA_STATUSCODE_BADSOURCENODEIDINVALID = (UA_Int32) 0x80640000, // The source node id does not reference a valid node.
	UA_STATUSCODE_BADTARGETNODEIDINVALID = (UA_Int32) 0x80650000, // The target node id does not reference a valid node.
	UA_STATUSCODE_BADDUPLICATEREFERENCENOTALLOWED = (UA_Int32) 0x80660000, // The reference type between the nodes is already defined.
	UA_STATUSCODE_BADINVALIDSELFREFERENCE = (UA_Int32) 0x80670000, // The server does not allow this type of self reference on this node.
	UA_STATUSCODE_BADREFERENCELOCALONLY = (UA_Int32) 0x80680000, // The reference type is not valid for a reference to a remote server.
	UA_STATUSCODE_BADNODELETERIGHTS = (UA_Int32) 0x80690000, // The server will not allow the node to be deleted.
	UA_STATUSCODE_UNCERTAINREFERENCENOTDELETED = (UA_Int32) 0x40bc0000, // The server was not able to delete all target references.
	UA_STATUSCODE_BADSERVERINDEXINVALID = (UA_Int32) 0x806a0000, // The server index is not valid.
	UA_STATUSCODE_BADVIEWIDUNKNOWN = (UA_Int32) 0x806b0000, // The view id does not refer to a valid view node.
	UA_STATUSCODE_BADVIEWTIMESTAMPINVALID = (UA_Int32) 0x80c90000, // The view timestamp is not available or not supported.
	UA_STATUSCODE_BADVIEWPARAMETERMISMATCH = (UA_Int32) 0x80ca0000, // The view parameters are not consistent with each other.
	UA_STATUSCODE_BADVIEWVERSIONINVALID = (UA_Int32) 0x80cb0000, // The view version is not available or not supported.
	UA_STATUSCODE_UNCERTAINNOTALLNODESAVAILABLE = (UA_Int32) 0x40c00000, // The list of references may not be complete because the underlying system is not available.
	UA_STATUSCODE_GOODRESULTSMAYBEINCOMPLETE = (UA_Int32) 0x00ba0000, // The server should have followed a reference to a node in a remote server but did not. The result set may be incomplete.
	UA_STATUSCODE_BADNOTTYPEDEFINITION = (UA_Int32) 0x80c80000, // The provided Nodeid was not a type definition nodeid.
	UA_STATUSCODE_UNCERTAINREFERENCEOUTOFSERVER = (UA_Int32) 0x406c0000, // One of the references to follow in the relative path references to a node in the address space in another server.
	UA_STATUSCODE_BADTOOMANYMATCHES = (UA_Int32) 0x806d0000, // The requested operation has too many matches to return.
	UA_STATUSCODE_BADQUERYTOOCOMPLEX = (UA_Int32) 0x806e0000, // The requested operation requires too many resources in the server.
	UA_STATUSCODE_BADNOMATCH = (UA_Int32) 0x806f0000, // The requested operation has no match to return.
	UA_STATUSCODE_BADMAXAGEINVALID = (UA_Int32) 0x80700000, // The max age parameter is invalid.
	UA_STATUSCODE_BADHISTORYOPERATIONINVALID = (UA_Int32) 0x80710000, // The history details parameter is not valid.
	UA_STATUSCODE_BADHISTORYOPERATIONUNSUPPORTED = (UA_Int32) 0x80720000, // The server does not support the requested operation.
	UA_STATUSCODE_BADINVALIDTIMESTAMPARGUMENT = (UA_Int32) 0x80bd0000, // The defined timestamp to return was invalid.
	UA_STATUSCODE_BADWRITENOTSUPPORTED = (UA_Int32) 0x80730000, // The server not does support writing the combination of value, status and timestamps provided.
	UA_STATUSCODE_BADTYPEMISMATCH = (UA_Int32) 0x80740000, // The value supplied for the attribute is not of the same type as the attribute's value.
	UA_STATUSCODE_BADMETHODINVALID = (UA_Int32) 0x80750000, // The method id does not refer to a method for the specified object.
	UA_STATUSCODE_BADARGUMENTSMISSING = (UA_Int32) 0x80760000, // The client did not specify all of the input arguments for the method.
	UA_STATUSCODE_BADTOOMANYSUBSCRIPTIONS = (UA_Int32) 0x80770000, // The server has reached its  maximum number of subscriptions.
	UA_STATUSCODE_BADTOOMANYPUBLISHREQUESTS = (UA_Int32) 0x80780000, // The server has reached the maximum number of queued publish requests.
	UA_STATUSCODE_BADNOSUBSCRIPTION = (UA_Int32) 0x80790000, // There is no subscription available for this session.
	UA_STATUSCODE_BADSEQUENCENUMBERUNKNOWN = (UA_Int32) 0x807a0000, // The sequence number is unknown to the server.
	UA_STATUSCODE_BADMESSAGENOTAVAILABLE = (UA_Int32) 0x807b0000, // The requested notification message is no longer available.
	UA_STATUSCODE_BADINSUFFICIENTCLIENTPROFILE = (UA_Int32) 0x807c0000, // The Client of the current Session does not support one or more Profiles that are necessary for the Subscription.
	UA_STATUSCODE_BADSTATENOTACTIVE = (UA_Int32) 0x80bf0000, // The sub-state machine is not currently active.
	UA_STATUSCODE_BADTCPSERVERTOOBUSY = (UA_Int32) 0x807d0000, // The server cannot process the request because it is too busy.
	UA_STATUSCODE_BADTCPMESSAGETYPEINVALID = (UA_Int32) 0x807e0000, // The type of the message specified in the header invalid.
	UA_STATUSCODE_BADTCPSECURECHANNELUNKNOWN = (UA_Int32) 0x807f0000, // The SecureChannelId and/or TokenId are not currently in use.
	UA_STATUSCODE_BADTCPMESSAGETOOLARGE = (UA_Int32) 0x80800000, // The size of the message specified in the header is too large.
	UA_STATUSCODE_BADTCPNOTENOUGHRESOURCES = (UA_Int32) 0x80810000, // There are not enough resources to process the request.
	UA_STATUSCODE_BADTCPINTERNALERROR = (UA_Int32) 0x80820000, // An internal error occurred.
	UA_STATUSCODE_BADTCPENDPOINTURLINVALID = (UA_Int32) 0x80830000, // The Server does not recognize the QueryString specified.
	UA_STATUSCODE_BADREQUESTINTERRUPTED = (UA_Int32) 0x80840000, // The request could not be sent because of a network interruption.
	UA_STATUSCODE_BADREQUESTTIMEOUT = (UA_Int32) 0x80850000, // Timeout occurred while processing the request.
	UA_STATUSCODE_BADSECURECHANNELCLOSED = (UA_Int32) 0x80860000, // The secure channel has been closed.
	UA_STATUSCODE_BADSECURECHANNELTOKENUNKNOWN = (UA_Int32) 0x80870000, // The token has expired or is not recognized.
	UA_STATUSCODE_BADSEQUENCENUMBERINVALID = (UA_Int32) 0x80880000, // The sequence number is not valid.
	UA_STATUSCODE_BADPROTOCOLVERSIONUNSUPPORTED = (UA_Int32) 0x80be0000, // The applications do not have compatible protocol versions.
	UA_STATUSCODE_BADCONFIGURATIONERROR = (UA_Int32) 0x80890000, // There is a problem with the configuration that affects the usefulness of the value.
	UA_STATUSCODE_BADNOTCONNECTED = (UA_Int32) 0x808a0000, // The variable should receive its value from another variable, but has never been configured to do so.
	UA_STATUSCODE_BADDEVICEFAILURE = (UA_Int32) 0x808b0000, // There has been a failure in the device/data source that generates the value that has affected the value.
	UA_STATUSCODE_BADSENSORFAILURE = (UA_Int32) 0x808c0000, // There has been a failure in the sensor from which the value is derived by the device/data source.
	UA_STATUSCODE_BADOUTOFSERVICE = (UA_Int32) 0x808d0000, // The source of the data is not operational.
	UA_STATUSCODE_BADDEADBANDFILTERINVALID = (UA_Int32) 0x808e0000, // The deadband filter is not valid.
	UA_STATUSCODE_UNCERTAINNOCOMMUNICATIONLASTUSABLEVALUE = (UA_Int32) 0x408f0000, // Communication to the data source has failed. The variable value is the last value that had a good quality.
	UA_STATUSCODE_UNCERTAINLASTUSABLEVALUE = (UA_Int32) 0x40900000, // Whatever was updating this value has stopped doing so.
	UA_STATUSCODE_UNCERTAINSUBSTITUTEVALUE = (UA_Int32) 0x40910000, // The value is an operational value that was manually overwritten.
	UA_STATUSCODE_UNCERTAININITIALVALUE = (UA_Int32) 0x40920000, // The value is an initial value for a variable that normally receives its value from another variable.
	UA_STATUSCODE_UNCERTAINSENSORNOTACCURATE = (UA_Int32) 0x40930000, // The value is at one of the sensor limits.
	UA_STATUSCODE_UNCERTAINENGINEERINGUNITSEXCEEDED = (UA_Int32) 0x40940000, // The value is outside of the range of values defined for this parameter.
	UA_STATUSCODE_UNCERTAINSUBNORMAL = (UA_Int32) 0x40950000, // The value is derived from multiple sources and has less than the required number of Good sources.
	UA_STATUSCODE_GOODLOCALOVERRIDE = (UA_Int32) 0x00960000, // The value has been overridden.
	UA_STATUSCODE_BADREFRESHINPROGRESS = (UA_Int32) 0x80970000, // This Condition refresh failed, a Condition refresh operation is already in progress.
	UA_STATUSCODE_BADCONDITIONALREADYDISABLED = (UA_Int32) 0x80980000, // This condition has already been disabled.
	UA_STATUSCODE_BADCONDITIONALREADYENABLED = (UA_Int32) 0x80cc0000, // This condition has already been enabled.
	UA_STATUSCODE_BADCONDITIONDISABLED = (UA_Int32) 0x80990000, // Property not available, this condition is disabled.
	UA_STATUSCODE_BADEVENTIDUNKNOWN = (UA_Int32) 0x809a0000, // The specified event id is not recognized.
	UA_STATUSCODE_BADEVENTNOTACKNOWLEDGEABLE = (UA_Int32) 0x80bb0000, // The event cannot be acknowledged.
	UA_STATUSCODE_BADDIALOGNOTACTIVE = (UA_Int32) 0x80cd0000, // The dialog condition is not active.
	UA_STATUSCODE_BADDIALOGRESPONSEINVALID = (UA_Int32) 0x80ce0000, // The response is not valid for the dialog.
	UA_STATUSCODE_BADCONDITIONBRANCHALREADYACKED = (UA_Int32) 0x80cf0000, // The condition branch has already been acknowledged.
	UA_STATUSCODE_BADCONDITIONBRANCHALREADYCONFIRMED = (UA_Int32) 0x80d00000, // The condition branch has already been confirmed.
	UA_STATUSCODE_BADCONDITIONALREADYSHELVED = (UA_Int32) 0x80d10000, // The condition has already been shelved.
	UA_STATUSCODE_BADCONDITIONNOTSHELVED = (UA_Int32) 0x80d20000, // The condition is not currently shelved.
	UA_STATUSCODE_BADSHELVINGTIMEOUTOFRANGE = (UA_Int32) 0x80d30000, // The shelving time not within an acceptable range.
	UA_STATUSCODE_BADNODATA = (UA_Int32) 0x809b0000, // No data exists for the requested time range or event filter.
	UA_STATUSCODE_BADBOUNDNOTFOUND = (UA_Int32) 0x80d70000, // No data found to provide upper or lower bound value.
	UA_STATUSCODE_BADBOUNDNOTSUPPORTED = (UA_Int32) 0x80d80000, // The server cannot retrieve a bound for the variable.
	UA_STATUSCODE_BADDATALOST = (UA_Int32) 0x809d0000, // Data is missing due to collection started/stopped/lost.
	UA_STATUSCODE_BADDATAUNAVAILABLE = (UA_Int32) 0x809e0000, // Expected data is unavailable for the requested time range due to an un-mounted volume, an off-line archive or tape, or similar reason for temporary unavailability.
	UA_STATUSCODE_BADENTRYEXISTS = (UA_Int32) 0x809f0000, // The data or event was not successfully inserted because a matching entry exists.
	UA_STATUSCODE_BADNOENTRYEXISTS = (UA_Int32) 0x80a00000, // The data or event was not successfully updated because no matching entry exists.
	UA_STATUSCODE_BADTIMESTAMPNOTSUPPORTED = (UA_Int32) 0x80a10000, // The client requested history using a timestamp format the server does not support (i.e requested ServerTimestamp when server only supports SourceTimestamp).
	UA_STATUSCODE_GOODENTRYINSERTED = (UA_Int32) 0x00a20000, // The data or event was successfully inserted into the historical database.
	UA_STATUSCODE_GOODENTRYREPLACED = (UA_Int32) 0x00a30000, // The data or event field was successfully replaced in the historical database.
	UA_STATUSCODE_UNCERTAINDATASUBNORMAL = (UA_Int32) 0x40a40000, // The value is derived from multiple values and has less than the required number of Good values.
	UA_STATUSCODE_GOODNODATA = (UA_Int32) 0x00a50000, // No data exists for the requested time range or event filter.
	UA_STATUSCODE_GOODMOREDATA = (UA_Int32) 0x00a60000, // The data or event field was successfully replaced in the historical database.
	UA_STATUSCODE_BADAGGREGATELISTMISMATCH = (UA_Int32) 0x80d40000, // The requested number of Aggregates does not match the requested number of NodeIds.
	UA_STATUSCODE_BADAGGREGATENOTSUPPORTED = (UA_Int32) 0x80d50000, // The requested Aggregate is not support by the server.
	UA_STATUSCODE_BADAGGREGATEINVALIDINPUTS = (UA_Int32) 0x80d60000, // The aggregate value could not be derived due to invalid data inputs.
	UA_STATUSCODE_BADAGGREGATECONFIGURATIONREJECTED = (UA_Int32) 0x80da0000, // The aggregate configuration is not valid for specified node.
	UA_STATUSCODE_GOODDATAIGNORED = (UA_Int32) 0x00d90000, // The request pecifies fields which are not valid for the EventType or cannot be saved by the historian.
	UA_STATUSCODE_GOODCOMMUNICATIONEVENT = (UA_Int32) 0x00a70000, // The communication layer has raised an event.
	UA_STATUSCODE_GOODSHUTDOWNEVENT = (UA_Int32) 0x00a80000, // The system is shutting down.
	UA_STATUSCODE_GOODCALLAGAIN = (UA_Int32) 0x00a90000, // The operation is not finished and needs to be called again.
	UA_STATUSCODE_GOODNONCRITICALTIMEOUT = (UA_Int32) 0x00aa0000, // A non-critical timeout occurred.
	UA_STATUSCODE_BADINVALIDARGUMENT = (UA_Int32) 0x80ab0000, // One or more arguments are invalid.
	UA_STATUSCODE_BADCONNECTIONREJECTED = (UA_Int32) 0x80ac0000, // Could not establish a network connection to remote server.
	UA_STATUSCODE_BADDISCONNECT = (UA_Int32) 0x80ad0000, // The server has disconnected from the client.
	UA_STATUSCODE_BADCONNECTIONCLOSED = (UA_Int32) 0x80ae0000, // The network connection has been closed.
	UA_STATUSCODE_BADINVALIDSTATE = (UA_Int32) 0x80af0000, // The operation cannot be completed because the object is closed, uninitialized or in some other invalid state.
	UA_STATUSCODE_BADENDOFSTREAM = (UA_Int32) 0x80b00000, // Cannot move beyond end of the stream.
	UA_STATUSCODE_BADNODATAAVAILABLE = (UA_Int32) 0x80b10000, // No data is currently available for reading from a non-blocking stream.
	UA_STATUSCODE_BADWAITINGFORRESPONSE = (UA_Int32) 0x80b20000, // The asynchronous operation is waiting for a response.
	UA_STATUSCODE_BADOPERATIONABANDONED = (UA_Int32) 0x80b30000, // The asynchronous operation was abandoned by the caller.
	UA_STATUSCODE_BADEXPECTEDSTREAMTOBLOCK = (UA_Int32) 0x80b40000, // The stream did not return all data requested (possibly because it is a non-blocking stream).
	UA_STATUSCODE_BADWOULDBLOCK = (UA_Int32) 0x80b50000, // Non blocking behaviour is required and the operation would block.
	UA_STATUSCODE_BADSYNTAXERROR = (UA_Int32) 0x80b60000, // A value had an invalid syntax.
	UA_STATUSCODE_BADMAXCONNECTIONSREACHED = (UA_Int32) 0x80b70000 // The operation could not be finished because all available connections are in use.
};

#endif /* UA_STATUSCODES_H_ */
#endif /* UA_TYPES_H_ */
