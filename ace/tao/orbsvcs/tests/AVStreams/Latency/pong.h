// pong.h,v 1.3 2001/03/01 02:36:06 yamuna Exp

// ============================================================================
//
// = LIBRARY
//   TAO/orbsvcs/tests/AVStreams/Latency
//
// = FILENAME
//   ping.h
//
// = AUTHOR
//   Carlos O'Ryan
//
// ============================================================================

#ifndef TAO_PONG_H
#define TAO_PONG_H

#include "orbsvcs/AV/AVStreams_i.h"
#include "orbsvcs/AV/Policy.h"
#include "orbsvcs/AV/Flows_T.h"

class Pong_Recv_Callback : public TAO_AV_Callback
{
public:
  virtual int handle_stop (void);
  virtual int receive_frame (ACE_Message_Block *frame,
                             TAO_AV_frame_info *frame_info = 0,
                             const ACE_Addr &peer_address = ACE_Addr::sap_any);
  virtual int handle_destroy (void);
};

class Pong_Recv : public TAO_FlowConsumer
{
public:
  Pong_Recv (void);

  virtual int get_callback (const char *flowname,
                            TAO_AV_Callback *&callback);

private:
  Pong_Recv_Callback callback_;
  // The callback object...
};

class Ping_Send_Callback : public TAO_AV_Callback
{
public:
  Ping_Send_Callback (void);

  virtual int handle_timeout (void *arg);
  virtual int handle_end_stream (void);
  virtual void get_timeout (ACE_Time_Value *&tv,
                            void *&arg);

private:
  ACE_Time_Value timeout_;
  // the timeout value

  ACE_Message_Block frame_;
  // Pre-allocate the message block to send...
  int count_;

};

class Ping_Send : public TAO_FlowProducer
{
public:
  Ping_Send (void);
  virtual int get_callback (const char *flowname,
                            TAO_AV_Callback *&callback);

private:
  Ping_Send_Callback callback_;
  // The callback object...
};

typedef TAO_AV_Endpoint_Reactive_Strategy_A <TAO_StreamEndPoint_A,TAO_VDev,AV_Null_MediaCtrl> Reactive_Strategy;

typedef TAO_FDev<TAO_FlowProducer,Pong_Recv> Pong_Recv_FDev;
typedef TAO_FDev<Ping_Send,TAO_FlowConsumer> Ping_Send_FDev;

#endif /* TAO_PONG_H */
