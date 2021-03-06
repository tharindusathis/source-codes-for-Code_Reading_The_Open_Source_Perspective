/* -*- C++ -*- */
// Broadcaster_i.h,v 1.6 2000/09/01 05:05:34 coryan Exp

// ===========================================================
//
// = LIBRARY
//    TAO/tests/Simple/chat
//
// = FILENAME
//    Broadcaster_i.h
//
// = DESCRIPTION
//    Defines the implementation header for the Broadcaster interface.
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ===========================================================

#ifndef BROADCASTER_I_H
#define BROADCASTER_I_H

#include "BroadcasterS.h"
#include "ReceiverC.h"
#include "tao/PortableServer/ORB_Manager.h"
#include "ace/Containers.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"

class Broadcaster_i : public POA_Broadcaster
{
  // = TITLE
  //    The implementation of the Broadcaster class, which is the
  //    servant object for the chat server.
public:
  // = Initialization and termination methods.
  Broadcaster_i (void);
  // Constructor.

  ~Broadcaster_i (void);
  // Destructor.

  virtual void add (Receiver_ptr receiver,
                    const char *nickname,
                    CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      Broadcaster::CannotAdd
    ));
  // Saves receiver references in a list.

  virtual void remove (Receiver_ptr receiver,
                       CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      Broadcaster::CannotRemove
    ));
  // Removes receiver references from the list.

  virtual void say (Receiver_ptr receiver,
                    const char *text,
                    CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  // Called by Broadcaster clients to send messages.

public:
  TAO_ORB_Manager orb_manager_;
  // The ORB manager.

  void broadcast (const char* text,
                  CORBA::Environment &ACE_TRY_ENV);
  // Broadcasts the text to all registered clients.

  class Receiver_Data
  {
    // = TITLE
    //   Per-client info.
    //
    // = DESCRIPTION
    //   Saves the Receiver_var and user nickname.
  public:
    int operator == (const Receiver_Data &receiver_data) const;
    // The == op required by the ACE_Unbounded set.

    Receiver_var receiver_;
    // Stores the receiver reference.

    ACE_CString nickname_;
    // Stores the client nickname.
    };

  typedef ACE_Unbounded_Set<Receiver_Data>
          RECEIVER_SET;
  typedef ACE_Unbounded_Set_Iterator<Receiver_Data>
          RECEIVER_SET_ITERATOR;

  RECEIVER_SET receiver_set_;
  // Set of registered clients.
};

#endif /* BROADCASTER_I_H */
