// -*- C++ -*-
//
// CodecFactory_ORBInitializer.cpp,v 1.2 2001/08/13 01:01:38 othman Exp

#include "CodecFactory_ORBInitializer.h"
#include "CodecFactory.h"

ACE_RCSID (TAO_CodecFactory,
           CodecFactory_ORBInitializer,
           "CodecFactory_ORBInitializer.cpp,v 1.2 2001/08/13 01:01:38 othman Exp")

void
TAO_CodecFactory_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr info
    TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_ENV_ARG_DEFN;

  // The CodecFactory is stateless and reentrant, so share a single
  // instance between all ORBs.
  if (CORBA::is_nil (this->codec_factory_.in ()))
    {
      IOP::CodecFactory_ptr codec_factory;
      ACE_NEW_THROW_EX (codec_factory,
                        TAO_CodecFactory,
                          CORBA::NO_MEMORY (
                            CORBA::SystemException::_tao_minor_code (
                              TAO_DEFAULT_MINOR_CODE,
                              ENOMEM),
                            CORBA::COMPLETED_NO));
      ACE_CHECK;

      this->codec_factory_ = codec_factory;
    }

  info->register_initial_reference ("CodecFactory",
                                    this->codec_factory_.in (),
                                    ACE_TRY_ENV);
  ACE_CHECK;
}

void
TAO_CodecFactory_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr
    TAO_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}
