#include "./UserManager.h"

/**
 * @brief Method that prints the remaining users
 * 
 * @param competitors 
 */
void UserManager::printRemainingUsers(std::vector<Competitor> competitors) {
    std::cout << "Remaining users: " << std::endl;
    for (Competitor competitor : competitors) {
        if (competitor.getIsEliminated()) continue;        
        std::cout << competitor.getFirstName() << " " << competitor.getLastName() << " " << competitor.getParticipantNumber() << std::endl;
    }
}

/**
 * @brief Method that assigns participant numbers to the competitors
 * 
 * @param competitors 
 */
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

/**
 * @brief Method that returns a competitor based on the participant number
 * 
 * @param participantNumber 
 * @param competitors 
 * @return Competitor 
 */
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

/**
 * @brief Method that creates the teams and randomizes the competitors and supervisors
 * 
 * @param competitors 
 * @param supervisors 
 * @param circleTeam 
 * @param triangleTeam 
 * @param rectangleTeam 
 */
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

        int circleSupervisorIndex = 0, triangleSupervisorIndex = 0, rectangleSupervisorIndex = 0;

        // Assign the competitors to the teams and assign their supervisor
        for (int i = 0; i < competitors.size(); i++) {
            if (i < 33) {
                if (circleTeam.getCompetitors().size() < 11) {
                    circleSupervisorIndex = 0;
                }
                else if (circleTeam.getCompetitors().size() < 22) {
                    circleSupervisorIndex = 1;
                }
                else {
                    circleSupervisorIndex = 2;
                }
                competitors[i].setAssignedSupervisor(circleTeam.getSupervisors()[circleSupervisorIndex]);
                circleTeam.addCompetitor(competitors[i]);
            }
            else if (i < 66) {
                if (triangleTeam.getCompetitors().size() < 11) {
                    triangleSupervisorIndex = 0;
                }
                else if (triangleTeam.getCompetitors().size() < 22) {
                    triangleSupervisorIndex = 1;
                }
                else {
                    triangleSupervisorIndex = 2;
                }
                competitors[i].setAssignedSupervisor(triangleTeam.getSupervisors()[triangleSupervisorIndex]);
                triangleTeam.addCompetitor(competitors[i]);
            }
            else {
                if (rectangleTeam.getCompetitors().size() < 11) {
                    rectangleSupervisorIndex = 0;
                }
                else if (rectangleTeam.getCompetitors().size() < 22) {
                    rectangleSupervisorIndex = 1;
                }
                else {
                    rectangleSupervisorIndex = 2;
                }
                competitors[i].setAssignedSupervisor(rectangleTeam.getSupervisors()[rectangleSupervisorIndex]);
                rectangleTeam.addCompetitor(competitors[i]);
            }
        }
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
    }
}

/**
 * @brief Method that returns the winner of the games
 * 
 * @param competitors 
 * @return Competitor 
 */
Competitor UserManager::getWinner(std::vector<Competitor>& competitors) {
    try {
        if (competitors.size() == 0) {
            throw "No competitors to find the winner of.";
        }

        for (Competitor& competitor : competitors) {
            if (!competitor.getIsEliminated()) {
                return competitor;
            }
        }

        throw "No winner found.";
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
        return Competitor();
    }
}

/**
 * @brief Method that prints relevant information about the winner of the game
 * 
 * @param competitors 
 */
void UserManager::printWinner(std::vector<Competitor>& competitors) {
    try {
        if (competitors.size() == 0) {
            throw "No competitors to find the winner of.";
        }

        Competitor winner = this->getWinner(competitors);
        int prize = this->computeWinnerPrize(competitors);
        std::cout << "The winner is " << winner.getFirstName() << " " << winner.getLastName() << " with participant number " << winner.getParticipantNumber() << " and prize " << prize << "." << std::endl;
        std::cout << "The amount of money he has left is " << prize - winner.getDebt() << "." << std::endl;
        return;
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
    }
}

/**
 * @brief Method that computes the prize of the winner
 * 
 * @param competitors 
 * @return int 
 */
