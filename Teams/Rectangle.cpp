#include "./Rectangle.h"

void Rectangle::addSupervisor(Supervisor& supervisor) {
    this->supervisors.push_back(supervisor);
    supervisor.setMaskForm("Rectangle");
}

void Rectangle::printRemainingCompetitors() {
    std::cout << "Remaining competitors in Rectangle team: " << std::endl;
    for (Competitor& competitor : this->competitors) {
        if (competitor.getIsEliminated()) continue;
        std::cout << competitor.getParticipantNumber() << std::endl;
    }
}