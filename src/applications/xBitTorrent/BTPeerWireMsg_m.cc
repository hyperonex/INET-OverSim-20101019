//
// Generated file, do not edit! Created by opp_msgc 4.1 from applications/xBitTorrent/BTPeerWireMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BTPeerWireMsg_m.h"

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
    cEnum *e = cEnum::find("PeerWireMsgIDs");
    if (!e) enums.getInstance()->add(e = new cEnum("PeerWireMsgIDs"));
    e->insert(CHOKE, "CHOKE");
    e->insert(UNCHOKE, "UNCHOKE");
    e->insert(INTERESTED, "INTERESTED");
    e->insert(NOT_INTERESTED, "NOT_INTERESTED");
    e->insert(HAVE, "HAVE");
    e->insert(BITFIELD, "BITFIELD");
    e->insert(REQUEST, "REQUEST");
    e->insert(PIECE, "PIECE");
    e->insert(CANCEL, "CANCEL");
);

Register_Class(BTMsgHandshake);

BTMsgHandshake::BTMsgHandshake(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->pstrlen_var = 0;
    this->pstr_var = 0;
    for (unsigned int i=0; i<8; i++)
        this->reserved_var[i] = 0;
    this->infoHash_var = 0;
    this->peerId_var = 0;
}

BTMsgHandshake::BTMsgHandshake(const BTMsgHandshake& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTMsgHandshake::~BTMsgHandshake()
{
}

BTMsgHandshake& BTMsgHandshake::operator=(const BTMsgHandshake& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->pstrlen_var = other.pstrlen_var;
    this->pstr_var = other.pstr_var;
    for (unsigned int i=0; i<8; i++)
        this->reserved_var[i] = other.reserved_var[i];
    this->infoHash_var = other.infoHash_var;
    this->peerId_var = other.peerId_var;
    return *this;
}

void BTMsgHandshake::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->pstrlen_var);
    doPacking(b,this->pstr_var);
    doPacking(b,this->reserved_var,8);
    doPacking(b,this->infoHash_var);
    doPacking(b,this->peerId_var);
}

void BTMsgHandshake::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->pstrlen_var);
    doUnpacking(b,this->pstr_var);
    doUnpacking(b,this->reserved_var,8);
    doUnpacking(b,this->infoHash_var);
    doUnpacking(b,this->peerId_var);
}

char BTMsgHandshake::pstrlen() const
{
    return pstrlen_var;
}

void BTMsgHandshake::setPstrlen(char pstrlen_var)
{
    this->pstrlen_var = pstrlen_var;
}

const char * BTMsgHandshake::pstr() const
{
    return pstr_var.c_str();
}

void BTMsgHandshake::setPstr(const char * pstr_var)
{
    this->pstr_var = pstr_var;
}

unsigned int BTMsgHandshake::reservedArraySize() const
{
    return 8;
}

bool BTMsgHandshake::reserved(unsigned int k) const
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return reserved_var[k];
}

void BTMsgHandshake::setReserved(unsigned int k, bool reserved_var)
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    this->reserved_var[k] = reserved_var;
}

const char * BTMsgHandshake::infoHash() const
{
    return infoHash_var.c_str();
}

void BTMsgHandshake::setInfoHash(const char * infoHash_var)
{
    this->infoHash_var = infoHash_var;
}

const char * BTMsgHandshake::peerId() const
{
    return peerId_var.c_str();
}

void BTMsgHandshake::setPeerId(const char * peerId_var)
{
    this->peerId_var = peerId_var;
}

class BTMsgHandshakeDescriptor : public cClassDescriptor
{
  public:
    BTMsgHandshakeDescriptor();
    virtual ~BTMsgHandshakeDescriptor();

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

Register_ClassDescriptor(BTMsgHandshakeDescriptor);

BTMsgHandshakeDescriptor::BTMsgHandshakeDescriptor() : cClassDescriptor("BTMsgHandshake", "GenericAppMsg")
{
}

BTMsgHandshakeDescriptor::~BTMsgHandshakeDescriptor()
{
}

bool BTMsgHandshakeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTMsgHandshake *>(obj)!=NULL;
}

