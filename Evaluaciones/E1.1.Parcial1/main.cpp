#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Command{
public:
    virtual void execute() = 0;
};

class Receiver
{
public:
    void sendSMS()
    {
        cout << "sms sent"<<endl;
    }
    void call()
    {
        cout << "call sent"<<endl;
    }
    void sendEmail()
    {
        cout << "email sent"<<endl;
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

class ConcreteCommandCall : public Command
{
private:
    Receiver *r;
public:
    ConcreteCommandCall(Receiver *r_temp) : r(r_temp){}
    void execute()
    {
        r->call();
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
        r->sendSMS();
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
        r->sendEmail();
    }
};

class Contacto{
public:
    string sNombre,iId;
    string sApellido;
    string sContacto;
    string iTelefono;
    string sEmail;
    Caller *cmd;
    Receiver *re;
    Contacto(string sN,string sA,string sC, string iT,string sE){
        sNombre=sN;
        sA=sApellido;
        sC=sContacto;
        iT=iTelefono;
        sE=sEmail;
    };
    Contacto(){};
    void contact()
    {
        cmd->executeAction();
    }


    //virtual void contact()=0;
    static Contacto *make_contacto(string sN, string sA, string sE, string iT,string sC);
};

class SendEmail : public Contacto{
private:
    SendEmail(string sN, string sA, string sE){
        sNombre=sN;
        sApellido=sA;
        sEmail=sE;
        re = new Receiver;
        cmd = new Caller;
        cmd->setCommand( new ConcreteCommandEmail(re));
        contact();
    };
    static SendEmail* instance;
public:
    static  SendEmail* getInstance(string sN, string sA, string sE)
    {
        instance = new SendEmail(sN,sA,sE);
        delete instance;
    }
    string sSubject;
    string sBody;

};

class SendSMS : public  Contacto{
private:

    SendSMS(string iT)
    {
        iT=iTelefono;
        re = new Receiver;
        cmd = new Caller;
        cmd->setCommand( new ConcreteCommandSMS(re));
        contact();
    };
    static SendSMS* instance;
public:

    static  SendSMS* getInstance(string iT)
    {
        instance = new SendSMS(iT);
        delete instance;
    };
};

class Call : public  Contacto{
private:
    Call(string iT){
        iT=iTelefono;
        re = new Receiver;
        cmd = new Caller;
        cmd->setCommand( new ConcreteCommandCall(re));
        contact();

    };
    static Call* instance;
public:
    string message;
    static  Call* getInstance(string iT)
    {
        instance = new Call(iT);
        delete instance;
    }
};

SendSMS* SendSMS::instance=0;
SendEmail* SendEmail::instance=0;
Call* Call::instance=0;
int main() {
    string id,iCell;
    string sName,sApeido,sEmail,sContact,sCrap;
    fstream myfile( "customers.csv", ios_base::in);
    while(myfile)
    {
        string line;
        string word;
        getline(myfile,line);
        stringstream ss(line);
        while(getline(myfile,line))
        {
            stringstream sss(line);
            getline(sss, word,',');
            id=(word);
            getline(sss, word,',');
            sName=word;
            getline(sss, word,',');
            sApeido=word;
            getline(sss, word,',');
            sContact=word;
            getline(sss, word,',');
            sEmail=word;
            getline(sss, word,',');
            iCell=(word);
            getline(sss, word,',');
            sCrap=word;
            getline(sss, word,',');
            sCrap=word;
            getline(sss, word,',');
            sCrap=word;
            Contacto cliente(sName,sApeido,sContact,iCell,sEmail);
            cliente.make_contacto(sName,sApeido,sEmail,iCell,sContact);



        }

    }
    return 0;
}
Contacto *Contacto::make_contacto(string sN, string sA, string sE, string iT,string sC)
{
    if(sC=="mail"){
        return SendEmail::getInstance(sN,sA ,sE);
    }
    if(sC=="phone_call"){
        return Call::getInstance(iT);
    }
    else{
        return SendSMS::getInstance(iT);
    }

}
