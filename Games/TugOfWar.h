#ifndef _TUG_OF_WAR_H_
#define _TUG_OF_WAR_H_

#include "./Game.h"
#include <iostream>
#include <vector>
#include <string>
#include "../User/Competitor.h"
#include "../Teams/Circle.h"
#include "../Teams/Triangle.h"
#include "../Teams/Rectangle.h"

class TugOfWar : public Game {
    public:
        TugOfWar(std::string name, std::string description);
        void play(std::vector<Competitor>& competitors);

        bool isPartOfTeam(Competitor& competitor, std::vector<Competitor>& team);

        int computeWeights(std::vector<Competitor>& team);
        void eliminateTeam(std::vector<Competitor>& team, std::vector<Competitor>& competitors);
};


#endif