const char *BTMsgHandshakeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTMsgHandshakeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int BTMsgHandshakeDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *BTMsgHandshakeDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pstrlen",
        "pstr",
        "reserved",
        "infoHash",
        "peerId",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int BTMsgHandshakeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pstrlen")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pstr")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "infoHash")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerId")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTMsgHandshakeDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "string",
        "bool",
        "string",
        "string",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *BTMsgHandshakeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTMsgHandshakeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTMsgHandshake *pp = (BTMsgHandshake *)object; (void)pp;
    switch (field) {
        case 2: return 8;
        default: return 0;
    }
}

std::string BTMsgHandshakeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTMsgHandshake *pp = (BTMsgHandshake *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->pstrlen());
        case 1: return oppstring2string(pp->pstr());
        case 2: return bool2string(pp->reserved(i));
        case 3: return oppstring2string(pp->infoHash());
        case 4: return oppstring2string(pp->peerId());
        default: return "";
    }
}

bool BTMsgHandshakeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTMsgHandshake *pp = (BTMsgHandshake *)object; (void)pp;
    switch (field) {
        case 0: pp->setPstrlen(string2long(value)); return true;
        case 1: pp->setPstr((value)); return true;
        case 2: pp->setReserved(i,string2bool(value)); return true;
        case 3: pp->setInfoHash((value)); return true;
        case 4: pp->setPeerId((value)); return true;
        default: return false;
    }
}

const char *BTMsgHandshakeDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *BTMsgHandshakeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTMsgHandshake *pp = (BTMsgHandshake *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTKeepAliveMsg);

BTKeepAliveMsg::BTKeepAliveMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->length_prefix_var = 0;
}

BTKeepAliveMsg::BTKeepAliveMsg(const BTKeepAliveMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTKeepAliveMsg::~BTKeepAliveMsg()
{
}

BTKeepAliveMsg& BTKeepAliveMsg::operator=(const BTKeepAliveMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->length_prefix_var = other.length_prefix_var;
    return *this;
}

void BTKeepAliveMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->length_prefix_var);
}

void BTKeepAliveMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->length_prefix_var);
}

int BTKeepAliveMsg::length_prefix() const
{
    return length_prefix_var;
}

void BTKeepAliveMsg::setLength_prefix(int length_prefix_var)
{
    this->length_prefix_var = length_prefix_var;
}

class BTKeepAliveMsgDescriptor : public cClassDescriptor
{
  public:
    BTKeepAliveMsgDescriptor();
    virtual ~BTKeepAliveMsgDescriptor();

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

Register_ClassDescriptor(BTKeepAliveMsgDescriptor);

BTKeepAliveMsgDescriptor::BTKeepAliveMsgDescriptor() : cClassDescriptor("BTKeepAliveMsg", "GenericAppMsg")
{
}

BTKeepAliveMsgDescriptor::~BTKeepAliveMsgDescriptor()
{
}

bool BTKeepAliveMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTKeepAliveMsg *>(obj)!=NULL;
}

const char *BTKeepAliveMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTKeepAliveMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BTKeepAliveMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *BTKeepAliveMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length_prefix",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BTKeepAliveMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length_prefix")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTKeepAliveMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *BTKeepAliveMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTKeepAliveMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTKeepAliveMsg *pp = (BTKeepAliveMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTKeepAliveMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTKeepAliveMsg *pp = (BTKeepAliveMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->length_prefix());
        default: return "";
    }
}

bool BTKeepAliveMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTKeepAliveMsg *pp = (BTKeepAliveMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setLength_prefix(string2long(value)); return true;
        default: return false;
    }
}

const char *BTKeepAliveMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *BTKeepAliveMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTKeepAliveMsg *pp = (BTKeepAliveMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTPeerStateMsg);

BTPeerStateMsg::BTPeerStateMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->length_prefix_var = 0;
    this->ID_var = 0;
}

BTPeerStateMsg::BTPeerStateMsg(const BTPeerStateMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTPeerStateMsg::~BTPeerStateMsg()
{
}

BTPeerStateMsg& BTPeerStateMsg::operator=(const BTPeerStateMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->length_prefix_var = other.length_prefix_var;
    this->ID_var = other.ID_var;
    return *this;
}

void BTPeerStateMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->length_prefix_var);
    doPacking(b,this->ID_var);
}

void BTPeerStateMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->length_prefix_var);
    doUnpacking(b,this->ID_var);
}

int BTPeerStateMsg::length_prefix() const
{
    return length_prefix_var;
}

