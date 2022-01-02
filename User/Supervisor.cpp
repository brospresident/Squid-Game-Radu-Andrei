#include "./Supervisor.h"

Supervisor::Supervisor() {
    this->maskForm = "";
}

Supervisor::Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight, std::string maskForm) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->maskForm = maskForm;
}

Supervisor::Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->maskForm = "";
}

void Supervisor::setMaskForm(std::string maskForm) {
    this->maskForm = maskForm;
}