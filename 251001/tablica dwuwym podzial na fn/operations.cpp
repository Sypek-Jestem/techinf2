#include <stdio.h>
#include "operations.h"

// Funkcja wyświetlająca menu
void menu(void) {
    printf("\n------------MENU---------------");
    printf("\n1 - Entering numbers to array");
    printf("\n2 - Displaying numbers from array");
    printf("\n3 - Calculate average value");
    printf("\n4 - Determine maximum value");
    printf("\n5 - Determine minimum value");
    printf("\n6 - Save array to file");
    printf("\n7 - Load array from file");
    printf("\n8 - EXIT");
}

// Funkcja pozwalająca użytkownikowi wprowadzić liczby do tablicy
void enterNumbers(int numbers[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("\nEnter value for element [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }
}

// Funkcja wyświetlająca wszystkie elementy tablicy w formie tabeli
void displayNumbers(int numbers[ROWS][COLS]) {
    printf("\nCurrent array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
}

// Funkcja obliczająca średnią wartość elementów tablicy
float calculateAverage(int numbers[ROWS][COLS]) {
    int sum = 0;
    int totalElements = ROWS * COLS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += numbers[i][j];
        }
    }

    float average = (float)sum / totalElements;
    printf("\nAverage: %.2f", average);
    return average;
}

// Funkcja wyznaczająca maksymalną wartość z tablicy
int maximumValue(int numbers[ROWS][COLS]) {
    int max = numbers[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (numbers[i][j] > max) {
                max = numbers[i][j];
            }
        }
    }
    printf("\nMaximum value is: %d", max);
    return max;
}

// Funkcja wyznaczająca minimalną wartość z tablicy
int minimumValue(int numbers[ROWS][COLS]) {
    int min = numbers[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (numbers[i][j] < min) {
                min = numbers[i][j];
            }
        }
    }
    printf("\nMinimum value is: %d", min);
    return min;
}

// Funkcja zapisująca tablicę do pliku tekstowego
void saveToFile(int numbers[ROWS][COLS]) {
    FILE *file = fopen("../array.txt", "w");

    if (file == NULL) {
        printf("\nError opening file for writing.\n");
        return;
    }

    // Zapisz tablicę do pliku w formie 2D
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, "%d ", numbers[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("\nArray has been saved to array.txt\n");
}

// Funkcja wczytująca tablicę z pliku tekstowego
void loadFromFile(int numbers[ROWS][COLS]) {
    FILE *file = fopen("../array.txt", "r");

    if (file == NULL) {
        printf("\nError opening file for reading.\n");
        return;
    }

    // Wczytaj tablicę z pliku
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%d", &numbers[i][j]);
        }
    }

    fclose(file);
    printf("\nArray has been loaded from array.txt\n");
}
