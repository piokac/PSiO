#include "binarytree.h"
#include <algorithm>
void foo(const BinaryTree &tree)
{
    std::cout << tree["kot"]; //operator indeksowania [] dla stałej
}
int main()
{
    BinaryTree tree;

    std::string filename(R"(../../suplementary/license.txt)");

    std::fstream file(filename);
    while (!file.eof()) {
        std::string word;
        file >> word;
        tree[word]++; //operator indeksowania [] dla zmiennej
    }

    std::cout << tree; //operator<<(std::cout, tree);

    std::fstream output("stats.txt", std::ios::out);
    output << tree; //zapis do pliku

    std::vector<std::pair<std::string, int>> v
        = static_cast<std::vector<std::pair<std::string, int>>>(tree);
    using Node_pair = std::pair<std::string, int>;
    std::sort(v.begin(), v.end(), [](const Node_pair &el1, const Node_pair &el2) {
        return el1.second < el2.second;
    });

    for (auto [key, value] : v) {
        std::cout << key << "- " << value << std::endl;
    }
    BinaryTree tree2 = tree;

    tree2["xxxxxxx"]++;
    tree2["xxxxxxx"]++;

    std::cout << tree;

    return 0;
}
