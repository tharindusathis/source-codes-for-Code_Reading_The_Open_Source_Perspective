// ESF_Proxy_List.cpp,v 1.3 2000/04/18 16:12:29 coryan Exp

#ifndef TAO_ESF_PROXY_LIST_CPP
#define TAO_ESF_PROXY_LIST_CPP

#include "ESF_Proxy_List.h"

#if ! defined (__ACE_INLINE__)
#include "ESF_Proxy_List.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ESF, ESF_Proxy_List, "ESF_Proxy_List.cpp,v 1.3 2000/04/18 16:12:29 coryan Exp")

template<class PROXY>
TAO_ESF_Proxy_List<PROXY>::
      TAO_ESF_Proxy_List (void)
{
}

template<class PROXY> void
TAO_ESF_Proxy_List<PROXY>::connected (PROXY *proxy,
                                      CORBA::Environment &)
{
  int r = this->impl_.insert (proxy);
  if (r == 0)
    return;

  if (r == 1)
    {
      // @@ Already there, throw some user exception..
      proxy->_decr_refcnt ();
    }
  if (r == -1)
    {
      // @@ Cannot insert, running out of memory? throw some other
      // user exception
      proxy->_decr_refcnt ();
    }
}

template<class PROXY> void
TAO_ESF_Proxy_List<PROXY>::reconnected (PROXY *proxy,
                                        CORBA::Environment &)
{
  int r = this->impl_.insert (proxy);
  if (r == 0)
    return;

  if (r == 1)
    {
      // Reference count is incremented by the callers to [re]connected.
      // @@ Find out if the protocol could be simplified, and decoupling
      //    increased.
      proxy->_decr_refcnt ();
      return;
    }

  if (r == -1)
    {
      // @@ Cannot insert, running out of memory? throw some other
      // user exception
      proxy->_decr_refcnt ();
    }
}

template<class PROXY> void
TAO_ESF_Proxy_List<PROXY>::disconnected (PROXY *proxy,
                                         CORBA::Environment &)
{
  int r = this->impl_.remove (proxy);
  if (r != 0)
    {
      // @@ Cannot remove, throw some other
      // user exception
      return;
    }
  proxy->_decr_refcnt ();
}

template<class PROXY> void
TAO_ESF_Proxy_List<PROXY>::shutdown (CORBA::Environment &)
{
  Iterator end = this->impl_.end ();
  for (Iterator i = this->impl_.begin (); i != end; ++i)
    {
      // Decrement reference count
      (*i)->_decr_refcnt ();
    }
  this->impl_.reset ();
}

#endif /* TAO_ESF_PROXY_LIST_CPP */
