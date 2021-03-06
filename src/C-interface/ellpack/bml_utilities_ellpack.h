/** \file */

#ifndef __BML_UTILITIES_ELLPACK_H
#define __BML_UTILITIES_ELLPACK_H

#include "bml_types_ellpack.h"

#include <stdio.h>
#include <stdlib.h>

void bml_read_bml_matrix_ellpack(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_read_bml_matrix_ellpack_single_real(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_read_bml_matrix_ellpack_double_real(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_read_bml_matrix_ellpack_single_complex(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_read_bml_matrix_ellpack_double_complex(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_write_bml_matrix_ellpack(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_write_bml_matrix_ellpack_single_real(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_write_bml_matrix_ellpack_double_real(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_write_bml_matrix_ellpack_single_complex(
    const bml_matrix_ellpack_t * A,
    const char *filename);

void bml_write_bml_matrix_ellpack_double_complex(
    const bml_matrix_ellpack_t * A,
    const char *filename);

#endif
