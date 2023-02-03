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

#ifndef ITER_hpp
#define ITER_hpp

#include "iterator_traits.hpp"
namespace ft{
    
    template <class T>
    class iterator{
        public:
            typedef typename iterator_traits<T *>::value_type               value_type;
            typedef typename iterator_traits<T *>::difference_type          difference_type;
            typedef typename iterator_traits<T *>::iterator_category        iterator_category;
            typedef typename iterator_traits<T *>::pointer                  pointer;
            typedef typename iterator_traits<T *>::reference                reference; 
        public:
            iterator() {_ptr = NULL;}
            iterator(pointer p){_ptr = p;}
            iterator(const iterator& p){*this = p;}
            ~iterator(){}
            iterator& operator=(const iterator& to_copy){
                _ptr = to_copy._ptr;
                return (*this);}
            bool operator==(iterator &a){return _ptr == a._ptr;}
            bool operator!=(iterator a){return _ptr != a._ptr;}
            bool operator<(iterator &a){return _ptr < a._ptr;}
            bool operator>(iterator &a){return _ptr > a._ptr;}
            bool operator<=(iterator &a){return _ptr <= a._ptr;}
            bool operator>=(iterator &a){return _ptr >= a._ptr;}
            pointer operator->(){return (_ptr);}
            reference operator*(){return (*_ptr);}
            iterator& operator+(int i){
                _ptr += i;
                return (*this);}
            iterator& operator-(difference_type i){
                _ptr -= i;
                return (*this);}
            iterator& operator+(iterator& i){
                _ptr += i._ptr;
                return (*this);}
            difference_type operator-(iterator& i){return (_ptr - i._ptr);}
            iterator& operator++(){
                _ptr++;
                return (*this);}
            iterator operator++(int){
                iterator temp = *this;
                ++_ptr;
                return (temp);}
            iterator& operator--(){
                _ptr--;
                return (*this);}
            iterator operator--(int){
                iterator temp = *this;
                --_ptr;
                return (temp);}
        private:
            pointer _ptr;
    };
}


#endif
