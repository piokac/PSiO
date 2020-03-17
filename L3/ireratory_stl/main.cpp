#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    std::vector<double> tab = {1, 4, 8, 9};
    //std::list<double> tab = {1, 4, 8, 9};

    //petla dzialająca niezależnie od typu kontenera
    for (auto it = tab.begin(); it != tab.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
