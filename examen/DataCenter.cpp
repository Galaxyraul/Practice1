//
// Created by admin on 05/04/2022.
//

#include "DataCenter.h"
#include "string"
#include <iostream>

DataCenter::DataCenter(const std::string &location, float surface) : _location(location), _surface(surface) {
    //TODO por ser coherentes, inicializa a nullptr _source
    for(int i = 0; i < _MAXDEVICES;++i){
        devices[i] = nullptr;
    }
}

const std::string &DataCenter::getLocation() const {
    return _location;
}

float DataCenter::getSurface() const {
    return _surface;
}

int DataCenter::getTechnicians() const {
    return _technicians;
}

void DataCenter::setTechnicians(int technicians) {
    if(technicians < 1 || technicians > 4){
        throw std::out_of_range("DataCenter.cpp::setTechnicians:The number of technicians is not suitable");
    }
   _technicians = technicians;
}
//FIXME en excepciones deben explicarse las causas que las generan
/**
 * @brief This method adds a new device to the DataCenter
 * @param[in] orig
 * @post If the DataCenter is already full of devices or It does not have a generator it will throw an exception
 * @throw Throws an out of range exception including where the error ocurred and its cause
 * @throw Throws and inivalid argument exception including where the error ocurred and its cause
 */
void DataCenter::installDevice(Device& orig){
    if(getNumDevices() >= _MAXDEVICES ){
        throw std::out_of_range("DataCenter.cpp::installDevice:This data center cannot have more devices");
    }
    if(_source == nullptr){
        throw std::invalid_argument("DataCenter.cpp::installDevice:This data center does not have a power supply");
    }

    for(int i = 0; i < _MAXDEVICES;++i){
        if (devices[i] == nullptr){
            devices[i] = &orig;
            break;
        }
    }

}

const float DataCenter::getPowerAvailable() {
    if(_source == nullptr){
        return 0;
    }
    return _source->getPower();
}

void DataCenter::setSource(Generator &orig) {
    if(_source != nullptr){
        throw std::invalid_argument("DataCenter.cpp::setGenerator:The generator has already been set");
    }
    //FIXME se requiere una copia al tratarse de composición
    _source = &orig;
}

DataCenter::~DataCenter() {
    if(_source != nullptr){
        //FIXME se requiere borrado (delete) al ser una composición y asignar a nullptr
        _source->~Generator();
    }
    for(int i = 0; i < _MAXDEVICES;++i){
        devices[i] = nullptr;
    }
}

int DataCenter::getNumDevices() {
    int result = 0;
    for (int i = 0; i < _MAXDEVICES; ++i){
        if (devices[i] != nullptr){
            ++result;
        }
    }
    return result;
}

Device *DataCenter::getDevice(int order) {
    //FIXME la comprobación no es suficiente para determinar si el dispositivo existe
    if (order > _MAXDEVICES){
        throw std::out_of_range("DataCenter.cpp::getDevice:The value is not suitable for the task");
    }
    return devices[order-1];
}
//As the problem does not mention anything about sharing or not devices and generators I assume that they can be shared
DataCenter::DataCenter(const DataCenter &orig):_location(orig._location),
                                                _surface(orig._surface),
                                                _technicians(orig._technicians),
                                                //FIXME se requiere copia por ser composición
                                                _source(orig._source){

    int k = 0;
    for(int i = 0; i < _MAXDEVICES;++i){
        devices[i] = nullptr;
        if (orig.devices[i] != nullptr){
            devices[k] = orig.devices[i];
            k++;
        }
    }
}

float DataCenter::currentComsuption() {
    float result = 0;
    //FIXME contador k no necesario ya que no influye en mejorar la eficiencia
    int k = getNumDevices();
    for(int i = 0; i<_MAXDEVICES && k > 0; ++i){
        if(devices[i] != nullptr && devices[i]->isActive()){
            result+= devices[i]->getConsumption();
            --k;
        }
    }
    return result;
}


