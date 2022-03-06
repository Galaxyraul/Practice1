#include <iostream>
#include "djutils.h"
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"


int main() {
    Temazo *list = new Temazo[20];
    Garito *pMiCasa = new Garito("Mi house","Av Barcelona");
    Garito *gList = new Garito[10];
    gList[0].setAddress("Av andalucía");
    gList[0].setName("Moët");
    gList[1].setAddress("Dr Eduardo García Triviño");
    gList[1].setName("The office");

    list[0].setTitle("Hoppípolla");
    list[0].setPerformer("Sigur Ros");
    list[0].setLengthInSeconds(268);
    list[0].setNameOfLastClub(pMiCasa->getName());
    list[0].setDateOfLastUse({13,4,2003});

    list[1].setTitle("Boulevard of broken dreams");
    list[1].setNameOfLastClub(gList[1].getName());
    list[1].setPerformer("Green day");
    list[1].setLengthInSeconds(287);
    list[1].setDateOfLastUse({26,5,2018});

    list[2].setTitle("Safe and sound");
    list[2].setNameOfLastClub(gList[2].getName());
    list[2].setPerformer("Capital cities");
    list[2].setLengthInSeconds(193);
    list[2].setDateOfLastUse({6,6,2015});

    delete [] list;
    delete [] gList;
    delete pMiCasa;
    pMiCasa = nullptr;
    list = nullptr;
    gList = nullptr;
 }
