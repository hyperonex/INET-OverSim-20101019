//
// Generated file, do not edit! Created by opp_msgc 4.1 from applications/xBitTorrent/BTTrackerMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BTTrackerMsg_m.h"

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
    cEnum *e = cEnum::find("ANNOUNCE_TYPE");
    if (!e) enums.getInstance()->add(e = new cEnum("ANNOUNCE_TYPE"));
    e->insert(A_STARTED, "A_STARTED");
    e->insert(A_STOPPED, "A_STOPPED");
    e->insert(A_COMPLETED, "A_COMPLETED");
    e->insert(A_NORMAL, "A_NORMAL");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("REPLY_TYPE");
    if (!e) enums.getInstance()->add(e = new cEnum("REPLY_TYPE"));
    e->insert(R_FAIL, "R_FAIL");
    e->insert(R_VALID, "R_VALID");
    e->insert(R_WARN, "R_WARN");
);

PEER::PEER()
{
    peerId = 0;
    peerPort = 0;
}

void doPacking(cCommBuffer *b, PEER& a)
{
    doPacking(b,a.peerId);
    doPacking(b,a.peerPort);
    doPacking(b,a.ipAddress);
}

void doUnpacking(cCommBuffer *b, PEER& a)
{
    doUnpacking(b,a.peerId);
    doUnpacking(b,a.peerPort);
    doUnpacking(b,a.ipAddress);
}

class PEERDescriptor : public cClassDescriptor
{
  public:
    PEERDescriptor();
    virtual ~PEERDescriptor();

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

Register_ClassDescriptor(PEERDescriptor);

PEERDescriptor::PEERDescriptor() : cClassDescriptor("PEER", "")
{
}

PEERDescriptor::~PEERDescriptor()
{
}

bool PEERDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PEER *>(obj)!=NULL;
}

const char *PEERDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PEERDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PEERDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PEERDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "peerId",
        "peerPort",
        "ipAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PEERDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerId")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerPort")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "ipAddress")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PEERDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "unsigned int",
        "IPvXAddress",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PEERDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PEERDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PEER *pp = (PEER *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PEERDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PEER *pp = (PEER *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->peerId);
        case 1: return ulong2string(pp->peerPort);
        case 2: {std::stringstream out; out << pp->ipAddress; return out.str();}
        default: return "";
    }
}

bool PEERDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PEER *pp = (PEER *)object; (void)pp;
    switch (field) {
        case 0: pp->peerId = (value); return true;
        case 1: pp->peerPort = string2ulong(value); return true;
        default: return false;
    }
}

const char *PEERDescriptor::getFieldStructName(void *object, int field) const
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
        "IPvXAddress",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *PEERDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PEER *pp = (PEER *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->ipAddress); break;
        default: return NULL;
    }
}

Register_Class(BTTrackerMsgAnnounce);

BTTrackerMsgAnnounce::BTTrackerMsgAnnounce(const char *name, int kind) : cPacket(name,kind)
{
    this->infoHash_var = 0;
    this->peerId_var = 0;
    this->peerPort_var = 0;
    this->event_var = 0;
    this->compact_var = 0;
    this->noPeerId_var = 0;
    this->numWant_var = 0;
    this->key_var = 0;
    this->trackerId_var = 0;
}

BTTrackerMsgAnnounce::BTTrackerMsgAnnounce(const BTTrackerMsgAnnounce& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

BTTrackerMsgAnnounce::~BTTrackerMsgAnnounce()
{
}

BTTrackerMsgAnnounce& BTTrackerMsgAnnounce::operator=(const BTTrackerMsgAnnounce& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->infoHash_var = other.infoHash_var;
    this->peerId_var = other.peerId_var;
    this->peerPort_var = other.peerPort_var;
    this->event_var = other.event_var;
    this->compact_var = other.compact_var;
    this->noPeerId_var = other.noPeerId_var;
    this->numWant_var = other.numWant_var;
    this->key_var = other.key_var;
    this->trackerId_var = other.trackerId_var;
    return *this;
}

void BTTrackerMsgAnnounce::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->infoHash_var);
    doPacking(b,this->peerId_var);
    doPacking(b,this->peerPort_var);
    doPacking(b,this->event_var);
    doPacking(b,this->compact_var);
    doPacking(b,this->noPeerId_var);
    doPacking(b,this->numWant_var);
    doPacking(b,this->key_var);
    doPacking(b,this->trackerId_var);
}

