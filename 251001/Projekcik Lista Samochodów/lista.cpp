#include "lista.h"
#include <iostream>
#include <fstream>
using namespace std;

// Lista (wektor) przechowująca wszystkie dane o samochodach
vector<Samochod> baza;

// Wczytanie danych z pliku do listy – jeśli plik istnieje, to go czytamy
void wczytaj() {
    baza.clear(); // Czyścimy listę, żeby nie było duplikatów
    ifstream plik("baza.txt");
    Samochod s;
    // Wczytujemy po jednej linii każdy samochód
    while (plik >> s.marka >> s.model >> s.przebieg)
        baza.push_back(s);
    plik.close();
}

// Zapisanie danych z listy do pliku – wszystko nadpisuje
void zapisz() {
    ofstream plik("baza.txt");
    for (auto& s : baza)
        plik << s.marka << " " << s.model << " " << s.przebieg << "\n";
    plik.close();
}

// Dodajemy nowy samochód – użytkownik podaje dane
void dodaj() {
    Samochod s;
    cout << "Marka: "; cin >> s.marka;
    cout << "Model: "; cin >> s.model;
    cout << "Przebieg: "; cin >> s.przebieg;
    baza.push_back(s); // Dodajemy do listy
}

// Edytujemy dane już istniejącego samochodu (na podstawie numeru z listy)
void edytuj() {
    int i;
    cout << "Index do edycji: "; cin >> i;
    if (i >= 0 && i < baza.size()) {
        cout << "Nowa marka: "; cin >> baza[i].marka;
        cout << "Nowy model: "; cin >> baza[i].model;
        cout << "Nowy przebieg: "; cin >> baza[i].przebieg;
    } else {
        cout << "Nieprawidlowy index!\n";
    }
}

// Usuwamy samochód z listy – podając jego numer z listy
void usun() {
    int i;
    cout << "Index do usuniecia: "; cin >> i;
    if (i >= 0 && i < baza.size())
        baza.erase(baza.begin() + i); // Usuwamy z listy
    else
        cout << "Nieprawidlowy index!\n";
}

// Wyświetlamy wszystkie zapisane samochody
void wyswietl() {
    if (baza.empty()) {
        cout << "Brak danych.\n";
        return;
    }
    for (int i = 0; i < baza.size(); i++)
        cout << i << ": " << baza[i].marka << " " << baza[i].model << " " << baza[i].przebieg << " km\n";
}
