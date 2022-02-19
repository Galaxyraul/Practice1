//
// Created by cocol on 19/02/2022.
//

#ifndef PRACTICE1_VEHICLE_H
#define PRACTICE1_VEHICLE_H
#include <string>
using namespace std;


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
