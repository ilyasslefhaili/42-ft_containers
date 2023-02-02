#include <vector>
#include "vector.hpp"
int main()
{
        const ft::vector<const int> v(8);
        //  for (int i = 0; i < 266; ++i) {
        //     std::cout<<v.size()<<"     "<<i<<std::endl;
        //     v.push_back(45.0123);
        // }
        std::cout<<v[0]<<std::endl;
} 