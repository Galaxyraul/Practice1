//
// Created by admin on 05/04/2022.
//

#ifndef CLOUDPOO_ENG_INI_DATACENTER_H
#define CLOUDPOO_ENG_INI_DATACENTER_H
#include "string"
#include "Generator.h"
#include "Device.h"


class DataCenter {
private:
    static const int _MAXDEVICES = 10;
    std::string _location = "";
    float _surface = 0;
    int _technicians = 1;
    Generator* _source = nullptr;
    Device* devices[_MAXDEVICES];
    //FIXME se requiere contador de dispositivos para mejorar eficiencia en operaciones O(1) vs O(n)
public:
    DataCenter(const std::string &location, float surface);

    DataCenter(const DataCenter& orig);

    virtual ~DataCenter();

    void setSource(Generator& orig);

    const float getPowerAvailable();

    void installDevice (Device& orig);

    Device* getDevice (int order);

    int getNumDevices ();

    float currentComsuption();

    const std::string &getLocation() const;

    float getSurface() const;

    int getTechnicians() const;

    void setTechnicians(int technicians);


};


#endif //CLOUDPOO_ENG_INI_DATACENTER_H
