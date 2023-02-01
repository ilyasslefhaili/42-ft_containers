#include <vector>
#include "vector.hpp"
int main()
{
    ft::vector<std::string> e;
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    e.push_back("lksafklj");
    for (int i = 0;i < 8;i++)
        std::cout<<e[i]<<std::endl;
    e.pop_back();
    e.pop_back();
    for (int i = 0;i < 8;i++)
        std::cout<<"sfkjslkf"<<e[i]<<std::endl;
}