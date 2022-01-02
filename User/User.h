#ifndef _USER_H_
#define _USER_H_

#include <string>

class User {
    protected:
        std::string firstName;
        std::string lastName;
        std::string city;
        int debt;
        int weight;

    public:
        User();
        User(std::string firstName, std::string lastName, std::string city, int debt, int weight);

        std::string getFirstName();
        std::string getLastName();
        std::string getCity();
        int getDebt();
        int getWeight();

        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setCity(std::string city);
        void setDebt(int debt);
        void setWeight(int weight);

        bool operator==(User& user);
};

#endif