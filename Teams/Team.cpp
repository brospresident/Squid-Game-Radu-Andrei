#include "./Team.h"

void Team::addCompetitor(Competitor& competitor) {
    this->competitors.push_back(competitor);
}

// void Team::setCompetitors(std::vector<Competitor&> competitors) {
//     this->competitors = competitors;
// }

// void Team::setSupervisors(std::vector<Supervisor&> supervisors) {
//     this->supervisors = supervisors;
// }

std::vector<Competitor> Team::getCompetitors() {
    return this->competitors;
}

std::vector<Supervisor> Team::getSupervisors() {
    return this->supervisors;
}

bool Team::doesTeamHaveSupervisor(Supervisor supervisor) {
    for (int i = 0; i < this->supervisors.size(); i++) {
        if (this->supervisors[i] == supervisor) {
            return true;
        }
    }
    return false;
}

bool Team::doesTeamHaveCompetitor(Competitor competitor) {
    for (int i = 0; i < this->competitors.size(); i++) {
        if (this->competitors[i] == competitor) {
            return true;
        }
    }
    return false;
}