#ifndef __BML_ALLOCATE_DENSE_H
#define __BML_ALLOCATE_DENSE_H

#include "bml_types_dense.h"

void bml_deallocate_dense(
    bml_matrix_dense_t * A);

bml_matrix_dense_t *bml_zero_matrix_dense(
    const bml_matrix_precision_t matrix_precision,
    const int N);

bml_matrix_dense_t *bml_zero_matrix_dense_single_real(
    const int N);

bml_matrix_dense_t *bml_zero_matrix_dense_double_real(
    const int N);

bml_matrix_dense_t *bml_zero_matrix_dense_single_complex(
    const int N);

bml_matrix_dense_t *bml_zero_matrix_dense_double_complex(
    const int N);

bml_matrix_dense_t *bml_banded_matrix_dense(
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M);

bml_matrix_dense_t *bml_banded_matrix_dense_single_real(
    const int N,
    const int M);

bml_matrix_dense_t *bml_banded_matrix_dense_double_real(
    const int N,
    const int M);

bml_matrix_dense_t *bml_banded_matrix_dense_single_complex(
    const int N,
    const int M);

bml_matrix_dense_t *bml_banded_matrix_dense_double_complex(
    const int N,
    const int M);

bml_matrix_dense_t *bml_random_matrix_dense(
    const bml_matrix_precision_t matrix_precision,
    const int N);

bml_matrix_dense_t *bml_random_matrix_dense_single_real(
    const int N);

bml_matrix_dense_t *bml_random_matrix_dense_double_real(
    const int N);

bml_matrix_dense_t *bml_random_matrix_dense_single_complex(
    const int N);

bml_matrix_dense_t *bml_random_matrix_dense_double_complex(
    const int N);

bml_matrix_dense_t *bml_identity_matrix_dense(
    const bml_matrix_precision_t matrix_precision,
    const int N);

bml_matrix_dense_t *bml_identity_matrix_dense_single_real(
    const int N);

bml_matrix_dense_t *bml_identity_matrix_dense_double_real(
    const int N);

bml_matrix_dense_t *bml_identity_matrix_dense_single_complex(
    const int N);

bml_matrix_dense_t *bml_identity_matrix_dense_double_complex(
    const int N);

void bml_update_domain_dense(
    bml_matrix_dense_t * A,
    int * localPartMin,
    int * localPartMax,
    int * nnodesInPart);

#endif
