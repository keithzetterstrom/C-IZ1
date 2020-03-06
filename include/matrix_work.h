#ifndef IZ1_MATRIX_WORK_H
#define IZ1_MATRIX_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int array_of_count_elements_initialization(int ** matrix, int * arrey_of_count_elements, int strings, int columns);
void result_vector_initialization(int ** matrix, int ** result_vector, int strings, int columns);
int ** delete_nulls_from_matrix(int ** matrix, int strings, int columns);
void matrix_free(int ** matrix, int strings);
void create_matrix(int ** matrix, int strings, int columns);
void print_matrix(int ** matrix, int strings, int columns);

#endif //IZ1_MATRIX_WORK_H
