#include <vector>
#include "vector.hpp"
int main()
{
    std::vector<int> l;
    l.push_back(5);
    l.push_back(4);
    ft::vector<int> e(l.begin(), l.end());
    std::cout<<e[-10]<<std::endl;
    std::cout<<l[-10];
}