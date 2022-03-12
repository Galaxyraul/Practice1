//
// Created by cocol on 26/02/2022.
//

#ifndef PRACTICE2_TEMAZO_H
#define PRACTICE2_TEMAZO_H
#include <string>
#include "Fecha.h"

/**
 * @brief This class will store the data of a Temazo
 * @param _title Title of the song
 * @param _performer Singer or group who plays the song
 * @param _lengthInSeconds Duration of the track in seconds
 * @param _audienceScore Score that shows how appealing it is to the public
 * @param _nameOfLastClub Name of the last place where it was used
 * @param _dateOfLastUse Fecha object in which the date of the last use it is store
 * @param _idTemazo Identifier of each temazo assigned when it was created
 */
static int _numTemazos = 0;

class Temazo {
private:
    std::string _title = "";
    std::string _performer ="";
    int _lengthInSeconds = 0;
    int _audienceScore = 0;
    std::string _nameOfLastClub = "";
    Fecha _dateOfLastUse;
    int _idTemazo = _numTemazos;
public:
    int getIdTemazo() const;

public:
    Temazo();

    Temazo(const std::string &title, const std::string &performer,
           const std::string& nameOfLastClub,int lengthInSeconds,int day,int month,int year, int idTemazo);

    Temazo(const Temazo& orig);

    ~Temazo();

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getPerformer() const;

    void setPerformer(const std::string &performer);

    const std::string &getNameOfLastClub() const;

    void setNameOfLastClub(const std::string &nameOfLastClub);

    const Fecha &getDateOfLastUse() const;

    void setDateOfLastUse(const Fecha &dateOfLastUse);

    int getLengthInSeconds() const;

    void setLengthInSeconds(int lengthInSeconds);

    int getAudienceScore() const;

    void increasePuntuation (const int extraPoints) ;

    const std::string toCSV() const;

};


#endif //PRACTICE2_TEMAZO_H
