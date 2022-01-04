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

// Games
#include "./Games/Game.h"
#include "./Games/RLGL.h"
#include "./Games/TugOfWar.h"
#include "./Games/Marbles.h"
#include "./Games/Genken.h"

using namespace std;

int main () {
    Generator generator;
    std::vector<Competitor> competitors = generator.generateUsers<Competitor>(99);
    std::vector<Supervisor> supervisors = generator.generateUsers<Supervisor>(9);

    UserManager userManager;
    userManager.assignParticipantNumbers(competitors);

    Circle circleTeam;
    Triangle triangleTeam;
    Rectangle rectangleTeam;

    userManager.randomizeTeams(competitors, supervisors, circleTeam, triangleTeam, rectangleTeam);

    RLGL rlgl("Red Light Green Light", "Every user with even participant number will be eliminated.");
    rlgl.play(competitors);
    rlgl.printRemainingUsers(circleTeam, triangleTeam, rectangleTeam, competitors);

    TugOfWar tugOfWar("Tug of War", "Competitors are split in 4 teams. We compute the weight of every team and the team with the lowest weight will be eliminated.");
    tugOfWar.play(competitors);
    tugOfWar.printRemainingUsers(circleTeam, triangleTeam, rectangleTeam, competitors);

    Marbles marbles("Marbles", "The competitors are split in pairs of two. Every competitor rolls a dice and the one with the lowest number will be eliminated.");
    marbles.play(competitors);
    marbles.printRemainingUsers(circleTeam, triangleTeam, rectangleTeam, competitors);

    Genken genken("Genken", "The competitors are playing 1v1 Rock papers scissors until there is only one competitor left.");
    genken.play(competitors);

    userManager.printWinner(competitors);
    userManager.computeSupervisorPrize(competitors, supervisors);
    userManager.printDescendingSupervisors(supervisors);
    userManager.printHighestWinningTeam(circleTeam, triangleTeam, rectangleTeam, supervisors);
    return 0;
}