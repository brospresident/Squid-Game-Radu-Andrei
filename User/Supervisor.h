#ifndef _SUPERVISOR_H_
#define _SUPERVISOR_H_

#include "./User.h"
#include <string>

class Supervisor : public User {
    private:
        std::string maskForm;

    public:
        Supervisor();
        Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight, std::string maskForm);
        Supervisor(std::string firstName, std::string lastName, std::string city, int debt, int weight);

        std::string getMaskForm();
        void setMaskForm(std::string maskForm);
};

#endif