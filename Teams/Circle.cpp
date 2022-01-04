#include "./Circle.h"

/**
 * @brief Adds a supervisor to the circle team
 * 
 * @param supervisor 
 */
void Circle::addSupervisor(Supervisor& supervisor) {
    this->supervisors.push_back(supervisor);
    supervisor.setMaskForm("Circle");
}

/**
 * @brief Prints the remaining competitors of the circle team
 * 
 */
void Circle::printRemainingCompetitors() {
    std::cout << "Remaining competitors in Circle team: " << std::endl;
    for (Competitor& competitor : this->competitors) {
        if (competitor.getIsEliminated()) continue;
        std::cout << competitor.getParticipantNumber() << std::endl;
    }
}