#include "bml_parallel.h"
#include "bml_introspection.h"
#include "bml_logger.h"
#include "dense/bml_parallel_dense.h"
#include "ellpack/bml_parallel_ellpack.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

static int myRank = 0;
static int nRanks = 1;
#ifdef DO_MPI
static MPI_Request* requestList;
MPI_Comm ccomm;
#endif
static int* rUsed;
static int reqCount = 0;

/** Initialize.
 *
 * \ingroup init_group_C
 *
 * \param argc Number of args
 * \param argv Args
 */

/** Get number of MPI ranks.
 */
int bml_getNRanks()
{
   return nRanks;
}

/** Get local MPI rank.
 */
int bml_getMyRank()
{
   return myRank;
}

//
/// \details
/// For now this is just a check for rank 0 but in principle it could be
/// more complex.  It is also possible to suppress practically all
/// output by causing this function to return 0 for all ranks.
int bml_printRank()
{
   if (myRank == 0) return 1;
   return 0;
}

void bml_initParallel(int* argc, char*** argv)
{
#ifdef DO_MPI
   MPI_Init(argc, argv);
   ccomm = MPI_COMM_WORLD;
   MPI_Comm_rank(ccomm, &myRank);
   MPI_Comm_size(ccomm, &nRanks);

   requestList = (MPI_Request*) malloc(nRanks*sizeof(MPI_Request));
   rUsed = (int*) malloc(nRanks*sizeof(int));
   for (int i = 0; i < nRanks; i++) { rUsed[i] = 0; }
#endif
}

#ifdef DO_MPI
void bml_initParallelF(MPI_Fint fcomm)
{
   ccomm = MPI_Comm_f2c(fcomm);
   MPI_Comm_rank(ccomm, &myRank);
   MPI_Comm_size(ccomm, &nRanks);

   if (bml_printRank())
       printf("MPI started in bml with %d ranks\n", nRanks);

   requestList = (MPI_Request*) malloc(nRanks*sizeof(MPI_Request));
   rUsed = (int*) malloc(nRanks*sizeof(int));
   for (int i = 0; i < nRanks; i++) { rUsed[i] = 0; }
}
#endif

void bml_shutdownParallelF()
{
#ifdef DO_MPI
   free(requestList);
   free(rUsed);
#endif
}

void bml_shutdownParallel()
{
#ifdef DO_MPI
   free(requestList);
   free(rUsed);

   MPI_Finalize();
#endif
}

void bml_barrierParallel()
{
#ifdef DO_MPI
   MPI_Barrier(ccomm);
#endif
}

/** Exchange pieces of matrix across MPI ranks.
 *
 * \param A Matrix A
 */
void 
bml_allGatherVParallel(bml_matrix_t * A)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_allGatherVParallel_dense(A);
            break;
        case ellpack:
            bml_allGatherVParallel_ellpack(A);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
}
