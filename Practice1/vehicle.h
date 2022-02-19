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
    void setBrand (const string& brand);
    void setModel (const string& model);
    void setPlate (const string& plate);
    void setManufacturerYear (const int& manufacturerYear);
    void setPrice(const float& price);
};


#endif //PRACTICE1_VEHICLE_H
