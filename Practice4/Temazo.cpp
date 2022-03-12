//
// Created by cocol on 26/02/2022.
//

#include "Temazo.h"
#include "Fecha.h"
#include "nonValidParameter.h"

/**
 * @brief Default constructor
 */
Temazo::Temazo() {}

/**
 * @brief Parameterized constructor
 * @param title string that will be the value of the _title field
 * @param performer string that will be the value of the _performer field
 * @param lengthInSeconds int that will be the value of the _lengthInSeconds field
 * @param nameOfLastClub string that will be the value of the _nameOfLastClub field
 * @param day int that will be the value of the field _day in the _dateOfLastUse object
 * @param month int that will be the value of the field _month in the _dateOfLastUse object
 * @param year int that will be the value of the field _year in the _dateOfLastUse object
 */
Temazo::Temazo(const std::string &title, const std::string &performer, const std::string& nameOfLastClub,int lengthInSeconds,int day,int month,int year)
:_title(title),_performer(performer),_lengthInSeconds(lengthInSeconds),_nameOfLastClub(nameOfLastClub),_dateOfLastUse(day,month,year) {}

/**
 * @brief copy constructor
 * @param orig object from which the new object will be created
 */
Temazo::Temazo(const Temazo &orig)
:_title(orig._title),_performer(orig._performer),_lengthInSeconds(orig._lengthInSeconds),
_audienceScore(orig._audienceScore),_nameOfLastClub(orig._nameOfLastClub),_dateOfLastUse(orig._dateOfLastUse) {}

/**
 * @brief Destructor
 */
Temazo::~Temazo() {}

/**
 * @brief Accesses to the field _title
 * @return the value of the _title field of an object
 */
const std::string &Temazo::getTitle() const {
    return _title;
}

/**
 * @brief Changes the field _title of an object
 * @param title Value which will replaced the old one
 */
void Temazo::setTitle(const std::string &title) {
    _title = title;
}

/**
 * @brief Accesses to the field _performer
 * @return the value of the _performer field of an object
 */
const std::string &Temazo::getPerformer() const {
    return _performer;
}

/**
 * @brief Changes the field _performer of an object
 * @param performer Value which will replaced the old one
 */
void Temazo::setPerformer(const std::string &performer) {
    _performer = performer;
}

/**
 * @brief Accesses to the field _lengthInSeconds
 * @return the value of the _lengthInSeconds field of an object
 */
int Temazo::getLengthInSeconds() const {
    return _lengthInSeconds;
}

/**
 * @brief Changes the field _lengthInSeconds of an object
 * @param lengthInSeconds Value which will replaced the old one
 */
void Temazo::setLengthInSeconds(int lengthInSeconds) {
    _lengthInSeconds = lengthInSeconds;
}

/**
 * @brief Accesses to the field _audienceScore
 * @return the value of the _audienceScore field of an object
 */
int Temazo::getAudienceScore() const {
    return _audienceScore;
}
/**
 * @brief Accesses to the field _nameOfLastClub
 * @return the value of the _nameOfLastClub field of an object
 */
const std::string &Temazo::getNameOfLastClub() const {
    return _nameOfLastClub;
}
/**
 * @brief Changes the field _nameOfLastClub of an object
 * @param nameOfLastClub Value which will replaced the old one
 */
void Temazo::setNameOfLastClub(const std::string &nameOfLastClub) {
    _nameOfLastClub = nameOfLastClub;
}
/**
 * @brief Accesses to the field _dateOfLastUse
 * @return the value of the _dateOfLastUse field of an object
 */
const Fecha &Temazo::getDateOfLastUse() const {
    return _dateOfLastUse;
}
/**
 * @brief Changes the field _dateOfLastUse of an object
 * @param dateOfLastUse Value which will replaced the old one
 */
void Temazo::setDateOfLastUse(const Fecha &dateOfLastUse) {
    _dateOfLastUse = dateOfLastUse;
}

int Temazo::increasePuntuation(const int extraPoints) const {
    if ((extraPoints > 10) || (extraPoints < -10)){
        throw nonValidParameter("Temazo.cpp","increasePuntuation","The puntuation is out of range" );
    }
}



