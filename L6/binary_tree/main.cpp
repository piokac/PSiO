#include "binarytree.h"
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

    //    std::vector<std::pair<std::string, int>> v
    //        = static_cast<std::vector<std::pair<std::string, int>>>(tree);

    //    for (auto [key, value] : v) {
    //        std::cout << key << std::endl;
    //    }

    return 0;
}
