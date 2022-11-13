
#ifndef SHARED_LIB_EXPORT_H
#define SHARED_LIB_EXPORT_H

#ifdef SHARED_LIB_STATIC_DEFINE
#  define SHARED_LIB_EXPORT
#  define SHARED_LIB_NO_EXPORT
#else
#  ifndef SHARED_LIB_EXPORT
#    ifdef shared_lib_EXPORTS
        /* We are building this library */
#      define SHARED_LIB_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define SHARED_LIB_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef SHARED_LIB_NO_EXPORT
#    define SHARED_LIB_NO_EXPORT 
#  endif
#endif

#ifndef SHARED_LIB_DEPRECATED
#  define SHARED_LIB_DEPRECATED __declspec(deprecated)
#endif

#ifndef SHARED_LIB_DEPRECATED_EXPORT
#  define SHARED_LIB_DEPRECATED_EXPORT SHARED_LIB_EXPORT SHARED_LIB_DEPRECATED
#endif

#ifndef SHARED_LIB_DEPRECATED_NO_EXPORT
#  define SHARED_LIB_DEPRECATED_NO_EXPORT SHARED_LIB_NO_EXPORT SHARED_LIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef SHARED_LIB_NO_DEPRECATED
#    define SHARED_LIB_NO_DEPRECATED
#  endif
#endif

#endif /* SHARED_LIB_EXPORT_H */
