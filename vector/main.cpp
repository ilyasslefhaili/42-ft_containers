#include <vector>
#include "vector.hpp"

#include <iostream>
#include <vector>
// int i = 0;
class m
{
        private:
                //int a;
        public:
        m(){
                std::cout<<"lksjalfjal\n";
         }
         m(const m& a){
                (void)a;
                //std::cout<<"copy " << i << std::endl;
                //i++;
         }
        ~m(){
                std::cout<<"dest"<<std::endl;
        }
};

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
    // NAMESPACE::vector<int> l;
    // for (int i = 0; i < 10; i++)
    //     l.push_back(i);
    // std::cout<<">>>>"<<*(l.erase(l.begin(), l.begin() + 3))<<std::endl;
    // for (int i = 0;i < 7;i++)
    //     std::cout<< l[i]<< std::endl;
    // std::cout<<l.size()<<std::endl;
    // ft::vector<int> a(10, 10);
    // ft::vector<int>::const_reverse_iterator l(a.rend());
    // ft::vector<int>::const_reverse_iterator l(a.rbegin());
    m l;
    NAMESPACE::vector<m> my_v(10, l);
    NAMESPACE::vector<m> v(20, l);
    // std::cout<<my_v.capacity()<<std::endl;
    // my_v.assign(90, 'n');
    // std::cout<<my_v.capacity()<<std::endl;
  
    my_v.insert(my_v.begin(), v.begin(), v.begin() + 15);
    // for (int i = 0;i < 14; i++)
        // std::cout<<my_v[i]<<std::endl;
    std::cout<<my_v.capacity()<<std::endl;
    std::cout<<my_v.size()<<std::endl;
    // std::cout << "const_ite +=/-=: " << *(l += 2) << " | " << *(l -= 2) << std::endl;
    // std::cout << "(ite + 3 == it): " << (l - a.rbegin()) << s
}