void BTPeerStateMsg::setLength_prefix(int length_prefix_var)
{
    this->length_prefix_var = length_prefix_var;
}

unsigned short BTPeerStateMsg::ID() const
{
    return ID_var;
}

void BTPeerStateMsg::setID(unsigned short ID_var)
{
    this->ID_var = ID_var;
}

class BTPeerStateMsgDescriptor : public cClassDescriptor
{
  public:
    BTPeerStateMsgDescriptor();
    virtual ~BTPeerStateMsgDescriptor();

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

Register_ClassDescriptor(BTPeerStateMsgDescriptor);

BTPeerStateMsgDescriptor::BTPeerStateMsgDescriptor() : cClassDescriptor("BTPeerStateMsg", "GenericAppMsg")
{
}

BTPeerStateMsgDescriptor::~BTPeerStateMsgDescriptor()
{
}

bool BTPeerStateMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTPeerStateMsg *>(obj)!=NULL;
}

const char *BTPeerStateMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTPeerStateMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int BTPeerStateMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *BTPeerStateMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length_prefix",
        "ID",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int BTPeerStateMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length_prefix")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTPeerStateMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "unsigned short",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *BTPeerStateMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "PeerWireMsgIDs";
            return NULL;
        default: return NULL;
    }
}

int BTPeerStateMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTPeerStateMsg *pp = (BTPeerStateMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTPeerStateMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTPeerStateMsg *pp = (BTPeerStateMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->length_prefix());
        case 1: return ulong2string(pp->ID());
        default: return "";
    }
}

bool BTPeerStateMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTPeerStateMsg *pp = (BTPeerStateMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setLength_prefix(string2long(value)); return true;
        case 1: pp->setID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BTPeerStateMsgDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *BTPeerStateMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTPeerStateMsg *pp = (BTPeerStateMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTHaveMsg);

BTHaveMsg::BTHaveMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->length_prefix_var = 0;
    this->ID_var = 0;
    this->index_var = 0;
    this->level_var = 0;
}

BTHaveMsg::BTHaveMsg(const BTHaveMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTHaveMsg::~BTHaveMsg()
{
}

BTHaveMsg& BTHaveMsg::operator=(const BTHaveMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->length_prefix_var = other.length_prefix_var;
    this->ID_var = other.ID_var;
    this->index_var = other.index_var;
    this->level_var = other.level_var;
    return *this;
}

void BTHaveMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->length_prefix_var);
    doPacking(b,this->ID_var);
    doPacking(b,this->index_var);
    doPacking(b,this->level_var);
}

void BTHaveMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->length_prefix_var);
    doUnpacking(b,this->ID_var);
    doUnpacking(b,this->index_var);
    doUnpacking(b,this->level_var);
}

int BTHaveMsg::length_prefix() const
{
    return length_prefix_var;
}

void BTHaveMsg::setLength_prefix(int length_prefix_var)
{
    this->length_prefix_var = length_prefix_var;
}

unsigned short BTHaveMsg::ID() const
{
    return ID_var;
}

void BTHaveMsg::setID(unsigned short ID_var)
{
    this->ID_var = ID_var;
}

int BTHaveMsg::index() const
{
    return index_var;
}

void BTHaveMsg::setIndex(int index_var)
{
    this->index_var = index_var;
}

int BTHaveMsg::level() const
{
    return level_var;
}

void BTHaveMsg::setLevel(int level_var)
{
    this->level_var = level_var;
}

class BTHaveMsgDescriptor : public cClassDescriptor
{
  public:
    BTHaveMsgDescriptor();
    virtual ~BTHaveMsgDescriptor();

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

Register_ClassDescriptor(BTHaveMsgDescriptor);

BTHaveMsgDescriptor::BTHaveMsgDescriptor() : cClassDescriptor("BTHaveMsg", "GenericAppMsg")
{
}

BTHaveMsgDescriptor::~BTHaveMsgDescriptor()
{
}

bool BTHaveMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTHaveMsg *>(obj)!=NULL;
}

const char *BTHaveMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTHaveMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int BTHaveMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *BTHaveMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length_prefix",
        "ID",
        "index",
        "level",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int BTHaveMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length_prefix")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "level")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTHaveMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "unsigned short",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *BTHaveMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "PeerWireMsgIDs";
            return NULL;
        default: return NULL;
    }
}

int BTHaveMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTHaveMsg *pp = (BTHaveMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTHaveMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTHaveMsg *pp = (BTHaveMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->length_prefix());
        case 1: return ulong2string(pp->ID());
        case 2: return long2string(pp->index());
        case 3: return long2string(pp->level());
        default: return "";
    }
}

bool BTHaveMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTHaveMsg *pp = (BTHaveMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setLength_prefix(string2long(value)); return true;
        case 1: pp->setID(string2ulong(value)); return true;
        case 2: pp->setIndex(string2long(value)); return true;
        case 3: pp->setLevel(string2long(value)); return true;
        default: return false;
    }
}

const char *BTHaveMsgDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *BTHaveMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTHaveMsg *pp = (BTHaveMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTBitfieldMsg);

BTBitfieldMsg::BTBitfieldMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->length_prefix_var = 0;
    this->ID_var = 0;
    bitfield_arraysize = 0;
    this->bitfield_var = 0;
}

BTBitfieldMsg::BTBitfieldMsg(const BTBitfieldMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    bitfield_arraysize = 0;
    this->bitfield_var = 0;
    operator=(other);
}

BTBitfieldMsg::~BTBitfieldMsg()
{
    delete [] bitfield_var;
}

BTBitfieldMsg& BTBitfieldMsg::operator=(const BTBitfieldMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->length_prefix_var = other.length_prefix_var;
    this->ID_var = other.ID_var;
    delete [] this->bitfield_var;
    this->bitfield_var = (other.bitfield_arraysize==0) ? NULL : new bool[other.bitfield_arraysize];
    bitfield_arraysize = other.bitfield_arraysize;
    for (unsigned int i=0; i<bitfield_arraysize; i++)
        this->bitfield_var[i] = other.bitfield_var[i];
    return *this;
}

void BTBitfieldMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->length_prefix_var);
    doPacking(b,this->ID_var);
    b->pack(bitfield_arraysize);
    doPacking(b,this->bitfield_var,bitfield_arraysize);
}

void BTBitfieldMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->length_prefix_var);
    doUnpacking(b,this->ID_var);
    delete [] this->bitfield_var;
    b->unpack(bitfield_arraysize);
    if (bitfield_arraysize==0) {
        this->bitfield_var = 0;
    } else {
        this->bitfield_var = new bool[bitfield_arraysize];
        doUnpacking(b,this->bitfield_var,bitfield_arraysize);
    }
}

int BTBitfieldMsg::length_prefix() const
{
    return length_prefix_var;
}

void BTBitfieldMsg::setLength_prefix(int length_prefix_var)
{
    this->length_prefix_var = length_prefix_var;
}

unsigned short BTBitfieldMsg::ID() const
{
    return ID_var;
}

void BTBitfieldMsg::setID(unsigned short ID_var)
{
    this->ID_var = ID_var;
}

void BTBitfieldMsg::setBitfieldArraySize(unsigned int size)
{
    bool *bitfield_var2 = (size==0) ? NULL : new bool[size];
    unsigned int sz = bitfield_arraysize < size ? bitfield_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        bitfield_var2[i] = this->bitfield_var[i];
    for (unsigned int i=sz; i<size; i++)
        bitfield_var2[i] = 0;
    bitfield_arraysize = size;
    delete [] this->bitfield_var;
    this->bitfield_var = bitfield_var2;
}

unsigned int BTBitfieldMsg::bitfieldArraySize() const
{
    return bitfield_arraysize;
}

bool BTBitfieldMsg::bitfield(unsigned int k) const
{
    if (k>=bitfield_arraysize) throw cRuntimeError("Array of size %d indexed by %d", bitfield_arraysize, k);
    return bitfield_var[k];
}

void BTBitfieldMsg::setBitfield(unsigned int k, bool bitfield_var)
{
    if (k>=bitfield_arraysize) throw cRuntimeError("Array of size %d indexed by %d", bitfield_arraysize, k);
    this->bitfield_var[k]=bitfield_var;
}

