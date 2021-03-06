#include "../typed.h"
#include "../blas.h"
#include "bml_allocate.h"
#include "bml_scale.h"
#include "bml_types.h"
#include "bml_allocate_dense.h"
#include "bml_copy_dense.h"
#include "bml_scale_dense.h"
#include "bml_types_dense.h"

#include <complex.h>
#include <stdlib.h>
#include <string.h>

#ifdef _OPENMP
#include <omp.h>
#endif

/** Scale a dense matrix - result in new matrix.
 *
 *  \ingroup scale_group
 *
 *  \param A The matrix to be scaled
 *  \return A scaled version of matrix A.
 */
bml_matrix_dense_t *TYPED_FUNC(
    bml_scale_dense_new) (
    const double scale_factor,
    const bml_matrix_dense_t * A)
{
    REAL_T sfactor = (REAL_T) scale_factor;

    bml_matrix_dense_t *B = TYPED_FUNC(bml_copy_dense_new) (A);
    int nElems = B->N * B->N;
    int inc = 1;

    C_BLAS(SCAL) (&nElems, &sfactor, B->matrix, &inc);
    return B;
}

/** Scale a dense matrix.
 *
 *  \ingroup scale_group
 *
 *  \param A The matrix to be scaled
 *  \param B Scaled version of matrix A
 */
void TYPED_FUNC(
    bml_scale_dense) (
    const double scale_factor,
    const bml_matrix_dense_t * A,
    bml_matrix_dense_t * B)
{
    REAL_T sfactor = scale_factor;

    if (A != B)
        TYPED_FUNC(bml_copy_dense) (A, B);

    int nElems = B->N * B->N;
    int inc = 1;

    C_BLAS(SCAL) (&nElems, &sfactor, B->matrix, &inc);
}

void TYPED_FUNC(
    bml_scale_inplace_dense) (
    const double scale_factor,
    bml_matrix_dense_t * A)
{
    REAL_T scale_factor_ = (REAL_T) scale_factor;
    int number_elements = A->N * A->N;
    int inc = 1;

    C_BLAS(SCAL) (&number_elements, &scale_factor_, A->matrix, &inc);
}
