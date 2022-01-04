#include "./Supervisor.h"

// Default constructor
Supervisor::Supervisor() {
    this->maskForm = "";
}

/**
 * @brief Construct a new Supervisor:: Supervisor object    
 * 
 * @param firstName 
 * @param lastName 
 * @param city 
 * @param debt 
 * @param weight 
 */
Supervisor::Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight, std::string maskForm) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->maskForm = maskForm;
}

/**
 * @brief Construct a new Supervisor:: Supervisor object    
 * 
 * @param firstName 
 * @param lastName 
 * @param city 
 * @param debt 
 * @param weight 
 */
Supervisor::Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->city = city;
    this->debt = debt;
    this->weight = weight;
    this->maskForm = "";
}

// Setters and getters
void Supervisor::setMaskForm(std::string maskForm) {
    this->maskForm = maskForm;
}

int Supervisor::getMoneyWon() {
    return this->moneyWon;
}

void Supervisor::setMoneyWon(int moneyWon) {
    this->moneyWon = moneyWon;
}
