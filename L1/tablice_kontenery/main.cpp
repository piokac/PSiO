#include <fstream>
#include <iostream>
#include <vector>
//using namespace std;

int main()
{
    int tab[100];
    std::vector<int> tab_stl(100);

    for (int i = 0; i < 100; i++)
        tab_stl[i] = std::rand();
    for (std::vector<int>::iterator it = tab_stl.begin(); it != tab_stl.end(); it++)
        std::cin >> *it;

    //użycie pętli while do odczytu pliku linia po lini
    std::fstream file("/home/piotr/license.txt");
    if (file.is_open()) {
        std::string text_line;
        while (getline(file, text_line)) {
            std::cout << text_line << std::endl;
        }

    } else {
        std::cout << "file does not exists" << std::endl;
    }
    //użycie pętli do while do pobrania właściwej odpowiedzi od użytkownika
    char answer;
    do {
        std::cout << "czy chcesz kontynuowac(t/n)??";
        std::cin >> answer;
    } while (!(answer == 't' || answer == 'T' || answer == 'n' || answer == 'N'));

    if (answer == 't' || answer == 'T') {
        std::cout << "opdowiedziales tak...." << std::endl;
    } else {
        std::cout << "odpowiedziales nie..." << std::endl;
    }
    return 0;
}
