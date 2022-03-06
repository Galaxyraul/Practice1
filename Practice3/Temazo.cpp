//
// Created by cocol on 26/02/2022.
//

#include "Temazo.h"

/**
 * @brief Default constructor
 */
Temazo::Temazo() {}

/**
 * @brief Parameterized constructor
 * @param title string that will be the value of the _title field
 * @param performer string that will be the value of the _performer field
 * @param lengthInSeconds int that will be the value of the _lengthInSeconds field
 */
Temazo::Temazo(const std::string &title, const std::string &performer, int lengthInSeconds)
:_title(title),_performer(performer),_lengthInSeconds(lengthInSeconds) {}

/**
 * @brief copy constructor
 * @param orig object from which the new object will be created
 */
Temazo::Temazo(const Temazo &orig)
:_title(orig._title),_performer(orig._performer),_lengthInSeconds(orig._lengthInSeconds),_audienceScore(orig._audienceScore) {}

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



