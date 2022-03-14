# Fortran to C API test

## Error library
A very basic error library is written in C++ and we provide a C interface for it.

This can be found in the `errorapi` directory.


## Input library
This illustrative (but nonsensical) library shows how to write functions in Fortran (modern) and bind to C.

The implementation is found in the `fortranlib` directory.
The interface can be found in the `api` directory.

Note that this Fortran implementation uses the C++ Error implementation through its C API.

## Example programs

Two stupid C++ programs are provided to show how to use this API via their corresponding C interfaces.

One tests for memory leaks: `memoryprogram`.

The other tests the error/logger: `testprogram`.

## More to do....

TODO: Add Fortran program example
TODO: Add C program example
TODO: Setup some tests using toast

## License
BSD-3-Clause License

Work of Thomas Stainer
