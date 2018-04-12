#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class VG;
class Visitor;
class Reader
{
public:
    Reader(){};
    void update()
    {
        cout<<"Reader got magazine"<<endl;
    }

};
class GameInformer
{
public:

    vector<Reader*> subs;
    void sub(Reader *nws)
    {
        subs.push_back(nws);
    }
    void unsub(Reader *nws){
        for(int i=0;i<subs.size();i++){
            if(subs[i]==nws)
            {
                subs.erase(subs.begin()+i);
            }
        }
    }
    void notify(){
        for(int i=0;i<subs.size();i++){
            string spesificMessage;
            subs[i]->update();
        }
    }
};



class VG
{
public:
    string title;
    int price;
    int id;
    vector<GameInformer> readers;
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

    bool operator < (const VG& cp) const
    {
        return (price < cp.price);
    }
    bool operator > (const VG& cp) const
    {
        return (price > cp.price);
    }

    virtual void accept(Visitor*) = 0;
};

template<class SubClass>
class CloneCRTP: public VG
{
public:
    VG* clone()
    {
        return new SubClass(dynamic_cast<SubClass&> (*this));
    }
};

class Strategy: public CloneCRTP<Strategy>
{
public:
    int levels;
    string dificulty;
    string bois;
    Strategy(){}
    Strategy(string t,int i,int p)
    {

        title=t;
        price=p;
        id=i;
        for(int x;readers.size()>x;x++)
        {
            readers[x].notify();
        }
    }
    VG* clone() {
        return new Strategy(*this);

    }
    Strategy(const VG& temp) {
        title = (temp.title);
        price = (temp.price);
        id = (temp.id);
        for(int x;readers.size()>x;x++)
        {
            readers[x].notify();
        }
    }
    void accept(Visitor* visitor);
};

class Adventure: public CloneCRTP<Adventure>
{
public:
    int world;
    string stas;
    string girls;
    Adventure(){}
    Adventure(string t,int i,int p) {

        title=t;
        price=p;
        id=i;
        for(int x;readers.size()>x;x++)
        {
            readers[x].notify();
        }
    }
    VG* clone() {
        return new Adventure(*this);
    }
    Adventure(const VG& temp) {
        title = (temp.title);
        price = (temp.price);
        id = (temp.id);

        for(int x;readers.size()>x;x++)
        {
            readers[x].notify();
        };
    }
    void accept(Visitor* visitor);
};

class Aprendizaje : public CloneCRTP<Aprendizaje>
{
public:
    int learn;
    string much;
    string pan;
    Aprendizaje (){}
    Aprendizaje (string t,int i,int p) {

        title=t;
        price=p;
        id=i;
        for(int x;readers.size()>x;x++)
        {
            readers[x].notify();
        }
    }
    VG* clone() {
        return new Aprendizaje (*this);
    }
    Aprendizaje (const VG& temp) {
        title = (temp.title);
        price = (temp.price);
        id = (temp.id);
        for(int x;readers.size()>x;x++)
        {
            readers[x].notify();
        }
    }
    void accept(Visitor* visitor);
};

class Factory
{
private:
        static Factory *instance;
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

    class Visitor
    {
    public:
        virtual void visit(Strategy&) = 0;
        virtual void visit(Adventure&) = 0;
        virtual void visit(Aprendizaje&) = 0;
    };

    class IncVisitor : public Visitor
    {
    public:
        void visit(Strategy& s)
        {
            s.price = s.price*1.1;
        }
        void visit(Adventure& a)
        {
            a.price = a.price*1.1;
        }
        void visit(Aprendizaje& l)
        {
            l.price = l.price*1.1;
        }
    };
    class DecVisitor: public Visitor
    {
    public:
        void visit(Strategy& s)
        {
            s.price = s.price/1.1;
        }
        void visit(Adventure& a)
        {
            a.price = a.price/1.1;
        }
        void visit(Aprendizaje& l)
        {
            l.price = l.price/1.1;
        }

    };

    void Strategy::accept(Visitor* visitor)
    {
        visitor->visit(*this);
    }
    void Adventure::accept(Visitor* visitor)
    {
        visitor->visit(*this);
    }
    void Aprendizaje::accept(Visitor* visitor)
    {
        visitor->visit(*this);
    }




class Almacen {
public:
    int sn = 0;
    vector<VG *> inv;
    vector<VG *> past;
    vector<bool> act;

    void addGame(VG *gm) {
        past.push_back(gm);
        inv.push_back(gm);
        act.push_back(true);
    }

    void deleteGame(string t) {
        for (int i = 0; i < inv.size(); i++) {
            if (inv[i]->title == t) {
                past.push_back(inv[i]);
                act.push_back(false);
                inv.erase(inv.begin() + i - 1);
            }
        }
    }

    void deleteGame(int x) {
        for (int i = 0; i < inv.size(); i++) {
            if (inv[i]->id == x) {
                past.push_back(inv[i]);
                act.push_back(false);
                inv.erase(inv.begin() + i - 1);
            }
        }
    }

    void undo() {
        if (act.front()) {
            for (int i = 0; i < inv.size(); i++) {
                if (inv[i] == past.front()) {
                    act.erase(act.begin());
                    inv.erase(inv.begin() + i - 1);
                    past.erase(past.begin());
                }
            }
        } else {
            inv.push_back(past.front());
            act.erase(act.begin());
            past.erase(past.begin());
        }

    }

