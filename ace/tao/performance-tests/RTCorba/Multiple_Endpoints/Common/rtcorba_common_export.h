
// -*- C++ -*-
// rtcorba_common_export.h,v 1.2 2000/10/10 22:16:02 nanbor Exp
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl
// ------------------------------
#ifndef RTCORBA_COMMON_EXPORT_H
#define RTCORBA_COMMON_EXPORT_H

#include "ace/config-all.h"

#if defined (TAO_AS_STATIC_LIBS)
#  if !defined (RTCORBA_COMMON_HAS_DLL)
#    define RTCORBA_COMMON_HAS_DLL 0
#  endif /* ! RTCORBA_COMMON_HAS_DLL */
#else
#  if !defined (RTCORBA_COMMON_HAS_DLL)
#    define RTCORBA_COMMON_HAS_DLL 1
#  endif /* ! RTCORBA_COMMON_HAS_DLL */
#endif

#if defined (RTCORBA_COMMON_HAS_DLL) && (RTCORBA_COMMON_HAS_DLL == 1)
#  if defined (RTCORBA_COMMON_BUILD_DLL)
#    define RTCORBA_COMMON_Export ACE_Proper_Export_Flag
#    define RTCORBA_COMMON_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define RTCORBA_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* RTCORBA_COMMON_BUILD_DLL */
#    define RTCORBA_COMMON_Export ACE_Proper_Import_Flag
#    define RTCORBA_COMMON_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define RTCORBA_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* RTCORBA_COMMON_BUILD_DLL */
#else /* RTCORBA_COMMON_HAS_DLL == 1 */
#  define RTCORBA_COMMON_Export
#  define RTCORBA_COMMON_SINGLETON_DECLARATION(T)
#  define RTCORBA_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* RTCORBA_COMMON_HAS_DLL == 1 */

#endif /* RTCORBA_COMMON_EXPORT_H */

// End of auto generated file.
