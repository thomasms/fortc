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

module error_m

    ! C functions declaration
    interface
        function ErrorCreate() result(error) bind(C, name="ErrorCreate")
            use iso_c_binding
            implicit none
            type(c_ptr) :: error
        end function ErrorCreate

        function ErrorClone(error) result(clone) bind(C, name="ErrorClone")
            use iso_c_binding
            implicit none
            type(c_ptr), value :: error
            type(c_ptr)        :: clone
        end function ErrorClone

        subroutine ErrorDelete(error) bind(C, name="ErrorDelete")
            use iso_c_binding
            implicit none
            type(c_ptr), value :: error
        end subroutine ErrorDelete

        subroutine ErrorReset(error) bind(C, name="ErrorReset")
            use iso_c_binding
            implicit none
            type(c_ptr), value :: error
        end subroutine ErrorReset

        subroutine ErrorAppend(error, message) bind(C, name="ErrorAppend")
            use iso_c_binding
            implicit none
            type(c_ptr), value                                :: error
            character(kind=c_char), dimension(*), intent(in)  :: message
        end subroutine ErrorAppend
    end interface

end module error_m
