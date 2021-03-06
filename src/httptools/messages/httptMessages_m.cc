//
// Generated file, do not edit! Created by opp_msgc 4.1 from httptools/messages/httptMessages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "httptMessages_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("HTTPMessageKind");
    if (!e) enums.getInstance()->add(e = new cEnum("HTTPMessageKind"));
    e->insert(HTTPT_REQUEST_MESSAGE, "HTTPT_REQUEST_MESSAGE");
    e->insert(HTTPT_DELAYED_REQUEST_MESSAGE, "HTTPT_DELAYED_REQUEST_MESSAGE");
    e->insert(HTTPT_RESPONSE_MESSAGE, "HTTPT_RESPONSE_MESSAGE");
    e->insert(HTTPT_DELAYED_RESPONSE_MESSAGE, "HTTPT_DELAYED_RESPONSE_MESSAGE");
);

Register_Class(httptBaseMessage);

httptBaseMessage::httptBaseMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->targetUrl_var = 0;
    this->originatorUrl_var = "";
    this->protocol_var = HTTP_11;
    this->keepAlive_var = true;
    this->serial_var = 0;
    this->heading_var = "";
    this->payload_var = "";
    this->headerLength_var = 0;
    this->contentLength_var = 0;
}

httptBaseMessage::httptBaseMessage(const httptBaseMessage& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

httptBaseMessage::~httptBaseMessage()
{
}

httptBaseMessage& httptBaseMessage::operator=(const httptBaseMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->targetUrl_var = other.targetUrl_var;
    this->originatorUrl_var = other.originatorUrl_var;
    this->protocol_var = other.protocol_var;
    this->keepAlive_var = other.keepAlive_var;
    this->serial_var = other.serial_var;
    this->heading_var = other.heading_var;
    this->payload_var = other.payload_var;
    this->headerLength_var = other.headerLength_var;
    this->contentLength_var = other.contentLength_var;
    return *this;
}

void httptBaseMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->targetUrl_var);
    doPacking(b,this->originatorUrl_var);
    doPacking(b,this->protocol_var);
    doPacking(b,this->keepAlive_var);
    doPacking(b,this->serial_var);
    doPacking(b,this->heading_var);
    doPacking(b,this->payload_var);
    doPacking(b,this->headerLength_var);
    doPacking(b,this->contentLength_var);
}

void httptBaseMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->targetUrl_var);
    doUnpacking(b,this->originatorUrl_var);
    doUnpacking(b,this->protocol_var);
    doUnpacking(b,this->keepAlive_var);
    doUnpacking(b,this->serial_var);
    doUnpacking(b,this->heading_var);
    doUnpacking(b,this->payload_var);
    doUnpacking(b,this->headerLength_var);
    doUnpacking(b,this->contentLength_var);
}

const char * httptBaseMessage::targetUrl() const
{
    return targetUrl_var.c_str();
}

void httptBaseMessage::setTargetUrl(const char * targetUrl_var)
{
    this->targetUrl_var = targetUrl_var;
}

const char * httptBaseMessage::originatorUrl() const
{
    return originatorUrl_var.c_str();
}

void httptBaseMessage::setOriginatorUrl(const char * originatorUrl_var)
{
    this->originatorUrl_var = originatorUrl_var;
}

int httptBaseMessage::protocol() const
{
    return protocol_var;
}

void httptBaseMessage::setProtocol(int protocol_var)
{
    this->protocol_var = protocol_var;
}

bool httptBaseMessage::keepAlive() const
{
    return keepAlive_var;
}

void httptBaseMessage::setKeepAlive(bool keepAlive_var)
{
    this->keepAlive_var = keepAlive_var;
}

int httptBaseMessage::serial() const
{
    return serial_var;
}

void httptBaseMessage::setSerial(int serial_var)
{
    this->serial_var = serial_var;
}

const char * httptBaseMessage::heading() const
{
    return heading_var.c_str();
}

void httptBaseMessage::setHeading(const char * heading_var)
{
    this->heading_var = heading_var;
}

const char * httptBaseMessage::payload() const
{
    return payload_var.c_str();
}

void httptBaseMessage::setPayload(const char * payload_var)
{
    this->payload_var = payload_var;
}

int httptBaseMessage::headerLength() const
{
    return headerLength_var;
}

void httptBaseMessage::setHeaderLength(int headerLength_var)
{
    this->headerLength_var = headerLength_var;
}

int httptBaseMessage::contentLength() const
{
    return contentLength_var;
}

void httptBaseMessage::setContentLength(int contentLength_var)
{
    this->contentLength_var = contentLength_var;
}

