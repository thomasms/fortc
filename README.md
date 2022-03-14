# Fortran to C API test

Fortran to C (and back again) examples. I get asked many times how can you call Fortran from C++ or from C and vice versa, well this is my example of how to do it.

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

- [ ] Add Fortran program example
- [ ] Add C program example
- [ ] Setup some tests using toast

## License
BSD-3-Clause License

Work of Thomas Stainer
