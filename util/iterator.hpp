#ifndef V_hpp
#define V_hpp

namespace ft{
    template <class T>
    class iterator{
        private:
            T* ptr;
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
            iterator& operator=(const iterator& to_copy){
                ptr = to_copy.ptr;
                return (*this);
            }
            bool operator==(iterator )
    }
}


#endif