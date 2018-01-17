#include <iostream>
#include <ctime>

using namespace std;
class Tiempo {
public:
    void getTime() {
        time_t t = time(0);
        struct tm *now = localtime(&t);
        cout << (now->tm_year + 1900) << '-'
             << (now->tm_mon + 1) << '-'
             << now->tm_mday << ' '
             << now->tm_hour << ':'
             << now->tm_min << ':'
             << now->tm_sec
             << endl;
    }
    static int instancia;

    static  Tiempo* getInstance()
    {

        if(instance==NULL)
        {
            instance = new Tiempo();
        }

        instancia++;

        return instance;
    };

    static void destroyInstance()
    {
        instancia--;
        if(instancia==0)
        {
            delete instance;
            cout<<"Todas las instancias an sido destrudias correctamente"<<endl;
        }
        else
        {
            cout<< "Aun queda(n) "<<instancia<<" instancias activas"<<endl;
        }
    }


private:
    Tiempo(){}
    static Tiempo* instance;
};

Tiempo* Tiempo::instance=0;
int Tiempo::instancia=0;

int main() {
    //Tiempo x = new Tiempo;

    Tiempo *instance;
    Tiempo::getInstance();
    Tiempo::getInstance();
    instance->getTime();
    Tiempo::destroyInstance();
    Tiempo::destroyInstance();

    return 0;
}

}