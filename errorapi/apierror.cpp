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

#include <string.h>
#include <memory>
#include <iostream>

#include "apierror.h"
#include "error.h"

struct ErrorStruct
{
    error::Error raw;
};

ErrorPtr ErrorCreate()
{
    try
    {
        return new ErrorStruct();
    }
    catch (...)
    {
        std::cout << "Unknown error when creating Error\n";
        return nullptr;
    }
}

ErrorPtr ErrorClone(ERROR_PTR_CONST_VALUE error)
{
    try
    {
        return new ErrorStruct(*error);
    }
    catch (...)
    {
        std::cout << "Unknown error when cloning Error\n";
        return nullptr;
    }
}

void ErrorReset(ERROR_PTR_CONST_VALUE error)
{
    try
    {
        error->raw.reset();
    }
    catch (...)
    {
        std::cout << "Unknown error when resetting Error\n";
    }
}

void ErrorDestroy(ERROR_PTR_VALUE error)
{
    try
    {
        delete error;
        error = nullptr;
    }
    catch (...)
    {
        std::cout << "Unknown error when destroying Error\n";
    }
}

int ErrorGetNumberOfMessages(ERROR_PTR_CONST_VALUE error)
{
    try
    {
        return static_cast<int>(error->raw.size());
    }
    catch (...)
    {
        std::cout << "Unknown error when getting number of messages\n";
        return -1;
    }
}

void ErrorGet(ERROR_PTR_CONST_VALUE error, int index, char *message)
{
    try
    {
        // auto rtrim = [](char *m)
        // {
        //     char *back = m + std::strlen(m);
        //     while (isspace(*--back))
        //         ;
        //     *(back + 1) = '\0';
        //     return back;
        // };

        auto &m = error->raw.get(index);
        strcpy(message, m.c_str());
        // message = rtrim(message);
    }
    catch (...)
    {
        std::cout << "Unknown error when getting message\n";
    }
}

void ErrorAppend(ERROR_PTR_CONST_VALUE error, const char *message)
{
    try
    {
        error->raw.addMessage(std::string(message));
    }
    catch (...)
    {
        std::cout << "Unknown error when appending message\n";
    }
}
