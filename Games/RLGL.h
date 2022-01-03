#ifndef _RLGL_H_
#define _RLGL_H_

#include "./Game.h"
#include <iostream>

class RLGL : public Game {
    public:
        RLGL(std::string name, std::string description);
        void play(std::vector<Competitor>& competitors);
};

#endif