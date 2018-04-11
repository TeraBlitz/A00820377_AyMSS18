#include <iostream>
using namespace std;

class Foo{
int value;
int* pointer;
public:
    ///         ///predefine el valor de value
    explicit Foo(int value = 0): value(value), pointer(new int[value]){cout<<"param const"<<endl;}
    Foo( const Foo& red){cout<<"coy const"<<endl;}
    Foo& operator=(const Foo& ref)
    {
        cout<<"copy assig"<<endl;
        this->value=ref.value;
        this->pointer= new int[value];
        ///ciclo para poiar cada valor del areglo pointer
        ///ooooooooooooooooooooooooooooo
        Foo temp(ref);
        swap(value,temp.value);
        swap(pointer,temp.pointer);
        return *this;
    }

    Foo& operator=(Foo&& temp)
    {
        cout<<"MOVEgi assig"<<endl;
        swap(value,temp.value);
        swap(pointer,temp.pointer);
        return *this;
    }
};

int main() {
    Foo a(5);
    Foo b;
    b=a;
    return 0;
}
