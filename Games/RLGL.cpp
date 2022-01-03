#include "./RLGL.h"

RLGL::RLGL(std::string name, std::string description) : Game(name, description) {
    std::cout << "The first game is " << this->getName() << "!" << std::endl;
    std::cout << this->getDescription() << std::endl;
}

void RLGL::play(std::vector<Competitor>& competitors) {
    std::cout << "The game is starting..." << std::endl;

    for (Competitor& c : competitors) {
        if (c.getParticipantNumber() % 2 == 0) {
            this->eliminate(c);
        }
    }
}