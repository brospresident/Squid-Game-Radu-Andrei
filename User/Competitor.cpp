#include "./Competitor.h"

// Default constructor
Competitor::Competitor() {
    this->participantNumber = 0;
}

/**
 * @brief Construct a new Competitor:: Competitor object    
 * 
 * @param participantNumber 
 */
Competitor::Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight, int participantNumber) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->participantNumber = participantNumber;
}

/**
 * @brief Construct a new Competitor:: Competitor object    
 * 
 * @param participantNumber 
 */
Competitor::Competitor(std::string& firstName, std::string& lastName, std::string& city, int& debt, int& weight) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->participantNumber = -1;
}

// Getters
int Competitor::getParticipantNumber() {
    return this->participantNumber;
}

void Competitor::setParticipantNumber(int participantNumber) {
    this->participantNumber = participantNumber;
}

bool Competitor::getIsEliminated() {
    return this->isEliminated;
}

Supervisor Competitor::getAssignedSupervisor() {
    return this->assignedSupervisor;
}

// Setters
void Competitor::setIsEliminated(bool isEliminated) {
    this->isEliminated = isEliminated;
}

void Competitor::setAssignedSupervisor(Supervisor assignedSupervisor) {
    this->assignedSupervisor = assignedSupervisor;
}

// Operator overloading
bool Competitor::operator > (const Competitor& competitor) {
    return this->participantNumber > competitor.participantNumber;
}