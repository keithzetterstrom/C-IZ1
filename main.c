#include "matrix_work.h"


int main(int argc, char const *argv[])
{
    int strings = 3, columns = 3;

    int ** matrix = (int**)malloc(strings * sizeof(int*));
    for (int i = 0; i < strings; ++i)
        matrix[i] = (int*)malloc(columns * sizeof(int));

    create_matrix(matrix, strings, columns);

    int ** v = delete_nulls_from_matrix(matrix, strings, columns);

    return 0;
}
