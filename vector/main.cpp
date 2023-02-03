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
        std::vector<char> v(64, 'a');
        std::vector<char>::iterator l = v.end();
        //std::cout<<std::distance(v.begin(), v.begin());
        //  for (int i = 0; i < 266; ++i) {
        //     std::cout<<v.size()<<"     "<<i<<std::endl;
        //     v.push_back(45.0123);
        // }
        v.insert(l, 'o');
        std::cout<<v[64]<<std::endl;
        std::cout<<v.size()<<"    "<<v.capacity()<<std::endl;
} 