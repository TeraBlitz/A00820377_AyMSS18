#include <iostream>

using namespace std;

class Visitor;

class Printer
{
public:
    virtual Printer* clone()=0;
    Printer(){}
    void Creacion()
    {
    }
    void Deployment()
    {
    }
    virtual void accept(Visitor*) = 0;
};

template<class SubClass>
class CloneCRTP: public Printer
{
public:
    Printer* clone()
    {
        return new SubClass(dynamic_cast<SubClass&> (*this));
    }
};

class Laser: public CloneCRTP<Laser>
{
public:
    string image;
    Laser(){}
    Laser(string t,int i,int p)
    {
    }
    Printer* clone() {
        return new Laser(*this);

    }
    void accept(Visitor* visitor);
};

class Inyeccion: public CloneCRTP<Inyeccion>
{
public:
    string wid;
    Inyeccion(){}

    Printer* clone() {
        return new Inyeccion(*this);
    }

    void accept(Visitor* visitor);
};

class PDF : public CloneCRTP<PDF>
{
public:
    int learn;
    string much;
    string pan;
    PDF (){}

    Printer* clone() {
        return new PDF (*this);
    }

    void accept(Visitor* visitor);
};


class Postscript : public CloneCRTP<Postscript>
{
public:
    Postscript (){}

    Printer* clone() {
        return new Postscript (*this);
    }

    void accept(Visitor* visitor);
};


class OtherPrinters : public CloneCRTP<OtherPrinters>
{
public:
    string sName;
    OtherPrinters (){}
    OtherPrinters(string n)
    {
        sName=n;
    }

    Printer* clone() {
        return new OtherPrinters (*this);
    }

    void accept(Visitor* visitor);
};

class Documents
{
public:
    virtual Documents* clone()=0;
    Documents(){}
};

template<class SubClass>
class CloneCR: public Documents
{
public:
    Documents* clone()
    {
        return new SubClass(dynamic_cast<SubClass&> (*this));
    }
};

class SimpleText: public CloneCR<SimpleText>
{
public:
    SimpleText(){}
    SimpleText(string t,int i,int p)
    {
    }
    Documents* clone() {
        return new SimpleText(*this);

    }
};

class FormatText: public CloneCR<FormatText>
{
public:
    FormatText(){}

    Documents* clone() {
        return new FormatText(*this);
    }
};

class Imagges : public CloneCR<Imagges>
{
public:
    Imagges (){}

    Documents* clone() {
        return new Imagges (*this);
    }
};


class OtherDocuments : public CloneCR<OtherDocuments>
{
public:
    string sName;
    OtherDocuments (){}
    OtherDocuments(string n)
    {
        sName=n;
    }

    Documents* clone() {
        return new OtherDocuments (*this);
    }
};


class Factory
{
private:
    static Factory *instance;
    static int counter;
public:
    template<class ptr>
    ptr* fMethod(string t, int p) {
        return new ptr(t, p);
    }
    static Factory* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new Factory;
        }
        return instance;
    }
    static void destoryInstance()
    {
        if(instance != nullptr && counter == 0)
        {
            delete instance;
            instance = nullptr;
        }
    }

    template<class ptr>
    ptr *execute(string t, int p) {
        ptr newP = fMethod<ptr>(t, p);
        newP->Conception();
        newP->Produccion();
        return newP;
    }
};

class Visitor
{
public:
    virtual void visit(Laser&) = 0;
    virtual void visit(Inyeccion&) = 0;
    virtual void visit(PDF&) = 0;
    virtual void visit(Postscript&) = 0;
    virtual void visit(OtherPrinters&) = 0;


};

class PrintVisitor : public Visitor
{
public:
    void visit(Laser& s)
    {
        cout<<"laser printer printing\n";
    }
    void visit(Inyeccion& a)
    {

        cout<<"Inyeccion printing\n";
    }
    void visit(PDF& l)
    {
        cout<<"PDF printing\n";
    }
    void visit(Postscript& x)
    {
        cout<<"Poscript printing\n";
    }
    void visit(OtherPrinters& x)
    {
        cout<<x.sName<<" printing \n";
    }
};

void Laser::accept(Visitor* visitor)
{
    visitor->visit(*this);
}
void Inyeccion::accept(Visitor* visitor)
{
    visitor->visit(*this);
}
void PDF::accept(Visitor* visitor)
{
    visitor->visit(*this);
}
void Postscript::accept(Visitor* visitor)
{
    visitor->visit(*this);
}
void OtherPrinters::accept(Visitor* visitor)
{
    visitor->visit(*this);
}

void accept(Visitor *visitor)
{
    accept(visitor);
}

Factory* Factory::instance = nullptr;

int main()
{
    OtherDocuments TarjetaDePresentacion("Tarjeta de presentacion");
    OtherPrinters ImpPortatil("Impresora Portatil");




    return 0;
}