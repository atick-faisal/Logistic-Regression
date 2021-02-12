#include "numc.h"

//----------------------- Matrix Implementation ----------------------//
static Matrix init_matrix(size_t rows, size_t cols) {
    Matrix matrix;
    double **x;
    x = malloc(rows * sizeof *x);
    for (int i = 0; i < rows; i++) {
        x[i] = malloc(cols * sizeof *x[i]);
    }
    matrix.data = x;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

Matrix create_matrix(size_t rows, size_t cols, const double *data) {
    Matrix matrix;
    double **x;
    int counter = 0;
    x = malloc(rows * sizeof *x);
    for (int i = 0; i < rows; i++) {
        x[i] = malloc(cols * sizeof *x[i]);
        for (int j = 0; j < cols; j++) {
            x[i][j] = *(data + counter);
            counter++;
        }
    }
    matrix.data = x;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

//-------------------- Zeros ----------------------//
Matrix zeros(size_t rows, size_t cols) {
    Matrix x = init_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            x.data[i][j] = 0.0;
        }
    }
    return x;
}

//------------------ Ones ---------------------//
Matrix ones(size_t rows, size_t cols) {
    Matrix x = init_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            x.data[i][j] = 1.0;
        }
    }
    return x;
}

//-------------------- Sum ---------------------//
double sum(Matrix A) {
    double sum = 0.0;
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; ++j) {
            sum += A.data[i][j];
        }
    }
    return sum;
}

//---------------------- Mean ---------------------//
double mean(Matrix A) {
    double sum = 0.0;
    double num_elements = (double) (A.rows * A.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; ++j) {
            sum += A.data[i][j];
        }
    }
    return sum / num_elements;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"
Matrix transpose(Matrix A) {
    Matrix T = init_matrix(A.cols, A.rows);
    for (int i = 0; i < A.cols; i++) {
        for (int j = 0; j < A.rows; ++j) {
            T.data[i][j] = A.data[j][i];
        }
    }
    T.rows = A.cols;
    T.cols = A.rows;
    return T;
}
#pragma clang diagnostic pop

Matrix mat_mul(Matrix A, Matrix B) {
    Matrix M = init_matrix(A.rows, B.cols);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; ++j) {
            for(int k = 0; k < B.rows; k++) {
                M.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return M;
}