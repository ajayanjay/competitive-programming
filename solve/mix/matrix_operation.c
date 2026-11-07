#include <stdio.h>
#include <stdbool.h>

int main(void) {

    int m, n;

    scanf("%d %d", &m, &n);

    if (m < 0 || n < 0)
        return -1;

    int matrix[m][n];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %d", &matrix[i][j]);
        }
    }


    return 0;
}

void print_matrix(int matrix[][], int m, int n) {

}

void print_matrix_at(int matrix[][], int m, int n, int row, int col) {

}

void print_matrix_diagonal(int matrix[][], int m, int n, int row, int col) {

}

void print_matrix_upper_triangle(int matrix[][], int m, int n) {

}

void print_matrix_lower_triangle(int matrix[][], int m, int n) {

}

bool is_matrix_identity(int matrix[][], int m, int n) {

}

bool is_matrix_zero(int matrix[][], int m, int n) {

}

bool is_matrix_sparse(int matrix[][], int m, int n ) {

}

bool is_matrix_upper_triangle(int matrix[][], int m ,int n) {

}

bool is_matrix_lower_triangle(int matrix[][], int m, int n) {
    
}