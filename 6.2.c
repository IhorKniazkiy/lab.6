#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3 // Розмір квадратної матриці

int main() {
    // Ініціалізація генератора псевдовипадкових чисел
    srand(time(NULL));

    // Створення та заповнення матриці псевдовипадковими числами
    int matrix[SIZE][SIZE];
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 201 - 100; // Відрізок [-100, 100]
        }
    }

    // Виведення початкової матриці
    printf("Початкова матриця:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Знаходження рядка з найбільшим елементом
    int maxRowIndex = 0;
    int maxRowElement = matrix[0][0];

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] > maxRowElement) {
                maxRowElement = matrix[i][j];
                maxRowIndex = i;
            }
        }
    }

    // Знаходження стовпчика з найменшим елементом
    int minColumnIndex = 0;
    int minColumnElement = matrix[0][0];

    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE; i++) {
            if (matrix[i][j] < minColumnElement) {
                minColumnElement = matrix[i][j];
                minColumnIndex = j;
            }
        }
    }

    // Обчислення скалярного добутку
    int scalarProduct = 0;
    for (j = 0; j < SIZE; j++) {
        scalarProduct += matrix[maxRowIndex][j] * matrix[j][minColumnIndex];
    }

    // Виведення результату
    printf("Скалярний добуток рядка з найбільшим елементом та стовпчика з найменшим елементом: %d\n", scalarProduct);

    return 0;
}