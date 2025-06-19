#include <iostream>
#include "lista.h"
using namespace std;

int main() {
    wczytaj();  // Przy uruchomieniu programu wczytujemy dane z pliku do listy

    int wybor;
    do {
        // Menu główne – wybieramy, co chcemy zrobić
        cout << "\n1. Dodaj Samochod\n2. Edytuj\n3. Usun\n4. Lista\n5. Zapisz\n0. Wyjdz\n\nWybor: ";
        cin >> wybor;

        // Sprawdzamy, czy użytkownik nie wpisał błędnych danych (np. litery)
        if (cin.fail()) {
            cin.clear();              // Resetujemy błąd
            cin.ignore(1000, '\n');   // Czyścimy bufor wejściowy
            cout << "Nieznana komenda!\n";
            continue;
        }

        // Obsługa wybranej opcji
        if (wybor == 1) dodaj();         // Dodaj nowy samochód
        else if (wybor == 2) edytuj();   // Edytuj istniejący
        else if (wybor == 3) usun();     // Usuń z listy
        else if (wybor == 4) wyswietl(); // Pokaż listę
        else if (wybor == 5) zapisz();   // Zapisz do pliku
        else if (wybor != 0)
            cout << "Nieznana komenda!\n"; // Błędny numer opcji

    } while (wybor != 0);

    zapisz();  // Po wyjściu zapisujemy dane
    return 0;
}