class BTBitfieldMsgDescriptor : public cClassDescriptor
{
  public:
    BTBitfieldMsgDescriptor();
    virtual ~BTBitfieldMsgDescriptor();

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

Register_ClassDescriptor(BTBitfieldMsgDescriptor);

BTBitfieldMsgDescriptor::BTBitfieldMsgDescriptor() : cClassDescriptor("BTBitfieldMsg", "GenericAppMsg")
{
}

BTBitfieldMsgDescriptor::~BTBitfieldMsgDescriptor()
{
}

bool BTBitfieldMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTBitfieldMsg *>(obj)!=NULL;
}

const char *BTBitfieldMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTBitfieldMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int BTBitfieldMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *BTBitfieldMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length_prefix",
        "ID",
        "bitfield",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int BTBitfieldMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length_prefix")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitfield")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTBitfieldMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "unsigned short",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *BTBitfieldMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "PeerWireMsgIDs";
            return NULL;
        default: return NULL;
    }
}

int BTBitfieldMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTBitfieldMsg *pp = (BTBitfieldMsg *)object; (void)pp;
    switch (field) {
        case 2: return pp->bitfieldArraySize();
        default: return 0;
    }
}

std::string BTBitfieldMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTBitfieldMsg *pp = (BTBitfieldMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->length_prefix());
        case 1: return ulong2string(pp->ID());
        case 2: return bool2string(pp->bitfield(i));
        default: return "";
    }
}

bool BTBitfieldMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTBitfieldMsg *pp = (BTBitfieldMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setLength_prefix(string2long(value)); return true;
        case 1: pp->setID(string2ulong(value)); return true;
        case 2: pp->setBitfield(i,string2bool(value)); return true;
        default: return false;
    }
}

const char *BTBitfieldMsgDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *BTBitfieldMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTBitfieldMsg *pp = (BTBitfieldMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTRequestCancelMsg);

BTRequestCancelMsg::BTRequestCancelMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->length_prefix_var = 0;
    this->ID_var = 0;
    this->index_var = 0;
    this->begin_var = 0;
    this->dataLength_var = 0;
    this->endGame_var = 0;
}

BTRequestCancelMsg::BTRequestCancelMsg(const BTRequestCancelMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTRequestCancelMsg::~BTRequestCancelMsg()
{
}

BTRequestCancelMsg& BTRequestCancelMsg::operator=(const BTRequestCancelMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->length_prefix_var = other.length_prefix_var;
    this->ID_var = other.ID_var;
    this->index_var = other.index_var;
    this->begin_var = other.begin_var;
    this->dataLength_var = other.dataLength_var;
    this->endGame_var = other.endGame_var;
    return *this;
}

void BTRequestCancelMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->length_prefix_var);
    doPacking(b,this->ID_var);
    doPacking(b,this->index_var);
    doPacking(b,this->begin_var);
    doPacking(b,this->dataLength_var);
    doPacking(b,this->endGame_var);
}

void BTRequestCancelMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->length_prefix_var);
    doUnpacking(b,this->ID_var);
    doUnpacking(b,this->index_var);
    doUnpacking(b,this->begin_var);
    doUnpacking(b,this->dataLength_var);
    doUnpacking(b,this->endGame_var);
}

int BTRequestCancelMsg::length_prefix() const
{
    return length_prefix_var;
}

void BTRequestCancelMsg::setLength_prefix(int length_prefix_var)
{
    this->length_prefix_var = length_prefix_var;
}

unsigned short BTRequestCancelMsg::ID() const
{
    return ID_var;
}

void BTRequestCancelMsg::setID(unsigned short ID_var)
{
    this->ID_var = ID_var;
}

int BTRequestCancelMsg::index() const
{
    return index_var;
}

void BTRequestCancelMsg::setIndex(int index_var)
{
    this->index_var = index_var;
}

int BTRequestCancelMsg::begin() const
{
    return begin_var;
}

void BTRequestCancelMsg::setBegin(int begin_var)
{
    this->begin_var = begin_var;
}

int BTRequestCancelMsg::dataLength() const
{
    return dataLength_var;
}

void BTRequestCancelMsg::setDataLength(int dataLength_var)
{
    this->dataLength_var = dataLength_var;
}

bool BTRequestCancelMsg::endGame() const
{
    return endGame_var;
}

void BTRequestCancelMsg::setEndGame(bool endGame_var)
{
    this->endGame_var = endGame_var;
}

