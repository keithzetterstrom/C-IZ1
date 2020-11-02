#ifndef IZ1_MATRIX_WORK_H
#define IZ1_MATRIX_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int array_of_count_elements_initialization(const int ** matrix, int * array_of_count_elements, int strings, int columns);
int result_vector_initialization(const int ** matrix, int ** result_vector, int strings, int columns);
int ** delete_nulls_from_matrix(int ** matrix, int strings, int columns);
void matrix_free(int ** matrix, int strings);
int print_matrix(const int ** matrix, int strings, int columns);
int print_vector(const int ** vector, const int * array_of_count_elements, int result_count_strings);

#endif //IZ1_MATRIX_WORK_H
