#include <cmath>
#include <iostream>
#include <vector>
//using namespace std;
int find_min(const std::vector<int> &tab_stl)
{
    int min;

    min = tab_stl[0];
    for (const int &el : tab_stl) {
        if (el < min) {
            min = el;
        }
    }
    return min;
}

int count_elements(const std::vector<int> &tab_stl, int value)
{
    int counter = 0;
    for (const int &el : tab_stl) {
        if (el == value) {
            counter++;
        }
    }
    return counter;
}

bool is_prime_number(int N)
{
    bool czy_podzielnik = false;
    for (int i = 2; i < sqrt(N) && czy_podzielnik == false; i++) {
        if (N % i == 0) {
            czy_podzielnik = true;
        }
    }
    return !czy_podzielnik;
}

int main()
{
    std::vector<int> tab_stl(100);
    int min;
    //inicjacja tablicy stl
    for (size_t i = 0; i < tab_stl.size(); i++)
        tab_stl[i] = rand() % 10;

    //znajdywanie minimum
    min = find_min(tab_stl);
    std::cout << "Wartość minimalna: " << min << std::endl;

    //zliczanie liczby elementów o danej wartości
    int number_to_find = 3;
    int count = count_elements(tab_stl, number_to_find);
    std::cout << "Liczba " << number_to_find << " wystepuje: " << count << " razy" << std::endl;

    //liczba pierwsza
    std::cout << "Podaj liczbe:";
    int number;
    std::cin >> number;
    std::cout << "liczba jest pierwsza: " << is_prime_number(number);

    return 0;
}
