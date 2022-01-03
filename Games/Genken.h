#ifndef _GENKEN_H_
#define _GENKEN_H_

#include "./Game.h"
#include <algorithm>

class Genken : public Game {
    public:
        Genken(std::string name, std::string description);
        void play(std::vector<Competitor>& competitors);

        int rockPaperScissors(int competitor1, int competitor2);
};

#endif