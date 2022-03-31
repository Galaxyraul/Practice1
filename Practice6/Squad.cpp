//
// Created by cocol on 27/03/2022.
//

#include "Squad.h"

Squad::Squad() {
    for(int i = 0; i < 50; ++i){
        _members[i] = nullptr;
    }
}

Squad::Squad(const std::string &name, const std::string &base) : _name(name), _base(base) {
    for(int i = 0; i < 50; ++i){
        _members[i] = nullptr;
    }
}

Squad::~Squad() {
    for(int i = 0; i < 50; ++i){
        if(_members[i]!= nullptr){
            _members[i]= nullptr;
        }
    }
}

const void Squad::newRecruit() {
    if(_numOfPilots == 50){
        throw std::string ("Squad.cpp::NewRecruit:This squad is full");
    }
    bool match = false;
    for(int i = 0; i < 50 && !match;++i){
        if(_members[i]== nullptr){
            _members[i] = new Piloto();
            match = true;
        }
    }
    ++_numOfPilots;
}
const void Squad::newRecuit(Piloto &orig) {
    if(_numOfPilots == 50){
        throw std::string ("Squad.cpp::NewRecruit:This squad is full");
    }
    bool match = false;
    for(int i = 0; i < 50 && !match;++i){
        if(_members[i]== nullptr){
            _members[i] = &orig;
            match = true;
        }
    }
    ++_numOfPilots;
}

const void Squad::casualty(int identifier) {
    int pos = 0;
    bool match = false;
    for(int i = 0; i < 50 && !match;++i){
        if(_members[i]!= nullptr){
            match =_members[i]->getIdP() == identifier;
            pos=match? i:pos;
        }
    }
    delete _members[pos];
    _members[pos] = nullptr;
    _numOfPilots--;
}

const std::string &Squad::getName() const {
    return _name;
}

void Squad::setName(const std::string &name) {
    _name = name;
}

const std::string &Squad::getBase() const {
    return _base;
}

void Squad::setBase(const std::string &base) {
    _base = base;
}

int Squad::getNumOfPilots() const {
    return _numOfPilots;
}

Piloto *const *Squad::getMembers() const {
    return _members;
}

float Squad::averageNumberOfMissions() {
    float result = 0;
    for(int i = 0; i < 50; ++i){
        if(_members[i]!= nullptr) {
            result += _members[i]->getNumMissions();
        }
    }
    return result/_numOfPilots;
}

const Squad &Squad::operator = (const Squad &otro){
    if(this!=&otro){
        _name = otro._name;
        _numOfPilots = otro._numOfPilots;
        _base = otro._base;
        for(int i = 0; i < 50; ++i){
            if(i < _numOfPilots){
                _members[i] = otro._members[i];
            } else{
                _members[i] = nullptr;
            }
        }

    }
    return (*this);
}

Squad::Squad(const Squad &otro):_base(otro._base),_numOfPilots(otro._numOfPilots),_name(otro._name) {
    for(int i = 0; i < 50; ++i){
        if(i < _numOfPilots){
            _members[i] = otro._members[i];
        } else{
            _members[i] = nullptr;
        }
    }

}

Piloto &Squad::partnerOfDroid(const Droide &which) const{
    int pos;
    bool  match;
    for(int i = 0;  i < 50 && !match; ++i){
        if(_members[i]!= nullptr) {
            match = &which == _members[i]->getSupportDroid();
            pos = (match) ? i : 50;
        }
    }
    if (pos == 50){
        throw std::string ("Squad.cpp::PartnerOfDroid:The droid does not belong to any of the pilots");
    }
    return *_members[pos];
}