void BTTrackerMsgAnnounce::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->infoHash_var);
    doUnpacking(b,this->peerId_var);
    doUnpacking(b,this->peerPort_var);
    doUnpacking(b,this->event_var);
    doUnpacking(b,this->compact_var);
    doUnpacking(b,this->noPeerId_var);
    doUnpacking(b,this->numWant_var);
    doUnpacking(b,this->key_var);
    doUnpacking(b,this->trackerId_var);
}

const char * BTTrackerMsgAnnounce::infoHash() const
{
    return infoHash_var.c_str();
}

void BTTrackerMsgAnnounce::setInfoHash(const char * infoHash_var)
{
    this->infoHash_var = infoHash_var;
}

const char * BTTrackerMsgAnnounce::peerId() const
{
    return peerId_var.c_str();
}

void BTTrackerMsgAnnounce::setPeerId(const char * peerId_var)
{
    this->peerId_var = peerId_var;
}

unsigned int BTTrackerMsgAnnounce::peerPort() const
{
    return peerPort_var;
}

void BTTrackerMsgAnnounce::setPeerPort(unsigned int peerPort_var)
{
    this->peerPort_var = peerPort_var;
}

unsigned int BTTrackerMsgAnnounce::event() const
{
    return event_var;
}

void BTTrackerMsgAnnounce::setEvent(unsigned int event_var)
{
    this->event_var = event_var;
}

bool BTTrackerMsgAnnounce::compact() const
{
    return compact_var;
}

void BTTrackerMsgAnnounce::setCompact(bool compact_var)
{
    this->compact_var = compact_var;
}

bool BTTrackerMsgAnnounce::noPeerId() const
{
    return noPeerId_var;
}

void BTTrackerMsgAnnounce::setNoPeerId(bool noPeerId_var)
{
    this->noPeerId_var = noPeerId_var;
}

unsigned int BTTrackerMsgAnnounce::numWant() const
{
    return numWant_var;
}

void BTTrackerMsgAnnounce::setNumWant(unsigned int numWant_var)
{
    this->numWant_var = numWant_var;
}

const char * BTTrackerMsgAnnounce::key() const
{
    return key_var.c_str();
}

void BTTrackerMsgAnnounce::setKey(const char * key_var)
{
    this->key_var = key_var;
}

const char * BTTrackerMsgAnnounce::trackerId() const
{
    return trackerId_var.c_str();
}

void BTTrackerMsgAnnounce::setTrackerId(const char * trackerId_var)
{
    this->trackerId_var = trackerId_var;
}

class BTTrackerMsgAnnounceDescriptor : public cClassDescriptor
{
  public:
    BTTrackerMsgAnnounceDescriptor();
    virtual ~BTTrackerMsgAnnounceDescriptor();

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

Register_ClassDescriptor(BTTrackerMsgAnnounceDescriptor);

BTTrackerMsgAnnounceDescriptor::BTTrackerMsgAnnounceDescriptor() : cClassDescriptor("BTTrackerMsgAnnounce", "cPacket")
{
}

BTTrackerMsgAnnounceDescriptor::~BTTrackerMsgAnnounceDescriptor()
{
}

bool BTTrackerMsgAnnounceDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTTrackerMsgAnnounce *>(obj)!=NULL;
}

const char *BTTrackerMsgAnnounceDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTTrackerMsgAnnounceDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int BTTrackerMsgAnnounceDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTTrackerMsgAnnounceDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "infoHash",
        "peerId",
        "peerPort",
        "event",
        "compact",
        "noPeerId",
        "numWant",
        "key",
        "trackerId",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int BTTrackerMsgAnnounceDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "infoHash")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerId")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerPort")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "event")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "compact")==0) return base+4;
    if (fieldName[0]=='n' && strcmp(fieldName, "noPeerId")==0) return base+5;
    if (fieldName[0]=='n' && strcmp(fieldName, "numWant")==0) return base+6;
    if (fieldName[0]=='k' && strcmp(fieldName, "key")==0) return base+7;
    if (fieldName[0]=='t' && strcmp(fieldName, "trackerId")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTTrackerMsgAnnounceDescriptor::getFieldTypeString(void *object, int field) const
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
        "unsigned int",
        "unsigned int",
        "bool",
        "bool",
        "unsigned int",
        "string",
        "string",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *BTTrackerMsgAnnounceDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3:
            if (!strcmp(propertyname,"enum")) return "ANNOUNCE_TYPE";
            return NULL;
        default: return NULL;
    }
}

int BTTrackerMsgAnnounceDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgAnnounce *pp = (BTTrackerMsgAnnounce *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTTrackerMsgAnnounceDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgAnnounce *pp = (BTTrackerMsgAnnounce *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->infoHash());
        case 1: return oppstring2string(pp->peerId());
        case 2: return ulong2string(pp->peerPort());
        case 3: return ulong2string(pp->event());
        case 4: return bool2string(pp->compact());
        case 5: return bool2string(pp->noPeerId());
        case 6: return ulong2string(pp->numWant());
        case 7: return oppstring2string(pp->key());
        case 8: return oppstring2string(pp->trackerId());
        default: return "";
    }
}

bool BTTrackerMsgAnnounceDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgAnnounce *pp = (BTTrackerMsgAnnounce *)object; (void)pp;
    switch (field) {
        case 0: pp->setInfoHash((value)); return true;
        case 1: pp->setPeerId((value)); return true;
        case 2: pp->setPeerPort(string2ulong(value)); return true;
        case 3: pp->setEvent(string2ulong(value)); return true;
        case 4: pp->setCompact(string2bool(value)); return true;
        case 5: pp->setNoPeerId(string2bool(value)); return true;
        case 6: pp->setNumWant(string2ulong(value)); return true;
        case 7: pp->setKey((value)); return true;
        case 8: pp->setTrackerId((value)); return true;
        default: return false;
    }
}

const char *BTTrackerMsgAnnounceDescriptor::getFieldStructName(void *object, int field) const
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

void *BTTrackerMsgAnnounceDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgAnnounce *pp = (BTTrackerMsgAnnounce *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTTrackerMsgResponse);

BTTrackerMsgResponse::BTTrackerMsgResponse(const char *name, int kind) : cPacket(name,kind)
{
    this->failure_var = 0;
    this->warning_var = 0;
    this->announceInterval_var = 0;
    this->trackerId_var = 0;
    this->complete_var = 0;
    this->incomplete_var = 0;
    peers_arraysize = 0;
    this->peers_var = 0;
}

BTTrackerMsgResponse::BTTrackerMsgResponse(const BTTrackerMsgResponse& other) : cPacket()
{
    setName(other.getName());
    peers_arraysize = 0;
    this->peers_var = 0;
    operator=(other);
}

BTTrackerMsgResponse::~BTTrackerMsgResponse()
{
    delete [] peers_var;
}

BTTrackerMsgResponse& BTTrackerMsgResponse::operator=(const BTTrackerMsgResponse& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->failure_var = other.failure_var;
    this->warning_var = other.warning_var;
    this->announceInterval_var = other.announceInterval_var;
    this->trackerId_var = other.trackerId_var;
    this->complete_var = other.complete_var;
    this->incomplete_var = other.incomplete_var;
    delete [] this->peers_var;
    this->peers_var = (other.peers_arraysize==0) ? NULL : new ::PEER[other.peers_arraysize];
    peers_arraysize = other.peers_arraysize;
    for (unsigned int i=0; i<peers_arraysize; i++)
        this->peers_var[i] = other.peers_var[i];
    return *this;
}

void BTTrackerMsgResponse::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->failure_var);
    doPacking(b,this->warning_var);
    doPacking(b,this->announceInterval_var);
    doPacking(b,this->trackerId_var);
    doPacking(b,this->complete_var);
    doPacking(b,this->incomplete_var);
    b->pack(peers_arraysize);
    doPacking(b,this->peers_var,peers_arraysize);
}

void BTTrackerMsgResponse::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->failure_var);
    doUnpacking(b,this->warning_var);
    doUnpacking(b,this->announceInterval_var);
    doUnpacking(b,this->trackerId_var);
    doUnpacking(b,this->complete_var);
    doUnpacking(b,this->incomplete_var);
    delete [] this->peers_var;
    b->unpack(peers_arraysize);
    if (peers_arraysize==0) {
        this->peers_var = 0;
    } else {
        this->peers_var = new ::PEER[peers_arraysize];
        doUnpacking(b,this->peers_var,peers_arraysize);
    }
}

const char * BTTrackerMsgResponse::failure() const
{
    return failure_var.c_str();
}

void BTTrackerMsgResponse::setFailure(const char * failure_var)
{
    this->failure_var = failure_var;
}

const char * BTTrackerMsgResponse::warning() const
{
    return warning_var.c_str();
}

void BTTrackerMsgResponse::setWarning(const char * warning_var)
{
    this->warning_var = warning_var;
}

unsigned int BTTrackerMsgResponse::announceInterval() const
{
    return announceInterval_var;
}

