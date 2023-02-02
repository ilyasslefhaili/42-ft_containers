#include <vector>
#include "vector.hpp"
int main()
{
        ft::vector<double> v;
        //  for (int i = 0; i < 266; ++i) {
        //     std::cout<<v.size()<<"     "<<i<<std::endl;
        //     v.push_back(45.0123);
        // }
        try 
        {
        v.resize(v.max_size() + 1, 9.000);
        }
        catch (std::exception e)
        {
                std::cout<<e.what()<<std::endl;
        }
        std::cout<<v.size()<<std::endl;
}