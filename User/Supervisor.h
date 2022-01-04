#ifndef _SUPERVISOR_H_
#define _SUPERVISOR_H_

#include "./User.h"
#include <string>

/**
 * @brief Class to represent the supervisor data. It inherits the User class
 * 
 */
class Supervisor : public User {
    private:
        std::string maskForm;
        int moneyWon = 0;

    public:
        Supervisor();
        Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight, std::string maskForm);
        Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight);

        std::string getMaskForm();
        void setMaskForm(std::string maskForm);
        int getMoneyWon();
        void setMoneyWon(int moneyWon);
};

#endif