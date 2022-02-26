//
// Created by cocol on 26/02/2022.
//

#include "Fecha.h"

/**
 * @brief Default constructor
 */
Fecha::Fecha() {}

/**
 * @brief Parameterized constructor
 * @param day int that will be the value of the _day field
 * @param month int that will be the value of the _month field
 * @param year int that will be the value of the _year field
 */
Fecha::Fecha(int day, int month, int year) : _day(day), _month(month), _year(year) {}

/**
 * @brief copy constructor
 * @param orig object from which the new object will be created
 */
Fecha::Fecha(const Fecha &orig) : _day(orig._day), _month(orig._month), _year(orig._year) {}

/**
 * @brief Accesses to the field _day
 * @return the value of the _day field of an object
 */
int Fecha::getDay() const {
    return _day;
}

/**
 * @brief Changes the field _day of an object
 * @param day Value which will replaced the old one
 */
void Fecha::setDay(int day) {
    _day = day;
}

/**
 * @brief Accesses to the field _month
 * @return the value of the _month field of an object
 */
int Fecha::getMonth() const {
    return _month;
}

/**
 * @brief Changes the field _month of an object
 * @param month Value which will replaced the old one
 */
void Fecha::setMonth(int month) {
    _month = month;
}

/**
 * @brief Accesses to the field _year
 * @return the value of the _year field of an object
 */
int Fecha::getYear() const {
    return _year;
}

/**
 * @brief Changes the field _year of an object
 * @param year Value which will replaced the old one
 */
void Fecha::setYear(int year) {
    _year = year;
}
