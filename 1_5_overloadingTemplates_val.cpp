#include<iostream>
#include<cstring>
#include<string>
#include<typeinfo>
template<typename T>
T max(T a,T b)
{
    return b<a?a:b;
}
template< typename T>
T* max(T* a,T* b)
{
    return *b<*a?a:b;
}

char const* max(char const*a,char const*b)
{
    return std::strcmp(b,a)<0?a:b;
}

int main()
{
int a=1;
int b=3;
auto t=::max(a,b);
std::cout<<typeid(decltype(t)).name()<<std::endl;
std::string s1="hello";
std::string s2="you";
auto t2=::max(s1,s2);
std::cout<<typeid(decltype(t2)).name()<<std::endl;

int *p1=&a;
int *p2=&b;
auto t3=::max(p1,p2);
std::cout<<typeid(decltype(t3)).name()<<std::endl;

char const *cstr1="hello";
char const *cstr2="you";
auto t4=::max(cstr1,cstr2);
std::cout<<typeid(decltype(t4)).name()<<std::endl;


return 0;
}