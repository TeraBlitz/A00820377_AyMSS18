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
    Tablet(){}
    Tablet(string iN,int i)
    {
        nombre=iN;
        x=new int (i);
        y=new int (i);

    }

};

class SPhone : public  Movil
{
public:

    Movil* clone()
    {
        return new SPhone(*this);
    }
    SPhone(const SPhone& temp)
    {
        ensendido = (temp.ensendido);
        nombre = (temp.nombre);
        x=new int (*(temp.x));
        y=new int (*(temp.y));
    }
    SPhone(){}
    SPhone(string iN,int i)
    {
        nombre=iN;
        x=new int (i);
        y=new int (i);

    }

};

class SWatch : public  Movil
{
public:

    Movil* clone()
    {
        return new SWatch(*this);
    }
    SWatch(const SWatch& temp)
    {
        ensendido = (temp.ensendido);
        nombre = (temp.nombre);
        x=new int (*(temp.x));
        y=new int (*(temp.y));
    }
    SWatch(){}
    SWatch(string iN,int i)
    {
        nombre=iN;
        x=new int (i);
        y=new int (i);

    }
};

int main()
{
    Tablet t("una",1);
    Tablet* pt = new Tablet("dos",2);
    Tablet ct(t);

    SPhone p("un",10);
    SPhone* pp = new SPhone("doz",20);
    SPhone cp(p);

    SWatch w("uns",100);
    SWatch* pw = new SWatch("ds",200);
    SWatch cw(w);


}