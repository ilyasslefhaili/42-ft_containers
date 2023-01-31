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
    template <class Iterator>
    class reverse_iterator:
    {
        typedef typename iterator_traits<T *>::value_type               value_type;
        typedef typename iterator_traits<T *>::difference_type          difference_type;
        typedef typename iterator_traits<T *>::iterator_category        iterator_category;
        typedef typename iterator_traits<T *>::pointer                  pointer;
        typedef typename iterator_traits<T *>::reference                reference;
        public:
            reverse_iterator() {ptr = NULL;}
            reverse_iterator(pointer p){ptr = p;}
            reverse_iterator(reverse_iterator& p){*this = p;}
            T& operator=(const reverse_iterator& to_copy){
                ptr = to_copy.ptr;
                return (*this);}
            bool operator==(reverse_iterator &a){return ptr == a.ptr;}
            bool operator!=(reverse_iterator a){return ptr != a.ptr;}
            bool operator<(reverse_iterator &a){return ptr < a.ptr;}
            bool operator>(reverse_iterator &a){return ptr > a.ptr;}
            bool operator<=(reverse_iterator &a){return ptr <= a.ptr;}
            bool operator>=(reverse_iterator &a){return ptr >= a.ptr;}
            pointer operator->(){return (ptr);}
            reference operator*(){return (*ptr);}
            reverse_iterator& operator+(int i){
                ptr += i;
                return (*this);}
            reverse_iterator& operator-(int i){
                ptr -= i;
                return (*this);}
            reverse_iterator& operator+(reverse_iterator& i){
                ptr -= i.ptr;
                return (*this);}
            reverse_iterator& operator-(reverse_iterator& i){
                ptr += i.ptr;
                return (*this);}
            reverse_iterator& operator++(){
                ptr--;
                return (*this);}
            reverse_iterator operator++(int){
                reverse_iterator temp = *this;
                --ptr;
                return (temp);}
            reverse_iterator& operator--(){
                ptr++;
                return (*this);}
            reverse_iterator operator--(int){
                reverse_iterator temp = *this;
                ++ptr;
                return (temp);}
        private:
            pointer ptr;
    }
}

#endif