class httptBaseMessageDescriptor : public cClassDescriptor
{
  public:
    httptBaseMessageDescriptor();
    virtual ~httptBaseMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(httptBaseMessageDescriptor);

httptBaseMessageDescriptor::httptBaseMessageDescriptor() : cClassDescriptor("httptBaseMessage", "cPacket")
{
}

httptBaseMessageDescriptor::~httptBaseMessageDescriptor()
{
}

bool httptBaseMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<httptBaseMessage *>(obj)!=NULL;
}

const char *httptBaseMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int httptBaseMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int httptBaseMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *httptBaseMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "targetUrl",
        "originatorUrl",
        "protocol",
        "keepAlive",
        "serial",
        "heading",
        "payload",
        "headerLength",
        "contentLength",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int httptBaseMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetUrl")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorUrl")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocol")==0) return base+2;
    if (fieldName[0]=='k' && strcmp(fieldName, "keepAlive")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "serial")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "heading")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+6;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "contentLength")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *httptBaseMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
        "bool",
        "int",
        "string",
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *httptBaseMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "HTTPProtocol";
            return NULL;
        default: return NULL;
    }
}

int httptBaseMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    httptBaseMessage *pp = (httptBaseMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string httptBaseMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    httptBaseMessage *pp = (httptBaseMessage *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->targetUrl());
        case 1: return oppstring2string(pp->originatorUrl());
        case 2: return long2string(pp->protocol());
        case 3: return bool2string(pp->keepAlive());
        case 4: return long2string(pp->serial());
        case 5: return oppstring2string(pp->heading());
        case 6: return oppstring2string(pp->payload());
        case 7: return long2string(pp->headerLength());
        case 8: return long2string(pp->contentLength());
        default: return "";
    }
}

bool httptBaseMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    httptBaseMessage *pp = (httptBaseMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setTargetUrl((value)); return true;
        case 1: pp->setOriginatorUrl((value)); return true;
        case 2: pp->setProtocol(string2long(value)); return true;
        case 3: pp->setKeepAlive(string2bool(value)); return true;
        case 4: pp->setSerial(string2long(value)); return true;
        case 5: pp->setHeading((value)); return true;
        case 6: pp->setPayload((value)); return true;
        case 7: pp->setHeaderLength(string2long(value)); return true;
        case 8: pp->setContentLength(string2long(value)); return true;
        default: return false;
    }
}

const char *httptBaseMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<9) ? fieldStructNames[field] : NULL;
}

void *httptBaseMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    httptBaseMessage *pp = (httptBaseMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(httptRequestMessage);

httptRequestMessage::httptRequestMessage(const char *name, int kind) : httptBaseMessage(name,kind)
{
    this->badRequest_var = false;
    this->method_var = RM_NONE;
    this->uri_var = "";
    this->firstBytePos_var = BRS_UNSPECIFIED;
    this->lastBytePos_var = BRS_UNSPECIFIED;
    this->entitySize_var = -1;
}

httptRequestMessage::httptRequestMessage(const httptRequestMessage& other) : httptBaseMessage()
{
    setName(other.getName());
    operator=(other);
}

httptRequestMessage::~httptRequestMessage()
{
}

httptRequestMessage& httptRequestMessage::operator=(const httptRequestMessage& other)
{
    if (this==&other) return *this;
    httptBaseMessage::operator=(other);
    this->badRequest_var = other.badRequest_var;
    this->method_var = other.method_var;
    this->uri_var = other.uri_var;
    this->firstBytePos_var = other.firstBytePos_var;
    this->lastBytePos_var = other.lastBytePos_var;
    this->entitySize_var = other.entitySize_var;
    return *this;
}

void httptRequestMessage::parsimPack(cCommBuffer *b)
{
    httptBaseMessage::parsimPack(b);
    doPacking(b,this->badRequest_var);
    doPacking(b,this->method_var);
    doPacking(b,this->uri_var);
    doPacking(b,this->firstBytePos_var);
    doPacking(b,this->lastBytePos_var);
    doPacking(b,this->entitySize_var);
}

void httptRequestMessage::parsimUnpack(cCommBuffer *b)
{
    httptBaseMessage::parsimUnpack(b);
    doUnpacking(b,this->badRequest_var);
    doUnpacking(b,this->method_var);
    doUnpacking(b,this->uri_var);
    doUnpacking(b,this->firstBytePos_var);
    doUnpacking(b,this->lastBytePos_var);
    doUnpacking(b,this->entitySize_var);
}

bool httptRequestMessage::badRequest() const
{
    return badRequest_var;
}

void httptRequestMessage::setBadRequest(bool badRequest_var)
{
    this->badRequest_var = badRequest_var;
}

int httptRequestMessage::method() const
{
    return method_var;
}

void httptRequestMessage::setMethod(int method_var)
{
    this->method_var = method_var;
}

const char * httptRequestMessage::uri() const
{
    return uri_var.c_str();
}

void httptRequestMessage::setUri(const char * uri_var)
{
    this->uri_var = uri_var;
}

int httptRequestMessage::firstBytePos() const
{
    return firstBytePos_var;
}

void httptRequestMessage::setFirstBytePos(int firstBytePos_var)
{
    this->firstBytePos_var = firstBytePos_var;
}

int httptRequestMessage::lastBytePos() const
{
    return lastBytePos_var;
}

void httptRequestMessage::setLastBytePos(int lastBytePos_var)
{
    this->lastBytePos_var = lastBytePos_var;
}

int httptRequestMessage::entitySize() const
{
    return entitySize_var;
}

void httptRequestMessage::setEntitySize(int entitySize_var)
{
    this->entitySize_var = entitySize_var;
}

class httptRequestMessageDescriptor : public cClassDescriptor
{
  public:
    httptRequestMessageDescriptor();
    virtual ~httptRequestMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(httptRequestMessageDescriptor);

httptRequestMessageDescriptor::httptRequestMessageDescriptor() : cClassDescriptor("httptRequestMessage", "httptBaseMessage")
{
}

httptRequestMessageDescriptor::~httptRequestMessageDescriptor()
{
}

bool httptRequestMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<httptRequestMessage *>(obj)!=NULL;
}

const char *httptRequestMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int httptRequestMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int httptRequestMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *httptRequestMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "badRequest",
        "method",
        "uri",
        "firstBytePos",
        "lastBytePos",
        "entitySize",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int httptRequestMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "badRequest")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "method")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "uri")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "firstBytePos")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastBytePos")==0) return base+4;
    if (fieldName[0]=='e' && strcmp(fieldName, "entitySize")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *httptRequestMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "string",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *httptRequestMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "RequestMethod";
            return NULL;
        default: return NULL;
    }
}

int httptRequestMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    httptRequestMessage *pp = (httptRequestMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string httptRequestMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    httptRequestMessage *pp = (httptRequestMessage *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->badRequest());
        case 1: return long2string(pp->method());
        case 2: return oppstring2string(pp->uri());
        case 3: return long2string(pp->firstBytePos());
        case 4: return long2string(pp->lastBytePos());
        case 5: return long2string(pp->entitySize());
        default: return "";
    }
}

bool httptRequestMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    httptRequestMessage *pp = (httptRequestMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setBadRequest(string2bool(value)); return true;
        case 1: pp->setMethod(string2long(value)); return true;
        case 2: pp->setUri((value)); return true;
        case 3: pp->setFirstBytePos(string2long(value)); return true;
        case 4: pp->setLastBytePos(string2long(value)); return true;
        case 5: pp->setEntitySize(string2long(value)); return true;
        default: return false;
    }
}

const char *httptRequestMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *httptRequestMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    httptRequestMessage *pp = (httptRequestMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(httptReplyMessage);

httptReplyMessage::httptReplyMessage(const char *name, int kind) : httptBaseMessage(name,kind)
{
    this->result_var = 0;
    this->contentType_var = 0;
    this->contentTypeString_var = "";
    this->phrase_var = "";
    this->relatedUri_var = "";
    this->firstBytePos_var = BRS_UNSPECIFIED;
    this->lastBytePos_var = BRS_UNSPECIFIED;
    this->instanceLength_var = BRS_UNSPECIFIED;
}

httptReplyMessage::httptReplyMessage(const httptReplyMessage& other) : httptBaseMessage()
{
    setName(other.getName());
    operator=(other);
}

httptReplyMessage::~httptReplyMessage()
{
}

httptReplyMessage& httptReplyMessage::operator=(const httptReplyMessage& other)
{
    if (this==&other) return *this;
    httptBaseMessage::operator=(other);
    this->result_var = other.result_var;
    this->contentType_var = other.contentType_var;
    this->contentTypeString_var = other.contentTypeString_var;
    this->phrase_var = other.phrase_var;
    this->relatedUri_var = other.relatedUri_var;
    this->firstBytePos_var = other.firstBytePos_var;
    this->lastBytePos_var = other.lastBytePos_var;
    this->instanceLength_var = other.instanceLength_var;
    return *this;
}

void httptReplyMessage::parsimPack(cCommBuffer *b)
{
    httptBaseMessage::parsimPack(b);
    doPacking(b,this->result_var);
    doPacking(b,this->contentType_var);
    doPacking(b,this->contentTypeString_var);
    doPacking(b,this->phrase_var);
    doPacking(b,this->relatedUri_var);
    doPacking(b,this->firstBytePos_var);
    doPacking(b,this->lastBytePos_var);
    doPacking(b,this->instanceLength_var);
}

void httptReplyMessage::parsimUnpack(cCommBuffer *b)
{
    httptBaseMessage::parsimUnpack(b);
    doUnpacking(b,this->result_var);
    doUnpacking(b,this->contentType_var);
    doUnpacking(b,this->contentTypeString_var);
    doUnpacking(b,this->phrase_var);
    doUnpacking(b,this->relatedUri_var);
    doUnpacking(b,this->firstBytePos_var);
    doUnpacking(b,this->lastBytePos_var);
    doUnpacking(b,this->instanceLength_var);
}

int httptReplyMessage::result() const
{
    return result_var;
}

void httptReplyMessage::setResult(int result_var)
{
    this->result_var = result_var;
}

int httptReplyMessage::contentType() const
{
    return contentType_var;
}

void httptReplyMessage::setContentType(int contentType_var)
{
    this->contentType_var = contentType_var;
}

const char * httptReplyMessage::contentTypeString() const
{
    return contentTypeString_var.c_str();
}

void httptReplyMessage::setContentTypeString(const char * contentTypeString_var)
{
    this->contentTypeString_var = contentTypeString_var;
}

const char * httptReplyMessage::phrase() const
{
    return phrase_var.c_str();
}

void httptReplyMessage::setPhrase(const char * phrase_var)
{
    this->phrase_var = phrase_var;
}

const char * httptReplyMessage::relatedUri() const
{
    return relatedUri_var.c_str();
}

void httptReplyMessage::setRelatedUri(const char * relatedUri_var)
{
    this->relatedUri_var = relatedUri_var;
}

int httptReplyMessage::firstBytePos() const
{
    return firstBytePos_var;
}

void httptReplyMessage::setFirstBytePos(int firstBytePos_var)
{
    this->firstBytePos_var = firstBytePos_var;
}

int httptReplyMessage::lastBytePos() const
{
    return lastBytePos_var;
}

void httptReplyMessage::setLastBytePos(int lastBytePos_var)
{
    this->lastBytePos_var = lastBytePos_var;
}

int httptReplyMessage::instanceLength() const
{
    return instanceLength_var;
}

void httptReplyMessage::setInstanceLength(int instanceLength_var)
{
    this->instanceLength_var = instanceLength_var;
}

class httptReplyMessageDescriptor : public cClassDescriptor
{
  public:
    httptReplyMessageDescriptor();
    virtual ~httptReplyMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(httptReplyMessageDescriptor);

httptReplyMessageDescriptor::httptReplyMessageDescriptor() : cClassDescriptor("httptReplyMessage", "httptBaseMessage")
{
}

httptReplyMessageDescriptor::~httptReplyMessageDescriptor()
{
}

bool httptReplyMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<httptReplyMessage *>(obj)!=NULL;
}

const char *httptReplyMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int httptReplyMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int httptReplyMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *httptReplyMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "result",
        "contentType",
        "contentTypeString",
        "phrase",
        "relatedUri",
        "firstBytePos",
        "lastBytePos",
        "instanceLength",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int httptReplyMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "result")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contentType")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "contentTypeString")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "phrase")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "relatedUri")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "firstBytePos")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastBytePos")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "instanceLength")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *httptReplyMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "string",
        "string",
        "string",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *httptReplyMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int httptReplyMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    httptReplyMessage *pp = (httptReplyMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string httptReplyMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    httptReplyMessage *pp = (httptReplyMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->result());
        case 1: return long2string(pp->contentType());
        case 2: return oppstring2string(pp->contentTypeString());
        case 3: return oppstring2string(pp->phrase());
        case 4: return oppstring2string(pp->relatedUri());
        case 5: return long2string(pp->firstBytePos());
        case 6: return long2string(pp->lastBytePos());
        case 7: return long2string(pp->instanceLength());
        default: return "";
    }
}

bool httptReplyMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    httptReplyMessage *pp = (httptReplyMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setResult(string2long(value)); return true;
        case 1: pp->setContentType(string2long(value)); return true;
        case 2: pp->setContentTypeString((value)); return true;
        case 3: pp->setPhrase((value)); return true;
        case 4: pp->setRelatedUri((value)); return true;
        case 5: pp->setFirstBytePos(string2long(value)); return true;
        case 6: pp->setLastBytePos(string2long(value)); return true;
        case 7: pp->setInstanceLength(string2long(value)); return true;
        default: return false;
    }
}

const char *httptReplyMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *httptReplyMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    httptReplyMessage *pp = (httptReplyMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


