/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:13:04 by ilefhail          #+#    #+#             */
/*   Updated: 2023/01/30 15:13:07 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_hpp
#define V_hpp

#include "iterator_traits.hpp"
namespace ft{
    
    template <class T>
    class iterator{
        typedef typename iterator_traits<T *>::value_type               value_type;
        typedef typename iterator_traits<T *>::difference_type          difference_type;
        typedef typename iterator_traits<T *>::iterator_category        iterator_category;
        typedef typename iterator_traits<T *>::pointer                  pointer;
        typedef typename iterator_traits<T *>::reference                reference; 
        public:
            iterator() {ptr = NULL;}
            iterator(pointer p){ptr = p;}
            iterator(iterator& p){*this = p;}
            T& operator=(const iterator& to_copy){
                ptr = to_copy.ptr;
                return (*this);}
            bool operator==(iterator &a){return ptr == a.ptr;}
            bool operator!=(iterator a){return ptr != a.ptr;}
            bool operator<(iterator &a){return ptr < a.ptr;}
            bool operator>(iterator &a){return ptr > a.ptr;}
            bool operator<=(iterator &a){return ptr <= a.ptr;}
            bool operator>=(iterator &a){return ptr >= a.ptr;}
            pointer operator->(){return (ptr);}
            reference operator*(){return (*ptr);}
            iterator& operator+(int i){
                ptr += i;
                return (*this);}
            iterator& operator-(int i){
                ptr -= i;
                return (*this);}
            iterator& operator+(iterator& i){
                ptr += i.ptr;
                return (*this);}
            iterator& operator-(iterator& i){
                ptr -= i.ptr;
                return (*this);}
            iterator& operator++(){
                ptr++;
                return (*this);}
            iterator operator++(int){
                iterator temp = *this;
                ++ptr;
                return (temp);}
            iterator& operator--(){
                ptr--;
                return (*this);}
            iterator operator--(int){
                iterator temp = *this;
                --ptr;
                return (temp);}
        private:
            pointer ptr;
    };
}


#endif
