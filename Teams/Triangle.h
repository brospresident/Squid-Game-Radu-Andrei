#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "./Team.h"
#include <vector>
#include <string>
#include <iostream>

class Triangle : public Team {
    public:
        void addSupervisor(Supervisor& supervisor);
        void printRemainingCompetitors(); 
};

#endif