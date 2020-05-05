#include <iostream>
#include <list>
#include <vector>
using namespace std;
bool change_greedy(const std::list<int> &denominations, int change_value, std::list<int> &solution)
{
    std::list<int> denomination_queue = denominations;
    while (denomination_queue.size() > 0 && change_value > 0) {
        int value = *denomination_queue.begin();
        denomination_queue.pop_front();
        if (change_value > value) {
            solution.emplace_back(value);
            change_value = change_value - value;
        }
    }
    return (change_value == 0);
}

bool change_dfs(const std::list<int> &denominations, int change_value, std::list<int> &solution)
{
    std::list<int> denomination_queue = denominations;
    while (denomination_queue.size() > 0 && change_value > 0) {
        int value = *denomination_queue.begin();
        denomination_queue.pop_front();

        if (change_value - value == 0) {
            solution.emplace_back(value);
            return true;
        }
        if (change_value > value) {
            bool res = change_dfs(denomination_queue, change_value - value, solution);
            if (res == true) {
                solution.emplace_back(value);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    std::list<int> denomination = {5, 5, 2, 2, 2};
    std::list<int> result;
    if (change_dfs(denomination, 6, result)) {
        std::cout << "result found: ";
        for (const auto &el : result)
            std::cout << el << ", ";

    } else {
        std::cout << "result not found" << endl;
    }
    return 0;
}
