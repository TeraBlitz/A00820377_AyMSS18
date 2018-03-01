#include <iostream>

using namespace std;

class Painting
{
public:
    string artist;
    int yearPainted;
    int price;
    int yearBought;
};

class Buy{
public:
    string sellerName;
    string sellerAdress;
    int priceSold;
    Painting paintingSold;
};

class Gallery
{
    Painting owned[];
    Painting findPainting(int year,string artist)
    {
        
    }

};
int main() {

    return 0;
}