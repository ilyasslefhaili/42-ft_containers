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
        typedef typename Allocator::reference           reference;
        typedef typename Allocator::const_reference     const_reference;
        typedef iterator<T>                             iterator;
        //typedef iterator<const T>                     const_iterator;
        typedef size_t                                  size_type;
        typedef ptrdiff_t                                  difference_type;
        typedef T                                       value_type;
        typedef typename Allocator::pointer             pointer;
        typedef typename Allocator::const_pointer       const_pointer;
        typedef Allocator                               allocator_type;
        typedef reverse_iterator<iterator>              reverse_iterator;
        //typedef reverse_iterator<const_iterator>      const_reverse_iterator;
        public:
            explicit vector (const allocator_type& alloc = allocator_type()){
                _allocator = alloc;
                _array = _allocator.allocate(0);
            }
            explicit vector(size_type size, const allocator_type& alloc = allocator_type()){
                _allocator = alloc;
                _array = _allocator.allocate(size);
            }
            vector (const vector& x, const allocator_type& alloc = allocator_type()){
                _allocator = alloc;
                _array = _allocator.allocate(x.size());
                for (difference_type i = 0; i < x.size();i++)
                    alloc.construct(&_array[i], x[i]);
            }
            template<class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
                difference_type len = std::distance(first, last);
                _allocator = alloc;
                _array = _allocator.allocate(len);
                for (difference_type i = 0;i < len;i++)
                    {
                        _allocator.construct(&_array[i], *first);
                        first++;
                    }
            }
        private:
            allocator_type  _allocator;
            pointer        _array;
            size_type      _size;
            size_type      _capacity;  
    };
}


#endif
