#include "gtest/gtest.h"

extern "C"
{
    #include "include/matrix_work.h"
}

TEST(testMainFunc, test1)
{
    int strings = 3, columns = 3, result_count_strings = 3;

    int * array_of_count_elements = (int*)malloc(strings * sizeof(int));
    array_of_count_elements[0] = 3;
    array_of_count_elements[1] = 3;
    array_of_count_elements[2] = 3;

    int ** matrix = (int**)malloc(strings * sizeof(int*));
    for (int i = 0; i < strings; ++i)
        matrix[i] = (int*)malloc(columns * sizeof(int));

    int **result_vector = (int**)malloc(result_count_strings * sizeof(int*));
    for(int i = 0; i < result_count_strings; i++)
        result_vector[i] = (int*)malloc((array_of_count_elements[i]) * sizeof(int));

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    result_vector[0][1] = 2;
    result_vector[0][2] = 3;
    result_vector[1][0] = 4;
    result_vector[1][1] = 5;
    result_vector[1][2] = 6;
    result_vector[2][0] = 7;
    result_vector[2][1] = 8;
    result_vector[2][2] = 9;

    int ** test_vector = delete_nulls_from_matrix(matrix, strings, columns);
    ASSERT_EQ(result_vector[0][0], test_vector[0][0]);
    ASSERT_EQ(result_vector[1][0], test_vector[1][0]);
    ASSERT_EQ(result_vector[2][0], test_vector[2][0]);
}
