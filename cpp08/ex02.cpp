#include<iostream>
#include<deque>
#include<stack>
#include<vector>
template<typename T>//, typename Container = std::vector<T>>
class MutantStack:public std::stack<T>//, Container>
{
    public:
    MutantStack():std::stack<T>()
    {
    }
    MutantStack(MutantStack const &other):std::stack<T>(other)
    {
    }
     ~MutantStack()
    {
    }
    MutantStack &operator=(MutantStack const &other)
    {
        this->c = other.c;
        return *this;
    }
  //  using std::stack<T, Container>::c;
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
    const_iterator begin() const
    {
        return this->c.begin();
    }
    const_iterator end() const
    {
        return this->c.end();
    }
};

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}