class BTRequestCancelMsgDescriptor : public cClassDescriptor
{
  public:
    BTRequestCancelMsgDescriptor();
    virtual ~BTRequestCancelMsgDescriptor();

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

Register_ClassDescriptor(BTRequestCancelMsgDescriptor);

BTRequestCancelMsgDescriptor::BTRequestCancelMsgDescriptor() : cClassDescriptor("BTRequestCancelMsg", "GenericAppMsg")
{
}

BTRequestCancelMsgDescriptor::~BTRequestCancelMsgDescriptor()
{
}

bool BTRequestCancelMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTRequestCancelMsg *>(obj)!=NULL;
}

const char *BTRequestCancelMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTRequestCancelMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int BTRequestCancelMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTRequestCancelMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length_prefix",
        "ID",
        "index",
        "begin",
        "dataLength",
        "endGame",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int BTRequestCancelMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length_prefix")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "begin")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataLength")==0) return base+4;
    if (fieldName[0]=='e' && strcmp(fieldName, "endGame")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTRequestCancelMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "unsigned short",
        "int",
        "int",
        "int",
        "bool",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *BTRequestCancelMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "PeerWireMsgIDs";
            return NULL;
        default: return NULL;
    }
}

int BTRequestCancelMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTRequestCancelMsg *pp = (BTRequestCancelMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTRequestCancelMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTRequestCancelMsg *pp = (BTRequestCancelMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->length_prefix());
        case 1: return ulong2string(pp->ID());
        case 2: return long2string(pp->index());
        case 3: return long2string(pp->begin());
        case 4: return long2string(pp->dataLength());
        case 5: return bool2string(pp->endGame());
        default: return "";
    }
}

bool BTRequestCancelMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTRequestCancelMsg *pp = (BTRequestCancelMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setLength_prefix(string2long(value)); return true;
        case 1: pp->setID(string2ulong(value)); return true;
        case 2: pp->setIndex(string2long(value)); return true;
        case 3: pp->setBegin(string2long(value)); return true;
        case 4: pp->setDataLength(string2long(value)); return true;
        case 5: pp->setEndGame(string2bool(value)); return true;
        default: return false;
    }
}

const char *BTRequestCancelMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *BTRequestCancelMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTRequestCancelMsg *pp = (BTRequestCancelMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTPieceMsg);

BTPieceMsg::BTPieceMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->length_prefix_var = 0;
    this->ID_var = 0;
    this->index_var = 0;
    this->begin_var = 0;
    this->level_var = 0;
    this->data_var = 0;
}

BTPieceMsg::BTPieceMsg(const BTPieceMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTPieceMsg::~BTPieceMsg()
{
}

BTPieceMsg& BTPieceMsg::operator=(const BTPieceMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->length_prefix_var = other.length_prefix_var;
    this->ID_var = other.ID_var;
    this->index_var = other.index_var;
    this->begin_var = other.begin_var;
    this->level_var = other.level_var;
    this->data_var = other.data_var;
    return *this;
}

void BTPieceMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->length_prefix_var);
    doPacking(b,this->ID_var);
    doPacking(b,this->index_var);
    doPacking(b,this->begin_var);
    doPacking(b,this->level_var);
    doPacking(b,this->data_var);
}

void BTPieceMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->length_prefix_var);
    doUnpacking(b,this->ID_var);
    doUnpacking(b,this->index_var);
    doUnpacking(b,this->begin_var);
    doUnpacking(b,this->level_var);
    doUnpacking(b,this->data_var);
}

int BTPieceMsg::length_prefix() const
{
    return length_prefix_var;
}

void BTPieceMsg::setLength_prefix(int length_prefix_var)
{
    this->length_prefix_var = length_prefix_var;
}

unsigned short BTPieceMsg::ID() const
{
    return ID_var;
}

void BTPieceMsg::setID(unsigned short ID_var)
{
    this->ID_var = ID_var;
}

int BTPieceMsg::index() const
{
    return index_var;
}

void BTPieceMsg::setIndex(int index_var)
{
    this->index_var = index_var;
}

int BTPieceMsg::begin() const
{
    return begin_var;
}

void BTPieceMsg::setBegin(int begin_var)
{
    this->begin_var = begin_var;
}

int BTPieceMsg::level() const
{
    return level_var;
}

void BTPieceMsg::setLevel(int level_var)
{
    this->level_var = level_var;
}

const char * BTPieceMsg::data() const
{
    return data_var.c_str();
}

