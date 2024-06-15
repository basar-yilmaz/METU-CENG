/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {
    "TEAM", /* Team Name */

    "e264440",      /* First student ID */
    "BAŞAR YILMAZ", /* First student name */

    "e264439",  /* Second student ID */
    "BARIŞ CAN" /* Second student name */

};

/*******************************************************
 * BATCHED MATRIX MULTIPLICATION \W SUM REDUCTION KERNEL
 *******************************************************/

/*********************************************************************************
 * Your different versions of the batched matrix multiplication functions go here
 *********************************************************************************/

/*
 * naive_batched_mm - The naive baseline version of batched matrix multiplication
 */
char naive_batched_mm_descr[] = "naive_batched_mm: Naive baseline implementation";
void naive_batched_mm(int dim, int *b_mat, int *mat, int *dst)
{
    int i, j, k, l;

    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            for (k = 0; k < dim; k++)
            {
                if (i == 0)
                {
                    dst[RIDX(j, k, dim)] = 0;
                }
                for (l = 0; l < dim; l++)
                {
                    dst[RIDX(j, k, dim)] += b_mat[RIDX(i * dim + j, l, dim)] * mat[RIDX(l, k, dim)];
                }
            }
        }
    }
}

typedef struct matrix_block
{
    int acc0, acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9, acc10, acc11, acc12, acc13, acc14, acc15, acc16, acc17, acc18, acc19, acc20, acc21, acc22, acc23, acc24, acc25, acc26, acc27, acc28, acc29, acc30, acc31;
} matrix_block;

void initializeStruct(struct matrix_block *myStruct)
{
    myStruct->acc0 = 0;
    myStruct->acc1 = 0;
    myStruct->acc2 = 0;
    myStruct->acc3 = 0;
    myStruct->acc4 = 0;
    myStruct->acc5 = 0;
    myStruct->acc6 = 0;
    myStruct->acc7 = 0;
    myStruct->acc8 = 0;
    myStruct->acc9 = 0;
    myStruct->acc10 = 0;
    myStruct->acc11 = 0;
    myStruct->acc12 = 0;
    myStruct->acc13 = 0;
    myStruct->acc14 = 0;
    myStruct->acc15 = 0;
    myStruct->acc16 = 0;
    myStruct->acc17 = 0;
    myStruct->acc18 = 0;
    myStruct->acc19 = 0;
    myStruct->acc20 = 0;
    myStruct->acc21 = 0;
    myStruct->acc22 = 0;
    myStruct->acc23 = 0;
    myStruct->acc24 = 0;
    myStruct->acc25 = 0;
    myStruct->acc26 = 0;
    myStruct->acc27 = 0;
    myStruct->acc28 = 0;
    myStruct->acc29 = 0;
    myStruct->acc30 = 0;
    myStruct->acc31 = 0;
}

/*
 * batched_mm - Your current working version of batched matrix multiplication
 * IMPORTANT: This is the version you will be graded on
 */
