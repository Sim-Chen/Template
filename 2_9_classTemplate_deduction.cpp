#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<deque>
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
    Stack()=default;
    Stack(Stack const &rhs)
    {
        elems=rhs.elems;
    }
    Stack& operator=(Stack const &rhs)
    {
        if(this!=&rhs)
        {
            this->elems=rhs.elems;
        }
        return *this;
    }
    T const & top()const;
    bool empty()const{return elems.empty();}
    template<typename U>
    friend std::ostream& operator<<(std::ostream &os,Stack<U,Container> const &s)
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
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    std::cout<<s1<<std::endl;
    Stack<int> s2=s1;
    std::cout<<s2<<std::endl;
    Stack s3=s1;
    std::cout<<s3<<std::endl;
    return 0;
}