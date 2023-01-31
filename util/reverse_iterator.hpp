/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:00:06 by ilefhail          #+#    #+#             */
/*   Updated: 2023/01/30 16:00:08 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVER_HPP
#define REVER_HPP

#include "iterator_traits.hpp"
namespace ft{
    template <class T>
    class reverse_iterator{
        typedef typename iterator_traits<T *>::value_type         value_type;
        typedef typename iterator_traits<T *>::difference_type    difference_type;
        typedef typename iterator_traits<T *>::iterator_category  iterator_category;
        typedef typename iterator_traits<T *>::pointer            pointer;
        typedef typename iterator_traits<T *>::reference          reference;
        public:
            reverse_iterator() {_ptr = NULL;}
            reverse_iterator(pointer p){_ptr = p;}
            reverse_iterator(const reverse_iterator& p){*this = p;}
            ~reverse_iterator(){}
            T& operator=(const reverse_iterator& to_copy){
                _ptr = to_copy._ptr;
                return (*this);}
            bool operator==(reverse_iterator &a){return _ptr == a._ptr;}
            bool operator!=(reverse_iterator a){return _ptr != a._ptr;}
            bool operator<(reverse_iterator &a){return _ptr < a._ptr;}
            bool operator>(reverse_iterator &a){return _ptr > a._ptr;}
            bool operator<=(reverse_iterator &a){return _ptr <= a._ptr;}
            bool operator>=(reverse_iterator &a){return _ptr >= a._ptr;}
            pointer operator->(){return (_ptr);}
            reference operator*(){return (*_ptr);}
            reverse_iterator& operator+(int i){
                _ptr += i;
                return (*this);}
            reverse_iterator& operator-(int i){
                _ptr -= i;
                return (*this);}
            reverse_iterator& operator+(reverse_iterator& i){
                _ptr -= i._ptr;
                return (*this);}
            reverse_iterator& operator-(reverse_iterator& i){
                _ptr += i._ptr;
                return (*this);}
            reverse_iterator& operator++(){
                _ptr--;
                return (*this);}
            reverse_iterator operator++(int){
                reverse_iterator temp = *this;
                --_ptr;
                return (temp);}
            reverse_iterator& operator--(){
                _ptr++;
                return (*this);}
            reverse_iterator operator--(int){
                reverse_iterator temp = *this;
                ++_ptr;
                return (temp);}
        private:
            pointer _ptr;
    };
}

#endif
