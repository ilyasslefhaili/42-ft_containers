#include <vector>
#include "vector.hpp"
int main()
{
        ft::vector<char> v(64, 'a');
        ft::vector<char>::iterator l = v.begin();

        l = l + 3;
        //  for (int i = 0; i < 266; ++i) {
        //     std::cout<<v.size()<<"     "<<i<<std::endl;
        //     v.push_back(45.0123);
        // }
        v.insert(l, 'o');
        std::cout<<v.at(2)<<std::endl;
} 