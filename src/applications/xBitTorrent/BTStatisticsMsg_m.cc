//
// Generated file, do not edit! Created by opp_msgc 4.1 from applications/xBitTorrent/BTStatisticsMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BTStatisticsMsg_m.h"

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




Register_Class(BTStatisticsDWLMsg);

BTStatisticsDWLMsg::BTStatisticsDWLMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->downloadTime_var = 0;
    this->remainingBlocks_var = 0;
}

BTStatisticsDWLMsg::BTStatisticsDWLMsg(const BTStatisticsDWLMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTStatisticsDWLMsg::~BTStatisticsDWLMsg()
{
}

BTStatisticsDWLMsg& BTStatisticsDWLMsg::operator=(const BTStatisticsDWLMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->downloadTime_var = other.downloadTime_var;
    this->remainingBlocks_var = other.remainingBlocks_var;
    return *this;
}

void BTStatisticsDWLMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->downloadTime_var);
    doPacking(b,this->remainingBlocks_var);
}

void BTStatisticsDWLMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->downloadTime_var);
    doUnpacking(b,this->remainingBlocks_var);
}

double BTStatisticsDWLMsg::downloadTime() const
{
    return downloadTime_var;
}

void BTStatisticsDWLMsg::setDownloadTime(double downloadTime_var)
{
    this->downloadTime_var = downloadTime_var;
}

double BTStatisticsDWLMsg::remainingBlocks() const
{
    return remainingBlocks_var;
}

void BTStatisticsDWLMsg::setRemainingBlocks(double remainingBlocks_var)
{
    this->remainingBlocks_var = remainingBlocks_var;
}

class BTStatisticsDWLMsgDescriptor : public cClassDescriptor
{
  public:
    BTStatisticsDWLMsgDescriptor();
    virtual ~BTStatisticsDWLMsgDescriptor();

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

Register_ClassDescriptor(BTStatisticsDWLMsgDescriptor);

BTStatisticsDWLMsgDescriptor::BTStatisticsDWLMsgDescriptor() : cClassDescriptor("BTStatisticsDWLMsg", "GenericAppMsg")
{
}

BTStatisticsDWLMsgDescriptor::~BTStatisticsDWLMsgDescriptor()
{
}

bool BTStatisticsDWLMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTStatisticsDWLMsg *>(obj)!=NULL;
}

const char *BTStatisticsDWLMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTStatisticsDWLMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int BTStatisticsDWLMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTStatisticsDWLMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "downloadTime",
        "remainingBlocks",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int BTStatisticsDWLMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "downloadTime")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remainingBlocks")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTStatisticsDWLMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *BTStatisticsDWLMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTStatisticsDWLMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsDWLMsg *pp = (BTStatisticsDWLMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTStatisticsDWLMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsDWLMsg *pp = (BTStatisticsDWLMsg *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->downloadTime());
        case 1: return double2string(pp->remainingBlocks());
        default: return "";
    }
}

bool BTStatisticsDWLMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsDWLMsg *pp = (BTStatisticsDWLMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setDownloadTime(string2double(value)); return true;
        case 1: pp->setRemainingBlocks(string2double(value)); return true;
        default: return false;
    }
}

const char *BTStatisticsDWLMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *BTStatisticsDWLMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsDWLMsg *pp = (BTStatisticsDWLMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTStatisticsNumProvidersMsg);

BTStatisticsNumProvidersMsg::BTStatisticsNumProvidersMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->numPeers_var = 0;
}

BTStatisticsNumProvidersMsg::BTStatisticsNumProvidersMsg(const BTStatisticsNumProvidersMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTStatisticsNumProvidersMsg::~BTStatisticsNumProvidersMsg()
{
}

BTStatisticsNumProvidersMsg& BTStatisticsNumProvidersMsg::operator=(const BTStatisticsNumProvidersMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->numPeers_var = other.numPeers_var;
    return *this;
}

void BTStatisticsNumProvidersMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->numPeers_var);
}

void BTStatisticsNumProvidersMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->numPeers_var);
}

int BTStatisticsNumProvidersMsg::numPeers() const
{
    return numPeers_var;
}

void BTStatisticsNumProvidersMsg::setNumPeers(int numPeers_var)
{
    this->numPeers_var = numPeers_var;
}

class BTStatisticsNumProvidersMsgDescriptor : public cClassDescriptor
{
  public:
    BTStatisticsNumProvidersMsgDescriptor();
    virtual ~BTStatisticsNumProvidersMsgDescriptor();

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

Register_ClassDescriptor(BTStatisticsNumProvidersMsgDescriptor);

BTStatisticsNumProvidersMsgDescriptor::BTStatisticsNumProvidersMsgDescriptor() : cClassDescriptor("BTStatisticsNumProvidersMsg", "GenericAppMsg")
{
}

BTStatisticsNumProvidersMsgDescriptor::~BTStatisticsNumProvidersMsgDescriptor()
{
}

bool BTStatisticsNumProvidersMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTStatisticsNumProvidersMsg *>(obj)!=NULL;
}

const char *BTStatisticsNumProvidersMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTStatisticsNumProvidersMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BTStatisticsNumProvidersMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTStatisticsNumProvidersMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numPeers",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BTStatisticsNumProvidersMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numPeers")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTStatisticsNumProvidersMsgDescriptor::getFieldTypeString(void *object, int field) const
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

const char *BTStatisticsNumProvidersMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTStatisticsNumProvidersMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumProvidersMsg *pp = (BTStatisticsNumProvidersMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTStatisticsNumProvidersMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumProvidersMsg *pp = (BTStatisticsNumProvidersMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->numPeers());
        default: return "";
    }
}

bool BTStatisticsNumProvidersMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumProvidersMsg *pp = (BTStatisticsNumProvidersMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumPeers(string2long(value)); return true;
        default: return false;
    }
}

const char *BTStatisticsNumProvidersMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *BTStatisticsNumProvidersMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumProvidersMsg *pp = (BTStatisticsNumProvidersMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTStatisticsNumSeederBlocksMsg);

BTStatisticsNumSeederBlocksMsg::BTStatisticsNumSeederBlocksMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->numSeederBlocks_var = 0;
}

BTStatisticsNumSeederBlocksMsg::BTStatisticsNumSeederBlocksMsg(const BTStatisticsNumSeederBlocksMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTStatisticsNumSeederBlocksMsg::~BTStatisticsNumSeederBlocksMsg()
{
}

BTStatisticsNumSeederBlocksMsg& BTStatisticsNumSeederBlocksMsg::operator=(const BTStatisticsNumSeederBlocksMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->numSeederBlocks_var = other.numSeederBlocks_var;
    return *this;
}

void BTStatisticsNumSeederBlocksMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->numSeederBlocks_var);
}

void BTStatisticsNumSeederBlocksMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->numSeederBlocks_var);
}

double BTStatisticsNumSeederBlocksMsg::numSeederBlocks() const
{
    return numSeederBlocks_var;
}

void BTStatisticsNumSeederBlocksMsg::setNumSeederBlocks(double numSeederBlocks_var)
{
    this->numSeederBlocks_var = numSeederBlocks_var;
}

class BTStatisticsNumSeederBlocksMsgDescriptor : public cClassDescriptor
{
  public:
    BTStatisticsNumSeederBlocksMsgDescriptor();
    virtual ~BTStatisticsNumSeederBlocksMsgDescriptor();

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

Register_ClassDescriptor(BTStatisticsNumSeederBlocksMsgDescriptor);

BTStatisticsNumSeederBlocksMsgDescriptor::BTStatisticsNumSeederBlocksMsgDescriptor() : cClassDescriptor("BTStatisticsNumSeederBlocksMsg", "GenericAppMsg")
{
}

BTStatisticsNumSeederBlocksMsgDescriptor::~BTStatisticsNumSeederBlocksMsgDescriptor()
{
}

bool BTStatisticsNumSeederBlocksMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTStatisticsNumSeederBlocksMsg *>(obj)!=NULL;
}

const char *BTStatisticsNumSeederBlocksMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTStatisticsNumSeederBlocksMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BTStatisticsNumSeederBlocksMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTStatisticsNumSeederBlocksMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numSeederBlocks",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BTStatisticsNumSeederBlocksMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numSeederBlocks")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTStatisticsNumSeederBlocksMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *BTStatisticsNumSeederBlocksMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTStatisticsNumSeederBlocksMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumSeederBlocksMsg *pp = (BTStatisticsNumSeederBlocksMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTStatisticsNumSeederBlocksMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumSeederBlocksMsg *pp = (BTStatisticsNumSeederBlocksMsg *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->numSeederBlocks());
        default: return "";
    }
}

bool BTStatisticsNumSeederBlocksMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumSeederBlocksMsg *pp = (BTStatisticsNumSeederBlocksMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumSeederBlocks(string2double(value)); return true;
        default: return false;
    }
}

const char *BTStatisticsNumSeederBlocksMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *BTStatisticsNumSeederBlocksMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumSeederBlocksMsg *pp = (BTStatisticsNumSeederBlocksMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTStatisticsNumHitsMsg);

BTStatisticsNumHitsMsg::BTStatisticsNumHitsMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->numHits_var = 0;
}

BTStatisticsNumHitsMsg::BTStatisticsNumHitsMsg(const BTStatisticsNumHitsMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTStatisticsNumHitsMsg::~BTStatisticsNumHitsMsg()
{
}

BTStatisticsNumHitsMsg& BTStatisticsNumHitsMsg::operator=(const BTStatisticsNumHitsMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->numHits_var = other.numHits_var;
    return *this;
}

void BTStatisticsNumHitsMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->numHits_var);
}

void BTStatisticsNumHitsMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->numHits_var);
}

double BTStatisticsNumHitsMsg::numHits() const
{
    return numHits_var;
}

