#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int arrey_of_count_elements_initialization(int ** matrix, int * arrey_of_count_elements, int strings, int columns);
void result_vector_initialization(int ** matrix, int ** result_vector, int strings, int columns);
int ** delete_nulls_from_matrix(int ** matrix, int strings, int columns);
void create_matrix(int ** matrix, int strings, int columns);
void print_matrix(int ** matrix, int strings, int columns);


int main(int argc, char const *argv[])
{
    int N = 3, M = 3;

    int ** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i)
        matrix[i] = (int*)malloc(M * sizeof(int));

    create_matrix(matrix, N, M);

    int ** v = delete_nulls_from_matrix(matrix, N, M);

    return 0;
}


int ** delete_nulls_from_matrix(int ** matrix, int strings, int columns)
{
    int * arrey_of_count_elements = (int*)malloc(strings * sizeof(int));

    print_matrix(matrix, strings, columns);

    int result_count_strings = arrey_of_count_elements_initialization(matrix, arrey_of_count_elements, strings, columns);

    int **result_vector = (int**)malloc(result_count_strings * sizeof(int*));
    for(int i = 0; i < result_count_strings; i++)
        result_vector[i] = (int*)malloc((arrey_of_count_elements[i] + 1) * sizeof(int));

    result_vector_initialization(matrix, result_vector, strings, columns);

    for (int i = 0; i < result_count_strings; ++i)
    {
        for (int j = 0; j < arrey_of_count_elements[i]; ++j)
        {
            printf("%i ", result_vector[i][j]);
        }
        printf("\n");
    }

    return result_vector;
}


int arrey_of_count_elements_initialization(int ** matrix, int * arrey_of_count_elements, int strings, int columns)
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
            arrey_of_count_elements[result_count_strings] = elements_in_strings;
            result_count_strings++;
            elements_in_strings = 0;
        }
    }

    return result_count_strings;
}


void result_vector_initialization(int ** matrix, int ** result_vector, int strings, int columns)
{
    for (int i = 0, k = 0; i < strings; ++i)
    {
        for (int j = 0, l = 0; j < columns; ++j)
        {
            if (matrix[i][j] != 0)
            {
                result_vector[k][l] = matrix[i][j];
                l++;
            }
        }
        //result_vector[k][l++] = NULL;
        k++;
    }
}


void create_matrix(int ** matrix, int strings, int columns)
{
    srand(time(NULL));

    for (int i = 0; i < strings; ++i)
    {
        for (int j = 0; j < columns; ++j)
            matrix[i][j] = rand() % 9;
    }
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