    void orderGames(bool t) {
        if (t)
            sort(inv.begin(), inv.end());
        else
            sort(inv.begin(), inv.end(), greater<VG *>());
    }

    void findGame(string title) {
        for (int i = 0; i < inv.size(); i++) {
            if (inv[i]->title == title) {
                inv.erase(inv.begin() + i - 1);
            }
        }
    }

    void findGame(int id) {
        for (int i = 0; i < inv.size(); i++) {
            if (inv[i]->id == id) {
                inv.erase(inv.begin() + i - 1);
            }
        }
    }

    void howMany() {
        cout << "there are " << inv.size() << " games in inventory" << endl;
    }

    void listAll() {
        for (int i = 0; i < inv.size(); i++) {
            cout << inv[i]->title << endl;
        }
    }

    void accept(Visitor *visitor) {
        for (int i = 0; i < inv.size(); i++) {
            inv[i]->accept(visitor);
        }
    }

    void mod(bool t) {
        if (t) {
            IncVisitor *incVisitor = new IncVisitor;
            accept(incVisitor);
        } else {
            DecVisitor *decvisitor = new DecVisitor;
            accept(decvisitor);
        }
    }

    void menu(Almacen a) {
        int s = 1;
        while (s != 0) {
            cout<< "Menu de inventario \nOpciones:\n1)Add Game \n 2)Delete Game \n3)Undo last add/delete \n4)Order avaiable games\n5)Look for games in stock\n6)Search available games\n7)Print available games\n8)Change prices\n0)exit menu"<<endl;
            cin >> s;
            if (s == 1) {
                cout << "Insert game name: ";
                string VGn;
                cin >> VGn;
                cout << endl;
                int ch = 0;
                while (1) {
                    cout << "Choose game genere:\n1)Adventure\n2)Strategy\n3)Learning\n";
                    cin >> ch;
                    if (ch == 1) {
                        cout << "Insert price: ";
                        int p;
                        cin >> p;
                        cout << endl;
                        cout << "Insert unique id";
                        int id;
                        cin>>id;
                        a.addGame(new Adventure(VGn, p, id));
                    }
                    else if (ch == 2) {
                        cout << "Insert price: ";
                        int p;
                        cin >> p;
                        cout << endl;
                        cout << "Insert unique id";
                        int id;
                        cin>>id;
                        a.addGame(new Strategy(VGn, p, id));
                    }
                    else if (ch == 3) {
                        cout << "Insert price: ";
                        int p;
                        cin >> p;
                        cout << endl;
                        cout << "Insert unique id";
                        int id;
                        cin>>id;
                        a.addGame(new Aprendizaje(VGn, p, id));
                    } else {
                        cout << endl << "Invalid answer, try again" << endl;
                    }
                    if(ch ==1 || ch == 2 || ch == 3)
                    {break;}
                }
            }
            if (s == 2) {
                cout << endl << "Do you want to delete by 1)ID or 2)Title" << endl;
                int ch = 0;
                cin >> ch;
                while (1) {
                    cout << endl << "Do you want to delete by 1)ID or 2)Title" << endl;
                    cin >> ch;
                    if (ch == 1) {
                        cout << endl << "What id do you want to delete: ";
                        int id;
                        cin >> id;
                        a.deleteGame(id);
                    }
                    else if (ch == 2) {
                        cout << endl << "What title do you want to delete: ";
                        string id;
                        cin >> id;
                        a.deleteGame(id);
                    } else {
                        cout << endl << "Invalid answer, try again" << endl;
                    }
                    if(ch ==1 || ch == 2)
                    {break;}
                }
            }
            if (s == 3) {
                cout << "Last add/delete undone";
                a.undo();
            }
            if (s == 4) {
                int ch = 0;
                while (1) {
                    cout << "Order by: 1)higher price 2)Lower price: ";
                    cin >> ch;
                    if (ch == 1) {
                        a.orderGames(true);
                    }
                    else if (ch == 2) {
                        a.orderGames(false);
                    } else {
                        cout << endl << "Invalid answer, try again" << endl;
                    }
                    if(ch ==1 || ch == 2)
                    {break;}
                }

            }
            if (s == 5) {
                a.listAll();
            }
            if (s == 6) {
                int ch = 0;
                while (1) {
                    cout << "Search by: 1)Id 2)Title : ";
                    cin >> ch;
                    if (ch == 1) {
                        cout << endl << "Insert id: ";
                        int id;
                        cin >> id;
                        a.findGame(id);
                    }
                    else if (ch == 2) {
                        cout << endl << "Insert title: ";
                        string id;
                        cin >> id;
                        a.findGame(id);
                    } else {
                        cout << endl << "Invalid answer, try again" << endl;
                    }
                    if(ch ==1 || ch == 2)
                    {break;}
                }
            }
            if (s == 7) {
                a.listAll();
            }
            if (s == 8) {
                int ch = 0;
                while (1) {
                    cout << "Choose: 1)Raise 2)Lower prices :";
                    cin >> ch;
                    if (ch == 1) {
                        a.mod(true);
                    }
                    else if (ch == 2) {
                        a.mod(false);
                    } else {
                        cout << endl << "Invalid answer, try again" << endl;
                    }
                    if(ch ==1 || ch == 2)
                    {break;}
                }
            }
        }

    }
};



Factory* Factory::instance = nullptr;
int main(){
    Almacen mazen;
    GameInformer GI;
    GI.sub(new Reader());
    mazen.menu(mazen);

return 0;
}