void BTStatisticsNumHitsMsg::setNumHits(double numHits_var)
{
    this->numHits_var = numHits_var;
}

class BTStatisticsNumHitsMsgDescriptor : public cClassDescriptor
{
  public:
    BTStatisticsNumHitsMsgDescriptor();
    virtual ~BTStatisticsNumHitsMsgDescriptor();

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

Register_ClassDescriptor(BTStatisticsNumHitsMsgDescriptor);

BTStatisticsNumHitsMsgDescriptor::BTStatisticsNumHitsMsgDescriptor() : cClassDescriptor("BTStatisticsNumHitsMsg", "GenericAppMsg")
{
}

BTStatisticsNumHitsMsgDescriptor::~BTStatisticsNumHitsMsgDescriptor()
{
}

bool BTStatisticsNumHitsMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTStatisticsNumHitsMsg *>(obj)!=NULL;
}

const char *BTStatisticsNumHitsMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTStatisticsNumHitsMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BTStatisticsNumHitsMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTStatisticsNumHitsMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numHits",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BTStatisticsNumHitsMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numHits")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTStatisticsNumHitsMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *BTStatisticsNumHitsMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTStatisticsNumHitsMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumHitsMsg *pp = (BTStatisticsNumHitsMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTStatisticsNumHitsMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumHitsMsg *pp = (BTStatisticsNumHitsMsg *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->numHits());
        default: return "";
    }
}

bool BTStatisticsNumHitsMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumHitsMsg *pp = (BTStatisticsNumHitsMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumHits(string2double(value)); return true;
        default: return false;
    }
}

const char *BTStatisticsNumHitsMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *BTStatisticsNumHitsMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumHitsMsg *pp = (BTStatisticsNumHitsMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BTStatisticsNumMissesMsg);

BTStatisticsNumMissesMsg::BTStatisticsNumMissesMsg(const char *name, int kind) : GenericAppMsg(name,kind)
{
    this->numMisses_var = 0;
}

BTStatisticsNumMissesMsg::BTStatisticsNumMissesMsg(const BTStatisticsNumMissesMsg& other) : GenericAppMsg()
{
    setName(other.getName());
    operator=(other);
}

BTStatisticsNumMissesMsg::~BTStatisticsNumMissesMsg()
{
}

BTStatisticsNumMissesMsg& BTStatisticsNumMissesMsg::operator=(const BTStatisticsNumMissesMsg& other)
{
    if (this==&other) return *this;
    GenericAppMsg::operator=(other);
    this->numMisses_var = other.numMisses_var;
    return *this;
}

void BTStatisticsNumMissesMsg::parsimPack(cCommBuffer *b)
{
    GenericAppMsg::parsimPack(b);
    doPacking(b,this->numMisses_var);
}

void BTStatisticsNumMissesMsg::parsimUnpack(cCommBuffer *b)
{
    GenericAppMsg::parsimUnpack(b);
    doUnpacking(b,this->numMisses_var);
}

double BTStatisticsNumMissesMsg::numMisses() const
{
    return numMisses_var;
}

void BTStatisticsNumMissesMsg::setNumMisses(double numMisses_var)
{
    this->numMisses_var = numMisses_var;
}

class BTStatisticsNumMissesMsgDescriptor : public cClassDescriptor
{
  public:
    BTStatisticsNumMissesMsgDescriptor();
    virtual ~BTStatisticsNumMissesMsgDescriptor();

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

Register_ClassDescriptor(BTStatisticsNumMissesMsgDescriptor);

BTStatisticsNumMissesMsgDescriptor::BTStatisticsNumMissesMsgDescriptor() : cClassDescriptor("BTStatisticsNumMissesMsg", "GenericAppMsg")
{
}

BTStatisticsNumMissesMsgDescriptor::~BTStatisticsNumMissesMsgDescriptor()
{
}

bool BTStatisticsNumMissesMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BTStatisticsNumMissesMsg *>(obj)!=NULL;
}

const char *BTStatisticsNumMissesMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BTStatisticsNumMissesMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BTStatisticsNumMissesMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BTStatisticsNumMissesMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numMisses",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BTStatisticsNumMissesMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numMisses")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BTStatisticsNumMissesMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *BTStatisticsNumMissesMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BTStatisticsNumMissesMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumMissesMsg *pp = (BTStatisticsNumMissesMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BTStatisticsNumMissesMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumMissesMsg *pp = (BTStatisticsNumMissesMsg *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->numMisses());
        default: return "";
    }
}

bool BTStatisticsNumMissesMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumMissesMsg *pp = (BTStatisticsNumMissesMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumMisses(string2double(value)); return true;
        default: return false;
    }
}

const char *BTStatisticsNumMissesMsgDescriptor::getFieldStructName(void *object, int field) const
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

void *BTStatisticsNumMissesMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BTStatisticsNumMissesMsg *pp = (BTStatisticsNumMissesMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


