// -*- C++ -*-
//
// RTPortableServerC.cpp,v 1.2 2001/08/21 19:00:28 parsons Exp

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#include "RTPortableServerC.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "RTPortableServerC.i"
#endif /* !defined INLINE */

int RTPortableServer::POA::_tao_class_id = 0;

// *************************************************************
// Operations for class RTPortableServer::POA_var
// *************************************************************

RTPortableServer::POA_var::POA_var (void) // default constructor
  : ptr_ (POA::_nil ())
{}

::RTPortableServer::POA_ptr
RTPortableServer::POA_var::ptr (void) const
{
  return this->ptr_;
}

RTPortableServer::POA_var::POA_var (const ::RTPortableServer::POA_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (POA::_duplicate (p.ptr ()))
{}

RTPortableServer::POA_var::~POA_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

RTPortableServer::POA_var &
RTPortableServer::POA_var::operator= (POA_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

RTPortableServer::POA_var &
RTPortableServer::POA_var::operator= (const ::RTPortableServer::POA_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::RTPortableServer::POA::_duplicate (p.ptr ());
  }
  return *this;
}

RTPortableServer::POA_var::operator const ::RTPortableServer::POA_ptr &() const // cast
{
  return this->ptr_;
}

RTPortableServer::POA_var::operator ::RTPortableServer::POA_ptr &() // cast 
{
  return this->ptr_;
}

::RTPortableServer::POA_ptr
RTPortableServer::POA_var::operator-> (void) const
{
  return this->ptr_;
}

::RTPortableServer::POA_ptr
RTPortableServer::POA_var::in (void) const
{
  return this->ptr_;
}

::RTPortableServer::POA_ptr &
RTPortableServer::POA_var::inout (void)
{
  return this->ptr_;
}

::RTPortableServer::POA_ptr &
RTPortableServer::POA_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::RTPortableServer::POA::_nil ();
  return this->ptr_;
}

::RTPortableServer::POA_ptr
RTPortableServer::POA_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::RTPortableServer::POA_ptr val = this->ptr_;
  this->ptr_ = ::RTPortableServer::POA::_nil ();
  return val;
}

::RTPortableServer::POA_ptr
RTPortableServer::POA_var::tao_duplicate (POA_ptr p)
{
  return ::RTPortableServer::POA::_duplicate (p);
}

void
RTPortableServer::POA_var::tao_release (POA_ptr p)
{
  CORBA::release (p);
}

::RTPortableServer::POA_ptr
RTPortableServer::POA_var::tao_nil (void)
{
  return ::RTPortableServer::POA::_nil ();
}

::RTPortableServer::POA_ptr
RTPortableServer::POA_var::tao_narrow (
    CORBA::Object *p,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return ::RTPortableServer::POA::_narrow (p, ACE_TRY_ENV);
}

CORBA::Object *
RTPortableServer::POA_var::tao_upcast (void *src)
{
  POA **tmp =
    ACE_static_cast (POA **, src);
  return *tmp;
}

// *************************************************************
// Inline operations for class RTPortableServer::POA_out
// *************************************************************

RTPortableServer::POA_out::POA_out (POA_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::RTPortableServer::POA::_nil ();
}

RTPortableServer::POA_out::POA_out (POA_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::RTPortableServer::POA::_nil ();
}

RTPortableServer::POA_out::POA_out (const ::RTPortableServer::POA_out &p) // copy constructor
  : ptr_ (ACE_const_cast (POA_out &, p).ptr_)
{}

::RTPortableServer::POA_out &
RTPortableServer::POA_out::operator= (const ::RTPortableServer::POA_out &p)
{
  this->ptr_ = ACE_const_cast (POA_out&, p).ptr_;
  return *this;
}

RTPortableServer::POA_out &
RTPortableServer::POA_out::operator= (const ::RTPortableServer::POA_var &p)
{
  this->ptr_ = ::RTPortableServer::POA::_duplicate (p.ptr ());
  return *this;
}

RTPortableServer::POA_out &
RTPortableServer::POA_out::operator= (POA_ptr p)
{
  this->ptr_ = p;
  return *this;
}

RTPortableServer::POA_out::operator ::RTPortableServer::POA_ptr &() // cast
{
  return this->ptr_;
}

::RTPortableServer::POA_ptr &
RTPortableServer::POA_out::ptr (void) // ptr
{
  return this->ptr_;
}

::RTPortableServer::POA_ptr
RTPortableServer::POA_out::operator-> (void)
{
  return this->ptr_;
}


// default constructor
RTPortableServer::POA::POA ()
{
  }

// destructor
RTPortableServer::POA::~POA (void)
{}

RTPortableServer::POA_ptr RTPortableServer::POA::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return POA::_unchecked_narrow (obj, ACE_TRY_ENV);
}

RTPortableServer::POA_ptr RTPortableServer::POA::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return POA::_nil ();
  return
      ACE_reinterpret_cast
        (
          POA_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &POA::_tao_class_id
                  )
              )
        );
}

RTPortableServer::POA_ptr
RTPortableServer::POA::_duplicate (POA_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *RTPortableServer::POA::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &ACE_NESTED_CLASS (::RTPortableServer, POA)::_tao_class_id))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &::PortableServer::POA::_tao_class_id))
    retv = ACE_reinterpret_cast
      (
        void *,
        ACE_static_cast
          (
            PortableServer::POA_ptr,
            this
          )
      );
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_tao_class_id))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));
    
  if (retv)
    this->_add_ref ();
  return retv;
}

const char* RTPortableServer::POA::_interface_repository_id (void) const
{
  return "IDL:omg.org/RTPortableServer/POA:1.0";
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Object_Manager<RTPortableServer::POA,RTPortableServer::POA_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Manager<RTPortableServer::POA,RTPortableServer::POA_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

