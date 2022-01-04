#include "./Rectangle.h"

/**
 * @brief Adds a supervisor to the rectangle team
 * 
 * @param supervisor 
 */
void Rectangle::addSupervisor(Supervisor& supervisor) {
    this->supervisors.push_back(supervisor);
    supervisor.setMaskForm("Rectangle");
}

/**
 * @brief Prints the remaining competitors of the rectangle team
 * 
 */
void Rectangle::printRemainingCompetitors() {
    std::cout << "Remaining competitors in Rectangle team: " << std::endl;
    for (Competitor& competitor : this->competitors) {
        if (competitor.getIsEliminated()) continue;
        std::cout << competitor.getParticipantNumber() << std::endl;
    }
}