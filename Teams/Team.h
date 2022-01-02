#ifndef _TEAM_H_
#define _TEAM_H_

#include <vector>
#include <string>

#include "../User/Competitor.h"
#include "../User/Supervisor.h"

class Team {
    protected:
        std::vector<Competitor> competitors;
        std::vector<Supervisor> supervisors;

    public:
        // getters
        std::vector<Competitor> getCompetitors();
        std::vector<Supervisor> getSupervisors();

        // setters
        // void setCompetitors(std::vector<Competitor&> competitors);
        // void setSupervisors(std::vector<Supervisor&> supervisors);

        // methods
        void addCompetitor(Competitor& competitor);
        virtual void addSupervisor(Supervisor& supervisor) = 0;
        virtual void printRemainingCompetitors() = 0;

        bool doesTeamHaveSupervisor(Supervisor supervisor);
        bool doesTeamHaveCompetitor(Competitor competitor);
};

#endif