//
// Created by cocol on 26/02/2022.
//

#include "Fecha.h"
#include <ctime>
#include <string>

/**
 * @brief Default constructor
 */
Fecha::Fecha() {
    std::time_t horaActual = std::time(0);
    std::tm* presente = std::localtime(&horaActual);

    _year = (presente->tm_year + 1900);
    _month = (presente->tm_mon + 1);
    _day = (presente->tm_mday);
}

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
    if(day > 31){
        throw std::string ("Fecha::setDay:The day cannot be over 31");
    }
    if(day <= 0){
        throw std::string ("Fecha::setDay:The day cannot be under 1");
    }
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
    if(month <= 0){
        throw std::string ("Fecha::setMonth:The month cannot be negative");
    }
    if(month > 12){
        throw std::string ("Fecha::setMonth:The month cannot be greater than twelve");
    }
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
    if(year < 0){
        throw std::string ("Fecha::setYear:The year cannot be negative");
    }
    _year = year;
}
