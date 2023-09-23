#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct matrix{
    int row;
    int col;
    double ** data;
};

static double _determinant_matrix(matrix_t mat);

matrix_t create_matrix(int row, int col){

    matrix_t new_matrix = malloc(sizeof(*new_matrix));
    if(new_matrix == NULL) return NULL;
    double ** data;
    new_matrix->col = col;
    new_matrix->row = row;
    data  = malloc(row * sizeof(double *));
    if(data == NULL) {
        free_matrix(new_matrix);
        return NULL;
    }
    for(int i =0; i < row; i++){
       data[i] = calloc(col, sizeof(double)); 
       if(data[i] == NULL){
           for(int j = 0; j < i; j++ ) free(data[j]);
           free(data);
           return NULL;
       }
    }
    new_matrix->data = data;
    return new_matrix;
}

matrix_t add_matrix(matrix_t mat1, matrix_t mat2){
    if((mat1->col != mat2->col) || (mat1->row != mat2->row)){
        return NULL;
    }
    matrix_t result = create_matrix(mat1->row, mat2->col);
    if(result == NULL) return NULL;
    for(int i = 0; i < result->row; i++){
        for(int j = 0; j < result->col; j++){
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
} 

matrix_t subtract_matrix(matrix_t mat1, matrix_t mat2){
    if((mat1 == NULL)|| (mat2 == NULL) || (mat1->col != mat2->col) || (mat1->row != mat2->row)){
        return NULL;
    }

    matrix_t result = create_matrix(mat1->row, mat2->col);
    if(result == NULL) return NULL;
    double **rdata = result->data;
    double **m1data = mat1->data;
    double **m2data = mat2->data;

    for(int i = 0; i < result->row; i++){
        for(int j = 0; j < result->col; j++){
            rdata[i][j] = m1data[i][j] - m2data[i][j];
        }
    }
    return result;
} 


matrix_t multiply_matrix(matrix_t mat1, matrix_t mat2){
    if (( mat1 == NULL )|| (mat2 == NULL) ||(mat1->col != mat2->row)) return NULL;
    matrix_t result = create_matrix(mat1->row, mat2->col); 
    if(result == NULL) return NULL;

    double **rdata = result->data;
    double **m1data = mat1->data;
    double **m2data = mat2->data;

    for(int i = 0; i < mat1->row; i++){
        for(int j = 0; j < mat2->col; j++){
            double product = 0;
            for(int k = 0; k  < mat1->col; k++)
                product += m1data[i][k] * m2data[k][j];
           rdata[i][j] = product;
        }
    }
        return result;
}


void matrix_set_value(matrix_t mat, int row, int col, double value) 
{
    if( mat == NULL) return;
    mat->data[row][col] = value; 
}

double matrix_get_value(matrix_t mat, int row, int col){
    if(mat == NULL) return MATERR;
    return mat->data[row][col];
}


void free_matrix(matrix_t mat){
    if(mat){
        for(int i =0; i<mat->row; i++){
            free(mat->data[i]);
        }
        free(mat->data);
        free(mat);
    }
} 


matrix_t invert_matrix(matrix_t mat){
    if(mat == NULL || mat->row != mat->col) return NULL;
    matrix_t adj = adjugate(mat);
    if(adj == NULL) return NULL;
    double det = determinant_matrix(mat); 
    if(det == MATERR || det == 0) return NULL;

    else return scalar_mult(adj, 1/det);
}

matrix_t copy_matrix(matrix_t mat){
    if(mat == NULL) return NULL;

    matrix_t new_matrix = create_matrix(mat->row, mat->col);
    
    if(new_matrix == NULL) return NULL;
    int row = mat->row, col = mat->col;
    double **data = mat->data;
    double ** nm_data = new_matrix->data;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            nm_data[i][j] = data[i][j];
        }
    }
    return new_matrix;
}

double determinant_matrix(matrix_t mat){
     matrix_t cp_matrix = copy_matrix(mat);
     if(cp_matrix == NULL) return MATERR; 
     return _determinant_matrix(cp_matrix);
}

double _determinant_matrix(matrix_t mat){
    if(mat == NULL) return MATERR;
    if(mat->row != mat->col) return MATERR; //check if square matrix
                                            
    double ** data = mat->data;
    int num = mat->row;

    if(num== 2){ 
        int result = (data[0][0] * data[1][1] - data[0][1] * data[1][0]);
        free_matrix(mat);
        return result;
    }

    matrix_t minor = create_matrix(num-1, num-1); 
    if(minor == NULL) return MATERR;

    int shift = 1;
    int minor_row = 0, minor_col =0;
    int result = 0;
    double ** mdata = minor->data; //minor data

    for(int min =0; min < num; min++){
        for(int i = 1; i < num; i++){
            for(int j = 0; j < num; j++){
                if(j ==min) continue;

                mdata[minor_row][minor_col] =  data[i][j];
                minor_col++;

                if(minor_col == num){
                    minor_col = 0; 
                    minor_row++;
                }
            }
        }

        result += shift * data[0][min] *determinant_matrix(minor);
        shift *= -1;
    }
    free_matrix(minor);
    return result;
}

matrix_t scalar_mult(matrix_t mat, double factor){
    if(mat == NULL) return NULL;
    matrix_t new_matrix = create_matrix(mat->row, mat->col);
    if(new_matrix == NULL) return NULL;

    for(int i = 0; i < mat->row; i++){
        for(int j = 0; j < mat->col; j++)
            new_matrix->data[i][j] = mat->data[i][j] * factor;
    }
    return new_matrix;
}


matrix_t adjugate(matrix_t mat){
    if(mat  == NULL || mat->row != mat->col) return NULL; 
    int n = mat->row;
    matrix_t adj_matrix = create_matrix(n, n); 

    if(adj_matrix == NULL) return NULL; 
    matrix_t minor = create_matrix(n-1, n-1);
        if(minor == NULL){
            free_matrix(adj_matrix);
            return NULL;
        }
    //calculate co_factor

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            for(int row = 0, new_row = 0; row < n; row++){
                if(row ==i) continue;
                for(int col = 0, new_col = 0; col <n; col++){
                    if(col == j) continue;

                    minor->data[new_row][new_col] = mat->data[row][col];
                    new_col++;
                }
                new_row++;
            }
            int det =  determinant_matrix(minor);
            adj_matrix->data[j][i]= ((i+j) & 1)? - det : det;
        }
    }
    free_matrix(minor);
    return adj_matrix;
    
}




