#ifndef __BML_TYPES_DENSE_H
#define __BML_TYPES_DENSE_H

#include "bml_types.h"

/** Dense matrix type. */
struct bml_matrix_dense_t
{
    /** The matrix type identifier. */
    bml_matrix_type_t matrix_type;
    /** The real precision. */
    bml_matrix_precision_t matrix_precision;
    /** The number of rows/columns. */
    int N;
    /** The dense matrix. */
    void *matrix;
    /** The domain decomposition when running in parallel. */
    bml_domain_t *domain;
    /** A copy of the domain decomposition. */
    bml_domain_t *domain2;
};
typedef struct bml_matrix_dense_t bml_matrix_dense_t;

#endif
