#include "./Game.h"

Game::Game(std::string name, std::string description) {
    this->name = name;
    this->description = description;
}

std::string Game::getName() {
    return this->name;
}

std::string Game::getDescription() {
    return this->description;
}

void Game::setName(std::string name) {
    this->name = name;
}

void Game::setDescription(std::string description) {
    this->description = description;
}

void Game::eliminate(Competitor& competitor) {
    competitor.setIsEliminated(true);
}

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

int Game::countRemainingCompetitors(std::vector<Competitor> competitors) {
    int count = 0;
    for (Competitor& c : competitors) {
        if (c.getIsEliminated() == false) {
            count++;
        }
    }
    return count;
}

std::vector<Competitor> Game::getRemainingCompetitors(std::vector<Competitor>& competitors) {
    std::vector<Competitor> res;

    for (Competitor& c : competitors) {
        if (c.getIsEliminated() == false) {
            res.push_back(c);
        }
    }

    return res;
}

void Game::eliminate(Competitor& competitor, std::vector<Competitor>& competitors) {
    for (Competitor& c : competitors) {
        if (c == competitor) {
            c.setIsEliminated(true);
        }
    }
}