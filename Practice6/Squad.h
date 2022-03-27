//
// Created by cocol on 27/03/2022.
//

#ifndef PRUEBA_SQUAD_H
#define PRUEBA_SQUAD_H
#include "Piloto.h"
#include "string"


class Squad {
private:
    std::string _name = "";
    int _numOfPilots = 0;
    std::string _base = "";
    Piloto *_members[50];
public:
    Squad();

    Squad(const std::string &name, const std::string &base);

    virtual ~Squad();

    const void newRecruit();

    const void newRecuit(Piloto& orig);

    const void casualty(int identifier);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getBase() const;

    void setBase(const std::string &base);

    int getNumOfPilots() const;

    Piloto *const *getMembers() const;

    float averageNumberOfMissions();


};


#endif //PRUEBA_SQUAD_H
