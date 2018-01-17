#include <iostream>
using namespace std;

class Prueba
{
public:
    int* val;
    int val2;
    Prueba()
    {
        cout<<"Default constructor";

    }

    Prueba(int val):val( new int(val)), val2(val)
    {
        cout<<"Params "<<val<<endl;
    }
    Prueba(const Prueba& temp)
    {
        val2 = *(temp.val);
        val = new int(*(temp.val));
    }

};


int main() {
    Prueba p;
    Prueba* z = new Prueba(2);
    cout << "antes" << *(z->val) << endl;
    Prueba w=*z;
    cout<<"copia"<<*(w.val)<<endl;
    *(w.val)=8;
    cout<<"original z"<<*(z->val)<<endl;
    cout<<"copia w"<<*(w.val)<<endl;
    return 0;
}
