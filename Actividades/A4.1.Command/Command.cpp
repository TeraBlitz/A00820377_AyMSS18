#include<iostream>
using namespace std;
int operacion(int a, int b, int (*f)(int,int))
{
   return f(a,b);
}
int suma (int a, int b)
{
    return a+b;
}

int resta ( int a , int b)
{
    return a-b;
}
int duplica(int a)
{
    return a*a;
}

typedef int(*f)(int,int);
f getOperacion(char o)
{
    if(o=='r')
    {return resta;}
    else
    { return suma;}
}
int (*getf(char s))(int a,int b)
{
    if(s=='r')
    {return resta;}
    else
    { return suma;}
}
template<class T,class Function>
T doTemplateFunction(T a,T b,Function f)
{
    return f(a,b);
};
template <class Function>
Function getTemplateOperation(char s)
{
    if(s=='r')
        {return resta;}
    if(s=='d')
        {return duplica;}
    else
        { return suma;}
}

int main()
{
    cout<<operacion(542,241,suma)<<endl;
    cout<<operacion(542,150,resta)<<endl;
    cout<<getf('s')(2,2)<<endl;
    cout<<getOperacion('s')(2,2)<<endl;
    cout<<doTemplateFunction(2,2,suma);
    cout<<getTemplateOperation<int(*)(int,int)>('s')(2,2);
    //cout<<getTemplateOperation<int(*)(int)>('d')(3);
}
