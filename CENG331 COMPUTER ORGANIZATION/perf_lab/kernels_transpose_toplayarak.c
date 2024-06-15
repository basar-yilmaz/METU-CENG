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
    "TEAM1", /* Team Name */

    "e257598",      /* First student ID */
    "AYTAC BAŞAR ", /* First student name */

    "e264441",    /* Second student ID */
    "KEREM BARIŞ" /* Second student name */

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
// char transpose_descr[] = "naive_batched_mm: Naive baseline implementation";
// void transpose_batched_mm(int dim, int *b_mat, int *mat, int *dst) {
//     int i,j,k,l;
//
//     for (i = 0; i < dim; i++) {
//         for (j = 0; j < dim; j++) {
//             for (k = 0; k < dim; k++) {
//             	if (i == 0){
//             	    dst[j][k] = 0;
//             	}
//             	for (l = 0; l < dim; l++){
//                     dst[j][k] += b_mat[i][j][l] * mat[k][l];
//                 }
//             }
//         }
//     }
// }
char transpose_descr[] = "naive_batched_mm: Naive baseline implementation";
void transpose_batched_mm(int dim, int *b_mat, int *mat, int *dst)
{
    int i, j, k, l;
    int dimSquare = dim * dim;
    int *transpose1 = malloc(dimSquare * sizeof(int));
    int *transpose1_cursor = transpose1;
    int *initialdst = dst;
    int resultara1 = 0;
    int resultara2 = 0;
    int resultara3 = 0;
    int resultara4 = 0;
    int resultara5 = 0;
    int resultara6 = 0;
    int resultara7 = 0;
    int resultara8 = 0;
    int resultara9 = 0;
    int resultara10 = 0;
    int resultara11 = 0;
    int resultara12 = 0;
    int resultara13 = 0;
    int resultara14 = 0;
    int resultara15 = 0;
    int resultara16 = 0;
    int resultara17 = 0;
    int resultara18 = 0;
    int resultara19 = 0;
    int resultara20 = 0;
    int resultara21 = 0;
    int resultara22 = 0;
    int resultara23 = 0;
    int resultara24 = 0;
    int resultara25 = 0;
    int resultara26 = 0;
    int resultara27 = 0;
    int resultara28 = 0;
    int resultara29 = 0;
    int resultara30 = 0;
    int resultara31 = 0;
    int resultara32 = 0;

    int *ptrtoplam;
    int *newMatrix = malloc(dimSquare * sizeof(int));
    int *newMatrix_cursor = newMatrix;
    for (int i = 0; i < dim; i++)
    {
        transpose1 = transpose1_cursor + i;
        for (int j = 0; j < dim; j += 32)
        {
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;
            *dst++ = 0;

            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;
            ((*transpose1)) = *mat++;
            transpose1 += dim;

            for (int k = 0; k < dim; k++)
            {
                ptrtoplam = &b_mat[k * dimSquare + i * dim + j];
                resultara1 += *ptrtoplam++;
                resultara2 += *ptrtoplam++;
                resultara3 += *ptrtoplam++;
                resultara4 += *ptrtoplam++;
                resultara5 += *ptrtoplam++;
                resultara6 += *ptrtoplam++;
                resultara7 += *ptrtoplam++;
                resultara8 += *ptrtoplam++;
                resultara9 += *ptrtoplam++;
                resultara10 += *ptrtoplam++;
                resultara11 += *ptrtoplam++;
                resultara12 += *ptrtoplam++;
                resultara13 += *ptrtoplam++;
                resultara14 += *ptrtoplam++;
                resultara15 += *ptrtoplam++;
                resultara16 += *ptrtoplam++;
                resultara17 += *ptrtoplam++;
                resultara18 += *ptrtoplam++;
                resultara19 += *ptrtoplam++;
                resultara20 += *ptrtoplam++;
                resultara21 += *ptrtoplam++;
                resultara22 += *ptrtoplam++;
                resultara23 += *ptrtoplam++;
                resultara24 += *ptrtoplam++;
                resultara25 += *ptrtoplam++;
                resultara26 += *ptrtoplam++;
                resultara27 += *ptrtoplam++;
                resultara28 += *ptrtoplam++;
                resultara29 += *ptrtoplam++;
                resultara30 += *ptrtoplam++;
                resultara31 += *ptrtoplam++;
                resultara32 += *ptrtoplam++;
            }
            *newMatrix++ = resultara1;
            *newMatrix++ = resultara2;
            *newMatrix++ = resultara3;
            *newMatrix++ = resultara4;
            *newMatrix++ = resultara5;
            *newMatrix++ = resultara6;
            *newMatrix++ = resultara7;
            *newMatrix++ = resultara8;
            *newMatrix++ = resultara9;
            *newMatrix++ = resultara10;
            *newMatrix++ = resultara11;
            *newMatrix++ = resultara12;
            *newMatrix++ = resultara13;
            *newMatrix++ = resultara14;
            *newMatrix++ = resultara15;
            *newMatrix++ = resultara16;
            *newMatrix++ = resultara17;
            *newMatrix++ = resultara18;
            *newMatrix++ = resultara19;
            *newMatrix++ = resultara20;
            *newMatrix++ = resultara21;
            *newMatrix++ = resultara22;
            *newMatrix++ = resultara23;
            *newMatrix++ = resultara24;
            *newMatrix++ = resultara25;
            *newMatrix++ = resultara26;
            *newMatrix++ = resultara27;
            *newMatrix++ = resultara28;
            *newMatrix++ = resultara29;
            *newMatrix++ = resultara30;
            *newMatrix++ = resultara31;
            *newMatrix++ = resultara32;
            resultara1 = 0;
            resultara2 = 0;
            resultara3 = 0;
            resultara4 = 0;
            resultara5 = 0;
            resultara6 = 0;
            resultara7 = 0;
            resultara8 = 0;
            resultara9 = 0;
            resultara10 = 0;
            resultara11 = 0;
            resultara12 = 0;
            resultara13 = 0;
            resultara14 = 0;
            resultara15 = 0;
            resultara16 = 0;
            resultara17 = 0;
            resultara18 = 0;
            resultara19 = 0;
            resultara20 = 0;
            resultara21 = 0;
            resultara22 = 0;
            resultara23 = 0;
            resultara24 = 0;
            resultara25 = 0;
            resultara26 = 0;
            resultara27 = 0;
            resultara28 = 0;
            resultara29 = 0;
            resultara30 = 0;
            resultara31 = 0;
            resultara32 = 0;
        }
    }
    newMatrix = newMatrix_cursor;
    transpose1 = transpose1_cursor;
    dst = initialdst;
    // int *ptr;
    int *ptr1;
    int *ptr2;
    int *ptr3;
    // int *bmatptr ;
    int result = 0;
    // for (i = 0; i < dim; i++)
    //{
    for (j = 0; j < dim; j++)
    {

        for (k = 0; k < dim; k++)
        {
            // if (i == 0){
            //     dst[j*dim+k] = 0;
            // }
            ptr1 = &dst[j * dim + k];
            ptr2 = &newMatrix[j * dim];
            ptr3 = &transpose1[k * dim];
            for (l = 0; l < dim; l += 32)
            {
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
                result += (*ptr2++) * (*ptr3++);
            }
            *ptr1 += result;
            result = 0;
        }
    }
    //}
}
char aytac_batched_mm_descr[] = "AYTAC";
void aytac_batched_mm(int dim, int *b_mat, int *mat, int *dst)
{
    int i, j, k, l;
    // int res;
    // int res1;
    // int res2;
    // int res3;
    // int res4;
    // int res5;
    // int res6;
    // int res7;
    // int res8;
    // int res9;
    // int res10;
    // int res11;
    // int res12;
    // int res13;
    // int res14;
    // int res15;
    int *ptr2;
    int *ptr;
    int *ptr1;
    // int *dstjdim;
    // int *ptr3;

    // int *cursorptr3 = &mat[- dim];
    int dimSquare = dim * dim;
    int iDimDim = -dimSquare;
    int *cursorcursorptr2 = &b_mat[iDimDim];
    int size = dim * dim;
    int *transpose1 = malloc(size * sizeof(int));
    int *cursortranspose = transpose1;
    for (int i = 0; i < dim; i++)
    {
        transpose1 = cursortranspose + i;
        for (int j = 0; j < dim; j += 32)
        {
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
            transpose1 += dim;
            ((*transpose1)) = *dst++;
        }
    }

    for (i = 0; i < dim; i++)
    {
        iDimDim += dimSquare;
        int jDim = -dim;
        ptr = &dst[-dim];
        cursorcursorptr2 += dimSquare;
        for (j = 0; j < dim; j++)
        {
            ptr += dim;
            jDim += dim;
            int *cursorptr2 = cursorcursorptr2 + jDim;

            ptr1 = &dst[jDim - 1];
            if (i == 0)
            {
                *(ptr++) = 0;
            }
            for (k = 0; k < dim; k++)
            {

                ptr1++;

                ptr2 = cursorptr2;
                // ptr3 = cursorptr3+dim;
                int result = 0;
                transpose1 = cursortranspose;
                for (l = 0; l < dim; l += 32)
                {
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    result += ((*ptr2++) * (*(transpose1++))) + ((*ptr2++) * (*(transpose1++)));
                    // res  =((*ptr2++)  * (*(ptr3 += dim)))+((*ptr2++) * (*(ptr3 += dim))) ;
                    // res1 =((*ptr2++)  * (*(ptr3 += dim)))+((*ptr2++)  * (*(ptr3 += dim)));
                    // res2 =((*ptr2++)  * (*(ptr3 += dim)))+((*ptr2++)  * (*(ptr3 += dim)));
                    // res3 =((*ptr2++)  * (*(ptr3 += dim)))+((*ptr2++)  * (*(ptr3 += dim)));
                    // res4 =((*ptr2++)  * (*(ptr3 += dim)))+((*ptr2++)  * (*(ptr3 += dim)));
                    // res5 =((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res6 =((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res7 =((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res8 =((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res9 =((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res10=((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res11=((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res12=((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res13=((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res14=((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));
                    // res15=((*ptr2++) *  (*(ptr3 += dim)))+((*ptr2++) *  (*(ptr3 += dim)));

                    //*ptr1+=(res+res1)+(res2+res3)+(res4+res5)+(res6+res7)+(res8+res9)+(res10+res11)+(res12+res13)+(res14+res15);
                    // int resson1=res+res1;
                    // int resson2=res2+res3;
                    // int resson3=res4+res5;
                    // int resson4=res6+res7;
                    // int resson5=res8+res9;
                    // int resson6=res10+res11;
                    // int resson7=res12+res13;
                    // int resson8=res14+res15;
                }
                *ptr1 = result;
                cursortranspose += dim;
            }
        }
    }
}
/*
 * batched_mm - Your current working version of batched matrix multiplication
 * IMPORTANT: This is the version you will be graded on
 */
