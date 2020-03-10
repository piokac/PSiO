#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//using namespace std;
//przeszukiwanie binarne uporządkowanego kontenera
size_t find_bin(std::string word, const std::vector<std::string> &dict)
{
    size_t start = 0;
    size_t end = dict.size() - 1;

    do {
        size_t mid = (start + end) / 2;

        if (word == dict[mid])
            return mid;
        if (word > dict[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    } while (start <= end);
    return std::string::npos;
}
//przeszukiwanie sekwencyjne po elementach
size_t find(const std::string &word, const std::vector<std::string> &dict)
{
    size_t pos = 0;
    for (const std::string &el : dict) {
        if (word == el)
            return pos;
        pos++;
    }
    std::cout << "nie znaleziono" << std::endl;
    return std::string::npos;
}
int main()
{
    std::vector<std::string> dict;

    std::fstream file("../../suplementary/slowa.txt");
    if (file.is_open()) {
        std::string word;
        while (getline(file, word)) {
            dict.push_back(word);
        }

        std::cout << "sequential search example" << std::endl;
        auto now = std::chrono::system_clock::now();
        std::cout << find("zebra\r", dict) << std::endl;
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = end - now;
        std::cout << "sequential search duration: " << duration.count() << std::endl;

        std::cout << "binary search example" << std::endl;
        now = std::chrono::system_clock::now();
        std::cout << find_bin("zebra\r", dict) << std::endl;
        end = std::chrono::system_clock::now();
        duration = end - now;
        std::cout << "binary search duration: " << duration.count() << std::endl;
    }
    return 0;
}
