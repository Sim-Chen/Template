#include<iostream>
#include<type_traits>
template<typename T1,typename T2>
T1 max(T1 a,T2 b)
{
    return b<a?a:b;
}

template<typename TR,typename T1,typename T2>
TR max_2(T1 a,T2 b)
{
    return a<b?b:a;
}


template<typename T1,typename T2>
auto max_3(T1 a,T2 b)->decltype(true?a:b)
{
    return b<a?a:b;
}

template<typename T1,typename T2>
auto max_4(T1 a,T2 b)-> typename std::decay_t<decltype(true ?a:b)>
{
    return b<a?a:b;
}

template<typename T1,typename T2>
auto max_5(T1 a,T2 b)
{
    return b<a?a:b;
}

template<typename T1,typename T2>
std::common_type_t<T1,T2>max_6(T1 a,T2 b)
{
    return b<a?a:b;
}
int main()
{
{
auto t1=max(2,9.0);
auto t2=max(9.0,2);
auto t3=max_2<double>(3.1,3);
auto t4=max_3(3,8.6);
auto t5=max_3(8.6,3);
int a=3;
double b=4.5;
auto t6=a<b?a:b;

std::cout<<typeid(t1).name()<<std::endl;
std::cout<<typeid(t2).name()<<std::endl;
std::cout<<typeid(t4).name()<<std::endl;
std::cout<<typeid(t5).name()<<std::endl;
std::cout<<t6<<std::endl;
std::cout<<typeid(t6).name()<<std::endl;

}



{
std::cout<<"test deducing the return type"<<std::endl;
int  t1=2;
int const &rt1=t1;
int  t2=4;
int const  &rt2=t2;
std::cout<<std::is_lvalue_reference<decltype(::max_3(rt1,rt2))>::value<<std::endl;
std::cout<<std::is_integral<decltype(::max_4(rt1,rt2))>::value<<std::endl;


std::cout<<std::is_lvalue_reference<decltype(::max_5(rt1,rt2))>::value<<std::endl;


std::cout<<std::is_same<decltype(::max_3(rt1,rt2)),decltype(::max_4(rt1,rt2))>::value<<std::endl;

int  t3=50;
int const &rt3=t3;
auto a=rt3;
std::cout<<std::is_lvalue_reference<decltype(a)>::value<<std::endl;

}



return 0;

}