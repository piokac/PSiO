#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

template<class X, class Y>
class BinaryTree
{
    using VectorConv = std::vector<std::pair<X, Y>>;

private:
    struct Node
    {
        Node(const X &key, const Y &val) : word(key), counter(val), l(nullptr), r(nullptr) {}
        X word;                  //klucz węzła
        Y counter;               //wartość węzła
        std::shared_ptr<Node> l; //wskaźnik do lewego poddrzewa
        std::shared_ptr<Node> r; //wskaźnik do prawego poddrzewa
    };
    std::shared_ptr<Node> root_;
    std::shared_ptr<Node> create(const X &key, const Y &val) //tworzy nowy węzeł drzewa
    {
        std::shared_ptr<BinaryTree::Node> node
            = std::make_shared<BinaryTree::Node>(key, val); //new BinaryTree::Node(key, val);

        return node;
    }
    std::shared_ptr<Node> find(std::shared_ptr<Node> node,
                               const X &key) //znajduje i dodaje nowy węzeł drzewa
    {
        if (node->word == key) {
            return node;
        } else {
            if (node->word < key) {
                if (node->r == nullptr) {
                    node->r = create(key, 0);
                    return node->r;
                } else {
                    return find(node->r, key);
                }
            } else {
                if (node->l == nullptr) {
                    node->l = create(key, 0);
                    return node->l;
                } else {
                    return find(node->l, key);
                }
            }
        }
    }
    const std::shared_ptr<Node> find(const std::shared_ptr<Node> node, const X &key)
        const //stała metoda, znajduje nowy węzeł drzewa, jeśli nie istnieje zwraca wyjątek std::ot_of_range
    {
        if (node->word == key) {
            return node;
        } else {
            if (node->word < key) {
                if (node->r == nullptr) {
                    throw std::out_of_range("element does not exist");

                } else {
                    return find(node->r, key);
                }
            } else {
                if (node->l == nullptr) {
                    throw std::out_of_range("element does not exist");
                } else {
                    return find(node->l, key);
                }
            }
        }
    }
    void print(const std::shared_ptr<Node> node, std::ostream &str)
        const //wyświetla rekursywnie wszystkie poddrzewo w kolejności rosnącej wg klucza
    {
        if (node->l != nullptr) {
            print(node->l, str);
        }
        str << node->word << " - " << node->counter << std::endl;
        if (node->r != nullptr) {
            print(node->r, str);
        }
    }
    void dump(const std::shared_ptr<Node> node, VectorConv &output) const
    {
        if (node->l != nullptr) {
            dump(node->l, output);
        }
        std::pair<std::string, int> element = {node->word, node->counter};
        output.emplace_back(element);

        if (node->r != nullptr) {
            dump(node->r, output);
        }
    }
    void copy(const std::shared_ptr<Node> node)
    {
        (*this)[node->word] = node->counter;
        if (node->l != nullptr) {
            copy(node->l);
        }
        if (node->r != nullptr) {
            copy(node->r);
        }
    }

public:
    BinaryTree() : root_(nullptr) {}
    BinaryTree(const BinaryTree &src) { copy(src.root_); }
    BinaryTree &operator=(const BinaryTree &src)
    {
        copy(src.root_);
        return *this;
    }
    //    ~BinaryTree();
    int &operator[](
        const X &
            key) //operator indeksowania dla zmiennej, umożliwia zamianę lub odczyt warości istniejącego węzła, lub dodanie nowego
    {
        if (root_ == nullptr) {
            root_ = create(key, 0);
            return root_->counter;
        } else {
            return find(root_, key)->counter;
        }
    }
    const int &operator[](const X &key)
        const //operator indeksowania dla stałej, umożliwia odczyt elementu o zadanym kluczu, jeśli element nie istnieje wyrzuca wyjątek std::out_of_range
    {
        if (root_ == nullptr) {
            throw std::out_of_range("element does not exist");

        } else {
            return find(root_, key)->counter;
        }
    }
    operator VectorConv() const //operator konwersji do std::vector<std::pair<key,value>>
    {
        {
            BinaryTree::VectorConv out;
            dump(root_, out);
            return out;
        }
    }
    friend std::ostream &operator<<(
        std::ostream &str,
        const BinaryTree &tree) //funkcja zaprzyjaźniona - operator zapisu do strumienia
    {
        tree.print(tree.root_, str);
        return str;
    }
};

#endif // BINARYTREE_H
