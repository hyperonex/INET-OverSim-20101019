//
// Generated file, do not edit! Created by opp_msgc 4.1 from applications/xBitTorrent/BTTrackerMsg.msg.
//

#ifndef _BTTRACKERMSG_M_H_
#define _BTTRACKERMSG_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include <IPvXAddress.h>
// }}



/**
 * Enum generated from <tt>applications/xBitTorrent/BTTrackerMsg.msg</tt> by opp_msgc.
 * <pre>
 * enum ANNOUNCE_TYPE
 * {
 * 
 *     A_STARTED = 1; 
 *     A_STOPPED = 2; 
 *     A_COMPLETED = 3; 
 *     A_NORMAL = 4; 
 * }
 * </pre>
 */
enum ANNOUNCE_TYPE {
    A_STARTED = 1,
    A_STOPPED = 2,
    A_COMPLETED = 3,
    A_NORMAL = 4
};

/**
 * Enum generated from <tt>applications/xBitTorrent/BTTrackerMsg.msg</tt> by opp_msgc.
 * <pre>
 * enum REPLY_TYPE
 * {
 * 
 *     R_FAIL = 1; 
 *     R_VALID = 2; 
 *     R_WARN = 3; 
 * }
 * </pre>
 */
enum REPLY_TYPE {
    R_FAIL = 1,
    R_VALID = 2,
    R_WARN = 3
};

/**
 * Struct generated from applications/xBitTorrent/BTTrackerMsg.msg by opp_msgc.
 */
struct PEER
{
    PEER();
    opp_string peerId;
    unsigned int peerPort;
    ::IPvXAddress ipAddress;
};

void doPacking(cCommBuffer *b, PEER& a);
void doUnpacking(cCommBuffer *b, PEER& a);

/**
 * Class generated from <tt>applications/xBitTorrent/BTTrackerMsg.msg</tt> by opp_msgc.
 * <pre>
 * message BTTrackerMsgAnnounce extends cPacket
 * {
 *     @omitGetVerb(true);
 * 
 *     string infoHash;			
 *     string peerId;				
 *     unsigned int peerPort;			
 *     unsigned int event @enum(ANNOUNCE_TYPE);	
 *     bool compact;				
 *     bool noPeerId;				
 *     unsigned int numWant;			
 *     string key;				
 *     string trackerId;
 * }
 * </pre>
 */
class BTTrackerMsgAnnounce : public ::cPacket
{
  protected:
    opp_string infoHash_var;
    opp_string peerId_var;
    unsigned int peerPort_var;
    unsigned int event_var;
    bool compact_var;
    bool noPeerId_var;
    unsigned int numWant_var;
    opp_string key_var;
    opp_string trackerId_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BTTrackerMsgAnnounce&);

  public:
    BTTrackerMsgAnnounce(const char *name=NULL, int kind=0);
    BTTrackerMsgAnnounce(const BTTrackerMsgAnnounce& other);
    virtual ~BTTrackerMsgAnnounce();
    BTTrackerMsgAnnounce& operator=(const BTTrackerMsgAnnounce& other);
    virtual BTTrackerMsgAnnounce *dup() const {return new BTTrackerMsgAnnounce(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * infoHash() const;
    virtual void setInfoHash(const char * infoHash_var);
    virtual const char * peerId() const;
    virtual void setPeerId(const char * peerId_var);
    virtual unsigned int peerPort() const;
    virtual void setPeerPort(unsigned int peerPort_var);
    virtual unsigned int event() const;
    virtual void setEvent(unsigned int event_var);
    virtual bool compact() const;
    virtual void setCompact(bool compact_var);
    virtual bool noPeerId() const;
    virtual void setNoPeerId(bool noPeerId_var);
    virtual unsigned int numWant() const;
    virtual void setNumWant(unsigned int numWant_var);
    virtual const char * key() const;
    virtual void setKey(const char * key_var);
    virtual const char * trackerId() const;
    virtual void setTrackerId(const char * trackerId_var);
};

inline void doPacking(cCommBuffer *b, BTTrackerMsgAnnounce& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BTTrackerMsgAnnounce& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>applications/xBitTorrent/BTTrackerMsg.msg</tt> by opp_msgc.
 * <pre>
 * message BTTrackerMsgResponse extends cPacket
 * {
 *     @omitGetVerb(true);
 * 
 *     string failure;			
 *     string warning;			
 *     unsigned int announceInterval;	
 *     string trackerId;		
 *     unsigned int complete;		
 *     unsigned int incomplete;	
 *     PEER peers[];			
 * }
 * </pre>
 */
class BTTrackerMsgResponse : public ::cPacket
{
  protected:
    opp_string failure_var;
    opp_string warning_var;
    unsigned int announceInterval_var;
    opp_string trackerId_var;
    unsigned int complete_var;
    unsigned int incomplete_var;
    ::PEER *peers_var; // array ptr
    unsigned int peers_arraysize;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BTTrackerMsgResponse&);

  public:
    BTTrackerMsgResponse(const char *name=NULL, int kind=0);
    BTTrackerMsgResponse(const BTTrackerMsgResponse& other);
    virtual ~BTTrackerMsgResponse();
    BTTrackerMsgResponse& operator=(const BTTrackerMsgResponse& other);
    virtual BTTrackerMsgResponse *dup() const {return new BTTrackerMsgResponse(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * failure() const;
    virtual void setFailure(const char * failure_var);
    virtual const char * warning() const;
    virtual void setWarning(const char * warning_var);
    virtual unsigned int announceInterval() const;
    virtual void setAnnounceInterval(unsigned int announceInterval_var);
    virtual const char * trackerId() const;
    virtual void setTrackerId(const char * trackerId_var);
    virtual unsigned int complete() const;
    virtual void setComplete(unsigned int complete_var);
    virtual unsigned int incomplete() const;
    virtual void setIncomplete(unsigned int incomplete_var);
    virtual void setPeersArraySize(unsigned int size);
    virtual unsigned int peersArraySize() const;
    virtual PEER& peers(unsigned int k);
    virtual const PEER& peers(unsigned int k) const {return const_cast<BTTrackerMsgResponse*>(this)->peers(k);}
    virtual void setPeers(unsigned int k, const PEER& peers_var);
};

inline void doPacking(cCommBuffer *b, BTTrackerMsgResponse& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BTTrackerMsgResponse& obj) {obj.parsimUnpack(b);}


#endif // _BTTRACKERMSG_M_H_
