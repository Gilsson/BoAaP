
#ifndef MYDYNAMICLIB_EXPORT_H
#define MYDYNAMICLIB_EXPORT_H

#ifdef MYDYNAMICLIB_STATIC_DEFINE
#  define MYDYNAMICLIB_EXPORT
#  define MYDYNAMICLIB_NO_EXPORT
#else
#  ifndef MYDYNAMICLIB_EXPORT
#    ifdef myDynamicLib_EXPORTS
        /* We are building this library */
#      define MYDYNAMICLIB_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MYDYNAMICLIB_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MYDYNAMICLIB_NO_EXPORT
#    define MYDYNAMICLIB_NO_EXPORT 
#  endif
#endif

#ifndef MYDYNAMICLIB_DEPRECATED
#  define MYDYNAMICLIB_DEPRECATED __declspec(deprecated)
#endif

#ifndef MYDYNAMICLIB_DEPRECATED_EXPORT
#  define MYDYNAMICLIB_DEPRECATED_EXPORT MYDYNAMICLIB_EXPORT MYDYNAMICLIB_DEPRECATED
#endif

#ifndef MYDYNAMICLIB_DEPRECATED_NO_EXPORT
#  define MYDYNAMICLIB_DEPRECATED_NO_EXPORT MYDYNAMICLIB_NO_EXPORT MYDYNAMICLIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MYDYNAMICLIB_NO_DEPRECATED
#    define MYDYNAMICLIB_NO_DEPRECATED
#  endif
#endif

#endif /* MYDYNAMICLIB_EXPORT_H */
