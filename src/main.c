#include "../include/matrix_work.h"


/* Составить программу обработки прямоугольной матрицы путем удаления ее нулевых элементов.
 * Обработку реализовать как построение вектора векторов (возможно, переменной длины),
 * каждый из которых содержит ненулевые элементы исходной матрицы, и оформить в виде функции,
 * принимающей на вход двойной указатель на матрицу и ее размеры по каждому измерению.
 * Конец каждого вектора должен быть задан указателем NULL.
 * На выход функция должна возвращать указатель на результирующую структуру.*/

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Enter count of strings and columns!");
        return 1;
    }

    int strings = atoi(argv[1]);
    int columns = atoi(argv[2]);
    char num_input[3], * end;

    int ** matrix = (int**)malloc(strings * sizeof(int*));
    if (matrix == NULL)
        return 1;
    for (int i = 0; i < strings; ++i)
    {
        matrix[i] = (int *) malloc(columns * sizeof(int));
        if (matrix[i] == NULL)
        {
            matrix_free(matrix, i);
            return 1;
        }
    }

    for (int i = 0; i < strings; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            fgets(num_input, 3, stdin);
            matrix[i][j] = strtol(num_input, &end, 10);
            memset(num_input, 0, 3);
        }
    }

    int ** result_vector = delete_nulls_from_matrix(matrix, strings, columns);
    if (result_vector == NULL)
    {
        matrix_free(matrix, strings);
        return 1;
    }

    matrix_free(result_vector, strings);

    matrix_free(matrix, strings);

    return 0;
}
