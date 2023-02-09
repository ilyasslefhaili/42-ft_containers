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
            typedef typename ft::iterator_traits<T *>::value_type               value_type;
            typedef typename ft::iterator_traits<T *>::difference_type          difference_type;
            typedef typename ft::iterator_traits<T *>::iterator_category        iterator_category;
            typedef typename ft::iterator_traits<T *>::pointer                  pointer;
            typedef typename ft::iterator_traits<T *>::reference                reference; 
        public:
            iterator() {_ptr = NULL;}
            iterator(pointer p){_ptr = p;}
            iterator(const iterator& p): _ptr(p._ptr) {}
            ~iterator(){}
            pointer base() const{
                return _ptr;
            }
            reference operator*()const{
                return *_ptr;
            }
            pointer operator->() const{
                return _ptr;
            }
            iterator& operator++(){
                _ptr++;
                return (*this);
            }
            iterator operator++(int){
                iterator temp = *this;
                _ptr++;
                return (temp);
            }
            iterator& operator--(){
                _ptr--;
                return (*this);
            }
            iterator operator--(int){
                iterator temp = *this;
                _ptr--;
                return (temp);
            }
            iterator operator+(difference_type n) const {
                iterator temp = *this;
                temp._ptr += n;
                return (temp);
            }
            iterator &operator+=(difference_type n){
                _ptr += n;
                return (*this);
            }
            iterator operator-(difference_type n) const{
                iterator temp = *this;
                temp._ptr -= n;
                return (temp);
            }
            iterator &operator-=(difference_type n){
                _ptr -= n;
                return (*this);
            }
            reference operator[](difference_type n) const{
                return _ptr[n];
            }
            iterator& operator=(const iterator& x){
                this->_ptr = x._ptr;
                return (*this);
            }
            operator iterator<const T>() const{
                iterator<const T> obj(this->_ptr);
                return  obj;
            }
        private:
            pointer _ptr;
    };
    template <class Iterator, class B> bool operator==( const iterator<Iterator>& x, const iterator<B>& y){
        return x.base() == y.base();
    }
    template <class Iterator, class B>bool operator<(const iterator<Iterator>& x,const iterator<B>& y){
        return x.base() < y.base();
    }
     template <class Iterator, class B>bool operator!=(const iterator<Iterator>& x,const iterator<B>& y){
        return x.base() != y.base();
    }
     template <class Iterator, class B>bool operator>(const iterator<Iterator>& x,const iterator<B>& y){
        return x.base() > y.base();
    }
     template <class Iterator, class B>bool operator>=(const iterator<Iterator>& x,const iterator<B>& y){
        return x.base() >= y.base();
    }
     template <class Iterator, class B>bool operator<=(const iterator<Iterator>& x,const iterator<B>& y){
        return x.base() <= y.base();
    }
    template <class Iterator, class B>typename iterator<Iterator>::difference_type operator-(const iterator<Iterator>& x,const iterator<B>& y){
        return x.base() - y.base();
    }
     template <class Iterator, class B>typename iterator<Iterator>::difference_type operator+(const iterator<Iterator>& x,const iterator<B>& y){
        return x.base() + y.base();
    }
     template <class Iterator>iterator<Iterator> operator+(typename iterator<Iterator>::difference_type n,const iterator<Iterator>& x){
        return x + n;
    }

}


#endif
