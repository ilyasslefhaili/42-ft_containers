/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTREE.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:07:43 by ilefhail          #+#    #+#             */
/*   Updated: 2023/02/15 15:07:44 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
template<class T>
struct node
{
    node *left;
    node *right;
    int  height;
    T    key;
    node *parent;
};
template<class T>
class AVL
{
    public:
        int height(node<T>* n)
        {
            if (n == NULL)
                return 0;
            else 
                return n->height;
        }
        int max(int a, int b){
            return (a > b) ? a : b;
        }
        node<T>* left_rotate(node<T>* root){
            node<T> *right_root = root->right;
            node<T> *left_right = right_root->left;
    
            right_root->left = root;
            root->parent = right_root;
            root->right = left_right;
            if (left_right != NULL)
                left_right->parent = root;
            root->height = max(height(root->left), height(root->right)) + 1;
            right_root->height = max(height(right_root->left), height(right_root->right)) + 1;
            return (right_root);
        }
        node<T>* right_rotate(node<T>* root){
            node<T> *left_root = root->left;
            node<T> *right_left = left_root->right;
           
            left_root->right = root; 
            root->parent = left_root;
            root->left = right_left;
            if (right_left != NULL)
                right_left->parent = root;
            root->height = max(height(root->left), height(root->right)) + 1;
            left_root->height = max(height(left_root->left), height(left_root->right)) + 1;
            return (left_root);
        }
    public:
        node<T> *root;
        size_t size;
    public:
        AVL(){
           root = NULL;
           size =  0;
        }
        node<T> *newNode(size_t key){
            node<T> *n = new node<T>;
            n->key = key;
            n->left= NULL;
            n->right = NULL;
            n->height = 0;
            return (n);
        }
        void insert(T key){
            node<T> *temp = root;
            node<T> *prev = temp;
            if (root == NULL){
                root = new node<T>;
                root->right = NULL;
                root->parent = NULL;
                root->left = NULL;
                root->key = key;
                root->height = 0;
                return ;
            }
            while (temp != NULL){
                prev = temp;
                if (key > temp->key){
                    temp->height += 1;
                    temp = temp->right;
                }
                else{
                    temp->height += 1;
                    temp = temp->left;
                }
            }
            if (prev->key < key)
            {
                prev->right = newNode(key);
                prev->right->parent = prev;
            }
            else
            {
                prev->left = newNode(key);
                prev->left->parent = prev;
            }
        }
};

#endif