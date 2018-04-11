#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Visitor;
class GameInformer
{
public:
    virtual void update(string, VG*) = 0;
};


class VG{
public:
    string title;
    int price;
    vector<GameInformer*> observers;
    virtual VG* clone()=0;
    VG(){}
    void Concepcion()
    {
        cout<<title<<" esta en concepcion..."<<endl;
    }
    void Diseno(){
        cout<<title<<" esta en diseno..."<<endl;
    }
    void Planificacion(){

        cout<<title<<" esta en planificacion..."<<endl;
    }
    void Produccion(){
        cout<<title<<" esta en produccion..."<<endl;
    }
    void Pruebas(){
        cout<<title<<" esta en pruebas..."<<endl;
    }
    virtual void accept(IVisitor*) = 0;
    void attach(GameInformer* o){
        observers.push_back(o);
    }
    void dettach(GameInformer* o)
    {
        for(int i = 0; i < observers.size();i++)
        {
            if(observers[i] == o)
            {
                observers.erase(observers.begin()+i);
                return;
            }
        }
    }
    void notifyAll(VG* vg)
    {
        for(int i = 0; i < observers.size(); i++)
        {
            observers[i]->update("game out ", vg);
        }
    }
    bool operator < (const VG& cp) const
    {
        return (price < cp.price);
    }
    bool operator > (const VG& cp) const
    {
        return (price > cp.price);
    }
};

template<class SubClass>
class CloneCRTP: public VG{
public:
    VG* clone()
    {
        return new SubClass(dynamic_cast<SubClass&> (*this));
    }
};

class Strategy: public CloneCRTP<Strategy>{
public:
    int levels;
    string dificulty;
    string bois;
    Strategy(){}
    Strategy(int l,string d, string b) {
        levels=l;
        dificulty=d;
        bois = b;
        notifyAll(this);
    }
    VG* clone() {
        return new Strategy(*this);
    }
    Strategy(const VG& temp) {
        title = (temp.title);
        price = (temp.price);
        notifyAll(this);
    }
    void accept(IVisitor* visitor);
};

class Adventure: public CloneCRTP<Adventure>{
public:
    int world;
    string stas;
    string girls;
    Adventure(){}
    Adventure(int l,string d, string b) {
        world=l;
        stas=d;
        girls = b;
        notifyAll(this);
    }
    VG* clone() {
        return new Adventure(*this);
        notifyAll(this);
    }
    Adventure(const VG& temp) {
        title = (temp.title);
        price = (temp.price);
        notifyAll(this);
    }
    void accept(IVisitor* visitor);
};

class Aprendizaje : public CloneCRTP<Aprendizaje>{
public:
    int learn;
    string much;
    string pan;
    Aprendizaje (){}
    Aprendizaje (int l,string d, string b) {
        learn=l;
        much=d;
        pan = b;
        notifyAll(this);
    }
    VG* clone() {
        return new Aprendizaje (*this);
    }
    Aprendizaje (const VG& temp) {
        title = (temp.title);
        price = (temp.price);
        notifyAll(this);
    }
    void accept(IVisitor* visitor);
};

class Factory {
private:
        static Factory* instance;
        static int counter;
public:
    template<class vgt>
    vgt* fMethod(string t, int p) {
        return new vgt(t, p);
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


    template<class vgt>
    vgt *execute(string t, int p) {
        vgt newG = fMethod<vgt>(t, p);
        newG->Conception();
        newG->Diseno();
        newG->Planificacion();
        newG->Produccion();
        newG->Pruebas();
        return newG;
    }
};



class Almacen{
public:
    int sn=0;
 vector<VG*> inv;
    void addGame(VG* gm){
        inv.push_back(gm);
    }
    void deleteGame(string t){
        for(int i=0;i<inv.size();i++){
            if(inv[i]->title==t) {
                inv.erase(inv.begin()+i-1);
            }
        }
    }
    void undo(int num);
    void orderGames(bool t){
        if(t){
            for(int i=0;i<inv.size();i++){
                if(t){
                }
            }
        }
    }
    void findGame(string title) {
        for(int i=0;i<inv.size();i++){
            if(inv[i]->title==title) {
                inv.erase(inv.begin()+i-1);
            }
        }
    }
    void howMany(){
        cout<<"there are "<<inv.size()<<" games in inventory"<<endl;
    }
    void listAll(){
        for(int i=0;i<inv.size();i++){
            cout<<inv[i]->title<<endl;
        }
    }
    void mod(Almacen, Visitor* visitor);
    void menu();

};


int main(){

}