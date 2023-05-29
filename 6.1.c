#include <stdio.h>//підключення бібліотеки
#define MAX_SIZE 100
void replaceRowWithDiagonalSum(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int maxElementRow = 0;
    int maxElement = matrix[0][0];
    
    // Знаходимо рядок з максимальним елементом
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxElementRow = i;
            }
        }
    }
    
    int diagonalSum = 0;
    
    // Обчислюємо суму елементів бічної діагоналі
    for (int i = 0; i < n; i++) {
        diagonalSum += matrix[i][n - i - 1];
    }
    
    // Замінюємо рядок з максимальним елементом сумою елементів бічної діагоналі
    for (int j = 0; j < n; j++) {
        matrix[maxElementRow][j] = diagonalSum;
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;
    
    printf("Введіть розмірність матриці (n): ");
    scanf("%d", &n);
        printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    replaceRowWithDiagonalSum(matrix, n);
        printf("Матриця після заміни:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
