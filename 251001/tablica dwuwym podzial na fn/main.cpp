#include <stdio.h>
#include "operations.h"

int main() {
    int numbers[ROWS][COLS] = {{15, 3, 36}, {42, 58, 22}, {95, 44, 76}};
    int option;
    char cycle = 'T';

    while (cycle == 'T' || cycle == 't') {
        menu();
        printf("\nChoose option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enterNumbers(numbers);
                break;
            case 2:
                displayNumbers(numbers);
                break;
            case 3:
                calculateAverage(numbers);
                break;
            case 4:
                maximumValue(numbers);
                break;
            case 5:
                minimumValue(numbers);
                break;
            case 6:
                saveToFile(numbers);
                break;
            case 7:
                loadFromFile(numbers);
                break;
            case 8:
                printf("\nExiting the program.\n");
                return 0;
            default:
                printf("\nChoose a correct option...");
                break;
        }

        printf("\nDo you want to continue using the application? (T/N): ");
        getchar();
        scanf("%c", &cycle);
    }

    return 0;
}

