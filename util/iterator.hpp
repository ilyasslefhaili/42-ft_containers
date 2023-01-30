#ifndef V_hpp
#define V_hpp

namespace ft{
    template <class Iterator>
    struct iterator_traits{
        typedef typename Iterator::value_type                   value_type;
        typedef typename Iterator::difference_type              difference_type;
        typedef typename Iterator::iterator_category            iterator_category;
        typedef typename Iterator::pointer                      pointer;
        typedef typename Iterator::reference                    reference;
    };
    template <class T*>
    struct iterator_traits{
        typedef  T                          value_type;
        typedef size_t                      difference_type;
        typedef random_access_iterator_tag  iterator_category;
        typedef T*                          pointer;
        typedef T&                          reference;
    };
    struct iterator_traits
    template <class T>
    class iterator{
        typedef typename iterator_traits<T *>::value_type               value_type;
        typedef typename iterator_traits<T *>::difference_type          difference_type;
        typedef typename iterator_traits<T *>::iterator_category        iterator_category;
        typedef typename iterator_traits<T *>::pointer                  pointer;
        typedef typename iterator_traits<T *>::reference                reference; 
        private:
            pointer ptr;
        public:
            iterator() {
                ptr = NULL;
            }
            iterator(T *p){
                ptr = p;
            }
            iterator(iterator& p){
                *this = p;
            }
            T& operator=(const iterator& to_copy){
                ptr = to_copy.ptr;
                return (*this);
            }
            bool operator==(iterator &a)
            {
                return ptr == a.ptr;
            }
            bool operator!=(iterator a)
            {
                return ptr != a.ptr;
            }
            bool operator<(iterator &a)
            {
                return ptr < a.ptr;
            }
            bool operator>(iterator &a)
            {
                return ptr > a.ptr;
            }
            bool operator<=(iterator &a)
            {
                return ptr <= a.ptr;
            }
            bool operator>=(iterator &a)
            {
                return ptr >= a.ptr;
            }
            T* operator->()
            {
                return (ptr);
            }
            T& operator*()
            {
                return (*ptr);
            }
            iterator& operator+(int i)
            {
                ptr += i;
                return (*this);
            }
            iterator& operator-(int i)
            {
                ptr -= i;
                return (*this);
            }
            iterator& operator+(iterator& i)
            {
                ptr += i.ptr;
                return (*this);
            }
            iterator& operator-(iterator& i)
            {
                ptr -= i.ptr;
                return (*this);
            }
            iterator& operator++()
            {
                ptr++;
                return (*this);
            }
            iterator operator++(int)
            {
                iterator temp = *this;
                ++ptr;
                return (temp);
            }
            iterator& operator--()
            {
                ptr--;
                return (*this);
            }
            iterator operator--(int)
            {
                iterator temp = *this;
                --ptr;
                return (temp);
            }
    };
}


#endif