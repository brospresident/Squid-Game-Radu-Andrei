#include "./Game.h"

/**
 * @brief Construct a new Game:: Game object    // constructor
 * 
 * @param name 
 * @param description 
 */
Game::Game(std::string name, std::string description) {
    this->name = name;
    this->description = description;
}

/**
* @brief Getter for the name of the game
* @returns name of the game
*/
std::string Game::getName() {
    return this->name;
}

/**
 * @brief Getter for the description of the game
 * @returns description of the game
*/
std::string Game::getDescription() {
    return this->description;
}

/**
 * @brief Setter for the game name
 * @param name name of the game
*/
void Game::setName(std::string name) {
    this->name = name;
}

/**
 * @brief Setter for the game description
 * 
 * @param description 
 */
void Game::setDescription(std::string description) {
    this->description = description;
}

/**
 * @brief Method to eliminate a competitor from the game
 * 
 * @param competitor 
 */
void Game::eliminate(Competitor& competitor) {
    competitor.setIsEliminated(true);
}

/**
 * @brief Method to print all of the competitors that are still not eliminated and update the teams they belong to
 * 
 * @param circleTeam 
 * @param triangleTeam 
 * @param rectangleTeam 
 * @param competitors 
 */
void Game::printRemainingUsers(Circle& circleTeam, Triangle& triangleTeam, Rectangle& rectangleTeam, std::vector<Competitor>& competitors) {
    circleTeam.updateTeam(competitors);
    triangleTeam.updateTeam(competitors);
    rectangleTeam.updateTeam(competitors);
    
    std::cout << "The remaining competitors of Circle team are: " << std::endl;
    for (Competitor& c : circleTeam.getCompetitors()) {
        if (c.getIsEliminated() == false) {
            std::cout << c.getFirstName() << " " << c.getLastName() << " " << c.getParticipantNumber() << std::endl;
        }
    }

    std::cout << "The remaining competitors of Triangle team are: " << std::endl;
    for (Competitor& c : triangleTeam.getCompetitors()) {
        if (c.getIsEliminated() == false) {
            std::cout << c.getFirstName() << " " << c.getLastName() << " " << c.getParticipantNumber() << std::endl;
        }
    }

    std::cout << "The remaining competitors of Rectangle team are: " << std::endl;
    for (Competitor& c : rectangleTeam.getCompetitors()) {
        if (c.getIsEliminated() == false) {
            std::cout << c.getFirstName() << " " << c.getLastName() << " " << c.getParticipantNumber() << std::endl;
        }
    }
}

/**
 * @brief Method to count the number of not eliminated competitors
 * 
 * @param competitors array
 * @return number of not eliminated competitors
 */
int Game::countRemainingCompetitors(std::vector<Competitor> competitors) {
    int count = 0;
    for (Competitor& c : competitors) {
        if (c.getIsEliminated() == false) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Method to get all of the competitors that are not eliminated
 * 
 * @param competitors array of competitors
 * @return std::vector<Competitor> of not eliminated competitors
 */
std::vector<Competitor> Game::getRemainingCompetitors(std::vector<Competitor>& competitors) {
    std::vector<Competitor> res;

    for (Competitor& c : competitors) {
        if (c.getIsEliminated() == false) {
            res.push_back(c);
        }
    }

    return res;
}

/**
 * @brief Method to eliminate a competitor from the game and update the competitors array
 * 
 * @param competitor 
 * @param competitors 
 */
void Game::eliminate(Competitor& competitor, std::vector<Competitor>& competitors) {
    for (Competitor& c : competitors) {
        if (c == competitor) {
            c.setIsEliminated(true);
        }
    }
}