#include <iostream>
#include <vector>

// My includes
#include "./User/User.h"
#include "./User/Supervisor.h"
#include "./User/Competitor.h"
#include "./Generator/Generator.h"
#include "./UserManager/UserManager.h"
#include "./Teams/Team.h"
#include "./Teams/Circle.h"
#include "./Teams/Triangle.h"
#include "./Teams/Rectangle.h"

using namespace std;

int main () {
    Generator generator;
    std::vector<Competitor> competitors = generator.generateUsers<Competitor>(99);
    std::vector<Supervisor> supervisors = generator.generateUsers<Supervisor>(9);

    UserManager userManager;
    userManager.assignParticipantNumbers(competitors);
    userManager.printRemainingUsers(competitors);

    Circle circleTeam;
    Triangle triangleTeam;
    Rectangle rectangleTeam;

    
    return 0;
}