#include <vector>
#include "vector.hpp"
int main()
{
        ft::vector<char> v(64, 'a');
        //  for (int i = 0; i < 266; ++i) {
        //     std::cout<<v.size()<<"     "<<i<<std::endl;
        //     v.push_back(45.0123);
        // }
        std::cout<<v.at(38)<<std::endl;
} 