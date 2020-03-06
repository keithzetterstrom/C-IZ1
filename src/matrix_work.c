#include "../include/matrix_work.h"


int ** delete_nulls_from_matrix(int ** matrix, int strings, int columns)
{
    int * array_of_count_elements = (int*)malloc(strings * sizeof(int));

    print_matrix(matrix, strings, columns);

    int result_count_strings = array_of_count_elements_initialization(matrix, array_of_count_elements, strings, columns);

    int **result_vector = (int**)malloc(result_count_strings * sizeof(int*));
    for(int i = 0; i < result_count_strings; i++)
        result_vector[i] = (int*)malloc((array_of_count_elements[i]) * sizeof(int));

    result_vector_initialization(matrix, result_vector, strings, columns);

    for (int i = 0; i < result_count_strings; ++i)
    {
        for (int j = 0; j < array_of_count_elements[i]; ++j)
        {
            printf("%i ", result_vector[i][j]);
        }
        printf("\n");
    }

    free(array_of_count_elements);

    return result_vector;
}


int array_of_count_elements_initialization(int ** matrix, int * array_of_count_elements, int strings, int columns)
{
    int elements_in_strings = 0, result_count_strings = 0;

    for (int i = 0; i < strings; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (matrix[i][j] != 0)
                elements_in_strings++;
        }
        if (elements_in_strings)
        {
            array_of_count_elements[result_count_strings] = elements_in_strings;
            result_count_strings++;
            elements_in_strings = 0;
        }
    }

    return result_count_strings;
}


void result_vector_initialization(int ** matrix, int ** result_vector, int strings, int columns)
{
    for (int i = 0, k = 0, flag = 0; i < strings; ++i)
    {
        for (int j = 0, l = 0; j < columns; ++j)
        {
            if (matrix[i][j] != 0)
            {
                result_vector[k][l] = matrix[i][j];
                l++;
                flag++;
            }
        }
        if (flag)
            ++k;
        flag = 0;
    }
}


void matrix_free(int ** matrix, int strings)
{
    for (int i = 0; i < strings; ++i)
        free(matrix[i]);
    free(matrix);
}


void print_matrix(int ** matrix, int strings, int columns)
{
    for (int i = 0; i < strings; ++i)
    {
        for (int j = 0; j < columns; ++j)
            printf("%i ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}