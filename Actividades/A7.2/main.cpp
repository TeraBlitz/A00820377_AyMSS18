#include <iostream>
using namespace std;

class Foo{
    int* pointer;
public:
    explicit  Foo(int i=0) : pointer(new int(i)){cout<<"const def/para"<<endl;}
    Foo(const Foo& original)
    {
        pointer = new int(0);
        cout<<"copy const"<<endl;
    }
    Foo(Foo&& temporal)
    {
        swap(this->pointer, temporal.pointer);
        temporal.pointer=nullptr;
        cout<<"coppy"<<endl;

    }
    Foo devuelveFoo(Foo a)
    {
        return a;
    }
    ~Foo(){delete pointer; cout<<"dest"<<endl;}

};

int main() {
    Foo a;
    Foo b(a);
    Foo c(a.devuelveFoo(a));
}