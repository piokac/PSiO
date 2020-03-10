#include <algorithm>
#include <iostream>
#include <vector>
//using namespace std;

int main()
{
    std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
    //sortowanie przez wstawianie
    for (std::vector<int>::iterator it = v.begin() + 1; it != v.end(); it++) {
        std::vector<int>::iterator pos = std::upper_bound(v.begin(), it, *it);
        std::rotate(pos, it, it + 1);
    }
    //wyswietlenie wyniku
    for (int &el : v) {
        std::cout << el << std::endl;
    }
    return 0;
}
