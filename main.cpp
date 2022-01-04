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

// Main function of the program
// Place where magic happens
int main () {
    Generator generator; // instance of generator
    std::vector<Competitor> competitors = generator.generateUsers<Competitor>(99); // generating 99 competitors
    std::vector<Supervisor> supervisors = generator.generateUsers<Supervisor>(9); // generating 9 supervisors

    UserManager userManager; // instance of user manager
    userManager.assignParticipantNumbers(competitors); // assigning participant numbers to competitors

    Circle circleTeam; // instance of circle team
    Triangle triangleTeam; // instance of triangle team
    Rectangle rectangleTeam; // instance of rectangle team

    userManager.randomizeTeams(competitors, supervisors, circleTeam, triangleTeam, rectangleTeam); // randomizing teams

    // Playing the first game (Red Light Green Light)
    RLGL rlgl("Red Light Green Light", "Every user with even participant number will be eliminated.");
    rlgl.play(competitors);
    rlgl.printRemainingUsers(circleTeam, triangleTeam, rectangleTeam, competitors);

    // Playing the second game (Tug of War)
    TugOfWar tugOfWar("Tug of War", "Competitors are split in 4 teams. We compute the weight of every team and the team with the lowest weight will be eliminated.");
    tugOfWar.play(competitors);
    tugOfWar.printRemainingUsers(circleTeam, triangleTeam, rectangleTeam, competitors);

    // Playing the third game (Marbles)
    Marbles marbles("Marbles", "The competitors are split in pairs of two. Every competitor rolls a dice and the one with the lowest number will be eliminated.");
    marbles.play(competitors);
    marbles.printRemainingUsers(circleTeam, triangleTeam, rectangleTeam, competitors);

    // Playing the fourth game (Genken)
    Genken genken("Genken", "The competitors are playing 1v1 Rock papers scissors until there is only one competitor left.");
    genken.play(competitors);

    userManager.printWinner(competitors); // Printing the winner
    userManager.computeSupervisorPrize(competitors, supervisors); // Computing the prize for every supervisor
    userManager.printDescendingSupervisors(supervisors); // Printing the descending order of supervisor based on their winning
    userManager.printHighestWinningTeam(circleTeam, triangleTeam, rectangleTeam, supervisors); // Printing the highest winning team
    return 0;
}