void BTTrackerMsgResponse::setAnnounceInterval(unsigned int announceInterval_var)
{
    this->announceInterval_var = announceInterval_var;
}

const char * BTTrackerMsgResponse::trackerId() const
{
    return trackerId_var.c_str();
}

void BTTrackerMsgResponse::setTrackerId(const char * trackerId_var)
{
    this->trackerId_var = trackerId_var;
}

unsigned int BTTrackerMsgResponse::complete() const
{
    return complete_var;
}

void BTTrackerMsgResponse::setComplete(unsigned int complete_var)
{
    this->complete_var = complete_var;
}

unsigned int BTTrackerMsgResponse::incomplete() const
{
    return incomplete_var;
}

void BTTrackerMsgResponse::setIncomplete(unsigned int incomplete_var)
{
    this->incomplete_var = incomplete_var;
}

void BTTrackerMsgResponse::setPeersArraySize(unsigned int size)
{
    ::PEER *peers_var2 = (size==0) ? NULL : new ::PEER[size];
    unsigned int sz = peers_arraysize < size ? peers_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        peers_var2[i] = this->peers_var[i];
    peers_arraysize = size;
    delete [] this->peers_var;
    this->peers_var = peers_var2;
}

unsigned int BTTrackerMsgResponse::peersArraySize() const
{
    return peers_arraysize;
}

PEER& BTTrackerMsgResponse::peers(unsigned int k)
{
    if (k>=peers_arraysize) throw cRuntimeError("Array of size %d indexed by %d", peers_arraysize, k);
    return peers_var[k];
}

void BTTrackerMsgResponse::setPeers(unsigned int k, const PEER& peers_var)
{
    if (k>=peers_arraysize) throw cRuntimeError("Array of size %d indexed by %d", peers_arraysize, k);
    this->peers_var[k]=peers_var;
}

class BTTrackerMsgResponseDescriptor : public cClassDescriptor
{
  public:
    BTTrackerMsgResponseDescriptor();
    virtual ~BTTrackerMsgResponseDescriptor();

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

Register_ClassDescriptor(BTTrackerMsgResponseDescriptor);

BTTrackerMsgResponseDescriptor::BTTrackerMsgResponseDescriptor() : cClassDescriptor("BTTrackerMsgResponse", "cPacket")
{
}

BTTrackerMsgResponseDescriptor::~BTTrackerMsgResponseDescriptor()
{
}

bool BTTrackerMsgResponseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTTrackerMsgResponse *>(obj)!=NULL;
}

const char *BTTrackerMsgResponseDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTTrackerMsgResponseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int BTTrackerMsgResponseDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *BTTrackerMsgResponseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "failure",
        "warning",
        "announceInterval",
        "trackerId",
        "complete",
        "incomplete",
        "peers",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int BTTrackerMsgResponseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "failure")==0) return base+0;
    if (fieldName[0]=='w' && strcmp(fieldName, "warning")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "announceInterval")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "trackerId")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "complete")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "incomplete")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "peers")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTTrackerMsgResponseDescriptor::getFieldTypeString(void *object, int field) const
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
        "unsigned int",
        "string",
        "unsigned int",
        "unsigned int",
        "PEER",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *BTTrackerMsgResponseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTTrackerMsgResponseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgResponse *pp = (BTTrackerMsgResponse *)object; (void)pp;
    switch (field) {
        case 6: return pp->peersArraySize();
        default: return 0;
    }
}

std::string BTTrackerMsgResponseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgResponse *pp = (BTTrackerMsgResponse *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->failure());
        case 1: return oppstring2string(pp->warning());
        case 2: return ulong2string(pp->announceInterval());
        case 3: return oppstring2string(pp->trackerId());
        case 4: return ulong2string(pp->complete());
        case 5: return ulong2string(pp->incomplete());
        case 6: {std::stringstream out; out << pp->peers(i); return out.str();}
        default: return "";
    }
}

bool BTTrackerMsgResponseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgResponse *pp = (BTTrackerMsgResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setFailure((value)); return true;
        case 1: pp->setWarning((value)); return true;
        case 2: pp->setAnnounceInterval(string2ulong(value)); return true;
        case 3: pp->setTrackerId((value)); return true;
        case 4: pp->setComplete(string2ulong(value)); return true;
        case 5: pp->setIncomplete(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BTTrackerMsgResponseDescriptor::getFieldStructName(void *object, int field) const
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
        "PEER",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *BTTrackerMsgResponseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTTrackerMsgResponse *pp = (BTTrackerMsgResponse *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->peers(i)); break;
        default: return NULL;
    }
}