void BTPieceMsg::setData(const char * data_var)
{
    this->data_var = data_var;
}

class BTPieceMsgDescriptor : public cClassDescriptor
{
  public:
    BTPieceMsgDescriptor();
    virtual ~BTPieceMsgDescriptor();

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

Register_ClassDescriptor(BTPieceMsgDescriptor);

BTPieceMsgDescriptor::BTPieceMsgDescriptor() : cClassDescriptor("BTPieceMsg", "GenericAppMsg")
{
}

BTPieceMsgDescriptor::~BTPieceMsgDescriptor()
{
}

bool BTPieceMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTPieceMsg *>(obj)!=NULL;
}

const char *BTPieceMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTPieceMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int BTPieceMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTPieceMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "length_prefix",
        "ID",
        "index",
        "begin",
        "level",
        "data",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int BTPieceMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length_prefix")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "ID")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "index")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "begin")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "level")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTPieceMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "unsigned short",
        "int",
        "int",
        "int",
        "string",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *BTPieceMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "PeerWireMsgIDs";
            return NULL;
        default: return NULL;
    }
}

int BTPieceMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTPieceMsg *pp = (BTPieceMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTPieceMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTPieceMsg *pp = (BTPieceMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->length_prefix());
        case 1: return ulong2string(pp->ID());
        case 2: return long2string(pp->index());
        case 3: return long2string(pp->begin());
        case 4: return long2string(pp->level());
        case 5: return oppstring2string(pp->data());
        default: return "";
    }
}

bool BTPieceMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTPieceMsg *pp = (BTPieceMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setLength_prefix(string2long(value)); return true;
        case 1: pp->setID(string2ulong(value)); return true;
        case 2: pp->setIndex(string2long(value)); return true;
        case 3: pp->setBegin(string2long(value)); return true;
        case 4: pp->setLevel(string2long(value)); return true;
        case 5: pp->setData((value)); return true;
        default: return false;
    }
}

const char *BTPieceMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *BTPieceMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTPieceMsg *pp = (BTPieceMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTInternalMsg);

BTInternalMsg::BTInternalMsg(const char *name, int kind) : cMessage(name,kind)
{
    this->text_var = 0;
    this->pieceIndex_var = 0;
    this->blockIndex_var = 0;
    this->chokedPiece_var = 0;
}

BTInternalMsg::BTInternalMsg(const BTInternalMsg& other) : cMessage()
{
    setName(other.getName());
    operator=(other);
}

BTInternalMsg::~BTInternalMsg()
{
}

BTInternalMsg& BTInternalMsg::operator=(const BTInternalMsg& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    this->text_var = other.text_var;
    this->peer_var = other.peer_var;
    this->pieceIndex_var = other.pieceIndex_var;
    this->blockIndex_var = other.blockIndex_var;
    this->chokedPiece_var = other.chokedPiece_var;
    return *this;
}

void BTInternalMsg::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->text_var);
    doPacking(b,this->peer_var);
    doPacking(b,this->pieceIndex_var);
    doPacking(b,this->blockIndex_var);
    doPacking(b,this->chokedPiece_var);
}

void BTInternalMsg::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->text_var);
    doUnpacking(b,this->peer_var);
    doUnpacking(b,this->pieceIndex_var);
    doUnpacking(b,this->blockIndex_var);
    doUnpacking(b,this->chokedPiece_var);
}

const char * BTInternalMsg::text() const
{
    return text_var.c_str();
}

void BTInternalMsg::setText(const char * text_var)
{
    this->text_var = text_var;
}

PEER& BTInternalMsg::peer()
{
    return peer_var;
}

void BTInternalMsg::setPeer(const PEER& peer_var)
{
    this->peer_var = peer_var;
}

int BTInternalMsg::pieceIndex() const
{
    return pieceIndex_var;
}

void BTInternalMsg::setPieceIndex(int pieceIndex_var)
{
    this->pieceIndex_var = pieceIndex_var;
}

int BTInternalMsg::blockIndex() const
{
    return blockIndex_var;
}

void BTInternalMsg::setBlockIndex(int blockIndex_var)
{
    this->blockIndex_var = blockIndex_var;
}

bool BTInternalMsg::chokedPiece() const
{
    return chokedPiece_var;
}