char batched_mm_descr[] = "Batched MM with sum reduction: Current working version";
void batched_mm(int dim, int *b_mat, int *mat, int *dst)
{
    // declare variables
    int i, j, k, dim_dim, initialDimSize, i_dim, tempAccumulator;
    int *tensorTrans, *tensorTrans_pointer;
    int *dest_pointer;
    int *reducedMatrix, *reducedMatrix_pointer;

    // just some pointers for temporary use

    // will hold the temporary ith dimension's jth row's value of batched matrix
    int *ptrtoplam;

    // keep dim*dim value for later use
    dim_dim = dim * dim;

    // determine the size of the initial matrix
    initialDimSize = dim_dim * sizeof(int);

    // allocate memory for the transposed matrix
    tensorTrans = malloc(initialDimSize);

    // create a pointer to the first element of the transposed matrix for filling
    tensorTrans_pointer = tensorTrans;

    // create a pointer to the first element of the initial matrix reading
    dest_pointer = dst;

    // create a struct for holding the accumulator values
    // we will use this later for sum reduction
    matrix_block accumulator;
    initializeStruct(&accumulator);

    // allocate memory for the new matrix
    reducedMatrix = malloc(initialDimSize);

    // create a pointer to the first element of the new matrix to go back when needed
    reducedMatrix_pointer = reducedMatrix;

    for (i = 0; i < dim; i++)
    {
        tensorTrans_pointer = tensorTrans + i;
        i_dim = i * dim;
        for (j = 0; j < dim; j += 32)
        {
            for (k = 0; k < 8; k++)
            {
                ((*tensorTrans_pointer)) = *mat++;
                tensorTrans_pointer += dim;
                ((*tensorTrans_pointer)) = *mat++;
                tensorTrans_pointer += dim;
                ((*tensorTrans_pointer)) = *mat++;
                tensorTrans_pointer += dim;
                ((*tensorTrans_pointer)) = *mat++;
                tensorTrans_pointer += dim;
            }

            int *pointer1 = &b_mat[i_dim + j];
            for (k = 0; k < dim; k++)
            {
                ptrtoplam = pointer1;
                accumulator.acc0 += *ptrtoplam++;
                accumulator.acc1 += *ptrtoplam++;
                accumulator.acc2 += *ptrtoplam++;
                accumulator.acc3 += *ptrtoplam++;
                accumulator.acc4 += *ptrtoplam++;
                accumulator.acc5 += *ptrtoplam++;
                accumulator.acc6 += *ptrtoplam++;
                accumulator.acc7 += *ptrtoplam++;
                accumulator.acc8 += *ptrtoplam++;
                accumulator.acc9 += *ptrtoplam++;
                accumulator.acc10 += *ptrtoplam++;
                accumulator.acc11 += *ptrtoplam++;
                accumulator.acc12 += *ptrtoplam++;
                accumulator.acc13 += *ptrtoplam++;
                accumulator.acc14 += *ptrtoplam++;
                accumulator.acc15 += *ptrtoplam++;
                accumulator.acc16 += *ptrtoplam++;
                accumulator.acc17 += *ptrtoplam++;
                accumulator.acc18 += *ptrtoplam++;
                accumulator.acc19 += *ptrtoplam++;
                accumulator.acc20 += *ptrtoplam++;
                accumulator.acc21 += *ptrtoplam++;
                accumulator.acc22 += *ptrtoplam++;
                accumulator.acc23 += *ptrtoplam++;
                accumulator.acc24 += *ptrtoplam++;
                accumulator.acc25 += *ptrtoplam++;
                accumulator.acc26 += *ptrtoplam++;
                accumulator.acc27 += *ptrtoplam++;
                accumulator.acc28 += *ptrtoplam++;
                accumulator.acc29 += *ptrtoplam++;
                accumulator.acc30 += *ptrtoplam++;
                accumulator.acc31 += *ptrtoplam++;

                // we can jump from this matrix to the next one in the z+1 dimension
                pointer1 += dim_dim;
            }
            *reducedMatrix++ = accumulator.acc0;
            *reducedMatrix++ = accumulator.acc1;
            *reducedMatrix++ = accumulator.acc2;
            *reducedMatrix++ = accumulator.acc3;
            *reducedMatrix++ = accumulator.acc4;
            *reducedMatrix++ = accumulator.acc5;
            *reducedMatrix++ = accumulator.acc6;
            *reducedMatrix++ = accumulator.acc7;
            *reducedMatrix++ = accumulator.acc8;
            *reducedMatrix++ = accumulator.acc9;
            *reducedMatrix++ = accumulator.acc10;
            *reducedMatrix++ = accumulator.acc11;
            *reducedMatrix++ = accumulator.acc12;
            *reducedMatrix++ = accumulator.acc13;
            *reducedMatrix++ = accumulator.acc14;
            *reducedMatrix++ = accumulator.acc15;
            *reducedMatrix++ = accumulator.acc16;
            *reducedMatrix++ = accumulator.acc17;
            *reducedMatrix++ = accumulator.acc18;
            *reducedMatrix++ = accumulator.acc19;
            *reducedMatrix++ = accumulator.acc20;
            *reducedMatrix++ = accumulator.acc21;
            *reducedMatrix++ = accumulator.acc22;
            *reducedMatrix++ = accumulator.acc23;
            *reducedMatrix++ = accumulator.acc24;
            *reducedMatrix++ = accumulator.acc25;
            *reducedMatrix++ = accumulator.acc26;
            *reducedMatrix++ = accumulator.acc27;
            *reducedMatrix++ = accumulator.acc28;
            *reducedMatrix++ = accumulator.acc29;
            *reducedMatrix++ = accumulator.acc30;
            *reducedMatrix++ = accumulator.acc31;

            // reset the accumulator
            initializeStruct(&accumulator);
        }
    }

    // get the pointer to the first element of the reduced matrix again
    // using the pointer we created before
    reducedMatrix = reducedMatrix_pointer;

    // get the pointer to the first element of the dst again
    // using the pointer we created before
    dst = dest_pointer;

    // at this point reducedMatrix, tensorTrans and dst pointers
    // are free to use

    int *temp_tensorPointer, *temp_reducedPointer;

    for (i = 0; i < dim; i++)
    {
        i_dim = i * dim;
        temp_tensorPointer = &tensorTrans[-dim];
        temp_reducedPointer = &reducedMatrix[i_dim];
        for (j = 0; j < dim; j++)
        {
            // reset the tempAccumulator
            tempAccumulator = 0;

            // reset the reducedMatrix_pointer
            reducedMatrix_pointer = temp_reducedPointer;

            // reset the tensorTrans_pointer
            // but this time we will go one dimension up
            temp_tensorPointer += dim;
            tensorTrans_pointer = temp_tensorPointer;

            for (k = 0; k < dim; k += 32)
            {
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
                tempAccumulator += (*reducedMatrix_pointer++) * (*tensorTrans_pointer++);
            }
            dest_pointer = &dst[i_dim + j];
            *dest_pointer += tempAccumulator;
        }
    }
}
/*********************************************************************
 * register_batched_mm_functions - Register all of your different versions
 *     of the batched matrix multiplication functions  with the driver by calling the
 *     add_batched_mm_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_batched_mm_functions()
{
    add_batched_mm_function(&naive_batched_mm, naive_batched_mm_descr);
    add_batched_mm_function(&batched_mm, batched_mm_descr);
    /* ... Register additional test functions here */
}

