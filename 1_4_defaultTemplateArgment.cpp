#include<iostream>
#include<type_traits>
template<typename T1,typename T2,
         typename RT=std::decay_t<decltype(true?T1():T2())>>
RT max(T1 a,T2 b)
{
    return b<a?a:b;
}

template<typename T1,typename T2,
         typename RT=std::common_type_t<T1,T2>>
RT max_1(T1 a,T2 b)
{
    return b<a?a:b;
}

int main()
{
{
std::cout<<::max(1,2)<<std::endl;
}
return 0;
}