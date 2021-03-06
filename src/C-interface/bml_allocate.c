#include "bml_allocate.h"
#include "bml_introspection.h"
#include "bml_logger.h"
#include "bml_parallel.h"
#include "dense/bml_allocate_dense.h"
#include "ellpack/bml_allocate_ellpack.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/** Allocate and zero a chunk of memory.
 *
 * \ingroup allocate_group_C
 *
 * \param size The size of the memory.
 * \return A pointer to the allocated chunk.
 */
void *
bml_allocate_memory(
    const size_t size)
{
    void *ptr = calloc(1, size);
    if (ptr == NULL)
    {
        LOG_ERROR("error allocating memory\n");
    }
    return ptr;
}

/** Deallocate a chunk of memory.
 *
 * \ingroup allocate_group_C
 *
 * \param ptr A pointer to the previously allocated chunk.
 */
void
bml_free_memory(
    void *ptr)
{
    free(ptr);
}

/** Deallocate a domain.
 *
 * \ingroup allocate_group_C
 *
 * \param D The domain.
 */
void
bml_deallocate_domain(
    bml_domain_t * D)
{
    bml_free_memory(D->localRowMin);
    bml_free_memory(D->localRowMax);
    bml_free_memory(D->localRowExtent);
    bml_free_memory(D->localDispl);
    bml_free_memory(D->localElements);
}

/** Deallocate a matrix.
 *
 * \ingroup allocate_group_C
 *
 * \param A The matrix.
 */
void
bml_deallocate(
    bml_matrix_t ** A)
{
    if (A == NULL)
    {
        LOG_DEBUG("A is NULL\n");
    }
    else if (*A == NULL)
    {
        LOG_DEBUG("*A is NULL\n");
    }
    else
    {
        LOG_DEBUG("deallocating bml matrix\n");
        switch (bml_get_type(*A))
        {
            case dense:
                bml_deallocate_dense(*A);
                break;
            case ellpack:
                bml_deallocate_ellpack(*A);
                break;
            default:
                LOG_ERROR("unknown matrix type (%d)\n", bml_get_type(*A));
                break;
        }
        *A = NULL;
    }
}

/** Allocate the zero matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The number of non-zeroes per row.
 *  \return The matrix.
 */
bml_matrix_t *
bml_zero_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("zero matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_zero_matrix_dense(matrix_precision, N);
            break;
        case ellpack:
            return bml_zero_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
    return NULL;
}

/** Allocate a random matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The number of non-zeroes per row.
 *  \return The matrix.
 */
bml_matrix_t *
bml_random_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("random matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_random_matrix_dense(matrix_precision, N);
            break;
        case ellpack:
            return bml_random_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type (type ID %d)\n", matrix_type);
            break;
    }
    return NULL;
}

/** Allocate a banded matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The bandwidth of the matrix.
 *  \return The matrix.
 */
bml_matrix_t *
bml_banded_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("banded matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_banded_matrix_dense(matrix_precision, N, M);
            break;
        case ellpack:
            return bml_banded_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type (type ID %d)\n", matrix_type);
            break;
    }
    return NULL;
}

/** Allocate the identity matrix.
 *
 *  Note that the matrix \f$ A \f$ will be newly allocated. The
 *  function does not check whether the matrix is already allocated.
 *
 *  \ingroup allocate_group_C
 *
 *  \param matrix_type The matrix type.
 *  \param matrix_precision The precision of the matrix.
 *  \param N The matrix size.
 *  \param M The number of non-zeroes per row.
 *  \return The matrix.
 */
bml_matrix_t *
bml_identity_matrix(
    const bml_matrix_type_t matrix_type,
    const bml_matrix_precision_t matrix_precision,
    const int N,
    const int M)
{
    LOG_DEBUG("identity matrix of size %d\n", N);
    switch (matrix_type)
    {
        case dense:
            return bml_identity_matrix_dense(matrix_precision, N);
            break;
        case ellpack:
            return bml_identity_matrix_ellpack(matrix_precision, N, M);
            break;
        default:
            LOG_ERROR("unknown matrix type (type ID %d)\n", matrix_type);
            break;
    }
    return NULL;
}

