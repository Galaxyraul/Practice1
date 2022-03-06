//
// Created by cocol on 26/02/2022.
//

#include "Garito.h"
#include "Fecha.h"

/**
 * @brief Parameterized constructor
 * @param name string that will be the value of the _name field
 * @param address string that will be the value of the _address field
 */
Garito::Garito(const std::string &name, const std::string &address) : _name(name), _address(address),_dateOfLastShow() {}

/**
 * @brief copy constructor
 * @param orig object from which the new object will be created
 */
Garito::Garito(const Garito& orig) : _name(orig._name), _address(orig._address),_dateOfLastShow(orig._dateOfLastShow) {}

/**
 * @brief Destructor
 */
Garito::~Garito() {

}

/**
 * @brief Accesses to the field _name
 * @return the value of the _name field of an object
 */
const std::string &Garito::getName() const {
    return _name;
}

/**
 * @brief Changes the field _name of an object
 * @param name Value which will replaced the old one
 * @throw string If the field is the empty string it throws an exception
 */
void Garito::setName(const std::string &name) {
    if (name == ""){
        throw std::string ("The name cannot be the empty chain");
    }
    this->_name = name;
}

/**
 * @brief Accesses to the field _address
 * @return the value of the _address field of an object
 */
const std::string &Garito::getAddress() const {
    return _address;
}

/**
 * @brief Changes the field _address of an object
 * @param address Value which will replaced the old one
 * @throw string If the field is the empty string it throws an exception
 */
void Garito::setAddress(const std::string &address) {
    if (address == ""){
        throw std::string ("The address  cannot be the empty chain");
    }
    this->_address = address;
}

/**
 * @brief This method assigns the values to the fecha attribute in the garito
 * @param day Value which will be assigned to the _day field of the fecha object
 * @param month Value which will be assigned to the _month field of the fecha oject
 * @param year Value which will be assigned to the _year field of the fecha object
 */
void Garito::setDateOfLastShow(int day, int month, int year) {
    _dateOfLastShow.setDay(day);
    _dateOfLastShow.setMonth(month);
    _dateOfLastShow.setYear(year);
}

/**
 * @brief This method returns the attribute fecha of the class
 * @return The object of type fecha in which it is store the last play of Segis
 */
const Fecha &Garito::getDateOfLastShow() const {
    return _dateOfLastShow;
}


