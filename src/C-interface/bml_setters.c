#include "bml_introspection.h"
#include "bml_logger.h"
#include "bml_setters.h"
#include "dense/bml_setters_dense.h"
#include "ellpack/bml_setters_ellpack.h"

void
bml_set_element_new(
    bml_matrix_t * A,
    const int i,
    const int j,
    const void *value)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_set_element_dense(A, i, j, value);
            break;
        case ellpack:
            bml_set_element_new_ellpack(A, i, j, value);
            break;
        default:
            LOG_ERROR("unknown matrix type in bml_set_new\n");
            break;
    }
}


void
bml_set_element(
    bml_matrix_t * A,
    const int i,
    const int j,
    const void *value)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_set_element_dense(A, i, j, value);
            break;
        case ellpack:
            bml_set_element_ellpack(A, i, j, value);
            break;
        default:
            LOG_ERROR("unknown matrix type in bml_set\n");
            break;
    }
}

void
bml_set_row(
    bml_matrix_t * A,
    const int i,
    const void *row,
    const double threshold)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_set_row_dense(A, i, row);
            break;
        case ellpack:
            bml_set_row_ellpack(A, i, row, threshold);
            break;
        default:
            LOG_ERROR("unknown matrix type in bml_set_row\n");
            break;
    }
}

void
bml_set_diagonal(
    bml_matrix_t * A,
    const void *diagonal,
    const double threshold)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_set_diagonal_dense(A, diagonal);
            break;
        case ellpack:
            bml_set_diagonal_ellpack(A, diagonal, threshold);
            break;
        default:
            LOG_ERROR("unknown matrix type in bml_set_diagonal\n");
            break;
    }
}