int UserManager::computeWinnerPrize(std::vector<Competitor>& competitors) {
    try {
        if (competitors.size() == 0) {
            throw "No competitors to find the winner of.";
        }

        int res = 0;

        for (int i = 0; i < competitors.size(); i++) {
            if (competitors[i].getIsEliminated() == true) {
                res += competitors[i].getDebt();
            }
        }
        return res;

    } 
    catch (const char* error) {
        std::cout << error << std::endl;
        return 0;
    }
}

/**
 * @brief Method that prints the information of the competitors
 * 
 * @param competitors 
 * @param supervisors 
 */
void UserManager::computeSupervisorPrize(std::vector<Competitor>& competitors, std::vector<Supervisor>& supervisors) {
    try {
        Competitor winner = this->getWinner(competitors);
        if (competitors.size() == 0) {
            throw "No competitors to compute the prize.";
        }
        if (supervisors.size() == 0) {
            throw "No supervisors to compute the prize.";
        }

        for (Supervisor& supervisor : supervisors) {
            int res = 0;
            for (Competitor& competitor : competitors) {
                if (competitor.getAssignedSupervisor() == supervisor) {
                    if (competitor == winner) {
                        res += winner.getDebt() * 10;
                    }
                    else res += competitor.getDebt();
                }
            }
            supervisor.setMoneyWon(res - supervisor.getDebt());
        }
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
    }
}

/**
 * @brief Method that sorts the supervisors and prints information about them
 * 
 * @param supervisors 
 */
void UserManager::printDescendingSupervisors(std::vector<Supervisor>& supervisors) {
    try {
        if (supervisors.size() == 0) {
            throw "No supervisors to print.";
        }

        std::sort(supervisors.begin(), supervisors.end(), [](Supervisor& a, Supervisor& b) {
            return a.getMoneyWon() > b.getMoneyWon();
        });

        for (Supervisor& supervisor : supervisors) {
            std::cout << "Supervisor " << supervisor.getFirstName() << " " << supervisor.getLastName() << " has won " << supervisor.getMoneyWon() << "$." << std::endl;
        }
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
    }
}

/**
 * @brief Method that computes the prize of every supervisor team
 * 
 * @param supervisors 
 * @return int 
 */
int UserManager::computeSupervisorTeamWinnings(std::vector<Supervisor> supervisors) {
    try {
        if (supervisors.size() == 0) {
            throw "No supervisors to compute the prize.";
        }

        int res = 0;

        for (Supervisor& supervisor : supervisors) {
            res += supervisor.getMoneyWon();
        }

        return res;
    } 
    catch (const char* error) {
        std::cout << error << std::endl;
        return 0;
    }
}

/**
 * @brief Method that finds what team won most money and prints the information about it
 * 
 * @param circleTeam 
 * @param triangleTeam 
 * @param rectangleTeam 
 * @param supervisors 
 */
void UserManager::printHighestWinningTeam(Circle& circleTeam, Triangle& triangleTeam, Rectangle& rectangleTeam, std::vector<Supervisor>& supervisors) {
    circleTeam.updateTeam(supervisors);
    triangleTeam.updateTeam(supervisors);
    rectangleTeam.updateTeam(supervisors);

    int circleWinnings = circleTeam.computeSupervisorWinnings();
    int triangleWinnings = triangleTeam.computeSupervisorWinnings();
    int rectangleWinnings = rectangleTeam.computeSupervisorWinnings();

    if (circleWinnings > triangleWinnings && circleWinnings > rectangleWinnings) {
        std::cout << "The highest winning team is the circle team with " << circleWinnings << "$." << std::endl;
        std::cout << "The team is composed of: " << std::endl;
        circleTeam.printSupervisors();
    }
    else if (triangleWinnings > circleWinnings && triangleWinnings > rectangleWinnings) {
        std::cout << "The highest winning team is the triangle team with " << triangleWinnings << "$." << std::endl;
        std::cout << "The team is composed of: " << std::endl;
        triangleTeam.printSupervisors();
    }
    else if (rectangleWinnings > circleWinnings && rectangleWinnings > triangleWinnings) {
        std::cout << "The highest winning team is the rectangle team with " << rectangleWinnings << "$." << std::endl;
        std::cout << "The team is composed of: " << std::endl;
        rectangleTeam.printSupervisors();
    }
    else {
        std::cout << "There is no highest winning team." << std::endl;
    }
}