char batched_mm_descr[] = "Batched MM with sum reduction: Current working version";
void batched_mm(int dim, int *b_mat, int *mat, int *dst)
{

    transpose_batched_mm(dim, b_mat, mat, dst);
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
    // add_batched_mm_function(&naive_batched_mm, naive_batched_mm_descr);
    add_batched_mm_function(&transpose_batched_mm, batched_mm_descr);
    // add_batched_mm_function(&aytac_batched_mm, aytac_batched_mm_descr);
    /* ... Register additional test functions here */
}

/************************
 * POINT REFLECTION KERNELchar aytac_reflect_descr[] = "AYTAC IMPLEMENTATION";
void aytac_reflect(int dim, int *src, int *dst) {
    int z,y,a, i, j;
    z=dim*dim;
    y=0;

    for (i = 0; i < dim; i+=8)
    {
        a=y;
        for (j = 0; j < dim; j+=8)
        {

            for(int i1=i;i1<i+8;i1++)
            {

                for(int j1=j;j1<j+8;j1++)
                {
                    dst[ z-1-j1-a] = src[j1+a];
                }
                a+=dim;
            }

        }
        y+=dim;

    }

}
 ************************/

/*********************************************************
 * Your different versions of the point reflection go here
 *********************************************************/

/*
 * naive_reflect - The naive baseline version of point reflection
 */

// #define RIDX(i,j,n) ((i)*(n)+(j))
char aytac_reflect_descr[] = "AYTAC IMPLEMENTATION";
void aytac_reflect(int dim, int *src, int *dst)
{
    int i, j;
    // int x;
    // int blocksize=dim-16;
    int *newdst = &dst[dim * dim - 1];
    // x=0;

    for (i = 0; i < dim; i++)
    {

        for (j = 0; j < dim; j += 32)
        {
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *(newdst--) = *(src++);
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
            *newdst-- = *src++;
        }
        // z-=dim;
        // x+=dim;
    }
}

char naive_reflect_descr[] = "Naive Point Reflection: Naive baseline implementation";
void naive_reflect(int dim, int *src, int *dst)
{
    int i, j;

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

    aytac_reflect(dim, src, dst);
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
    // add_reflect_function(&naive_reflect, naive_reflect_descr);
    add_reflect_function(&reflect, reflect_descr);
    // add_reflect_function(&aytac_reflect, aytac_reflect_descr);
    /* ... Register additional test functions here */
}
