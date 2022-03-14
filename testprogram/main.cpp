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

#include <iostream>
#include <string>
#include <algorithm>

#include "apiinput.h"
#include "apierror.h"

const size_t STRING_BUFFER_LENGTH = 1064;

std::string GetErrorMessage(const ErrorPtr &error, size_t index)
{

  auto trim = [](std::string s)
  {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
    return s;
  };

  std::string message(STRING_BUFFER_LENGTH, ' ');
  ErrorGet(error, index, &message[0]);
  return trim(message);
}

// A simple test program - should be moved to unit tests
// but for the sake of a simple example we use this program
int main()
{

  std::cout << "Running test program... " << std::endl;
  try
  {
    std::string message(STRING_BUFFER_LENGTH, ' ');

    auto error = ErrorCreate();
    std::cout << "Number of messages: " << ErrorGetNumberOfMessages(error) << std::endl;

    ErrorAppend(error, "Added from C.");
    std::cout << "Adding test message" << std::endl;
    std::cout << "Number of messages: " << ErrorGetNumberOfMessages(error) << std::endl;
    std::cout << "First message: " << GetErrorMessage(error, 0) << std::endl;

    auto errorClone = ErrorClone(error);
    ErrorDestroy(error);
    std::cout << "Number of messages in clone: " << ErrorGetNumberOfMessages(errorClone) << std::endl;

    auto i1 = InputCreate(errorClone);
    std::cout << "First message: " << GetErrorMessage(errorClone, 0) << std::endl;
    std::cout << "Second message: " << GetErrorMessage(errorClone, 1) << std::endl;
    std::cout << "Created input object 1. Default value: " << InputGet(i1, errorClone) << std::endl;
    std::cout << "Number of messages in clone: " << ErrorGetNumberOfMessages(errorClone) << std::endl;

    auto i2 = InputCreate(errorClone);
    std::cout << "Created input object 2. Default value: " << InputGet(i2, errorClone) << std::endl;
    std::cout << "Number of messages in clone: " << ErrorGetNumberOfMessages(errorClone) << std::endl;
    InputSet(i1, errorClone, 4.5);
    InputSet(i2, errorClone, -0.2342);
    std::cout << "Set new value for input 1: " << InputGet(i1, errorClone) << std::endl;
    std::cout << "Set new value for input 2: " << InputGet(i2, errorClone) << std::endl;
    InputSet(i1, errorClone, -992.5);
    InputSet(i2, errorClone, 35.213);
    std::cout << "Set another new value for input 1: " << InputGet(i1, errorClone) << std::endl;
    std::cout << "Set another new value for input 2: " << InputGet(i2, errorClone) << std::endl;

    std::cout << "Cloning input 2" << std::endl;
    auto i3 = InputClone(i2, errorClone);
    std::cout << "Value for input 3: " << InputGet(i3, errorClone) << std::endl;

    std::cout << "Resetting input 2" << std::endl;
    InputReset(i2, errorClone);
    std::cout << "Check value for input 3 again: " << InputGet(i3, errorClone) << std::endl;

    std::cout << "Destroying input 1" << std::endl;
    InputDestroy(i1, errorClone);
    std::cout << "Check value for input 2 still exists and is default: " << InputGet(i2, errorClone) << std::endl;

    std::cout << "Destroying input 2" << std::endl;
    InputDestroy(i2, errorClone);
    std::cout << "Check value for input 3 still exists with non zero value: " << InputGet(i3, errorClone) << std::endl;

    std::cout << "Destroying input 3" << std::endl;
    InputDestroy(i3, errorClone);

    // error messages
    std::cout << "=================" << std::endl;
    std::cout << "      Errors    " << std::endl;
    std::cout << "=================" << std::endl;
    for (int i = 0; i < ErrorGetNumberOfMessages(errorClone); ++i)
    {
      std::cout << "Message " << i << ": " << GetErrorMessage(errorClone, i) << std::endl;
    }
    std::cout << "=================" << std::endl;
    ErrorDestroy(errorClone);

    std::cout << "Done!" << std::endl;
  }
  catch (std::exception &ex)
  {
    std::cout << ex.what() << std::endl;
  }
  catch (...)
  {
    std::cout << "Unknown error!" << std::endl;
  }
  return 0;
}
