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
#include "../util/util_vector.hpp"
namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef iterator<T> iterator;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef Allocator allocator_type;
        typedef reverse_iterator<iterator> reverse_iterator;
        typedef ft::iterator<const T> const_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        //////////////////////////
        // constructors
        //////////////////////////
        explicit vector(const allocator_type &alloc = allocator_type())
        {
            _capacity = _size = 0;
            _allocator = alloc;
            _array = NULL;
        }
        explicit vector(size_type size, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            if (size < 0 || size > this->max_size())
                throw(std::length_error("vector"));
            _allocator = alloc;
            _size = _capacity = 0;
            _array = NULL;
            if (size > 0 && size < this->max_size())
            {
                for (size_type i = 0; i < size; i++)
                    this->push_back(val);
            }
        }
        vector(const vector &x)
        {
            _capacity = _size = x._size;
            _allocator = x._allocator;
            _array = _allocator.allocate(x.size());
            for (size_type i = 0; i < x.size(); i++)
                _allocator.construct(&_array[i], x[i]);
        }
        template <class InputIterator>
        vector(InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type())
        {
            _array = NULL;
            _capacity = _size = 0;
            _allocator = alloc;
            while (first != last)
            {
                this->push_back(*first);
                first++;
            }
        }
        void assign(size_type n, const T &u)
        {
            this->clear();
            for (size_type i = 0; i < n; i++)
                this->push_back(u);
        }
        template <class InputIterator>
        void assign(InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            this->clear();
            while (first != last)
            {
                this->push_back(*first);
                first++;
            }
        }
        allocator_type get_allocator() const
        {
            return _allocator;
        }
        //////////////////////////
        // operators:
        //////////////////////////
        vector &operator=(const vector &x)
        {
            this->assign(x.begin(), x.end());
            return (*this);
        }
        //////////////////////////
        // element access:
        //////////////////////////
        reference operator[](size_type index) { return (_array[index]); }
        const_reference operator[](size_type index) const { return (_array[index]); }
        const_reference at(size_type n) const
        {
            if (n < _size)
                return (_array[n]);
            throw(std::out_of_range("std::exception"));
        }
        reference at(size_type n)
        {
            if (n < _size)
                return (_array[n]);
            throw(std::out_of_range("std::exception"));
        }
        reference front() { return _array[0]; }
        const_reference front() const { return _array[0]; }
        reference back() { return _array[_size - 1]; }
        const_reference back() const { return _array[_size - 1]; }
        //////////////////////////
        // modifiers:
        //////////////////////////
        void pop_back()
        {
            _allocator.destroy(&_array[_size - 1]);
            _size -= 1;
        }
        void push_back(const value_type &val)
        {
            if (_size == _capacity)
            {
                pointer temp = _array;
                size_type temp_capacity = _capacity;
                if (_capacity == 0)
                    _capacity += 1;
                _capacity *= 2;
                _array = _allocator.allocate(_capacity);

                for (size_type i = 0; i < _size; i++)
                {
                    _allocator.construct(&_array[i], temp[i]);
                    _allocator.destroy(&temp[i]);
                }
                _allocator.construct(&_array[_size], val);
                if (temp_capacity > 0)
                    _allocator.deallocate(temp, temp_capacity);
                _size += 1;
            }
            else
            {
                _allocator.construct(&_array[_size], val);
                _size += 1;
            }
        }
        iterator insert(iterator position, const value_type &val)
        {
            difference_type pos = std::distance(this->begin(), position);
            this->push_back(val);
            difference_type e = _size - 1;
            while (e > pos)
            {
                value_type temp = _array[e];
                _array[e] = _array[e - 1];
                _array[e - 1] = temp;
                e--;
            }
            return (this->begin() + pos);
        }
        void insert(iterator position, size_type n, const value_type &val)
        {
            if (n > this->max_size())
                _allocator.allocate(n);
            for (size_type i = 0; i < n; i++)
            {
                position = this->insert(position, val) + 1;
            }
        }
        template <class InputIterator>
        void insert(iterator position, InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            while (first != last)
            {
                position = this->insert(position, *first) + 1;
                first++;
            }
        }
        iterator erase(iterator position)
        {
            difference_type pos = std::distance(this->begin(), position);
            difference_type l = _size;
            if (pos < l && pos >= 0)
            {
                pos++;
                while (pos < l)
                {
                    value_type temp = _array[pos - 1];
                    _array[pos - 1] = _array[pos];
                    _array[pos] = temp;
                    pos++;
                }
                this->pop_back();
            }
            return (position);
        }
        iterator erase(iterator first, iterator last)
        {
            difference_type pos = std::distance(this->begin(), first);
            difference_type count = std::distance(first, last);
            difference_type to_locate = std::distance(last, this->end());
            if (to_locate < 0)
                return last;
            size_type l = count;
            while (to_locate)
            {
                value_type temp = _array[l + pos];
                _array[l + pos] = _array[pos];
                _array[pos] = temp;
                pos++;
                to_locate--;
            }
            for (size_type i = 0; i < l; i++)
                this->pop_back();
            return (last);
        }
        void swap(vector &x)
        {
            std::swap(this->_array, x._array);
            std::swap(x._size, _size);
            std::swap(_capacity, x._capacity);
        }
        void clear()
        {
            while (!this->empty())
                this->pop_back();
        }
        //////////////////////////
        // iterators:
        //////////////////////////
        iterator begin() { return iterator(_array); }
        const_iterator begin() const { return iterator(_array); }
        iterator end() { return iterator(_array + _size); }
        const_iterator end() const { return iterator(_array + _size); }
        reverse_iterator rbegin()
        {
            return reverse_iterator(iterator(&_array[_size]));
            // return reverse_iterator(iterator(this->_array[_size]));
        }
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(iterator(&this->_array[_size])));
        }
        reverse_iterator rend()
        {
            return reverse_iterator(iterator(&_array[0]));
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(this->begin()));
        }
        //////////////////////////
        // capacity:
        //////////////////////////
        size_type capacity() const { return _capacity; }
        size_type size() const { return _size; }
        bool empty() const { return !(_size); }
        size_type max_size() const
        {
            return std::min((std::size_t)std::numeric_limits<std::ptrdiff_t>::max(), _allocator.max_size());
        }
        void resize(size_type n, value_type val = value_type())
        {
            if (n > this->max_size())
                throw(std::length_error("std::exception"));
            else if (_size < n)
            {
                while (_size < n)
                    this->push_back(val);
            }
            else
            {
                while (_size > n)
                    this->pop_back();
            }
        }
        void reserve(size_type n)
        {
            if (n > this->max_size())
                throw(std::length_error("std::exception"));
            else if (n > _capacity)
            {
                size_type temp_capacity = _capacity;
                size_type a = _size;
                pointer temp = _array;
                _array = _allocator.allocate(n);
                _capacity = n;
                _size = 0;
                for (size_type i = 0; i < a; i++)
                {
                    this->push_back(temp[i]);
                    _allocator.destroy(&temp[i]);
                }
                if (temp_capacity > 0)
                    _allocator.deallocate(temp, temp_capacity);
            }
        }
        //////////////////////////
        // destructor:
        //////////////////////////
        ~vector()
        {
            if (_array != NULL)
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.destroy(&_array[i]);
                _allocator.deallocate(_array, _capacity);
            }
        }

    private:
        allocator_type _allocator;
        pointer _array;
        size_type _size;
        size_type _capacity;
    };
    template <class T, class Allocator>
    void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
    {
        x.swap(y);
    }
    template <class T, class Allocator>
    bool operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
    {
        if (x.size() != y.size())
            return (false);
        for (size_t i = 0; i < x.size(); i++)
        {
            if (x.at(i) != y.at(i))
                return false;
        }
        return true;
    }
    template <class T, class Allocator>
    bool operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
    {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }
    template <class T, class Allocator>
    bool operator!=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
    {
        return !(x == y);
    }
    template <class T, class Allocator>
    bool operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
    {
        return (y < x);
    }
    template <class T, class Allocator>
    bool operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
    {
        return (!(x < y));
    }
    template <class T, class Allocator>
    bool operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
    {
        return (!(y < x));
    }
}

#endif
