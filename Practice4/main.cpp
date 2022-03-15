#include <iostream>
#include "djutils.h"
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"
#include "nonValidParameter.h"


int main() {
    Temazo *list = new Temazo[5];
    Garito *pMiCasa = new Garito("My house","Av Barcelona");
    Garito *gList[10];
    for(int i = 0;i < 2;++i){
        gList[i] = new Garito;
    }
    for(int i = 2; i < 10; ++i){
        gList[i] = nullptr;
    }
    gList[0]->setAddress("Av andalucía");
    gList[0]->setName("Moët");
    gList[1]->setAddress("Dr Eduardo García Triviño");
    gList[1]->setName("The office");
    gList[2] = pMiCasa;

    list[0].setTitle("Hoppípolla");
    list[0].setPerformer("Sigur Ros");
    list[0].setLengthInSeconds(268);
    list[0].setNameOfLastClub(gList[0]->getName());
    list[0].setDateOfLastUse({13,4,2003});
    list[0].setAudienceScore(80);


    list[1].setTitle("Boulevard of broken dreams");
    list[1].setNameOfLastClub(gList[1]->getName());
    list[1].setPerformer("Green day");
    list[1].setLengthInSeconds(287);
    list[1].setDateOfLastUse({26,5,2018});
    list[1].setAudienceScore(70);

    list[2].setTitle("Safe and sound");
    list[2].setNameOfLastClub(gList[2]->getName());
    list[2].setPerformer("Capital cities");
    list[2].setLengthInSeconds(193);
    list[2].setDateOfLastUse({6,6,2015});
    list[2].setAudienceScore(65);
    std::cout <<list[0].getMaxScore() << std::endl;
    list[0].increasePuntuation(10);
    std::cout <<list[0].getMaxScore() << std::endl;
    std::cout <<list[0].relativePuntuation() << std::endl;
    std::cout <<list[1].relativePuntuation() << std::endl;
    std::cout <<list[2].relativePuntuation() << std::endl;
    //showPreviousTemazos(list,3,{20,02,2022});
    //showCombinedData(list,20,gList,10);
    /*
    for(int i = 0; i < 10; ++i){
        if(gList[i] != nullptr) {
            std::cout << gList[i]->toCSV() << std::endl;
        }
    }

    for(int i = 0; i < 5; ++i){
        std::cout << list[i].toCSV() << std::endl;
    }
     */

    delete [] list;
    for (int i = 0; i < 10;++i){
        delete gList[i];
        gList [i] = nullptr;
    }
    pMiCasa = nullptr;
    list = nullptr;
}