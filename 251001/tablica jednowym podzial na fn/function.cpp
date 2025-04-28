#include <stdio.h>
#include "function.h"



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

// Funkcja wprowadzająca liczby o tablicy
void enterNumbers(int numbers[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("\nEnter value for element %d: ", i);
        scanf("%d", &numbers[i]);
    }
}

// Funkcja wyświetlająca wszystkie elementy tablicy
void displayNumbers(int numbers[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("\nElement %d: %d", i, numbers[i]);
    }
}

// Funkcja obliczająca średnią wartość elementów tablicy
float calculateAverage(int numbers[]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += numbers[i];
    }
    float average = (float) sum / SIZE;
    printf("\nAverage: %.2f", average);
    return average;
}

// Funkcja wyznaczająca maksymalną wartość z tablicy
int maximumValue(int numbers[]) {
    int max = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    printf("\nMaximum value is: %d", max);
    return max;
}

// Funkcja wyznaczająca minimalną wartość z tablicy
int minimumValue(int numbers[]) {
    int min = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    printf("\nMinimum value is: %d", min);
    return min;
}

// Funkcja zapisująca tablicę do pliku tekstowego
void saveToFile(int numbers[]) {
    FILE *file = fopen("../array.txt", "w");

    if (file == NULL) {
        printf("\nError opening file for writing.\n");
        return;
    }

    // Zapisz wszystkie elementy tablicy do pliku
    for (int i = 0; i < SIZE; i++) {
        fprintf(file, "Element %d: %d\n", i, numbers[i]);
    }

    fclose(file);
    printf("\nArray has been saved to array.txt\n");
}

// Funkcja wczytująca tablicę z pliku tekstowego
void loadFromFile(int numbers[]) {
    FILE *file = fopen("../array.txt", "r");

    if (file == NULL) {
        printf("\nError opening file for reading.\n");
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        if (fscanf(file, "Element %d: %d\n", &i, &numbers[i]) != 2) {
            printf("\nError reading file. The format of the file might be incorrect.\n");
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("\nArray has been loaded from array.txt\n");
}
