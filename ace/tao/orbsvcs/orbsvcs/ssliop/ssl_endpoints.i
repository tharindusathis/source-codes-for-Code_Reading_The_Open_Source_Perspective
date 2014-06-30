/* -*- C++ -*- ssl_endpoints.i,v 1.2 2000/09/26 03:53:02 marina Exp */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_TAO_SSLENDPOINTSEQUENCE_CI_)
#define __TAO_UNBOUNDED_SEQUENCE_TAO_SSLENDPOINTSEQUENCE_CI_

  // = Static operations.
  ACE_INLINE SSLIOP::SSL *
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::allocbuf (CORBA::ULong size)
  // Allocate storage for the sequence.
  {
    SSLIOP::SSL *retval = 0;
    ACE_NEW_RETURN (retval, SSLIOP::SSL[size], 0);
    return retval;
  }

  ACE_INLINE void _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::freebuf (SSLIOP::SSL *buffer)
  // Free the sequence.
  {
    delete [] buffer;
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::_TAO_Unbounded_Sequence_TAO_SSLEndpointSequence (void) // Default constructor.
  {
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::_TAO_Unbounded_Sequence_TAO_SSLEndpointSequence (CORBA::ULong maximum) // Constructor using a maximum length value.
    : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::allocbuf (maximum))
  {
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::_TAO_Unbounded_Sequence_TAO_SSLEndpointSequence (CORBA::ULong maximum,
    CORBA::ULong length,
    SSLIOP::SSL *data,
    CORBA::Boolean release)
  : TAO_Unbounded_Base_Sequence (maximum, length, data, release)
  {
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::_TAO_Unbounded_Sequence_TAO_SSLEndpointSequence (const _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence &rhs)
  // Copy constructor.
    : TAO_Unbounded_Base_Sequence (rhs)
  {
    if (rhs.buffer_ != 0)
    {
      SSLIOP::SSL *tmp1 = _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::allocbuf (this->maximum_);
      SSLIOP::SSL * const tmp2 = ACE_reinterpret_cast (SSLIOP::SSL * ACE_CAST_CONST, rhs.buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp1[i] = tmp2[i];

      this->buffer_ = tmp1;
    }
    else
    {
      this->buffer_ = 0;
    }
  }

  ACE_INLINE _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence &
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::operator= (const _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence &rhs)
  // Assignment operator.
  {
    if (this == &rhs)
      return *this;

    if (this->release_)
    {
      if (this->maximum_ < rhs.maximum_)
      {
        // free the old buffer
        SSLIOP::SSL *tmp = ACE_reinterpret_cast (SSLIOP::SSL *, this->buffer_);
        _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::freebuf (tmp);
        this->buffer_ = _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::allocbuf (rhs.maximum_);
      }
    }
    else
      this->buffer_ = _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::allocbuf (rhs.maximum_);

    TAO_Unbounded_Base_Sequence::operator= (rhs);

    SSLIOP::SSL *tmp1 = ACE_reinterpret_cast (SSLIOP::SSL *, this->buffer_);
    SSLIOP::SSL * const tmp2 = ACE_reinterpret_cast (SSLIOP::SSL * ACE_CAST_CONST, rhs.buffer_);

    for (CORBA::ULong i = 0; i < this->length_; ++i)
      tmp1[i] = tmp2[i];

    return *this;
  }

  // = Accessors.
  ACE_INLINE SSLIOP::SSL &
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::operator[] (CORBA::ULong i)
  // operator []
  {
    ACE_ASSERT (i < this->maximum_);
    SSLIOP::SSL* tmp = ACE_reinterpret_cast(SSLIOP::SSL*,this->buffer_);
    return tmp[i];
  }

  ACE_INLINE const SSLIOP::SSL &
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::operator[] (CORBA::ULong i) const
  // operator []
  {
    ACE_ASSERT (i < this->maximum_);
    SSLIOP::SSL * const tmp = ACE_reinterpret_cast (SSLIOP::SSL* ACE_CAST_CONST, this->buffer_);
    return tmp[i];
  }

  // Implement the TAO_Base_Sequence methods (see Sequence.h)

  ACE_INLINE SSLIOP::SSL *
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::get_buffer (CORBA::Boolean orphan)
  {
    SSLIOP::SSL *result = 0;
    if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
      {
        result = _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::allocbuf (this->length_);
        this->buffer_ = result;
        this->release_ = 1;
      }
      else
      {
        result = ACE_reinterpret_cast (SSLIOP::SSL*, this->buffer_);
      }
    }
    else // if (orphan == 1)
    {
      if (this->release_ != 0)
      {
        // We set the state back to default and relinquish
        // ownership.
        result = ACE_reinterpret_cast(SSLIOP::SSL*,this->buffer_);
        this->maximum_ = 0;
        this->length_ = 0;
        this->buffer_ = 0;
        this->release_ = 0;
      }
    }
    return result;
  }

  ACE_INLINE const SSLIOP::SSL *
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::get_buffer (void) const
  {
    return ACE_reinterpret_cast(const SSLIOP::SSL * ACE_CAST_CONST, this->buffer_);
  }

  ACE_INLINE void
  _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::replace (CORBA::ULong max,
  CORBA::ULong length,
  SSLIOP::SSL *data,
  CORBA::Boolean release)
  {
    this->maximum_ = max;
    this->length_ = length;
    if (this->buffer_ && this->release_ == 1)
    {
      SSLIOP::SSL *tmp = ACE_reinterpret_cast(SSLIOP::SSL*,this->buffer_);
      _TAO_Unbounded_Sequence_TAO_SSLEndpointSequence::freebuf (tmp);
    }
    this->buffer_ = data;
    this->release_ = release;
  }

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_TAO_SSLENDPOINTSEQUENCE_CI_)
#define _TAO_SSLENDPOINTSEQUENCE_CI_

// *************************************************************
// Inline operations for class TAO_SSLEndpointSequence_var
// *************************************************************

ACE_INLINE
TAO_SSLEndpointSequence_var::TAO_SSLEndpointSequence_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
TAO_SSLEndpointSequence_var::TAO_SSLEndpointSequence_var (TAO_SSLEndpointSequence *p)
  : ptr_ (p)
{}

ACE_INLINE
TAO_SSLEndpointSequence_var::TAO_SSLEndpointSequence_var (const ::TAO_SSLEndpointSequence_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::TAO_SSLEndpointSequence (*p.ptr_));
  else
    this->ptr_ = 0;
}

// fixed-size base types only
ACE_INLINE
TAO_SSLEndpointSequence_var::TAO_SSLEndpointSequence_var (const ::TAO_SSLEndpointSequence &p)
{
  ACE_NEW (this->ptr_, ::TAO_SSLEndpointSequence (p));
}

ACE_INLINE
TAO_SSLEndpointSequence_var::~TAO_SSLEndpointSequence_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE TAO_SSLEndpointSequence_var &
TAO_SSLEndpointSequence_var::operator= (TAO_SSLEndpointSequence *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO_SSLEndpointSequence_var &
TAO_SSLEndpointSequence_var::operator= (const ::TAO_SSLEndpointSequence_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, ::TAO_SSLEndpointSequence (*p.ptr_), *this);
  }
  return *this;
}

