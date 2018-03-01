#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Command{
public:
    virtual void execute() = 0;
};

class Receiver
{
public:
    void actionSMS()
    {
        cout << "CONTACTING SMS\n";
    }
    void actionPHONE()
    {
        cout << "CONTACTING PHONE\n";
    }
    void actionEMAIL()
    {
        cout << "CONTACTING EMAIL\n";
    }
};

class Caller
{
private:
    Command *cmd;
public:
    void setCommand(Command *cmd_temp)
    {
        cmd = cmd_temp;
    }
    void executeAction()
    {
        cmd->execute();
    }
};

class ConcreteCommandPhone : public Command
{
private:
    Receiver *r;
public:
    ConcreteCommandPhone(Receiver *r_temp) : r(r_temp){}
    void execute()
    {
        r->actionPHONE();
    }
};

class ConcreteCommandSMS : public Command
{
private:
    Receiver *r;
public:
    ConcreteCommandSMS(Receiver *r_temp) : r(r_temp){}
    void execute()
    {
        r->actionSMS();
    }
};

class ConcreteCommandEmail : public Command
{
private:
    Receiver *r;
public:
    ConcreteCommandEmail(Receiver *r_temp) : r(r_temp){}
    void execute()
    {
        r->actionEMAIL();
    }
};

class Cliente
{
private:
    string id;
    string nombre;
    string apellido;
    string type_comm;
    string mail;
    string phone;
    string calle;
    string numero;
    string colonia;
    Caller *cmd;
    Receiver *re;
public:
    Cliente() {}
    Cliente(string i, string no, string a, string t, string m, string p, string ca, string nu, string co):
            id (i), nombre (no), apellido(a), type_comm(t), mail(m), phone(p), calle(ca), numero(nu), colonia(co)
    {
        re = new Receiver;
        cmd = new Caller;
        if(type_comm == "mail")
        {
            cmd->setCommand( new ConcreteCommandEmail(re));
        }
        else if(type_comm == "sms")
        {
            cmd->setCommand( new ConcreteCommandSMS(re));
        }
        else if(type_comm == "phone_call")
        {
            cmd->setCommand( new ConcreteCommandPhone(re));
        }
    }
    void contact()
    {
        cmd->executeAction();
    }
};

class Database
{
public:

private:
    static Database* instance;
    static int counter;
    vector<Cliente>  cliente;
    Database(){     }
    ~Database() {   }
    static void addRef()
    {
        ++counter;
    }
    static void destroyRef()
    {
        --counter;
    }
public:
    static Database* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new Database;
        }
        addRef();
        return instance;
    }
    static void destroyInstance()
    {
        destroyRef();
        if(instance!=nullptr && counter == 0)
        {
            delete instance;
            instance = nullptr;
        }
    }
    void readFile()
    {
        string line, id_d,name_d,type_d,mail_d,phone_d,street_d,number_d,col_d;
        ifstream file;
        file.open("customers.csv");
        while (getline(file, id_d,',')){
            getline(file,type_d,',');
            getline(file,mail_d,',');
            getline(file,phone_d,',');
            getline(file,street_d,',');
            getline(file,number_d,',');
            getline(file,col_d,',');
        }
        Cliente *boi = new Cliente(id_d,type_d,mail_d,phone_d,street_d,number_d
    }

};

int main()
{
    Cliente *c = new Cliente("id","nombre","apellido","sms", "mail", "phone","calle", "numero", "colonia");
    Cliente *e = new Cliente("id","nombre","apellido","mail", "mail", "phone","calle", "numero", "colonia");
    c->contact();
    e->contact();
}