#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include <vector>
#include "../User/Competitor.h"
#include "../Teams/Circle.h"
#include "../Teams/Triangle.h"
#include "../Teams/Rectangle.h"

class Game {
    private:
        std::string name;
        std::string description;
    
    public:
        Game(std::string name, std::string description);
        std::string getName();
        std::string getDescription();

        void setName(std::string name);
        void setDescription(std::string description);

        void eliminate(Competitor& competitor);
        void eliminate(Competitor& competitor, std::vector<Competitor>& competitors);

        virtual void play(std::vector<Competitor>& competitors) = 0;

        void printRemainingUsers(Circle& circleTeam, Triangle& triangleTeam, Rectangle& rectangleTeam, std::vector<Competitor>& competitors);

        int countRemainingCompetitors(std::vector<Competitor> competitors);

        std::vector<Competitor> getRemainingCompetitors(std::vector<Competitor>& competitors);
};

#endif