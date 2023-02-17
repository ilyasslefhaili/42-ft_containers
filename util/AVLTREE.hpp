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
        node<T>* left_rotate(node<T>* root){
            node<T> *temp = root->right;
            root->right = temp->left;
            temp->left = root;
            return (temp);
        }
    public:
        node<T> *root;
        AVL(T key){
            root = new(node<T>);
            root->key = key;
            root->left = NULL;
            root->right = NULL;
        }
        node<T> *newNode(size_t key){
            node<T> *n = new node<T>;
            n->key = key;
            n->left= NULL;
            n->right = NULL;
            return (n);
        }
        void insert(T key){
            node<T> *temp = root;
            node<T> *prev = temp;
            while (temp != NULL){
                prev = temp;
                if (key > temp->key)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            if (prev->key < key)
                prev->right = newNode(key);
            else
                prev->left = newNode(key);
        }
};
#endif