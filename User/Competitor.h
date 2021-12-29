#ifndef _COMPETITOR_H_
#define _COMPETITOR_H_

#include "./User.h"

class Competitor : private User { 
    private:
        int participantNumber;

    public:
        Competitor();
        Competitor(std::string firstName, std::string lastName, std::string city, int age, int debt, int weight, int participantNumber);

        int getParticipantNumber();
        void setParticipantNumber(int participantNumber);
};

#endif