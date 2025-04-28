#ifndef OPERATIONS_H
#define OPERATIONS_H

#define ROWS 3
#define COLS 3

void menu(void);
void enterNumbers(int numbers[ROWS][COLS]);
void displayNumbers(int numbers[ROWS][COLS]);
float calculateAverage(int numbers[ROWS][COLS]);
int maximumValue(int numbers[ROWS][COLS]);
int minimumValue(int numbers[ROWS][COLS]);
void saveToFile(int numbers[ROWS][COLS]);
void loadFromFile(int numbers[ROWS][COLS]);

#endif

