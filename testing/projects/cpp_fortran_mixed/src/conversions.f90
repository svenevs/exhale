!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! This file is dedicated to the public domain.  If your jurisdiction requires a        !
! specific license:                                                                    !
!                                                                                      !
! Copyright (c) Stephen McDowell, 2017-2022                                            !
! License:      CC0 1.0 Universal                                                      !
! License Text: https://creativecommons.org/publicdomain/zero/1.0/legalcode            !
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!---------------------------------------------------------------------------------------
! MODULE: conversions
!> \author Thomas E. Kurtz
!
!> \file
!
!> \brief A fortran module for converting between degrees and radians.
!
!> Conversions may be done using either single or double precision.  This file is mostly
!> an adaptation of the excellent crash-course slides presented in Fall 2010:
!> https://pages.mtu.edu/~shene/COURSES/cs201/NOTES/F90-Subprograms.pdf
!---------------------------------------------------------------------------------------
module conversions
  use iso_c_binding, only : c_float, c_double
  implicit none

  !> The single precision representation of \f$\Pi\f$.
  real(c_float),  parameter :: pi_s  = 3.14159265358979323846
  !> The double precision representation of \f$\Pi\f$.
  real(c_double), parameter :: pi_d  = 3.14159265358979323846264338327950288
  !> The single precision representation of ``180.0``.
  real(c_float),  parameter :: s_180 = 180.0
  !> The double precision representation of ``180.0``.
  real(c_double), parameter :: d_180 = 180.0

contains
  !-------------------------------------------------------------------------------------
  !> \brief
  !>     Convert degrees into radians using single precision floating point numbers.
  !>
  !> \param degrees_s
  !>     The input single precision number representing degrees to be converted.
  !>
  !> \return
  !>     The input ``degrees_s`` converted to radians.  Return type is single precision.
  !-------------------------------------------------------------------------------------
  function degrees_to_radians_s(degrees_s) result(radians_s)
    real(c_float), intent(in) :: degrees_s
    real(c_float)             :: radians_s
    radians_s = degrees_s * pi_s / s_180
  end function degrees_to_radians_s

  !-------------------------------------------------------------------------------------
  !> \brief
  !>     Convert radians into degrees using single precision floating point numbers.
  !>
  !> \param radians_s
  !>     The input single precision number representing radians to be converted.
  !>
  !> \return
  !>     The input ``radians_s`` converted to degrees.  Return type is single precision.
  !-------------------------------------------------------------------------------------
  function radians_to_degrees_s(radians_s) result(degrees_s)
    real(c_float), intent(in) :: radians_s
    real(c_float)             :: degrees_s
    degrees_s = radians_s * s_180 / pi_s
  end function radians_to_degrees_s

  !-------------------------------------------------------------------------------------
  !> \brief
  !>     Convert degrees into radians using double precision floating point numbers.
  !>
  !> \param degrees_d
  !>     The input double precision number representing degrees to be converted.
  !>
  !> \return
  !>     The input ``degrees_d`` converted to radians.  Return type is double precision.
  !-------------------------------------------------------------------------------------
  function degrees_to_radians_d(degrees_d) result(radians_d)
    real(c_double), intent(in) :: degrees_d
    real(c_double)             :: radians_d
    radians_d = degrees_d * pi_d / d_180
  end function degrees_to_radians_d

  !-------------------------------------------------------------------------------------
  !> \brief
  !>     Convert radians into degrees using double precision floating point numbers.
  !>
  !> \param radians_d
  !>     The input double precision number representing radians to be converted.
  !>
  !> \return
  !>     The input ``radians_d`` converted to degrees.  Return type is double precision.
  !-------------------------------------------------------------------------------------
  function radians_to_degrees_d(radians_d) result(degrees_d)
    real(c_double), intent(in) :: radians_d
    real(c_double)             :: degrees_d
    degrees_d = radians_d * d_180 / pi_d
  end function radians_to_degrees_d
end module conversions
