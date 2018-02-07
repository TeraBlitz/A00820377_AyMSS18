#include<iostream>
using namespace std;

int GCommand1 (int a)
{
    return a;
}
int GCommand2 (int a)
{
    return a;
}

template<class T,class Function>
T GenericConcreateCommand(T a,Function Caller)
{
    return Caller(a);
};
