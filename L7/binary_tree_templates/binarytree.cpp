#include "binarytree.h"

//std::shared_ptr<BinaryTree::Node> BinaryTree::create(const std::string &key, const int &val)
//{
//    std::shared_ptr<BinaryTree::Node> node
//        = std::make_shared<BinaryTree::Node>(key, val); //new BinaryTree::Node(key, val);

//    return node;
//}

//std::shared_ptr<BinaryTree::Node> BinaryTree::find(std::shared_ptr<BinaryTree::Node> node,
//                                                   const std::string &key)
//{
//    if (node->word == key) {
//        return node;
//    } else {
//        if (node->word < key) {
//            if (node->r == nullptr) {
//                node->r = create(key, 0);
//                return node->r;
//            } else {
//                return find(node->r, key);
//            }
//        } else {
//            if (node->l == nullptr) {
//                node->l = create(key, 0);
//                return node->l;
//            } else {
//                return find(node->l, key);
//            }
//        }
//    }
//}

//const std::shared_ptr<BinaryTree::Node> BinaryTree::find(
//    const std::shared_ptr<BinaryTree::Node> node, const std::string &key) const
//{
//    if (node->word == key) {
//        return node;
//    } else {
//        if (node->word < key) {
//            if (node->r == nullptr) {
//                throw std::out_of_range("element does not exist");

//            } else {
//                return find(node->r, key);
//            }
//        } else {
//            if (node->l == nullptr) {
//                throw std::out_of_range("element does not exist");
//            } else {
//                return find(node->l, key);
//            }
//        }
//    }
//}

//void BinaryTree::print(const std::shared_ptr<BinaryTree::Node> node, std::ostream &str) const
//{
//    if (node->l != nullptr) {
//        print(node->l, str);
//    }
//    str << node->word << " - " << node->counter << std::endl;
//    if (node->r != nullptr) {
//        print(node->r, str);
//    }
//}

//void BinaryTree::dump(const std::shared_ptr<BinaryTree::Node> node,
//                      BinaryTree::VectorConv &output) const
//{
//    if (node->l != nullptr) {
//        dump(node->l, output);
//    }
//    std::pair<std::string, int> element = {node->word, node->counter};
//    output.emplace_back(element);

//    if (node->r != nullptr) {
//        dump(node->r, output);
//    }
//}

////void BinaryTree::release(const std::shared_ptr<BinaryTree::Node> node)
////{
////    if (node->l != nullptr) {
////        release(node->l);
////    }
////    if (node->r != nullptr) {
////        release(node->r);
////    }
////    delete node;
////}

//void BinaryTree::copy(const std::shared_ptr<BinaryTree::Node> node)
//{
//    (*this)[node->word] = node->counter;
//    if (node->l != nullptr) {
//        copy(node->l);
//    }
//    if (node->r != nullptr) {
//        copy(node->r);
//    }
//}

//BinaryTree::BinaryTree() : root_(nullptr) {}

//BinaryTree::BinaryTree(const BinaryTree &src)
//{
//    copy(src.root_);
//}

//BinaryTree &BinaryTree::operator=(const BinaryTree &src)
//{
//    copy(src.root_);
//    return *this;
//}

//int &BinaryTree::operator[](const std::string &key)
//{
//    if (root_ == nullptr) {
//        root_ = create(key, 0);
//        return root_->counter;
//    } else {
//        return find(root_, key)->counter;
//    }
//}

//const int &BinaryTree::operator[](const std::string &key) const
//{
//    if (root_ == nullptr) {
//        throw std::out_of_range("element does not exist");

//    } else {
//        return find(root_, key)->counter;
//    }
//}

//BinaryTree::operator VectorConv() const
//{
//    BinaryTree::VectorConv out;
//    dump(root_, out);
//    return out;
//}

//std::ostream &operator<<(std::ostream &str, const BinaryTree &tree)
//{
//    tree.print(tree.root_, str);
//    return str;
//}
