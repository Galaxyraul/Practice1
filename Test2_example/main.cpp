/**
 * @file main.cpp
 * @author jjurado
 *
 * @date 29 de marzo de 2021, 8:30
 */

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <sstream>

#include "Parcel.h"
#include "ControlTower.h"
#include "BrokenDrone.h"
#include "RentedDrone.h"

using namespace std;

void showDrones(ControlTower& t1){
    stringstream ss;
    for(int i = 0; i < t1.getNDrones();++i){
        BrokenDrone* referenceb = dynamic_cast<BrokenDrone*>(t1.getDrone(i));
        RentedDrone* referencer = dynamic_cast<RentedDrone*>(t1.getDrone(i));
        if(referenceb!= nullptr){
            ss << "Broken Drone" << ";" <<referenceb->getPlateNumber() << ";" << referenceb->getCost(1);
            cout << ss.str()<<endl;
        }else{
            if(referencer!= nullptr){
                if(referencer!= nullptr){
                    ss << "Rented Drone" << ";" <<referencer->getPlateNumber() << ";" << referencer->getCost(1);
                    cout << ss.str() << endl;
                }
            }else{
                ss << "Normal Drone" << ";" <<t1.getDrone(i)->getPlateNumber() << ";" << t1.getDrone(i)->getCost(1);
                cout << ss.str() << endl;
            }
        }


    }
}
void outputParcel ( Parcel& paramP )
{
   Drone* carrier = paramP.getCarrier ( );

   std::cout << "Parcel id: " << paramP.getParcelId ( ) << std::endl
             << "   carried by drone "
             << carrier->getPlateNumber ( ) << std::endl
             << "   weight difference: "
             << carrier->getMaximumLoad ( ) - paramP.getWeight ( ) << std::endl;
}

/*
 *
 */
int main ( int argc, char** argv )
{

   ControlTower t1 ( 1, 100, "Jaén" );

   RentedDrone r1("Gremsy",5),r2("Álava",15);
   BrokenDrone b1(2,25,5),b2(1,20,9);
   try{
       t1.addDrone(&r1);
       t1.addDrone(&r2);
       t1.addDrone(&b1);
       t1.addDrone(&b2);
   }catch (std::length_error& e){
       cerr<<e.what();
   }
    showDrones(t1);
   Drone* cost = t1.searchDrone(50);
   cout << cost->getPlateNumber()<<";"<<cost->getCost(1);










   return 0;
}

