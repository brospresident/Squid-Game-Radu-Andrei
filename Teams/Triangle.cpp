#include "./Triangle.h"

void Triangle::addSupervisor(Supervisor& supervisor) {
    this->supervisors.push_back(supervisor);
    supervisor.setMaskForm("Triangle");
}

void Triangle::printRemainingCompetitors() {
    std::cout << "Remaining competitors in Triangle team: " << std::endl;
    for (Competitor& competitor : this->competitors) {
        if (competitor.getIsEliminated()) continue;
        std::cout << competitor.getParticipantNumber() << std::endl;
    }
}