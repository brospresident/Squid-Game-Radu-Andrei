#include "./Supervisor.h"

Supervisor::Supervisor() {
    this->maskForm = "";
}

Supervisor::Supervisor(std::string firstName, std::string lastName, std::string city, int age, int debt, int weight, std::string maskForm) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->age = age;
    this->debt = debt;
    this->weight = weight;
    this->maskForm = maskForm;
}