/************************
 * POINT REFLECTION KERNEL
 ************************/

/*********************************************************
 * Your different versions of the point reflection go here
 *********************************************************/

/*
 * naive_reflect - The naive baseline version of point reflection
 */
char naive_reflect_descr[] = "Naive Point Reflection: Naive baseline implementation";
void naive_reflect(int dim, int *src, int *dst)
{
    int i, j;

    // RIDX(i,j,n) ((i)*(n)+(j))

    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            dst[RIDX(dim - 1 - i, dim - 1 - j, dim)] = src[RIDX(i, j, dim)];
        }
    }
}

/*
 * reflect - Your current working version of reflect
 * IMPORTANT: This is the version you will be graded on
 */
char reflect_descr[] = "Point Reflection: Current working version";
void reflect(int dim, int *src, int *dst)
{
    int i, dim_by_dim = dim * dim;
    int *tmp_src = src;
    int block_size = dim_by_dim - 64;
    int *tmp_dst = &dst[dim_by_dim - 1];
    for (i = 0; i <= block_size; i += 64)
    {
        // printf("dst_index: %d src_index: %d", dst_index, src_index);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
        *(tmp_dst--) = *(tmp_src++);
    }
}

/******************************************************************************
 * register_reflect_functions - Register all of your different versions
 *     of the reflect with the driver by calling the
 *     add_reflect_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 ******************************************************************************/

void register_reflect_functions()
{
    add_reflect_function(&naive_reflect, naive_reflect_descr);
    add_reflect_function(&reflect, reflect_descr);
    /* ... Register additional test functions here */
}
