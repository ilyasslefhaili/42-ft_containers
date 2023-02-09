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
// ft::vector<m> num(43, l);
//     m h = l;

// l = h;
// num.insert(num.begin() + 8, h);

//}

#define NAMESPACE ft

int main()
{
    NAMESPACE::vector<int> l;
    for (int i = 0; i < 10; i++)
        l.push_back(i);
    std::reverse(l.rbegin(), l.rend());
    NAMESPACE::vector<int>::iterator e = l.begin();
    while (e != l.end())
    {
        std::cout << *e << " ";
        e++;
    }
    std::cout << std::endl;
}