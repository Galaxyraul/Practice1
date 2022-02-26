//
// Created by cocol on 26/02/2022.
//

#include "Temazo.h"

Temazo::Temazo() {}

Temazo::Temazo(const std::string &title, const std::string &performer, int lengthInSeconds)
:_title(title),_performer(performer),_lengthInSeconds(lengthInSeconds) {}

Temazo::Temazo(const Temazo &orig)
:_title(orig._title),_performer(orig._performer),_lengthInSeconds(orig._lengthInSeconds),_audienceScore(orig._audienceScore) {}

Temazo::~Temazo() {}

const std::string &Temazo::getTitle() const {
    return _title;
}

void Temazo::setTitle(const std::string &title) {
    _title = title;
}

const std::string &Temazo::getPerformer() const {
    return _performer;
}

void Temazo::setPerformer(const std::string &performer) {
    _performer = performer;
}

int Temazo::getLengthInSeconds() const {
    return _lengthInSeconds;
}

void Temazo::setLengthInSeconds(int lengthInSeconds) {
    _lengthInSeconds = lengthInSeconds;
}

int Temazo::getAudienceScore() const {
    return _audienceScore;
}



