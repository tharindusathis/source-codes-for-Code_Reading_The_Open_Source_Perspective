/* -*- C++ -*- */
// Test_i.h,v 4.2 1998/10/20 02:34:48 levine Exp

#include "ace/Log_Msg.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Test.hh"

class Test_i
{
public:
  virtual void method (long input,
                       ACE_CORBA_1 (Environment) &IT_env = ACE_CORBA_1 (default_environment));
};

DEF_TIE_Test (Test_i)
