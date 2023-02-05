#include <vector>
#include "vector.hpp"

#include <iostream>
#include <vector>
// int i = 0;
class m
{
        private:
                int a;
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
    //ft::vector<m> num(43, l);  
//     m h = l;

    //l = h;
    //num.insert(num.begin() + 8, h);

//}

#define NAMESPACE ft

int main()
{
	NAMESPACE::vector<int> vec;
	for (int i = 0; i < 7; ++i)
		vec.push_back(i + 1);
	vec.erase(vec.begin() + 4, vec.end() - 1);
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec.at(i) << " ";
	std::cout << std::endl;
} 