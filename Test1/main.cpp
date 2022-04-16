#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "Parcel.h"
#include "Drone.h"
#include "ControlTower.h"

using namespace std;


void showParcelId(Parcel& p){
    cout << p.getParcelId() + p.getAssociated()->getPlateNumber() << p.getAssociated()->getMaximumLoad() - p.getWeight() << endl;
}
int main(int argc, char** argv)
{
    /* Data for the object attributes:
     * Control tower 1:
     *    tower id: 1
     *    control area: 100
     *    location: Jaén
     * Drone 1:
     *    plate number: 10001
     *    maximum load: 10
     *    registration date: January 21st, 2020
     *    type: quadcopter
     * Drone 2:
     *    plate number: 10002
     *    maximum load: 5
     *    registration d"September 9th, 2020"
     *    type: tricopter
     * Dron 3:
     *    plate number: 10003
     *    maximum load: 3
     *    registration date: "February 1st, 2021"
     *    type: tricopter
     * Parcel 1:
     *    parcel id: 201
     *    weight: 4
     *    description: Destination Coruña
     * Parcel 2:
     *    parcel id: 202
     *    weight: 3
     *    description: Destination Salamanca
     * Parcel 3:
     *    parcel id: 203
     *    weight: 8
     *    description: Destination Madrid
     */
    Drone d1;
    Drone d2;
    Drone d3;
    d1.setPlateNumber(10001);
    d1.setType("quadcopter");
    d1.setMaximumLoad(10);
    d1.setRegistrationDate("January 21st, 2020");
    d2.setPlateNumber(10002);
    d2.setType("tricopter");
    d2.setMaximumLoad(5);
    d2.setRegistrationDate("September 9th, 2020" );
    d3.setPlateNumber(10003);
    d3.setType("tricopter");
    d3.setMaximumLoad(3);
    d3.setRegistrationDate("February 1st, 2021");
    Parcel packages[3]={{201,4,"Destination Coruña"},
                        {202,3,"Destination Salamanca"},
                        {203,8,"Destination Madrid"}};
    packages[2].setAssociated(d1);
    packages[0].setAssociated(d2);
    packages[1].setAssociated(d3);
    ControlTower t1(1,100,"Jaén");
    try{
        t1.addDrone(d1);
        t1.addDrone(d2);
    }catch (std::invalid_argument &e){
        cerr<< e.what() << endl;
    }
    ControlTower t2(t1);

    try{
        packages[2].setAssociated(d3);
    }catch (std::invalid_argument &e) {
        cerr << e.what() << endl;
    }
    showParcelId(packages[0]);
    showParcelId(packages[1]);
    showParcelId(packages[2]);
    cout << t2.bestDrone()->getPlateNumber() << endl;

    return 0;
}
