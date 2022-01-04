#ifndef _COMPETITOR_H_
#define _COMPETITOR_H_

#include "./User.h"
#include "./Supervisor.h"

/**
 * @brief Class to represent the competitor data. It inherits the User class
 * 
 */
class Competitor : public User { 
    private:
        int participantNumber;
        bool isEliminated = false;
        Supervisor assignedSupervisor;

    public:
        Competitor();
        Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight, int participantNumber);
        Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight);

        int getParticipantNumber();
        void setParticipantNumber(int participantNumber);
        bool getIsEliminated();
        void setIsEliminated(bool isEliminated);

        bool operator > (const Competitor& competitor);
        Supervisor getAssignedSupervisor();
        void setAssignedSupervisor(Supervisor assignedSupervisor);
};

#endif