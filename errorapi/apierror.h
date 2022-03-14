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

#ifndef API_ERROR_HH
#define API_ERROR_HH

#ifdef API_DLL_EXPORT
#define API_OPTIONAL_SPEC __declspec(dllexport)
#elif API_DLL_IMPORT
#define API_OPTIONAL_SPEC __declspec(dllimport)
#else
#define API_OPTIONAL_SPEC
#endif // API_DLL_EXPORT

#ifdef __cplusplus
#include <memory>
extern "C"
{
    /**
     *   @brief  From the C++ side, the error C pointer
     *           is wrapped in a structure using a standard pointer
     *
     *           Sadly we cannot use shared pointers since this causes
     *           issues when calling from fortran. It is not clear if
     *           this is possible but it is far to difficult to figure out
     *           and does not add that much benefit.
     */
    struct ErrorStruct;
    typedef ErrorStruct *ErrorPtr;
    typedef ErrorPtr &ERROR_PTR_REF;
#else
/**
     *   @brief  From the C side, the error C pointer
     *           is merely wrapped as an opaque pointer
     */
typedef struct ErrorStruct *ErrorPtr;
typedef ErrorPtr ERROR_PTR_REF;
#endif

    typedef ErrorPtr ERROR_PTR_VALUE;
    typedef const ErrorPtr ERROR_PTR_CONST_VALUE;

    API_OPTIONAL_SPEC ERROR_PTR_VALUE ErrorCreate();

    API_OPTIONAL_SPEC ERROR_PTR_VALUE ErrorClone(const ERROR_PTR_CONST_VALUE error);

    API_OPTIONAL_SPEC void ErrorReset(ERROR_PTR_CONST_VALUE error);

    API_OPTIONAL_SPEC void ErrorDestroy(ERROR_PTR_VALUE error);

    API_OPTIONAL_SPEC int ErrorGetNumberOfMessages(ERROR_PTR_CONST_VALUE error);

    API_OPTIONAL_SPEC void ErrorGet(ERROR_PTR_CONST_VALUE error, int index, char *message);

    API_OPTIONAL_SPEC void ErrorAppend(ERROR_PTR_CONST_VALUE error, const char *message);

#ifdef __cplusplus
}
#endif

#endif
