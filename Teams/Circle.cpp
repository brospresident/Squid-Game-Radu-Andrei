#include "./Circle.h"

void Circle::addSupervisor(Supervisor& supervisor) {
    this->supervisors.push_back(supervisor);
    supervisor.setMaskForm("Rectangle");
}

void Circle::printRemainingCompetitors() {
    std::cout << "Remaining competitors in Circle team: " << std::endl;
    for (Competitor& competitor : this->competitors) {
        if (competitor.getIsEliminated()) continue;
        std::cout << competitor.getParticipantNumber() << std::endl;
    }
}