#include "AVLTREE.hpp"

int main()
{
   AVL<int> a;

    a.insert(8);
    a.insert(10);
    a.insert(611);
    // a.root = a.right_rotate(a.root);
    std::cout<<a.root->key<<std::endl;
    std::cout<<a.root->left->key<<std::endl;
    std::cout<<a.root->right->key<<std::endl;
}