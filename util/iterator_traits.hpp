/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:13:20 by ilefhail          #+#    #+#             */
/*   Updated: 2023/01/30 15:13:25 by ilefhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
#define TRAITS_HPP

namespace ft{
    template <class Iterator>
    struct iterator_traits{
        typedef typename Iterator::value_type                   value_type;
        typedef typename Iterator::difference_type              difference_type;
        typedef typename Iterator::iterator_category            iterator_category;
        typedef typename Iterator::pointer                      pointer;
        typedef typename Iterator::reference                    reference;
    };
    template <class T>
    struct iterator_traits<T*>{
        typedef  T                                  value_type;
        typedef size_t                              difference_type;
        typedef std::random_access_iterator_tag     iterator_category;
        typedef T*                                  pointer;
        typedef T&                                  reference;
    };
    template <class T>
    struct iterator_traits<const T*>{
        typedef  T                                  value_type;
        typedef size_t                              difference_type;
        typedef std::random_access_iterator_tag     iterator_category;
        typedef const T*                            pointer;
        typedef const T&                            reference;
    };
}





#endif