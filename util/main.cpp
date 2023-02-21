#include "AVLTREE.hpp"

int main()
{
   AVL<int> a;

    a.insert(8);
    a.insert(10);
    a.insert(9);
    a.insert(11);
    a.insert(18);
    a.insert(7);
    a.insert(0);
    std::cout<<a.root->key<<std::endl;
    std::cout<<a.root->right->key<<std::endl;
    std::cout<<a.root->right->left->key<<std::endl;
    std::cout<<a.root->right->right->key<<std::endl;
    std::cout<<a.root->left->key<<std::endl;
    std::cout<<a.root->left->left->key<<std::endl;
    std::cout<<a.root->left->right->key<<std::endl;
    // a.root = a.right_rotate(a.root);
}