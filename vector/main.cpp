#include <vector>
#include "vector.hpp"

#include <iostream>
#include <vector>
// int i = 0;
// class m
// {
//         private:
//                 int a;
//         public:
//         m(){
//                 std::cout<<"lksjalfjal\n";
//          }
//          m(const m& a){
//                 (void)a;
//                 //std::cout<<"copy " << i << std::endl;
//                 //i++;
//          }
//         ~m(){
//                 std::cout<<"dest"<<std::endl;
//         }
// };

// int main()
// {
//     m l;
    //ft::vector<m> num(43, l);  
//     m h = l;

    //l = h;
    //num.insert(num.begin() + 8, h);

//}

#define NAMESPACE ft

int main()
{
    ft::vector<int> l(10,9);
    std::reverse(l.rbegin(), l.rend());
    std::cout   << "*l.rbegin() = " << *l.rbegin() << std::endl;
} 