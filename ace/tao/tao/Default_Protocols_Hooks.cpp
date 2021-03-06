// Default_Protocols_Hooks.cpp,v 1.11 2001/09/18 00:05:30 irfan Exp

#include "Default_Protocols_Hooks.h"
#include "PolicyC.h"
#include "ace/Dynamic_Service.h"

#if !defined (__ACE_INLINE__)
# include "Default_Protocols_Hooks.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID (tao,
           Default_Protocols_Hooks,
           "Default_Protocols_Hooks.cpp,v 1.11 2001/09/18 00:05:30 irfan Exp")

/// destructor
TAO_Default_Protocols_Hooks::~TAO_Default_Protocols_Hooks (void)
{
}

void
TAO_Default_Protocols_Hooks::init_hooks (TAO_ORB_Core *,
                                         CORBA::Environment &)
{
}

int
TAO_Default_Protocols_Hooks::call_client_protocols_hook (int &,
                                                         int &,
                                                         int &,
                                                         const char *)
{
  return 0;
}

int
TAO_Default_Protocols_Hooks::call_server_protocols_hook (int &,
                                                         int &,
                                                         int &,
                                                         const char *)
{
  return 0;
}

void
TAO_Default_Protocols_Hooks::add_rt_service_context_hook (TAO_Service_Context &,
                                                          CORBA::Policy *,
                                                          CORBA::Short &,
                                                          CORBA::Environment &)
{
}

void
TAO_Default_Protocols_Hooks::get_selector_hook (CORBA::Policy *,
                                                CORBA::Boolean &,
                                                CORBA::Short &)
{
}

void
TAO_Default_Protocols_Hooks::get_selector_bands_policy_hook (CORBA::Policy *,
                                                             CORBA::Short &,
                                                             CORBA::Short &,
                                                             CORBA::Short &,
                                                             int &)
{
}

int
TAO_Default_Protocols_Hooks::get_thread_CORBA_priority (CORBA::Short &,
                                                        CORBA::Environment &)
{
  return 0;
}

int
TAO_Default_Protocols_Hooks::get_thread_native_priority (CORBA::Short &,
                                                         CORBA::Environment &)
{
  return 0;
}

int
TAO_Default_Protocols_Hooks::get_thread_CORBA_and_native_priority (CORBA::Short &,
                                                                   CORBA::Short &,
                                                                   CORBA::Environment &)
{
  return 0;
}

int
TAO_Default_Protocols_Hooks::set_thread_CORBA_priority (CORBA::Short,
                                                        CORBA::Environment &)
{
  return 0;
}

int
TAO_Default_Protocols_Hooks::set_thread_native_priority (CORBA::Short,
                                                         CORBA::Environment &)
{
  return 0;
}

int
TAO_Default_Protocols_Hooks::set_default_policies (CORBA::Environment &)
{
  return 0;
}

int
TAO_Default_Protocols_Hooks::set_default_server_protocol_policy (TAO_Acceptor_Registry &,
                                                                 CORBA::Environment &)
{
  return 0;
}

void
TAO_Default_Protocols_Hooks::rt_service_context (TAO_Stub *,
                                                 TAO_Service_Context &,
                                                 CORBA::Boolean ,
                                                 CORBA::Environment &)
{
}


// ****************************************************************

ACE_STATIC_SVC_DEFINE (TAO_Default_Protocols_Hooks,
                       ACE_TEXT ("Protocols_Hooks"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_Default_Protocols_Hooks),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO, TAO_Default_Protocols_Hooks)
