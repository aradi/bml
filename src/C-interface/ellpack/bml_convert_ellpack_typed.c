#include "../macros.h"
#include "../typed.h"
#include "bml_allocate.h"
#include "bml_allocate_ellpack.h"
#include "bml_convert.h"
#include "bml_convert_ellpack.h"
#include "bml_logger.h"
#include "bml_types.h"
#include "bml_types_ellpack.h"

#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

/** Convert a dense matrix into a bml matrix.
 *
 * \ingroup convert_group
 *
 * \param N The number of rows/columns
 * \param matrix_precision The real precision
 * \param A The dense matrix
 * \return The bml matrix
 */
bml_matrix_ellpack_t *TYPED_FUNC(
    bml_convert_from_dense_ellpack) (
    const bml_dense_order_t order,
    const int N,
    const void *A,
    const double threshold,
    const int M)
{
    bml_matrix_ellpack_t *A_bml = TYPED_FUNC(bml_zero_matrix_ellpack) (N, M);

    int *A_index = A_bml->index;
    int *A_nnz = A_bml->nnz;

    REAL_T *dense_A = (REAL_T *) A;
    REAL_T *A_value = A_bml->value;

#pragma omp parallel for default(none) shared(A_value, A_index, A_nnz, dense_A)
    for (int i = 0; i < N; i++)
    {
        A_nnz[i] = 0;
        for (int j = 0; j < N; j++)
        {
            REAL_T A_ij;
            switch (order)
            {
                case dense_row_major:
                    A_ij = dense_A[ROWMAJOR(i, j, N, N)];
                    break;
                case dense_column_major:
                    A_ij = dense_A[COLMAJOR(i, j, N, N)];
                    break;
                default:
                    LOG_ERROR("unknown order\n");
                    break;
            }
            if (is_above_threshold(A_ij, threshold))
            {
                A_value[ROWMAJOR(i, A_nnz[i], N, M)] = A_ij;
                A_index[ROWMAJOR(i, A_nnz[i], N, M)] = j;
                A_nnz[i]++;
            }
        }
    }

    return A_bml;
}

/** Convert a bml matrix into a dense matrix.
 *
 * \ingroup convert_group
 *
 * \param A The bml matrix
 * \return The dense matrix
 */
void *TYPED_FUNC(
    bml_convert_to_dense_ellpack) (
    const bml_matrix_ellpack_t * A,
    const bml_dense_order_t order)
{
    int N = A->N;
    int M = A->M;
    int *A_nnz = A->nnz;
    int *A_index = A->index;
    REAL_T *A_dense = bml_allocate_memory(sizeof(REAL_T) * A->N * A->N);
    REAL_T *A_value = A->value;

    switch (order)
    {
        case dense_row_major:
#pragma omp parallel for default(none) shared(N, M, A_nnz, A_index, A_value, A_dense)
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < A_nnz[i]; j++)
                {
                    A_dense[ROWMAJOR
                            (i, A_index[ROWMAJOR(i, j, N, M)], N,
                             N)] = A_value[ROWMAJOR(i, j, N, M)];
                }
            }
            break;
        case dense_column_major:
#pragma omp parallel for default(none) shared(N, M, A_nnz, A_index, A_value, A_dense)
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < A_nnz[i]; j++)
                {
                    A_dense[COLMAJOR
                            (i, A_index[ROWMAJOR(i, j, N, M)], N,
                             N)] = A_value[ROWMAJOR(i, j, N, M)];
                }
            }
            break;
        default:
            LOG_ERROR("unknown order\n");
            break;
    }
    return A_dense;
}
