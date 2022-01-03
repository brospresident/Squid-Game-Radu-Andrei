#ifndef _MARBLES_H_
#define _MARBLES_H_

#include "./Game.h"

class Marbles : public Game {
    public:
        Marbles(std::string name, std::string description);
        void play(std::vector<Competitor>& competitors);
};

#endif