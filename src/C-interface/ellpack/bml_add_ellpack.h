#ifndef __BML_ADD_ELLPACK_H
#define __BML_ADD_ELLPACK_H

#include "bml_types_ellpack.h"

void bml_add_ellpack(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

void bml_add_ellpack_single_real(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

void bml_add_ellpack_double_real(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

void bml_add_ellpack_single_complex(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

void bml_add_ellpack_double_complex(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

double bml_add_norm_ellpack(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

double bml_add_norm_ellpack_single_real(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

double bml_add_norm_ellpack_double_real(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

double bml_add_norm_ellpack_single_complex(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

double bml_add_norm_ellpack_double_complex(
    const bml_matrix_ellpack_t * A,
    const bml_matrix_ellpack_t * B,
    const double alpha,
    const double beta,
    const double threshold);

void bml_add_identity_ellpack(
    const bml_matrix_ellpack_t * A,
    const double beta,
    const double threshold);

void bml_add_identity_ellpack_single_real(
    const bml_matrix_ellpack_t * A,
    const double beta,
    const double threshold);

void bml_add_identity_ellpack_double_real(
    const bml_matrix_ellpack_t * A,
    const double beta,
    const double threshold);

void bml_add_identity_ellpack_single_complex(
    const bml_matrix_ellpack_t * A,
    const double beta,
    const double threshold);

void bml_add_identity_ellpack_double_complex(
    const bml_matrix_ellpack_t * A,
    const double beta,
    const double threshold);

void bml_scale_add_identity_ellpack(
    const bml_matrix_ellpack_t * A,
    const double alpha,
    const double beta,
    const double threshold);

void bml_scale_add_identity_ellpack_single_real(
    const bml_matrix_ellpack_t * A,
    const double alpha,
    const double beta,
    const double threshold);

void bml_scale_add_identity_ellpack_double_real(
    const bml_matrix_ellpack_t * A,
    const double alpha,
    const double beta,
    const double threshold);

void bml_scale_add_identity_ellpack_single_complex(
    const bml_matrix_ellpack_t * A,
    const double alpha,
    const double beta,
    const double threshold);

void bml_scale_add_identity_ellpack_double_complex(
    const bml_matrix_ellpack_t * A,
    const double alpha,
    const double beta,
    const double threshold);

#endif
