//
// Created by cocol on 26/02/2022.
//

#include "Fecha.h"

Fecha::Fecha() {}

Fecha::Fecha(int day, int month, int year) : _day(day), _month(month), _year(year) {}

Fecha::Fecha(const Fecha &orig) : _day(orig._day), _month(orig._month), _year(orig._year) {}

int Fecha::getDay() const {
    return _day;
}

void Fecha::setDay(int day) {
    _day = day;
}

int Fecha::getMonth() const {
    return _month;
}

void Fecha::setMonth(int month) {
    _month = month;
}

int Fecha::getYear() const {
    return _year;
}

void Fecha::setYear(int year) {
    _year = year;
}
