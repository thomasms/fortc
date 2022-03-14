!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!                                               !!
!!                    FORK                       !!
!!                                               !!
!!      Copyright (c) 2018, Thomas Stainer       !!
!!                                               !!
!!            All rights reserved.               !!
!!    Licensed under the 3-clause BSD license.   !!
!!                                               !!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

module fork_m
    use, intrinsic :: iso_fortran_env
    implicit none
    private

    !!
    !! Platform independent integer and real kinds
    !!
    !! It uses the intrinsic iso_fortran_env which maps
    !! the values to selected_int_kind and selected_real_kind

    !< If you want to use kind names which map to
    !! bits then define FORK_USE_BIT_KIND
    !! else by default it uses byte notation
    !!
    !! For integer example ki1 = int8 for bytes and
    !!                     ki8 = int8 for bits
    !! For real example kr4  = real32 for bytes and
    !!                  ki32 = real32 for bits
#ifdef FORK_USE_BIT_KIND
    !> Integer - [8 bit] / [1 bytes]
    integer, parameter, public :: ki8 = int8
    !> Integer - [16 bit] / [2 bytes]
    integer, parameter, public :: ki16 = int16
    !> Integer - [32 bit] / [4 bytes]
    integer, parameter, public :: ki32 = int32
    !> Integer - [64 bit] / [8 bytes]
    integer, parameter, public :: ki64 = int64

    !> Single precision - [32 bit] / [4 bytes]
    integer, parameter, public :: kr32 = real32
    !> Double precision - [64 bit] / [8 bytes]
    integer, parameter, public :: kr64 = real64
    !> Quad precision - [128 bit] / [16 bytes]
    integer, parameter, public :: kr128 = real128
#else
    !> Integer - [8 bit] / [1 bytes]
    integer, parameter, public :: ki1 = int8
    !> Integer - [16 bit] / [2 bytes]
    integer, parameter, public :: ki2 = int16
    !> Integer - [32 bit] / [4 bytes]
    integer, parameter, public :: ki4 = int32
    !> Integer - [64 bit] / [8 bytes]
    integer, parameter, public :: ki8 = int64

    !> Single precision - [32 bit] / [4 bytes]
    integer, parameter, public :: kr4 = real32
    !> Double precision - [64 bit] / [8 bytes]
    integer, parameter, public :: kr8 = real64
    !> Quad precision - [128 bit] / [16 bytes]
    integer, parameter, public :: kr16 = real128
#endif

    !< If we specify FORK_USE_PREC_KIND it
    !! enables SP, DP and QP aliases
    !!
    !! Naming convention for reals using FORK_USE_PREC_KIND
    !! is then SP (single precision), DP (Double precision)
    !! and QP (quad precision)
#ifdef FORK_USE_PREC_KIND
    !> Single precision - [32 bit] / [4 bytes]
    integer, parameter, public :: sp = real32
    !> Double precision - [64 bit] / [8 bytes]
    integer, parameter, public :: dp = real64
    !> Quad precision - [128 bit] / [16 bytes]
    integer, parameter, public :: qp = real128
#endif

    !< Add custom definitions here
    

end module fork_m