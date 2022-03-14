!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!                                               !!
!!                    FORTC                      !!
!!                                               !!
!!      Copyright (c) 2022, Thomas Stainer       !!
!!                                               !!
!!            All rights reserved.               !!
!!    Licensed under the 3-clause BSD license.   !!
!!                                               !!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

module apiinput_m
    use iso_c_binding
    use input_m
    implicit none
    private

    public :: InputCreate
    public :: InputClone
    public :: InputReset
    public :: InputGet
    public :: InputSet
    public :: InputDestroy

contains

    !> Create
    function InputCreate(error_c_ptr) result(input_c_ptr) bind(C, name="InputCreate")
        type(c_ptr)        :: input_c_ptr
        type(c_ptr), value :: error_c_ptr

        type(input_t), pointer :: input_native_ptr

        allocate(input_native_ptr)
        call input_native_ptr%init(error_c_ptr)

        input_c_ptr = c_loc(input_native_ptr)

    end function InputCreate

    !> Clone
    function InputClone(input_c_ptr, error_c_ptr) result(input_clone_c_ptr) bind(C, name="InputClone")
        type(c_ptr), value, intent(in) :: input_c_ptr
        type(c_ptr)                    :: input_clone_c_ptr
        type(c_ptr), value, intent(in) :: error_c_ptr

        type(input_t), pointer :: input_native_ptr
        type(input_t), pointer :: input_clone_native_ptr

        allocate(input_clone_native_ptr)
        call input_clone_native_ptr%init(error_c_ptr)

        ! do the copy - since data structure is simple, this is good enough
        ! if input_t has pointers or allocatables then we need to implement
        ! a correct deep copy
        call c_f_pointer(input_c_ptr, input_native_ptr)
        input_clone_native_ptr = input_native_ptr

        input_clone_c_ptr = c_loc(input_clone_native_ptr)

    end function InputClone

    !> Reset
    subroutine InputReset(input_c_ptr, error_c_ptr, value) bind(C, name="InputReset")
        type(c_ptr), value, intent(in)    :: input_c_ptr
        type(c_ptr), value, intent(in)    :: error_c_ptr
        real(C_DOUBLE), value, intent(in) :: value

        type(input_t), pointer :: input_native_ptr

        call c_f_pointer(input_c_ptr, input_native_ptr)

        call input_native_ptr%reset(error_c_ptr)

    end subroutine InputReset

    !> Get
    function InputGet(input_c_ptr, error_c_ptr) result(result) bind(C, name="InputGet")
        type(c_ptr), value, intent(in) :: input_c_ptr
        type(c_ptr), value, intent(in) :: error_c_ptr

        real(C_DOUBLE) :: result
        type(input_t), pointer :: input_native_ptr

        call c_f_pointer(input_c_ptr, input_native_ptr)

        result = input_native_ptr%get(error_c_ptr)

    end function InputGet

    !> Set
    subroutine InputSet(input_c_ptr, error_c_ptr, value) bind(C, name="InputSet")
        type(c_ptr), value, intent(in)    :: input_c_ptr
        type(c_ptr), value, intent(in)    :: error_c_ptr
        real(C_DOUBLE), value, intent(in) :: value

        type(input_t), pointer :: input_native_ptr

        call c_f_pointer(input_c_ptr, input_native_ptr)

        call input_native_ptr%set(error_c_ptr, value)

    end subroutine InputSet

    !> Destroy
    subroutine InputDestroy(input_c_ptr, error_c_ptr) bind(C, name="InputDestroy")
        type(c_ptr), value, intent(in) :: input_c_ptr
        type(c_ptr), value, intent(in) :: error_c_ptr

        type(input_t), pointer :: input_native_ptr

        call c_f_pointer(input_c_ptr, input_native_ptr)

        deallocate(input_native_ptr)
        nullify(input_native_ptr)

    end subroutine InputDestroy

end module apiinput_m
