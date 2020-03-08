#include "../include/matrix_work.h"


int ** delete_nulls_from_matrix(int ** matrix, int strings, int columns)
{
    if (matrix == NULL)
        return NULL;

    if (print_matrix(matrix, strings, columns))
        return NULL;

    int * array_of_count_elements = (int*)malloc(strings * sizeof(int));
    if (array_of_count_elements == NULL)
        return NULL;

    int result_count_strings = array_of_count_elements_initialization(matrix, array_of_count_elements, strings, columns);
    if (result_count_strings == -1)
        return NULL;

    int **result_vector = (int**)malloc(result_count_strings * sizeof(int*));
    if (!result_vector)
        return NULL;
    for(int i = 0; i < result_count_strings; i++)
    {
        result_vector[i] = (int *) malloc((array_of_count_elements[i]) * sizeof(int));
        if (!result_vector[i])
            return NULL;
    }

    if (result_vector_initialization(matrix, result_vector, strings, columns))
        return NULL;

    if (print_vector(result_vector, array_of_count_elements, result_count_strings))
        return NULL;

    free(array_of_count_elements);

    return result_vector;
}


int array_of_count_elements_initialization(const int ** matrix, int * array_of_count_elements, int strings, int columns)
{
    if (matrix == NULL || array_of_count_elements == NULL)
        return -1;

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


int result_vector_initialization(const int ** matrix, int ** result_vector, int strings, int columns)
{
    if (matrix == NULL || result_vector == NULL)
        return 1;

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
    return 0;
}


void matrix_free(int ** matrix, int strings)
{
    for (int i = 0; i < strings; ++i)
        free(matrix[i]);
    free(matrix);
}


int print_matrix(const int ** matrix, int strings, int columns)
{
    if (matrix == NULL)
        return 1;

    for (int i = 0; i < strings; ++i)
    {
        for (int j = 0; j < columns; ++j)
            printf("%i ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}

int print_vector(const int ** vector, const int * array_of_count_elements, int result_count_strings)
{
    if (vector == NULL || array_of_count_elements == NULL)
        return 1;
    for (int i = 0; i < result_count_strings; ++i)
    {
        for (int j = 0; j < array_of_count_elements[i]; ++j)
        {
            printf("%i ", vector[i][j]);
        }
        printf("\n");
    }

    return 0;
}