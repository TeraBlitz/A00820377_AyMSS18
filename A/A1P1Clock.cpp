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

    static  Tiempo* getInstance()
    {
        if(instance==NULL)
        { instance = new Tiempo();}
        return instance;

    };


private:
    Tiempo(){}
    static Tiempo* instance;
};

Tiempo* Tiempo::instance=0;
int main() {
    //Tiempo x = new Tiempo;

    Tiempo* instance;
    //Tiempo::getInstance();
    instance->getTime();

    return 0;


}