// fixed-size types only
ACE_INLINE ::TAO_SSLEndpointSequence_var &
TAO_SSLEndpointSequence_var::operator= (const ::TAO_SSLEndpointSequence &p)
{
  if (this->ptr_ != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, ::TAO_SSLEndpointSequence (p), *this);
  }
  return *this;
}

ACE_INLINE const ::TAO_SSLEndpointSequence *
TAO_SSLEndpointSequence_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO_SSLEndpointSequence *
TAO_SSLEndpointSequence_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
TAO_SSLEndpointSequence_var::operator const ::TAO_SSLEndpointSequence &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO_SSLEndpointSequence_var::operator ::TAO_SSLEndpointSequence &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO_SSLEndpointSequence_var::operator ::TAO_SSLEndpointSequence &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE SSLIOP::SSL &
TAO_SSLEndpointSequence_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const ::TAO_SSLEndpointSequence &
TAO_SSLEndpointSequence_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::TAO_SSLEndpointSequence &
TAO_SSLEndpointSequence_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE ::TAO_SSLEndpointSequence *&
TAO_SSLEndpointSequence_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::TAO_SSLEndpointSequence *
TAO_SSLEndpointSequence_var::_retn (void)
{
  ::TAO_SSLEndpointSequence *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::TAO_SSLEndpointSequence *
TAO_SSLEndpointSequence_var::ptr (void) const
{
  return this->ptr_;
}

#endif /* end #if !defined */


#if !defined _TAO_CDR_OP_TAO_SSLEndpointSequence_I_
#define _TAO_CDR_OP_TAO_SSLEndpointSequence_I_

CORBA::Boolean TAO_SSLIOP_Export operator<< (
    TAO_OutputCDR &,
    const TAO_SSLEndpointSequence &
  );
CORBA::Boolean TAO_SSLIOP_Export operator>> (
    TAO_InputCDR &,
    TAO_SSLEndpointSequence &
  );

#endif /* _TAO_CDR_OP_TAO_SSLEndpointSequence_I_ */