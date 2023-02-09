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
#include "iterator.hpp"
namespace ft{
    template <class T>
    class reverse_iterator{
        protected:
            T _iterator;
        public:
            ////////////////
            ////member types
            ////////////////
            typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;
            typedef T                                                   iterator_type;
            typedef typename ft::iterator_traits<T>::value_type         value_type;
            typedef typename ft::iterator_traits<T>::difference_type    difference_type;
            typedef typename ft::iterator_traits<T>::reference          reference;
            typedef typename ft::iterator_traits<T>::pointer            pointer;
            /////////////////////////////
            /////constructors / destructor
            ////////////////////////////
            reverse_iterator() : _iterator() {}
            explicit reverse_iterator(iterator_type x): _iterator(x) {
            }
            template <class Iter>  reverse_iterator (const reverse_iterator<Iter>& rev_it){
                _iterator = rev_it.base();
            }
            ~reverse_iterator(){}
            iterator_type base() const{
                return _iterator;
            }
            ////////////////
            //////operators
            ////////////////
            reference operator*() const{
                iterator_type tmp = _iterator;
                return *--tmp;
            }
            pointer operator->() const{
                return (&(operator*()));
            }
            reverse_iterator& operator++(){
                _iterator--;
                return (*this);
            }
            reverse_iterator operator++(int){
                reverse_iterator temp = *this;
                _iterator--;
                return (temp); 
            }
            reverse_iterator& operator--(){
                _iterator++;
                return (*this);
            }
            reverse_iterator& operator=(const reverse_iterator &x){
                this->_iterator = x.base();
                return *this;
            }
            reverse_iterator operator--(int){
                reverse_iterator temp = *this;
                _iterator++;
                return (temp); 
            }
            reverse_iterator operator+ (difference_type n) const{
                reverse_iterator temp = *this;
                temp._iterator -= n;
                return (temp);
            }
            reverse_iterator& operator+=(difference_type n){
                _iterator -= n;
                return *this;
            }
            reverse_iterator operator- (difference_type n) const{
                reverse_iterator temp = *this;
                temp._iterator += n;
                return (temp);
            }
            reverse_iterator& operator-=(difference_type n){
                _iterator += n;
                return (*this);
            }
            reference operator[](difference_type n) const{
                return _iterator[-n-1];
            }
    };
    template <class Iterator, class B> bool operator==( const reverse_iterator<Iterator>& x, const reverse_iterator<B>& y){
        return x.base() == y.base();
    }
     template <class Iterator, class B> bool operator<(const reverse_iterator<Iterator>& x,const reverse_iterator<B>& y){
        return x.base() > y.base();
    }
     template <class Iterator, class B> bool operator!=(const reverse_iterator<Iterator>& x,const reverse_iterator<B>& y){
        return x.base() != y.base();
    }
     template <class Iterator, class B> bool operator>(const reverse_iterator<Iterator>& x,const reverse_iterator<B>& y){
        return x.base() < y.base();
    }
     template <class Iterator, class B> bool operator>=(const reverse_iterator<Iterator>& x,const reverse_iterator<B>& y){
        return x.base() <= y.base();
    }
     template <class Iterator, class B> bool operator<=(const reverse_iterator<Iterator>& x,const reverse_iterator<B>& y){
        return x.base() >= y.base();
    }
    template <class Iterator, class B>typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,const reverse_iterator<B>& y){
        return y.base() - x.base();
    }
    template <class Iterator, class B>typename reverse_iterator<Iterator>::difference_type operator+(const reverse_iterator<Iterator>& x,const reverse_iterator<B>& y){
        return x.base() - y.base();
    }
    template <class Iterator>reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& x){
        return reverse_iterator<Iterator>(x.base() - n);
    }
}

#endif
