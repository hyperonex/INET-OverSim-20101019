//
// Generated file, do not edit! Created by opp_msgc 4.1 from httptools/messages/httptMessages.msg.
//

#ifndef _HTTPTMESSAGES_M_H_
#define _HTTPTMESSAGES_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "HTTPMsgDefs.h"
// }}



/**
 * Enum generated from <tt>httptools/messages/httptMessages.msg</tt> by opp_msgc.
 * <pre>
 * enum HTTPMessageKind
 * {
 *     HTTPT_REQUEST_MESSAGE 			= 10000;
 *     HTTPT_DELAYED_REQUEST_MESSAGE 	= 10001;
 *     HTTPT_RESPONSE_MESSAGE 			= 10010;
 *     HTTPT_DELAYED_RESPONSE_MESSAGE 	= 10011;
 * };
 * </pre>
 */
enum HTTPMessageKind {
    HTTPT_REQUEST_MESSAGE = 10000,
    HTTPT_DELAYED_REQUEST_MESSAGE = 10001,
    HTTPT_RESPONSE_MESSAGE = 10010,
    HTTPT_DELAYED_RESPONSE_MESSAGE = 10011
};

/**
 * Class generated from <tt>httptools/messages/httptMessages.msg</tt> by opp_msgc.
 * <pre>
 * packet httptBaseMessage
 * {
 *     @omitGetVerb(true);
 *     string targetUrl; 				
 *     string originatorUrl = "";		
 *     int protocol enum(HTTPProtocol) = HTTP_11; 
 *     bool keepAlive = true;			
 *     int serial = 0;					
 *     string heading = "";			
 *     string payload = "";			
 *     								
 *     int headerLength = 0;			
 *     int contentLength = 0;			
 * }
 * </pre>
 */
class httptBaseMessage : public ::cPacket
{
  protected:
    opp_string targetUrl_var;
    opp_string originatorUrl_var;
    int protocol_var;
    bool keepAlive_var;
    int serial_var;
    opp_string heading_var;
    opp_string payload_var;
    int headerLength_var;
    int contentLength_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const httptBaseMessage&);

  public:
    httptBaseMessage(const char *name=NULL, int kind=0);
    httptBaseMessage(const httptBaseMessage& other);
    virtual ~httptBaseMessage();
    httptBaseMessage& operator=(const httptBaseMessage& other);
    virtual httptBaseMessage *dup() const {return new httptBaseMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * targetUrl() const;
    virtual void setTargetUrl(const char * targetUrl_var);
    virtual const char * originatorUrl() const;
    virtual void setOriginatorUrl(const char * originatorUrl_var);
    virtual int protocol() const;
    virtual void setProtocol(int protocol_var);
    virtual bool keepAlive() const;
    virtual void setKeepAlive(bool keepAlive_var);
    virtual int serial() const;
    virtual void setSerial(int serial_var);
    virtual const char * heading() const;
    virtual void setHeading(const char * heading_var);
    virtual const char * payload() const;
    virtual void setPayload(const char * payload_var);
    virtual int headerLength() const;
    virtual void setHeaderLength(int headerLength_var);
    virtual int contentLength() const;
    virtual void setContentLength(int contentLength_var);
};

inline void doPacking(cCommBuffer *b, httptBaseMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, httptBaseMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>httptools/messages/httptMessages.msg</tt> by opp_msgc.
 * <pre>
 * packet httptRequestMessage extends httptBaseMessage
 * {
 *     @omitGetVerb(true);			
 *     bool badRequest = false;	
 *     int method enum(RequestMethod) = RM_NONE;
 *     string uri = "";
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     int firstBytePos = BRS_UNSPECIFIED;
 *     
 *     
 *     int lastBytePos = BRS_UNSPECIFIED;
 *     
 *     
 *     int entitySize = -1;
 * }
 * </pre>
 */
class httptRequestMessage : public ::httptBaseMessage
{
  protected:
    bool badRequest_var;
    int method_var;
    opp_string uri_var;
    int firstBytePos_var;
    int lastBytePos_var;
    int entitySize_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const httptRequestMessage&);

  public:
    httptRequestMessage(const char *name=NULL, int kind=0);
    httptRequestMessage(const httptRequestMessage& other);
    virtual ~httptRequestMessage();
    httptRequestMessage& operator=(const httptRequestMessage& other);
    virtual httptRequestMessage *dup() const {return new httptRequestMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool badRequest() const;
    virtual void setBadRequest(bool badRequest_var);
    virtual int method() const;
    virtual void setMethod(int method_var);
    virtual const char * uri() const;
    virtual void setUri(const char * uri_var);
    virtual int firstBytePos() const;
    virtual void setFirstBytePos(int firstBytePos_var);
    virtual int lastBytePos() const;
    virtual void setLastBytePos(int lastBytePos_var);
    virtual int entitySize() const;
    virtual void setEntitySize(int entitySize_var);
};

inline void doPacking(cCommBuffer *b, httptRequestMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, httptRequestMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>httptools/messages/httptMessages.msg</tt> by opp_msgc.
 * <pre>
 * packet httptReplyMessage extends httptBaseMessage
 * {
 *     @omitGetVerb(true);
 *     int result = 0; 				
 *     int contentType = 0;			
 *     string contentTypeString = "";	
 *     								
 *     string phrase = "";				
 *     								
 *     								
 *     string relatedUri = "";			
 *     								
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     
 *     int firstBytePos = BRS_UNSPECIFIED;
 *     
 *     int lastBytePos = BRS_UNSPECIFIED;
 *     
 *     int instanceLength = BRS_UNSPECIFIED; 
 * }
 * </pre>
 */
class httptReplyMessage : public ::httptBaseMessage
{
  protected:
    int result_var;
    int contentType_var;
    opp_string contentTypeString_var;
    opp_string phrase_var;
    opp_string relatedUri_var;
    int firstBytePos_var;
    int lastBytePos_var;
    int instanceLength_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const httptReplyMessage&);

  public:
    httptReplyMessage(const char *name=NULL, int kind=0);
    httptReplyMessage(const httptReplyMessage& other);
    virtual ~httptReplyMessage();
    httptReplyMessage& operator=(const httptReplyMessage& other);
    virtual httptReplyMessage *dup() const {return new httptReplyMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int result() const;
    virtual void setResult(int result_var);
    virtual int contentType() const;
    virtual void setContentType(int contentType_var);
    virtual const char * contentTypeString() const;
    virtual void setContentTypeString(const char * contentTypeString_var);
    virtual const char * phrase() const;
    virtual void setPhrase(const char * phrase_var);
    virtual const char * relatedUri() const;
    virtual void setRelatedUri(const char * relatedUri_var);
    virtual int firstBytePos() const;
    virtual void setFirstBytePos(int firstBytePos_var);
    virtual int lastBytePos() const;
    virtual void setLastBytePos(int lastBytePos_var);
    virtual int instanceLength() const;
    virtual void setInstanceLength(int instanceLength_var);
};

inline void doPacking(cCommBuffer *b, httptReplyMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, httptReplyMessage& obj) {obj.parsimUnpack(b);}


#endif // _HTTPTMESSAGES_M_H_
