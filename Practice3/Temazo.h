//
// Created by cocol on 26/02/2022.
//

#ifndef PRACTICE2_TEMAZO_H
#define PRACTICE2_TEMAZO_H
#include <string>

/**
 * @brief This class will store the data of a Temazo
 * @param _title Title of the song
 * @param _performer Singer or group who plays the song
 * @param _lengthInSeconds Duration of the track in seconds
 * @param _audienceScore Score that shows how appealing it is to the public
 */
class Temazo {
private:
    std::string _title = "";
    std::string _performer ="";
    int _lengthInSeconds = 0;
    int _audienceScore = 0;
public:
    Temazo();

    Temazo(const std::string &title, const std::string &performer, int lengthInSeconds);

    Temazo(const Temazo& orig);

    ~Temazo();
    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getPerformer() const;

    void setPerformer(const std::string &performer);

    int getLengthInSeconds() const;

    void setLengthInSeconds(int lengthInSeconds);

    int getAudienceScore() const;

};


#endif //PRACTICE2_TEMAZO_H
