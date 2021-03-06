/* -*- C++ -*- */

// Nil.h,v 5.4 2000/03/23 20:52:18 nanbor Exp

// ============================================================================
//
// = LIBRARY
//   ORBSVCS AVStreams
//
// = FILENAME
//   Nil.h
//
// = AUTHOR
//    Nagarajan Surendran <naga@cs.wustl.edu>
//
//
// ============================================================================

#ifndef TAO_AV_NIL_H
#define TAO_AV_NIL_H
#include "ace/pre.h"

#include "Policy.h"

// class TAO_AV_Export TAO_AV_UDP_MCast_Object  : public TAO_AV_Protocol_Object
// {
// public:
//   TAO_AV_UDP_MCast_Object (TAO_AV_Callback *callback,
//                            TAO_AV_Transport *transport = 0);

//   virtual ~TAO_AV_UDP_MCast_Object (void);
//   // Dtor

//   virtual int send_frame (ACE_Message_Block *frame,
//                           TAO_AV_frame_info *frame_info = 0);
//   // send a data frame.

//   virtual int send_frame (const iovec *iov,
//                           int iovcnt,
//                           TAO_AV_frame_info *frame_info = 0);

//   virtual int end_stream (void);
//   // end the stream.
// };

#include "ace/post.h"
#endif /* TAO_AV_NIL_H */
