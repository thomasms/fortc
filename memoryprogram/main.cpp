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
#include <assert.h>
#include <algorithm>

#include "apiinput.h"
#include "apierror.h"

// Test for no memory leaks
// Run create and destroy 1 billion times
const size_t iterations = 1000000000;

int main()
{

  std::cout << "Running memory program... " << std::endl;
  try
  {
#pragma omp parallel for
    for (size_t i = 0; i < iterations; ++i)
    {
      auto error = ErrorCreate();
      auto input = InputCreate(error);
      InputSet(input, error, 4.5);
      assert(4.5 == InputGet(input, error));
      InputDestroy(input, error);
      ErrorDestroy(error);
    }

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
