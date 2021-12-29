#ifndef _SUPERVISOR_H_
#define _SUPERVISOR_H_

#include "./User.h"
#include <string>

class Supervisor : private User {
    private:
        std::string maskForm;

    public:
        Supervisor();
        Supervisor(std::string firstName, std::string lastName, std::string city, int age, int debt, int weight, std::string maskForm);

        std::string getMaskForm();
        void setMaskForm(std::string maskForm);
};

#endif