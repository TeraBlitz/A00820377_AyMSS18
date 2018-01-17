//
// Created by Tera on 1/17/2018.
//

class Prototype
{
public:
    virtual Prototype* clone()=0;
};

class Concrete1 : public Prototype
{
public:
    Prototype* clone()
    {
        return new Concrete1(*this);
    }
};

int main()
{
    Concrete1* c1 = new Concrete1;
}
