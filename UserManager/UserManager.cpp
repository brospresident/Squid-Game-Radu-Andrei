#include "./UserManager.h"

void UserManager::printRemainingUsers(std::vector<Competitor> competitors) {
    std::cout << "Remaining users: " << std::endl;
    for (Competitor competitor : competitors) {
        if (competitor.getIsEliminated()) continue;        
        std::cout << competitor.getFirstName() << " " << competitor.getLastName() << " " << competitor.getParticipantNumber() << std::endl;
    }
}

void UserManager::assignParticipantNumbers(std::vector<Competitor>& competitors) {
    try {
        if (competitors.size() == 0) {
            throw "No competitors to assign numbers to.";
        }
        int participantNumber = 1;
        for (Competitor& competitor : competitors) {
            competitor.setParticipantNumber(participantNumber);
            participantNumber++;
        }
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
    }
}

Competitor UserManager::getCompetitor(int participantNumber, std::vector<Competitor> competitors) {
    try {
        if (participantNumber < 1 && participantNumber > 100) {
            throw "Participant number must be greater than 0 and lower than 100.";
        }

        for (Competitor& competitor : competitors) {
            if (competitor.getParticipantNumber() == participantNumber) {
                return competitor;
            }
        }

        throw "No competitor with that participant number.";
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
        return Competitor();
    }
}

void UserManager::randomizeTeams(std::vector<Competitor>& competitors, std::vector<Supervisor>& supervisors, Circle& circleTeam, Triangle& triangleTeam, Rectangle& rectangleTeam) {
    try {
        if (competitors.size() == 0) {
            throw "No competitors to assign to teams.";
        }
        if (supervisors.size() == 0) {
            throw "No supervisors to assign to teams.";
        }

        // Randomize the competitors and supervisors
        std::random_shuffle(competitors.begin(), competitors.end());
        std::random_shuffle(supervisors.begin(), supervisors.end());

        // Assign the competitors to the teams
        for (int i = 0; i < competitors.size(); i++) {
            if (i < 33) {
                circleTeam.addCompetitor(competitors[i]);
            }
            else if (i < 66) {
                triangleTeam.addCompetitor(competitors[i]);
            }
            else {
                rectangleTeam.addCompetitor(competitors[i]);
            }
        }

        // Assign the supervisors to the teams
        for (int i = 0; i < supervisors.size(); i++) {
            if (i < 3) {
                circleTeam.addSupervisor(supervisors[i]);
            }
            else if (i < 6) {
                triangleTeam.addSupervisor(supervisors[i]);
            }
            else {
                rectangleTeam.addSupervisor(supervisors[i]);
            }
        }
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
    }
}