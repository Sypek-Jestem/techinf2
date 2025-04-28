#include <stdio.h>


void male_litery(char* ciag) {
    while (*ciag) {
        if (*ciag >= 'A' && *ciag <= 'Z') {
            *ciag = *ciag - ('A' - 'a');
        }
        ciag++;
    }
}


void wielkie_litery(char* ciag) {
    while (*ciag) {
        if (*ciag >= 'a' && *ciag <= 'z') {
            *ciag = *ciag - ('a' - 'A');
        }
        ciag++;
    }
}

void policz_znaki(const char* ciag) {
    int wszystkie = 0, litery = 0;
    while (*ciag) {
        wszystkie++;
        if ((*ciag >= 'A' && *ciag <= 'Z') || (*ciag >= 'a' && *ciag <= 'z'))
            litery++;
        ciag++;
    }
    printf("Wszystkich znakow: %d\n", wszystkie);
    printf("Liczba liter: %d\n", litery);
}


void dodaj_lancuchy(const char* lancuch1, const char* lancuch2, char* wynik) {
    while (*lancuch1) {
        *wynik++ = *lancuch1++;
    }
    while (*lancuch2) {
        *wynik++ = *lancuch2++;
    }
    *wynik = '\0'; // zakończenie
}

int main(int argc, char const* argv[]) {
    char tekst[] = "!!Agent 47!! ";
    printf("%s\n", tekst);

    male_litery(tekst);
    printf("%s\n", tekst);

    wielkie_litery(tekst);
    printf("%s\n", tekst);



    char dodatkowy[] = " Jak dzeremi dzeremi!!!";
    char wynik[200];

    dodaj_lancuchy(tekst, dodatkowy, wynik);
    printf("%s\n", wynik);

    policz_znaki(wynik);
    return 0;
}
