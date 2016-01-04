//
// Generated file, do not edit! Created by opp_msgc 4.1 from httptools/messages/httptEventMessages.msg.
//

#ifndef _HTTPTEVENTMESSAGES_M_H_
#define _HTTPTEVENTMESSAGES_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>httptools/messages/httptEventMessages.msg</tt> by opp_msgc.
 * <pre>
 * packet httptServerStatusUpdateMsg
 * {
 *     @omitGetVerb(true);
 *     string www;				
 *     simtime_t setTime;		
 *     int eventKind;			
 *     double pvalue;			
 *     double pamortize;		
 * }
 * </pre>
 */
class httptServerStatusUpdateMsg : public ::cPacket
{
  protected:
    opp_string www_var;
    simtime_t setTime_var;
    int eventKind_var;
    double pvalue_var;
    double pamortize_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const httptServerStatusUpdateMsg&);

  public:
    httptServerStatusUpdateMsg(const char *name=NULL, int kind=0);
    httptServerStatusUpdateMsg(const httptServerStatusUpdateMsg& other);
    virtual ~httptServerStatusUpdateMsg();
    httptServerStatusUpdateMsg& operator=(const httptServerStatusUpdateMsg& other);
    virtual httptServerStatusUpdateMsg *dup() const {return new httptServerStatusUpdateMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * www() const;
    virtual void setWww(const char * www_var);
    virtual simtime_t setTime() const;
    virtual void setSetTime(simtime_t setTime_var);
    virtual int eventKind() const;
    virtual void setEventKind(int eventKind_var);
    virtual double pvalue() const;
    virtual void setPvalue(double pvalue_var);
    virtual double pamortize() const;
    virtual void setPamortize(double pamortize_var);
};

inline void doPacking(cCommBuffer *b, httptServerStatusUpdateMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, httptServerStatusUpdateMsg& obj) {obj.parsimUnpack(b);}


#endif // _HTTPTEVENTMESSAGES_M_H_
