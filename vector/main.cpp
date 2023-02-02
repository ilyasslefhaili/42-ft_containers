#include <vector>
#include "vector.hpp"
int main()
{
        const ft::vector<double> v;
        //  for (int i = 0; i < 266; ++i) {
        //     std::cout<<v.size()<<"     "<<i<<std::endl;
        //     v.push_back(45.0123);
        // }
        std::cout<<v.max_size()<<std::endl;
}