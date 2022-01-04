#include "./Competitor.h"

Competitor::Competitor() {
    this->participantNumber = 0;
}

Competitor::Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight, int participantNumber) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->participantNumber = participantNumber;
}

int Competitor::getParticipantNumber() {
    return this->participantNumber;
}

void Competitor::setParticipantNumber(int participantNumber) {
    this->participantNumber = participantNumber;
}

Competitor::Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->participantNumber = -1;
}

bool Competitor::getIsEliminated() {
    return this->isEliminated;
}

void Competitor::setIsEliminated(bool isEliminated) {
    this->isEliminated = isEliminated;
}

bool Competitor::operator > (const Competitor& competitor) {
    return this->participantNumber > competitor.participantNumber;
}

Supervisor Competitor::getAssignedSupervisor() {
    return this->assignedSupervisor;
}

void Competitor::setAssignedSupervisor(Supervisor assignedSupervisor) {
    this->assignedSupervisor = assignedSupervisor;
}