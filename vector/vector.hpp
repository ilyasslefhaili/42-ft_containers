/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:08:03 by ilefhail          #+#    #+#             */
/*   Updated: 2023/01/31 12:08:06 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_HPP
#define V_HPP
#include <iostream>
#include "../util/iterator.hpp"
#include "../util/reverse_iterator.hpp"
namespace ft{
    template <class T, class Allocator = std::allocator<T> >
    class vector{
        public:
            typedef typename Allocator::reference           reference;
            typedef typename Allocator::const_reference     const_reference;
            typedef iterator<T>                             iterator;
            //typedef iterator<const T>                     const_iterator;
            typedef size_t                                  size_type;
            typedef ptrdiff_t                               difference_type;
            typedef T                                       value_type;
            typedef typename Allocator::pointer             pointer;
            typedef typename Allocator::const_pointer       const_pointer;
            typedef Allocator                               allocator_type;
            typedef reverse_iterator<iterator>              reverse_iterator;
            //typedef reverse_iterator<const_iterator>      const_reverse_iterator;
        
            //////////////////////////
            //constructors
            //////////////////////////
            explicit vector (const allocator_type& alloc = allocator_type()){
                _capacity = _size = 0;
                _allocator = alloc;
                _array = _allocator.allocate(0);
            }
            explicit vector(size_type size, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()){
                _allocator = alloc;
                _size = _capacity = 0;
                _array = _allocator.allocate(0);
                for (size_type i = 0;i < size;i++)
                    this->push_back(val);
            }
            vector (const vector& x){
                _capacity = _size = x._size;
                _allocator = x._allocator;
                _array = _allocator.allocate(x.size());
                for (difference_type i = 0; i < x.size();i++)
                    _allocator.construct(&_array[i], x[i]);
            }
            template<class InputIterator>
            vector(InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator >::type  last, const allocator_type& alloc = allocator_type()){
                difference_type len = std::distance(first, last);
                _capacity = _size = len;
                _allocator = alloc;
                _array = _allocator.allocate(len);
                for (difference_type i = 0;i < len;i++){
                        _allocator.construct(&_array[i], *first);
                        first++;
                    }
            }
            //////////////////////////
            //element access:
            //////////////////////////
            reference operator[](size_type index){return (_array[index]);}
            const_reference operator[](size_type index) const {return (_array[index]);}
            const_reference at(size_type n) const{ 
                if (n < _size)
                    return (_array[n]);
                throw (std::out_of_range("std::exception"));
            }
            reference at(size_type n){
                if (n < _size)
                    return (_array[n]);
                throw (std::out_of_range("std::exception"));
            }
            reference front(){return _array[0];}
            const_reference front() const{return _array[0];}
            reference back(){return _array[_size - 1];}
            const_reference back() const{return _array[_size - 1];}
            //////////////////////////
            //modifiers:
            //////////////////////////
            void pop_back(){
                _allocator.destroy(&_array[_size - 1]);
                _size -= 1;
            }
            void push_back(const value_type& val){
                if (_size == _capacity)
                {
                    pointer temp = _array;
                    if (_capacity == 0)
                        _capacity += 1;
                    _capacity *= 2;
                    _array = _allocator.allocate(_capacity);
                    for (size_type i = 0;i < _size;i++)
                    {
                        _allocator.construct(&_array[i], temp[i]);
                        _allocator.destroy(&temp[i]);
                    }
                    _allocator.construct(&_array[_size], val);
                    _allocator.deallocate(temp, _size);
                    _size += 1;
                }
                else
                {
                    _allocator.construct(&_array[_size], val);
                    _size += 1;
                }
            }
            iterator insert (iterator position, const value_type& val);
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last);
            //////////////////////////
            //iterators:
            //////////////////////////
            iterator begin() { return iterator(_array); }
            // const_iterator begin() const { return iterator(_array); }
            iterator end(){return iterator(_array + _size);}
            // const_iterator end()const{return iterator(_array + _size);}
            //////////////////////////
            //capacity:
            //////////////////////////
            size_type capacity()const {return _capacity;}
            size_type size()const{return _size;}
            bool empty() const{return !(_size);}
            size_type max_size() const{return _allocator.max_size();}
            void resize (size_type n, value_type val = value_type()){
                if (_size < n)
                {
                    if (n > this->max_size())
                        throw(std::length_error("std::exception"));
                    while (_size < n)
                        this->push_back(val);
                }
                else
                {
                    while (_size > n)
                        this->pop_back();
                }
            }
            void reserve(size_type n){
                if (n > this->max_size())
                    throw(std::length_error("std::exception"));
                else if (n > _capacity){
                    size_type temp_capacity = _capacity;
                    size_type a = _size;
                    pointer temp = _array;
                    _array = _allocator.allocate(n);
                    _capacity = n;
                    _size = 0;
                    for (size_type i = 0;i < a;i++){
                        this->push_back(temp[i]);
                        _allocator.destroy(&temp[i]);
                    }
                    _allocator.deallocate(temp, temp_capacity);
                }
            }
            //////////////////////////
            //destructor:
            //////////////////////////
            ~vector(){
                for (size_type i = 0;i < _size; i++)
                    _allocator.destroy(&_array[i]);
                _allocator.deallocate(_array, _capacity);
            }
          
        private:
            allocator_type      _allocator;
            pointer             _array;
            size_type           _size;
            size_type           _capacity;  
    };
}


#endif
