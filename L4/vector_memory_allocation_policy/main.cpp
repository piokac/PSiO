#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> tab;
    for (int i = 0; i < 100; i++) {
        tab.emplace_back(rand() % 100);

        //prints number of elements and allocated size of the tab vector
        std::cout << tab.size() << " - " << tab.capacity() << std::endl;
    }

    return 0;
}
