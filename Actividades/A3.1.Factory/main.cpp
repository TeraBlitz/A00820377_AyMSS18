#include <iostream>

using namespace std;
class Veiculo
{
public:
    virtual void Ensamblador() = 0;
    virtual void Hojalateria() = 0;
    virtual void Pintura() = 0;
    virtual void Entrega() = 0;
};

class Carro : public Veiculo
{
public:
    void Ensamblador()
    {

    }
    void Hojalateria()
    {

    }
    void Pintura()
    {

    }
    void Entrega()
    {

    }
};


class Creator
{
    template<class Marca>
    Marca* factoryMethod()
    {
        return new Marca;
    }
public:

    template <class Marca>
    Marca* create()
    {
        Marca* temp;
        temp= factoryMethod<Marca>();
        temp->operacion1();
        temp->operacion2();
        return temp;
    }
};

int main()
{
    Creator* cliente = new Creator;
    Carro* miCarro = cliente->create<Carro>();

    return 1;
}