#include "./Competitor.h"

Competitor::Competitor() {
    this->participantNumber = 0;
}

Competitor::Competitor(std::string firstName, std::string lastName, std::string city, int age, int debt, int weight, int participantNumber) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->age = age;
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