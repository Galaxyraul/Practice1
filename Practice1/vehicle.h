//
// Created by cocol on 19/02/2022.
//

#ifndef PRACTICE1_VEHICLE_H
#define PRACTICE1_VEHICLE_H
#include <string>

using namespace std;
namespace v {
    struct Vehicle {
        string Brand ;
        string Model ;
        string Plate ;
        int ManufacturerYear = 0;
        float Price = 0;
    };

    void kbRead(Vehicle &v);

    void kbRead(Vehicle *v, int size);

    void showOnScreen(const Vehicle &v);

    void showOnScreen(const Vehicle *v, int size);

    int findMostExpensive(const Vehicle *v, int size);

    void platesSECharacter(const Vehicle *v, int size);

    void platesPalyndrome(const Vehicle *v, int size);

    int fillVector (Vehicle v[], int lenV);

    void showOnScreen ( Vehicle v[], int lenV );

    int maxPrice (const  Vehicle v[], int lenV );

    int searchByPlate ( string plateNumber, const Vehicle v[], int lenV );
}


#endif //PRACTICE1_VEHICLE_H
