
module bml_getters_m

  use bml_c_interface_m
  use bml_types_m

  implicit none
  private

  interface bml_get_row
     module procedure bml_get_row_single_real
     module procedure bml_get_row_double_real
     module procedure bml_get_row_single_complex
     module procedure bml_get_row_double_complex
  end interface bml_get_row

  interface bml_get_diagonal
     module procedure bml_get_diagonal_single_real
     module procedure bml_get_diagonal_double_real
     module procedure bml_get_diagonal_single_complex
     module procedure bml_get_diagonal_double_complex
  end interface bml_get_diagonal
  
  public :: bml_get_row, bml_get_diagonal

contains
  
  !Getters for diagonal

  !> Get the diagonal i of matrix a
  !! \param a The matrix 
  !! \param diagonal The diagonal that is extracted
  subroutine bml_get_diagonal_single_real(a, diagonal)

    type(bml_matrix_t), intent(in) :: a
    real(C_FLOAT), target, intent(out) :: diagonal(*)

    call bml_get_diagonal_C(a%ptr, c_loc(diagonal))

  end subroutine bml_get_diagonal_single_real

  !> Get the diagonal i of matrix a
  !! \param a The matrix 
  !! \param diagonal The diagonal that is extracted
  subroutine bml_get_diagonal_double_real(a, diagonal)

    type(bml_matrix_t), intent(in) :: a
    real(C_DOUBLE), target, intent(out) :: diagonal(*)

    call bml_get_diagonal_C(a%ptr, c_loc(diagonal))

  end subroutine bml_get_diagonal_double_real

  !> Get the diagonal i of matrix a
  !! \param a The matrix 
  !! \param diagonal The diagonal that is extracted
  subroutine bml_get_diagonal_single_complex(a, diagonal)

    type(bml_matrix_t), intent(in) :: a
    complex(C_FLOAT_COMPLEX), target, intent(out) :: diagonal(*)

    call bml_get_diagonal_C(a%ptr, c_loc(diagonal))

  end subroutine bml_get_diagonal_single_complex

  !> Get the diagonal i of matrix a
  !! \param a The matrix 
  !! \param diagonal The diagonal that is extracted  
  subroutine bml_get_diagonal_double_complex(a, diagonal)

    type(bml_matrix_t), intent(in) :: a
    complex(C_DOUBLE_COMPLEX), target, intent(out) :: diagonal(*)

    call bml_get_diagonal_C(a%ptr, c_loc(diagonal))

  end subroutine bml_get_diagonal_double_complex

  !Getter for row
  
  !> Get the row i of matrix a
  !! \param a The matrix
  !! \param i The row number
  !! \param row The row that is extracted
  subroutine bml_get_row_single_real(a, i, row)

    type(bml_matrix_t), intent(in) :: a
    integer(C_INT), intent(in) :: i
    real(C_FLOAT), target, intent(out) :: row(*)

    call bml_get_row_C(a%ptr, i-1, c_loc(row))

  end subroutine bml_get_row_single_real

  !> Get the row i of matrix a
  !! \param a The matrix
  !! \param i The row number
  !! \param row The row that is extracted
  subroutine bml_get_row_double_real(a, i, row)

    type(bml_matrix_t), intent(in) :: a
    integer(C_INT), intent(in) :: i
    real(C_DOUBLE), target, intent(out) :: row(*)

    call bml_get_row_C(a%ptr, i-1, c_loc(row))

  end subroutine bml_get_row_double_real

  !> Get the row i of matrix a
  !! \param a The matrix
  !! \param i The row number
  !! \param row The row that is extracted
  subroutine bml_get_row_single_complex(a, i, row)

    type(bml_matrix_t), intent(in) :: a
    integer(C_INT), intent(in) :: i
    complex(C_FLOAT_COMPLEX), target, intent(out) :: row(*)

    call bml_get_row_C(a%ptr, i-1, c_loc(row))

  end subroutine bml_get_row_single_complex

  !> Get the row i of matrix a
  !! \param a The matrix
  !! \param i The row number
  !! \param row The row that is extracted
  subroutine bml_get_row_double_complex(a, i, row)

    type(bml_matrix_t), intent(in) :: a
    integer(C_INT), intent(in) :: i
    complex(C_DOUBLE_COMPLEX), target, intent(out) :: row(*)

    call bml_get_row_C(a%ptr, i-1, c_loc(row))

  end subroutine bml_get_row_double_complex

end module bml_getters_m
