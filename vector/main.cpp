#include <vector>
#include "vector.hpp"

#include <iostream>
#include <vector>
// int i = 0;
// class m
// {
        // private:
                // int a;
        // public:
        // m(){
                // std::cout<<"lksjalfjal\n";
        //  }
        //  m(const m& a){
                // (void)a;
                // std::cout<<"copy " << i << std::endl;
                // i++;
        //  }
        // ~m(){}
// };

// int main()
// {
//     m l;
    //ft::vector<m> num(43, l);  
//     m h = l;

    //l = h;
    //num.insert(num.begin() + 8, h);

//}
int main()
{
     ft::vector<int> l;
     l.insert(l.end(), 10, 64);
     for (int i = 0; i < 10;i++)
        std::cout<<l[i]<<"\n";
} 