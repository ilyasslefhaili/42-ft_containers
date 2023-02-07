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
    class reverse_iterator {
        protected:
            T _iterator;
        public:
            ////////////////
            ////member types
            ////////////////
            typedef T                                               iterator_type;
            typedef typename iterator_traits<T>::difference_type    difference_type;
            typedef typename iterator_traits<T>::reference   reference;
            typedef typename iterator_traits<T>::pointer     pointer;
            /////////////////////////////
            /////constructors / destructor
            ////////////////////////////
            reverse_iterator() : _iterator() {}
            explicit reverse_iterator(iterator_type x){
                _iterator = x;
            }
            template <class Iter>  reverse_iterator (const reverse_iterator<Iter>& rev_it){
                _iterator = rev_it._iterator;
            }
            ~reverse_iterator(){}
            T base() const{
                return _iterator;
            }
            ////////////////
            //////operators
            ////////////////
            reference operator*() const{
                return *_iterator;
            }
            pointer operator->() const{
                return (&(operator*()));
            }
            reverse_iterator& operator++(){
                _iterator--;
                return (*this);
            }
            reverse_iterator& operator++(int){
                iterator_type temp = _iterator;
                _iterator--;
                return (temp); 
            }
            reverse_iterator& operator--(){
                _iterator++;
                return (*this);
            }
            reverse_iterator& operator--(int){
                iterator_type temp = _iterator;
                _iterator++;
                return (temp); 
            }
            reverse_iterator operator+ (difference_type n) const{
                _iterator = _iterator - n;
                return (*this);
            }
            reverse_iterator& operator+=(difference_type n){
                _iterator -= n;
            }
            reverse_iterator operator- (difference_type n) const{
                _iterator = _iterator + n;
                return (*this);
            }
            reverse_iterator& operator-=(difference_type n){
                _iterator += n;
                return (*this);
            }
            reference operator[](difference_type n) const{
                return _iterator[-n];
            }
    };
    template <class Iterator> bool operator==( const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y){
        return x.base() == y.base();
    }
    template <class Iterator>bool operator<(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y){
        return x.base() < y.base();
    }
    template <class Iterator>bool operator!=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y){
        return x.base() != y.base();
    }
    template <class Iterator>bool operator>(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y){
        return x.base() > y.base();
    }
    template <class Iterator>bool operator>=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y){
        return x.base() >= y.base();
    }
    template <class Iterator>bool operator<=(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y){
        return x.base() <= y.base();
    }
    template <class Iterator>typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y){
        return x.base() - y.base();
    }
    template <class Iterator>typename reverse_iterator<Iterator>::difference_type operator+(const reverse_iterator<Iterator>& x,const reverse_iterator<Iterator>& y){
        return x.base() + y.base();
    }
    template <class Iterator>reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& x){
        return x + n;
    }
}

#endif
