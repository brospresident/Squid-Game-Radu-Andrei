#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "./Team.h"
#include <vector>
#include <string>
#include <iostream>

class Rectangle : public Team {
    public:
        void addSupervisor(Supervisor& supervisor);
        void printRemainingCompetitors(); 
};

#endif