// If an element in an MxN matrix is 0, its entire row and column is set to 0.
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _IntMatrix {
  size_t row_size;
  size_t column_size;
  int **data;
} IntMatrix;

// Free a matrix.
void matrix_free(IntMatrix *matrix) {
  for (int i = 0; i < matrix->row_size; ++i) free(matrix->data[i]);
  free(matrix->data);
  matrix->data = NULL;
}

// Initialize a matrix.
// @in matrix: Pointer to the matrix that needs to be initialized.
// @in row_size: The row size of the matrix.
// @in column_size: The column_size of the matrix.
// @return: 0 if the matrix is successfully initialized. 1 if error on
//   allocating memory.
int matrix_init(IntMatrix *matrix, size_t row_size, size_t column_size) {
  int result = 0;
  matrix->row_size = row_size;
  matrix->column_size = column_size;
  matrix->data = (int **) malloc(sizeof(int*) * row_size);
  if (matrix->data == NULL) return 1;
  for (int i = 0; i < row_size; ++i) matrix->data[i] = NULL;
  for (int i = 0; i < row_size; ++i) {
    matrix->data[i] = (int *) malloc(sizeof(int) * column_size);
    if (matrix->data[i] == NULL) {
      result = 1;
      break;
    }
  }
  if (result == 1) {
    matrix_free(matrix);
  }
  return result;
}

void matrix_print(IntMatrix matrix) {
  for (size_t i = 0; i < matrix.row_size; ++i) {
    for (size_t j = 0; j < matrix.column_size; ++j) {
      printf("%d ", matrix.data[i][j]);
    }
    printf("\n");
  }
}

// If an element in an MxN matrix is 0, its entire row and column is set to 0.
void matrix_set_zero(IntMatrix *matrix) {
  int *row_mark = (int *) malloc(matrix->row_size*sizeof(int));
  for (size_t i = 0; i < matrix->row_size; ++i) row_mark[i] = 0;
  int *column_mark = (int *) malloc(matrix->column_size*sizeof(int));
  for (size_t i = 0; i < matrix->column_size; ++i) column_mark[i] = 0;

  for (size_t i = 0; i < matrix->row_size; ++i) {
    for (size_t j = 0; j < matrix->column_size; ++j) {
      if (matrix->data[i][j] == 0) {
        row_mark[i] = 1;
        column_mark[j] = 1;
      }
    }
  }
  for (size_t i = 0; i < matrix->row_size; ++i) {
    if (row_mark[i] == 1) {
      for (size_t j = 0; j < matrix->column_size; ++j) {
        matrix->data[i][j] = 0;
      }
    }
  }
  for (size_t j = 0; j < matrix->column_size; ++j) {
    if (column_mark[j] == 1) {
      for (size_t i = 0; i < matrix->row_size; ++i) {
        matrix->data[i][j] = 0;
      }
    }
  }
  free(column_mark);
  free(row_mark);
}

int main() {
  IntMatrix matrix;
  if (0 != matrix_init(&matrix, 3, 4)) {
    return 1;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      matrix.data[i][j] = i+j;
    }
  }
  matrix_print(matrix);
  matrix_set_zero(&matrix);
  matrix_print(matrix);
  matrix_free(&matrix);
}
