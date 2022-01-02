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

class UserManager {
    public:
        void printRemainingUsers(std::vector<Competitor> competitors);
        void assignParticipantNumbers(std::vector<Competitor>& competitors);
        Competitor getCompetitor(int participantNumber, std::vector<Competitor> competitors);
        void randomizeTeams(std::vector<Competitor>& competitors, std::vector<Supervisor>& supervisors, Circle& circleTeam, Triangle& triangleTeam, Rectangle& rectangleTeam);
};

#endif