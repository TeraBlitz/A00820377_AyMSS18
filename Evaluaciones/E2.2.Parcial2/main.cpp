#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Visitor;


class VG{
public:
    string title;
    int price;

    virtual VG* clone()=0;
    VG(){}
    void Concepcion();
    void Diseno();
    void Planificacion();
    void Produccion();
    void Pruebas();
};

class Strategy:public VG{
public:
    int levels;
    string dificulty;
    string bois;
    Strategy(){}
    Strategy(int l,string d, string b) {
        levels=l;
        dificulty=d;
        bois = b;

    }
    VG* clone() {
        return new Strategy(*this);
    }
    Strategy(const VG& temp) {
        title = (temp.title);
        price = (temp.price);
    }
};

class Adventure:public VG{
public:
    int world;
    string stas;
    string girls;
    Adventure(){}
    Adventure(int l,string d, string b) {
        world=l;
        stas=d;
        girls = b;

    }
    VG* clone() {
        return new Adventure(*this);
    }
    Adventure(const VG& temp) {
        title = (temp.title);
        price = (temp.price);
    }
};

class Aprendizaje :public VG{
public:
    int learn;
    string much;
    string pan;
    Aprendizaje (){}
    Aprendizaje (int l,string d, string b) {
        learn=l;
        much=d;
        pan = b;

    }
    VG* clone() {
        return new Aprendizaje (*this);
    }
    Aprendizaje (const VG& temp) {
        title = (temp.title);
        price = (temp.price);
    }
};

class Factory {
    template<class vgt>
    vgt* fMethod(string t, int p) {
        return new vgt(t, p);
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
                    sort(inv.begin(),inv.end(),[](const VG& a,const VG& b){return a.price<b.price;});
                }

            }
        }
    }
    void findGame(int id) {
        for(int i=0;i<inv.size();i++){
            if(inv[i]->title==id) {
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

class GameInformer


int main(){
   
    return 0;
}