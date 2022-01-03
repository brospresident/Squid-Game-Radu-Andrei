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

void Team::updateTeam(std::vector<Competitor> competitors) {
    for (int i = 0; i < this->competitors.size(); i++) {
        for (int j = 0; j < competitors.size(); j++) {
            if (this->competitors[i] == competitors[j]) {
                this->competitors[i] = competitors[j];
            }
        }
    }
}

void Team::printSupervisors() {
    std::sort(this->supervisors.begin(), this->supervisors.end(), [](Supervisor& s1, Supervisor& s2) {
        return s1.getDebt() > s2.getDebt();
    });

    for (Supervisor& s : this->supervisors) {
        std::cout << s.getFirstName() << " " << s.getLastName() << " " << s.getDebt() << std::endl;
    }
}