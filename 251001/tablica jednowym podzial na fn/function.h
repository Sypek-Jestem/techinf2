#ifndef FUNCTION_H
#define FUNCTION_H

#define SIZE 10

void menu(void);
void enterNumbers(int numbers[]);
void displayNumbers(int numbers[]);
float calculateAverage(int numbers[]);
int maximumValue(int numbers[]);
int minimumValue(int numbers[]);
void saveToFile(int numbers[]);
void loadFromFile(int numbers[]);

#endif

