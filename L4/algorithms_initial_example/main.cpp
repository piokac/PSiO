#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int f()
{
    return rand() % 10;
}

int main()
{
    std::vector<int> tab(10);
    std::generate(tab.begin(), tab.end(), f); //uses f() function to initialize every element

    std::list<int> list_ex(5);
    std::generate(list_ex.begin(), list_ex.end(), std::rand); //runs the std::rand as predicate

    //sorts array in ascending order
    sort(tab.begin(), tab.end());

    //append elements from tab to end of list
    copy(tab.begin(), tab.end(), back_inserter(list_ex));

    //std::list cannot be sorted using std::sort because it does not have random acces iterator
    list_ex.sort();

    for (auto &el : list_ex) {
        std::cout << el << std::endl;
    }
    return 0;
}
