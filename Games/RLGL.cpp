#include "./RLGL.h"

/**
 * @brief Construct a new RLGL::RLGL object    // constructor
 * 
 * @param name 
 * @param description 
 */
RLGL::RLGL(std::string name, std::string description) : Game(name, description) {
    std::cout << "The first game is " << this->getName() << "!" << std::endl;
    std::cout << this->getDescription() << std::endl;
}

/**
 * @brief Method that implements the logic of the Red Light Green Light game
 * 
 * @param competitors 
 */
void RLGL::play(std::vector<Competitor>& competitors) {
    std::cout << "The game is starting..." << std::endl;

    for (Competitor& c : competitors) { // Eliminate every competitor that has an even participant number
        if (c.getParticipantNumber() % 2 == 0) {
            this->eliminate(c);
        }
    }
}