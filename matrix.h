#ifndef __MATRIX_H
#define __MATRIX_H

#include <float.h>

/* Define a value for MATERR to represent an error condition when calculating the determinant. */
#define MATERR (-DBL_MAX)

struct matrix;
typedef struct matrix * matrix_t;

/**
 * Create a new matrix with the specified number of rows and columns.
 *
 * @param row The number of rows for the matrix.
 * @param col The number of columns for the matrix.
 * @return A pointer to the newly created matrix (matrix_t), or NULL if an error occurs during matrix creation.
 */
matrix_t create_matrix(int row, int col);

/**
 * Add two matrices and return a new matrix containing the result.
 *
 * @param mat1 The first matrix of type matrix_t.
 * @param mat2 The second matrix of type matrix_t.
 * @return A pointer to the resulting matrix (matrix_t), or NULL if an error occurs during addition.
 */
matrix_t add_matrix(matrix_t mat1, matrix_t mat2);

/**
 * Subtract the second matrix from the first matrix and return a new matrix with the result.
 *
 * @param mat1 The first matrix of type matrix_t.
 * @param mat2 The second matrix of type matrix_t.
 * @return A pointer to the resulting matrix (matrix_t), or NULL if an error occurs during subtraction.
 */
matrix_t subtract_matrix(matrix_t mat1, matrix_t mat2);

/**
 * Perform matrix multiplication of two matrices and return a new matrix with the result.
 *
 * @param mat1 The first matrix of type matrix_t.
 * @param mat2 The second matrix of type matrix_t.
 * @return A pointer to the resulting matrix (matrix_t), or NULL if an error occurs during multiplication.
 */
matrix_t multiply_matrix(matrix_t mat1, matrix_t mat2);

/**
 * Create a new matrix that is a duplicate of the input matrix.
 *
 * @param mat The matrix to be duplicated.
 * @return A pointer to the duplicated matrix (matrix_t), or NULL if an error occurs during duplication.
 */
matrix_t copy_matrix(matrix_t mat);

/**
 * Free the memory occupied by a matrix. The matrix cannot be used after freeing.
 *
 * @param mat The matrix to be freed.
 */
void free_matrix(matrix_t mat);

/**
 * Calculate the determinant of the input matrix.
 *
 * @param mat The matrix for which the determinant is to be calculated.
 * @return The determinant of the matrix, or MATERR if the determinant cannot be calculated.
 */
double determinant_matrix(matrix_t mat);


/**
 * Calculate the adjugate of a matrix
 * @parm mat The matrix for which the adjugate is to be calculated
 * @return The adjugate of the matrix or NULL if an error occur 
 */

matrix_t adjugate(matrix_t mat);

/**
 * Calculate the scalar multiplication of a matrix with a  numble
 * @param mat The matrix to be multiplied
 * @param factor The numbe to use to multiply the matrix
 * @return The result matrix (matrix_t) or NULL if an error is encountered
 */

matrix_t scalar_mult(matrix_t mat, double factor);

/**
 * Calculate the inverse of a matrix
 * @param mat The matrix to find the inverse
 * @return The result inverse of the matrix (matrix_T)
 */

matrix_t invert_matrix(matrix_t mat);

/** 
 * Set the position of a matrix  to a given value
 * @param mat The matrix to set value
 * @param row The row position of the matrix
 * @param col The column position of the matrix
 * @param value The value to set the position of the matrix to
 */

void matrix_set_value(matrix_t mat, int row, int col, int value); 


/*
 * return the value at a position row, col in the  matrix
 * @param mat The matrix to get value from
 * @param row The row position of the matrix
 * @param col The column position of the matrix
 * @return the value at the position row, column of the matrix 
 */

double matrix_get_value(matrix mat, int row, int col); 






#endif
