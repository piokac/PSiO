#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <fstream>
#include <iostream>
#include <vector>

class BinaryTree
{
    using VectorConv = std::vector<std::pair<std::string, int>>;

private:
    struct Node
    {
        Node(const std::string &key, const int &val)
            : word(key), counter(val), l(nullptr), r(nullptr)
        {}
        std::string word; //klucz węzła
        int counter;      //wartość węzła
        Node *l;          //wskaźnik do lewego poddrzewa
        Node *r;          //wskaźnik do prawego poddrzewa
    };
    Node *root_;
    Node *create(const std::string &key, const int &val); //tworzy nowy węzeł drzewa
    Node *find(Node *node, const std::string &key);       //znajduje i dodaje nowy węzeł drzewa
    const Node *find(const Node *node, const std::string &key)
        const; //stała metoda, znajduje nowy węzeł drzewa, jeśli nie istnieje zwraca wyjątek std::ot_of_range
    void print(const Node *node, std::ostream &str)
        const; //wyświetla rekursywnie wszystkie poddrzewo w kolejności rosnącej wg klucza
    void dump(const Node *node, VectorConv &output) const;
    void release(const Node *node);
    void copy(const Node *node);

public:
    BinaryTree();
    BinaryTree(const BinaryTree &src);
    BinaryTree operator=(const BinaryTree &src);
    ~BinaryTree();
    int &operator[](
        const std::string &
            key); //operator indeksowania dla zmiennej, umożliwia zamianę lub odczyt warości istniejącego węzła, lub dodanie nowego
    const int &operator[](const std::string &key)
        const; //operator indeksowania dla stałej, umożliwia odczyt elementu o zadanym kluczu, jeśli element nie istnieje wyrzuca wyjątek std::out_of_range
    operator VectorConv() const;
    friend std::ostream &operator<<(
        std::ostream &,
        const BinaryTree &tree); //funkcja zaprzyjaźniona - operator zapisu do strumienia
};

#endif // BINARYTREE_H
