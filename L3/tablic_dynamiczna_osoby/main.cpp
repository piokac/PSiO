#include <iostream>

struct Osoba
{
    char imie[30];
    char nazwisko[20];

    int wiek;
    char plec;
};
void pobierz(Osoba &o)
{
    std::cout << "podaj imie i nazwisko";
    std::cin >> o.imie >> o.nazwisko;

    std::cout << "podaj wiek: ";
    std::cin >> o.wiek;
    std::cout << "podaj plec: ";
    std::cin >> o.plec;
}
int main()
{
    Osoba *osoby;
    int n = 0;
    std::cout << "Ile osob chcesz wprowadzic?";
    std::cin >> n;

    osoby = new Osoba[n];

    for (int i = 0; i < n; i++)
        pobierz(osoby[i]);

    delete[] osoby; //usuwa liste
    return 0;
}
