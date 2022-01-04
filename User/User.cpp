#include "./User.h"

// Default constructor
User::User() {
    this->firstName = "";
    this->lastName = "";
    this->city = "";
    this->debt = 0;
    this->weight = 0;
}

/**
 * @brief Construct a new User:: User object    
 * 
 * @param firstName 
 * @param lastName 
 * @param city 
 * @param debt 
 * @param weight 
 */
User::User(std::string firstName, std::string lastName, std::string city, int debt, int weight) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
}

// Getters
std::string User::getFirstName() {
    return this->firstName;
}

std::string User::getLastName() {
    return this->lastName;
}

std::string User::getCity() {
    return this->city;
}

int User::getDebt() {
    return this->debt;
}

int User::getWeight() {
    return this->weight;
}

// Setters
void User::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void User::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void User::setCity(std::string city) {
    this->city = city;
}

void User::setDebt(int debt) {
    this->debt = debt;
}

void User::setWeight(int weight) {
    this->weight = weight;
}


// Operator overloading
bool User::operator==(User& user) {
    return (this->firstName == user.firstName && this->lastName == user.lastName && this->city == user.city && this->debt == user.debt && this->weight == user.weight);
}
