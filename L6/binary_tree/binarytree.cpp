#include "binarytree.h"

BinaryTree::Node *BinaryTree::create(const std::string &key, const int &val)
{
    BinaryTree::Node *node = new BinaryTree::Node(key, val);

    return node;
}

BinaryTree::Node *BinaryTree::find(BinaryTree::Node *node, const std::string &key)
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

const BinaryTree::Node *BinaryTree::find(const BinaryTree::Node *node, const std::string &key) const
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

void BinaryTree::print(const BinaryTree::Node *node, std::ostream &str) const
{
    if (node->l != nullptr) {
        print(node->l, str);
    }
    str << node->word << " - " << node->counter << std::endl;
    if (node->r != nullptr) {
        print(node->r, str);
    }
}

BinaryTree::BinaryTree() : root_(nullptr) {}

int &BinaryTree::operator[](const std::string &key)
{
    if (root_ == nullptr) {
        root_ = create(key, 0);
        return root_->counter;
    } else {
        return find(root_, key)->counter;
    }
}

const int &BinaryTree::operator[](const std::string &key) const
{
    if (root_ == nullptr) {
        throw std::out_of_range("element does not exist");

    } else {
        return find(root_, key)->counter;
    }
}

std::ostream &operator<<(std::ostream &str, const BinaryTree &tree)
{
    tree.print(tree.root_, str);
    return str;
}