/** Allocate a default domain for a bml matrix.
 *
 * \ingroup allocate_group_C
 *
 *  \param N number of rows
 *  \param M number of columns
 *  \return The domain
 */
bml_domain_t *
bml_default_domain(
    const int N,
    const int M)
{
    int nRanks = bml_getNRanks();

    bml_domain_t *domain = bml_allocate_memory(sizeof(bml_domain_t));

    domain->totalProcs = nRanks;
    domain->totalRows = N;
    domain->totalCols = M;

    domain->maxLocalExtent = ceil((float)N / (float)nRanks);
    domain->minLocalExtent = N - (nRanks-1) * domain->maxLocalExtent;

    domain->globalRowMin = 0;
    domain->globalRowMax = domain->totalRows;
    domain->globalRowExtent = domain->globalRowMax - domain->globalRowMin;

    domain->localRowMin = bml_allocate_memory(nRanks * sizeof(int));
    domain->localRowMax = bml_allocate_memory(nRanks * sizeof(int));
    domain->localRowExtent = bml_allocate_memory(nRanks * sizeof(int));
    domain->localElements = bml_allocate_memory(nRanks * sizeof(int));
    domain->localDispl = bml_allocate_memory(nRanks * sizeof(int));

    /** For first rank */
    domain->localRowMin[0] = domain->globalRowMin;
    domain->localRowMax[0] = domain->globalRowMin + domain->maxLocalExtent;
    domain->localRowExtent[0] = domain->localRowMax[0] - domain->localRowMin[0];

    /** For middle ranks */
    for (int i = 1; i < (nRanks-1); i++)
    {
      domain->localRowMin[i] = domain->globalRowMin + i * domain->maxLocalExtent;
      domain->localRowMax[i] = domain->globalRowMin + (i+1) * domain->maxLocalExtent;
      domain->localRowExtent[i] = domain->localRowMax[i] - domain->localRowMin[i];
    }

    /** For last rank */
    if (nRanks > 1)
    {
      int last = nRanks - 1;
      domain->localRowMin[last] = domain->localRowMax[last-1];
      domain->localRowMax[last] = domain->localRowMin[last] + domain->minLocalExtent;
      domain->localRowExtent[last] = domain->localRowMax[last] - domain->localRowMin[last];
    }

    /** Number of elements and displacement per rank */
    for (int i = 0; i < nRanks; i++)
    {
      domain->localElements[i] = domain->localRowExtent[i] * domain->totalCols;
      domain->localDispl[i] = (i == 0) ? 0 : domain->localDispl[i-1] + domain->localElements[i-1];
    }

/*
    if (bml_printRank() == 1)
    {
      printf("Default Domain\n");
      for (int i = 0; i < nRanks; i++)
      {
        printf("rank %d localRow %d %d %d localElem %d localDispl %d\n",
          i, domain->localRowMin[i], domain->localRowMax[i], 
          domain->localRowExtent[i], domain->localElements[i],
          domain->localDispl[i]);
      }
    }    
*/
    return domain;
}

/** Update a domain for a bml matrix.
 *
 * \ingroup allocate_group_C
 *
 * \param A Matrix with domain
 * \param localPartMin First part on each rank
 * \param localPartMax Last part on each rank
 * \param nnodesInPart Number of nodes in each part
 */
void 
bml_update_domain(
    bml_matrix_t * A,
    int * localPartMin,
    int * localPartMax,
    int * nnodesInPart)
{
    switch (bml_get_type(A))
    {
      case dense:
          bml_update_domain_dense(A, localPartMin, localPartMax, nnodesInPart);
          break;
      case ellpack:
          bml_update_domain_ellpack(A, localPartMin, localPartMax, nnodesInPart);
          break;
      default:
          LOG_ERROR("unknown matrix type (%d)\n", bml_get_type(A));
          break;
    }
}
