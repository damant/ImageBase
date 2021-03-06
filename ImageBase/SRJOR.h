//
// MATLAB Compiler: 4.15 (R2011a)
// Date: Mon Mar 28 21:18:29 2016
// Arguments: "-B" "macro_default" "-W" "cpplib:SRJOR" "-T" "link:lib" "-d"
// "E:\����\JOR\JOR_Code_v2.0\deploy\SRJOR\src" "-w"
// "enable:specified_file_mismatch" "-w" "enable:repeated_file" "-w"
// "enable:switch_ignored" "-w" "enable:missing_lib_sentinel" "-w"
// "enable:demo_license" "-v"
// "E:\����\JOR\JOR_Code_v2.0\deploy\SuperResolutionJOR.m" "-a"
// "E:\����\JOR\JOR_Code_v2.0\deploy\vlfeat" 
//

#ifndef __SRJOR_h
#define __SRJOR_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_SRJOR
#define PUBLIC_SRJOR_C_API __global
#else
#define PUBLIC_SRJOR_C_API /* No import statement needed. */
#endif

#define LIB_SRJOR_C_API PUBLIC_SRJOR_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_SRJOR
#define PUBLIC_SRJOR_C_API __declspec(dllexport)
#else
#define PUBLIC_SRJOR_C_API __declspec(dllimport)
#endif

#define LIB_SRJOR_C_API PUBLIC_SRJOR_C_API


#else

#define LIB_SRJOR_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_SRJOR_C_API 
#define LIB_SRJOR_C_API /* No special import/export declaration */
#endif

extern LIB_SRJOR_C_API 
bool MW_CALL_CONV SRJORInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_SRJOR_C_API 
bool MW_CALL_CONV SRJORInitialize(void);

extern LIB_SRJOR_C_API 
void MW_CALL_CONV SRJORTerminate(void);



extern LIB_SRJOR_C_API 
void MW_CALL_CONV SRJORPrintStackTrace(void);

extern LIB_SRJOR_C_API 
bool MW_CALL_CONV mlxSuperResolutionJOR(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[]);

extern LIB_SRJOR_C_API 
long MW_CALL_CONV SRJORGetMcrID();


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_SRJOR
#define PUBLIC_SRJOR_CPP_API __declspec(dllexport)
#else
#define PUBLIC_SRJOR_CPP_API __declspec(dllimport)
#endif

#define LIB_SRJOR_CPP_API PUBLIC_SRJOR_CPP_API

#else

#if !defined(LIB_SRJOR_CPP_API)
#if defined(LIB_SRJOR_C_API)
#define LIB_SRJOR_CPP_API LIB_SRJOR_C_API
#else
#define LIB_SRJOR_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_SRJOR_CPP_API void MW_CALL_CONV SuperResolutionJOR(const mwArray& img_file, const mwArray& upscaling, const mwArray& out_file);

#endif
#endif
