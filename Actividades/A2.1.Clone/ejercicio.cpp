#include <iostream>
using namespace std;

class Movil
{
public:
    bool ensendido;
    string nombre;
    int* x,*y;
    virtual Movil* clone()=0;
    virtual void encernder();
    virtual void apagar();
    virtual  void reiniciar();
    virtual void restaurar();
};

void Movil::encernder()
{
    if(!ensendido)
    {
        ensendido=true;
        cout<<nombre<<" is turning on";
    }
    else
    {
        cout<<nombre<<" is turning already on";
    }
}
void Movil::apagar()
{
    if(!ensendido)
    {
        cout<<nombre<<" is turning already off";
    }
    else
    {
        ensendido=false;
        cout<<nombre<<" is turning off";
    }


}
void Movil::reiniciar()
{
    ensendido=false;
    ensendido=true;
    cout<<nombre<<" se a reiniciado";
}
void Movil::restaurar()
{
    cout<<nombre<<" se a restaurado";
}


class Tablet : public  Movil
{
public:
    Movil* clone()
    {
        return new Tablet(*this);
    }
    Tablet(const Tablet& temp)
    {
        ensendido = (temp.ensendido);
        nombre = (temp.nombre);
        x=new int (*(temp.x));
        y=new int (*(temp.y));
    }
};

class SPhone : public  Movil
{
public:
    Movil* clone()
    {
        return new SPhone(*this);
    }

};

class SWatch : public  Movil
{
public:
    Movil* clone()
    {
        return new SWatch(*this);
    }
};

int main()
{

}