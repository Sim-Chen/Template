#include<iostream>
#include<vector>
#include<cassert>
#include<string>
template<typename T,typename Container=std::vector<T>>
class Stack
{
private:
    Container elems;
public:
   /*  Stack(Stack const & rhs);
    Stack& operator=(Stack const &rhs); */
    void push(T const & elem);
    void pop();
    T const & top()const;
    bool empty()const{return elems.empty();}
    template<typename U>
    friend std::ostream& operator<<(std::ostream &os,Stack<U> const &s)
    {
        for(auto i:s.elems)
            std::cout<<i<<" ";
        return os;
    }
};

template<typename T,typename Container>
void Stack<T,Container>::push(T const &elem)
{
    elems.push_back(elem);
}
template<typename T,typename Container>
void Stack<T,Container>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}
template<typename T,typename Container>
T const& Stack<T,Container>::top()const
{
    assert(!elems.empty());
    return elems.back();
}





int main()
{
    Stack<int> int_Stack;
    int_Stack.push(1);
    int_Stack.push(2);
    int_Stack.push(3);
    std::cout<<int_Stack<<std::endl;

    return 0;
}