void BTInternalMsg::setChokedPiece(bool chokedPiece_var)
{
    this->chokedPiece_var = chokedPiece_var;
}

class BTInternalMsgDescriptor : public cClassDescriptor
{
  public:
    BTInternalMsgDescriptor();
    virtual ~BTInternalMsgDescriptor();

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

Register_ClassDescriptor(BTInternalMsgDescriptor);

BTInternalMsgDescriptor::BTInternalMsgDescriptor() : cClassDescriptor("BTInternalMsg", "cMessage")
{
}

BTInternalMsgDescriptor::~BTInternalMsgDescriptor()
{
}

bool BTInternalMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTInternalMsg *>(obj)!=NULL;
}

const char *BTInternalMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTInternalMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int BTInternalMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *BTInternalMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "text",
        "peer",
        "pieceIndex",
        "blockIndex",
        "chokedPiece",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int BTInternalMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "text")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "peer")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "pieceIndex")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockIndex")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "chokedPiece")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTInternalMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "PEER",
        "int",
        "int",
        "bool",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *BTInternalMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTInternalMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTInternalMsg *pp = (BTInternalMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTInternalMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTInternalMsg *pp = (BTInternalMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->text());
        case 1: {std::stringstream out; out << pp->peer(); return out.str();}
        case 2: return long2string(pp->pieceIndex());
        case 3: return long2string(pp->blockIndex());
        case 4: return bool2string(pp->chokedPiece());
        default: return "";
    }
}

bool BTInternalMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTInternalMsg *pp = (BTInternalMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setText((value)); return true;
        case 2: pp->setPieceIndex(string2long(value)); return true;
        case 3: pp->setBlockIndex(string2long(value)); return true;
        case 4: pp->setChokedPiece(string2bool(value)); return true;
        default: return false;
    }
}

const char *BTInternalMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "PEER",
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *BTInternalMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTInternalMsg *pp = (BTInternalMsg *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->peer()); break;
        default: return NULL;
    }
}

Register_Class(BTAcceptConnectionMsg);

BTAcceptConnectionMsg::BTAcceptConnectionMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->accept_var = true;
}

BTAcceptConnectionMsg::BTAcceptConnectionMsg(const BTAcceptConnectionMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTAcceptConnectionMsg::~BTAcceptConnectionMsg()
{
}

BTAcceptConnectionMsg& BTAcceptConnectionMsg::operator=(const BTAcceptConnectionMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->accept_var = other.accept_var;
    return *this;
}

void BTAcceptConnectionMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->accept_var);
}

void BTAcceptConnectionMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->accept_var);
}

bool BTAcceptConnectionMsg::accept() const
{
    return accept_var;
}

void BTAcceptConnectionMsg::setAccept(bool accept_var)
{
    this->accept_var = accept_var;
}

class BTAcceptConnectionMsgDescriptor : public cClassDescriptor
{
  public:
    BTAcceptConnectionMsgDescriptor();
    virtual ~BTAcceptConnectionMsgDescriptor();

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

Register_ClassDescriptor(BTAcceptConnectionMsgDescriptor);

BTAcceptConnectionMsgDescriptor::BTAcceptConnectionMsgDescriptor() : cClassDescriptor("BTAcceptConnectionMsg", "GenericAppMsg")
{
}

BTAcceptConnectionMsgDescriptor::~BTAcceptConnectionMsgDescriptor()
{
}

bool BTAcceptConnectionMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTAcceptConnectionMsg *>(obj)!=NULL;
}

const char *BTAcceptConnectionMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTAcceptConnectionMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BTAcceptConnectionMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *BTAcceptConnectionMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "accept",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BTAcceptConnectionMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "accept")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTAcceptConnectionMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *BTAcceptConnectionMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTAcceptConnectionMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTAcceptConnectionMsg *pp = (BTAcceptConnectionMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTAcceptConnectionMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTAcceptConnectionMsg *pp = (BTAcceptConnectionMsg *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->accept());
        default: return "";
    }
}

bool BTAcceptConnectionMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTAcceptConnectionMsg *pp = (BTAcceptConnectionMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setAccept(string2bool(value)); return true;
        default: return false;
    }
}

const char *BTAcceptConnectionMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *BTAcceptConnectionMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTAcceptConnectionMsg *pp = (BTAcceptConnectionMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


