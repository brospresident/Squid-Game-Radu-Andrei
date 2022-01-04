#include "./Triangle.h"

/**
 * @brief Adds a supervisor to the triangle team
 * 
 * @param supervisor 
 */
void Triangle::addSupervisor(Supervisor& supervisor) {
    this->supervisors.push_back(supervisor);
    supervisor.setMaskForm("Triangle");
}

/**
 * @brief Prints the remaining competitors of the triangle team
 * 
 */
void Triangle::printRemainingCompetitors() {
    std::cout << "Remaining competitors in Triangle team: " << std::endl;
    for (Competitor& competitor : this->competitors) {
        if (competitor.getIsEliminated()) continue;
        std::cout << competitor.getParticipantNumber() << std::endl;
    }
}