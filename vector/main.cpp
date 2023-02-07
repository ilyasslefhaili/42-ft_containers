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
        ft::vector<int> vl;
       vl.insert(vl.begin(), 10, 0);
	// for (int i = 0; i < 7; ++i)
	// 	vec.push_back(i + 1);
        // for (int i = 0; i < 4;i++)
        //         std::cout<<vec[i]<<std::endl;
        NAMESPACE::vector<int>::iterator it = vl.begin();
       NAMESPACE::vector<int>::const_iterator cit = vl.begin();
       std::cout<<*(2+it);
} 