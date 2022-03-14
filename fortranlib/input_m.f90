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

module input_m
    use iso_c_binding
    use fork_m
    use error_m
    implicit none
    private

    !> Dummy input object
    type, public :: input_t
        private
        real(kr8)          :: value    = 0.0          !< Value to set
        logical            :: isinit   = .false.      !< A flag to set if the serializer
                                                      !! has been initialized
    contains
        procedure          :: init       !< Initialize
        procedure          :: get        !< Getter
        procedure          :: set        !< Setter
        procedure          :: reset      !< Reset
        final              :: finalize   !< Clean up
    end type input_t

contains

    !> Initialise the input
    subroutine init(this, error)
        class(input_t), intent(inout) :: this     !< Object instance
        type(c_ptr), value            :: error    !< Error C pointer

        call ErrorAppend(error, "Initialising input"//c_null_char)
        this%isinit   = .true.

    end subroutine init

    !> Reset the input
    subroutine reset(this, error)
        class(input_t), intent(inout) :: this     !< Object instance
        type(c_ptr), value            :: error    !< Error C pointer

        call ErrorAppend(error, "Resetting input"//c_null_char)
        this%value    = 0.0
        this%isinit   = .false.

    end subroutine reset

    !> Get the value
    function get(this, error) result(value)
        class(input_t), intent(inout) :: this     !< Object instance
        type(c_ptr), value            :: error    !< Error C pointer
        real(kr8) :: value

        call ErrorAppend(error, "Getting value from input"//c_null_char)
        value = this%value

    end function get

    !> Set the input value
    subroutine set(this, error, value)
        class(input_t), intent(inout) :: this     !< Object instance
        type(c_ptr), value            :: error    !< Error C pointer
        real(kr8), value, intent(in)  :: value

        call ErrorAppend(error, "Setting value in input"//c_null_char)
        this%value    = value
    end subroutine set

    !> Cleanup
    subroutine finalize(this)
        type(input_t), intent(inout) :: this       !< Object instance

        !call this%reset()

    end subroutine finalize

end module input_m
