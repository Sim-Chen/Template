#include<iostream>

int max(int a,int b)
{
    return b<a?a:b;
}

template<typename T>
T max(T a,T b)
{
    return b<a?a:b;
}

int main()
{

{
::max(7,2);//prefer call nontemplate for two ints
::max(3.0,4.0);//max<double>
::max('a','b');//max<char>
::max<>(1,2);//max<int>
::max<double>(2,3);//max<double>
::max('a',42.5);//call nontemplate for two ints


}
return 0;
}