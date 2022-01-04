#ifndef _USER_MANAGER_H_
#define _USER_MANAGER_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "../User/Competitor.h"
#include "../User/Supervisor.h"
#include "../Teams/Circle.h"
#include "../Teams/Triangle.h"
#include "../Teams/Rectangle.h"

/**
 * @brief Class to manage the users and do certain actions on them
 * 
 */
class UserManager {
    public:
        void printRemainingUsers(std::vector<Competitor> competitors);
        void assignParticipantNumbers(std::vector<Competitor>& competitors);
        Competitor getCompetitor(int participantNumber, std::vector<Competitor> competitors);
        void randomizeTeams(std::vector<Competitor>& competitors, std::vector<Supervisor>& supervisors, Circle& circleTeam, Triangle& triangleTeam, Rectangle& rectangleTeam);
        Competitor getWinner(std::vector<Competitor>& competitors);
        void printWinner(std::vector<Competitor>& competitors);
        int computeWinnerPrize(std::vector<Competitor>& competitors);
        void computeSupervisorPrize(std::vector<Competitor>& competitors, std::vector<Supervisor>& supervisors);
        void printDescendingSupervisors(std::vector<Supervisor>& supervisors);
        int computeSupervisorTeamWinnings(std::vector<Supervisor> supervisors);
        void printHighestWinningTeam(Circle& circleTeam, Triangle& triangleTeam, Rectangle& rectangleTeam, std::vector<Supervisor>& supervisors);
};

#endif