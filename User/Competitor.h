#ifndef _COMPETITOR_H_
#define _COMPETITOR_H_

#include "./User.h"

class Competitor : public User { 
    private:
        int participantNumber;
        bool isEliminated = false;

    public:
        Competitor();
        Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight, int participantNumber);
        Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight);

        int getParticipantNumber();
        void setParticipantNumber(int participantNumber);
        bool getIsEliminated();
        void setIsEliminated(bool isEliminated);
};

#endif