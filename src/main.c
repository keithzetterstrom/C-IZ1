#include "../include/matrix_work.h"


/* Составить программу обработки прямоугольной матрицы путем удаления ее нулевых элементов.
 * Обработку реализовать как построение вектора векторов (возможно, переменной длины),
 * каждый из которых содержит ненулевые элементы исходной матрицы, и оформить в виде функции,
 * принимающей на вход двойной указатель на матрицу и ее размеры по каждому измерению.
 * Конец каждого вектора должен быть задан указателем NULL.
 * На выход функция должна возвращать указатель на результирующую структуру.*/

int main(int argc, char const *argv[])
{
    int strings = 3, columns = 2;

    int ** matrix = (int**)malloc(strings * sizeof(int*));
    for (int i = 0; i < strings; ++i)
        matrix[i] = (int*)malloc(columns * sizeof(int));

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][1] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 2;

    int ** result_vector = delete_nulls_from_matrix(matrix, strings, columns);

    matrix_free(result_vector, strings);

    matrix_free(matrix, strings);

    return 0;
}
