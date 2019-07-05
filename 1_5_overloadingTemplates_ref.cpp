#include<iostream>
#include<cstring>
#include<string>
#include<typeinfo>
//call by reference
template<typename T>
T const& max(T const  &a,T const & b)
{
    std::cout<<"reference is called"<<std::endl;
    return b<a?a:b;
}

//call by value
char const* max(char const*a,char const*b)
{
    std::cout<<"c_string is called"<<std::endl;
    return std::strcmp(b,a)<0?a:b;
}

//call by reference
template <typename T>
T const& max(T const  &a,T const & b,T const &c)
{
    return max(max(a,b),c);//error if max(a,b)uses call by value
}
int main()
{
//auto t1=::max(1,2,3);
char const *s1="one";
char const *s2="two";
char const *s3="three";
auto t2=::max(s1,s2,s3);
std::cout<<typeid(decltype(t2)).name()<<std::endl;

return 0;
}