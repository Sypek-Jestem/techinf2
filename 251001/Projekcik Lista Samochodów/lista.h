#ifndef LISTA_H
#define LISTA_H

#include <string>
#include <vector>

// Tutaj tworzymy "szablon" pojazdu – co każdy samochód ma
struct Samochod {
    std::string marka, model;
    int przebieg;
};

// Lista wszystkich samochodów (czyli "baza danych" w pamięci)
extern std::vector<Samochod> baza;

// Funkcje do pracy z listą samochodów:
void wczytaj();    // Wczytuje dane z pliku do listy
void zapisz();     // Zapisuje dane z listy do pliku
void dodaj();      // Dodaje nowy samochód
void edytuj();     // Edytuje istniejący samochód
void usun();       // Usuwa samochód
void wyswietl();   // Pokazuje wszystkie samochody

#endif
