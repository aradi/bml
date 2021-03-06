#include "bml_logger.h"
#include "bml_submatrix.h"
#include "bml_submatrix_ellpack.h"
#include "bml_types.h"
#include "bml_types_ellpack.h"
#include "dense/bml_types_dense.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Determine element indices for submatrix, given a set of nodes/orbitals.
 *
 * \ingroup submatrix_group_C
 *
 * \param A Hamiltonian matrix A
 * \param B Graph matrix B
 * \param nodelist List of node/orbital indeces
 * \param nsize Size of nodelist
 * \param core_halo_index List of core+halo indeces
 * \param core_pos List of core indeces in core_halo_index
 * \param vsize Size of core_halo_index and core_pos
 * \param double_jump_flag Flag to use double jump (0=no, 1=yes)
 */
void
bml_matrix2submatrix_index_ellpack(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const int *nodelist,
    const int nsize,
    int *core_halo_index,
    int *core_pos,
    int *vsize,
    const int double_jump_flag)
{
    switch (A->matrix_precision)
    {
        case single_real:
            bml_matrix2submatrix_index_ellpack_single_real(A, B, nodelist,
                                                           nsize,
                                                           core_halo_index,
                                                           core_pos, vsize,
                                                           double_jump_flag);
            break;
        case double_real:
            bml_matrix2submatrix_index_ellpack_double_real(A, B, nodelist,
                                                           nsize,
                                                           core_halo_index,
                                                           core_pos, vsize,
                                                           double_jump_flag);
            break;
        case single_complex:
            bml_matrix2submatrix_index_ellpack_single_complex(A, B, nodelist,
                                                              nsize,
                                                              core_halo_index,
                                                              core_pos, vsize,
                                                              double_jump_flag);
            break;
        case double_complex:
            bml_matrix2submatrix_index_ellpack_double_complex(A, B, nodelist,
                                                              nsize,
                                                              core_halo_index,
                                                              core_pos, vsize,
                                                              double_jump_flag);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

/** Extract a submatrix from a matrix given a set of core+halo rows.
 *
 * \ingroup submatrix_group_C
 *
 * \param A Matrix A
 * \param B Submatrix B
 * \param core_halo_index Set of row indeces for submatrix
 * \param llsize Number of indeces
 */
void
bml_matrix2submatrix_ellpack(
    const bml_matrix_ellpack_t * A,
    bml_matrix_dense_t * B,
    const int *core_halo_index,
    const int lsize)
{
    switch (A->matrix_precision)
    {
        case single_real:
            bml_matrix2submatrix_ellpack_single_real(A, B, core_halo_index,
                                                     lsize);
            break;
        case double_real:
            bml_matrix2submatrix_ellpack_double_real(A, B, core_halo_index,
                                                     lsize);
            break;
        case single_complex:
            bml_matrix2submatrix_ellpack_single_complex(A, B, core_halo_index,
                                                        lsize);
            break;
        case double_complex:
            bml_matrix2submatrix_ellpack_double_complex(A, B, core_halo_index,
                                                        lsize);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

/** Assemble submatrix into a full matrix based on core+halo indeces.
 *
 * \ingroup submatrix_group_C
 *
 * \param A Submatrix A
 * \param B Matrix B
 * \param core_halo_index Set of submatrix row indeces
 * \param lsize Number of indeces
 * \param core_pos Set of positions in core_halo_index for core rows
 * \param llsize Number of core positions
 * \param threshold Threshold for elements
 */
void
bml_submatrix2matrix_ellpack(
    const bml_matrix_dense_t * A,
    bml_matrix_ellpack_t * B,
    const int *core_halo_index,
    const int lsize,
    const int *core_pos,
    const int llsize,
    const double threshold)
{
    switch (A->matrix_precision)
    {
        case single_real:
            bml_submatrix2matrix_ellpack_single_real(A, B, core_halo_index,
                                                     lsize, core_pos, llsize,
                                                     threshold);
            break;
        case double_real:
            bml_submatrix2matrix_ellpack_double_real(A, B, core_halo_index,
                                                     lsize, core_pos, llsize,
                                                     threshold);
            break;
        case single_complex:
            bml_submatrix2matrix_ellpack_single_complex(A, B, core_halo_index,
                                                        lsize, core_pos,
                                                        llsize, threshold);
            break;
        case double_complex:
            bml_submatrix2matrix_ellpack_double_complex(A, B, core_halo_index,
                                                        lsize, core_pos,
                                                        llsize, threshold);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

/** Get vector from matrix.
 *
 * \ingroup submatrix_group_C
 *
 * \param A Matrix A
 * \param jj Index set
 * \param irow Which row
 * \param colCnt Number of columns
 * \param rvalue Returned vector
 */
void *
bml_getVector_ellpack(
    const bml_matrix_ellpack_t * A,
    const int *jj,
    const int irow,
    const int colCnt)
{
    switch (A->matrix_precision)
    {
        case single_real:
            return bml_getVector_ellpack_single_real(A, jj, irow, colCnt);
            break;
        case double_real:
            return bml_getVector_ellpack_double_real(A, jj, irow, colCnt);
            break;
        case single_complex:
            return bml_getVector_ellpack_single_complex(A, jj, irow, colCnt);
            break;
        case double_complex:
            return bml_getVector_ellpack_double_complex(A, jj, irow, colCnt);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
    return NULL;
}
