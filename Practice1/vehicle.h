//
// Created by cocol on 19/02/2022.
//

#ifndef PRACTICE1_VEHICLE_H
#define PRACTICE1_VEHICLE_H
#include <string>
using namespace std;

struct Vehicle{
    string Brand ="";
    string Model ="";
    string Plate ="" ;
    int ManufacturerYear = 0;
    float Price = 0;
};
void kbRead(Vehicle &v,int size);
void kbRead(Vehicle *v,int size);
void showOnScreen(const Vehicle &v,int size);
void showOnScreen(const Vehicle *v,int size);
int findMostExpensive(const Vehicle *v,int size);
void platesSECharacter (const Vehicle *v,int size);
void platesPalyndrome (const Vehicle *v,int size);

class vehicle {
private:
    string _brand ="";
    string _model ="";
    string _plate="";
    int _manufacturerYear = 0;
    float _price = 0;
public:
    void setBrand ();
    void setModel ();
    void setPlate ();
    void setManufacturerYear ();
    void setPrice();
};


#endif //PRACTICE1_VEHICLE_H
