#ifndef _TEAM_H_
#define _TEAM_H_

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

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

        // methods
        void addCompetitor(Competitor& competitor);
        virtual void addSupervisor(Supervisor& supervisor) = 0;
        virtual void printRemainingCompetitors() = 0;

        bool doesTeamHaveSupervisor(Supervisor supervisor);
        bool doesTeamHaveCompetitor(Competitor competitor);

        void updateTeam(std::vector<Competitor> competitors);
        void updateTeam(std::vector<Supervisor> supervisors);
        int computeSupervisorWinnings();
        void printSupervisors();
};

#endif