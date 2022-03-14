///////////////////////////////////////////////////
//                                               //
//                    FORTC                      //
//                                               //
//      Copyright (c) 2022, Thomas Stainer       //
//                                               //
//            All rights reserved.               //
//    Licensed under the 3-clause BSD license.   //
//                                               //
///////////////////////////////////////////////////

#ifndef API_INPUT_HH
#define API_INPUT_HH

#ifdef API_DLL_EXPORT
#define API_OPTIONAL_SPEC __declspec(dllexport)
#elif API_DLL_IMPORT
#define API_OPTIONAL_SPEC __declspec(dllimport)
#else
#define API_OPTIONAL_SPEC
#endif // API_DLL_EXPORT

#include "apierror.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef void *InputPtr;

    API_OPTIONAL_SPEC InputPtr InputCreate(ErrorPtr error);

    API_OPTIONAL_SPEC InputPtr InputClone(InputPtr input, ErrorPtr error);

    API_OPTIONAL_SPEC void InputReset(InputPtr input, ErrorPtr error);

    API_OPTIONAL_SPEC double InputGet(InputPtr input, ErrorPtr error);

    API_OPTIONAL_SPEC void InputSet(InputPtr input, ErrorPtr error, double value);

    API_OPTIONAL_SPEC void InputDestroy(InputPtr input, ErrorPtr error);

#ifdef __cplusplus
}
#endif

#endif
