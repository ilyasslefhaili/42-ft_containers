#include <vector>
#include "vector.hpp"
int main()
{
        ft::vector<double> v;
        //  for (int i = 0; i < 266; ++i) {
        //     std::cout<<v.size()<<"     "<<i<<std::endl;
        //     v.push_back(45.0123);
        // }
        v.reserve(0);
        std::cout<<v.capacity()<<std::endl;
        v.reserve(32);
        std::cout<<v.capacity()<<std::endl;
        v.reserve(48);
        std::cout<<v.capacity()<<std::endl;

}