#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "./Team.h"
#include <vector>
#include <string>
#include <iostream>

class Circle : public Team {
    public:
        void addSupervisor(Supervisor& supervisor);
        void printRemainingCompetitors(); 
};

#endif