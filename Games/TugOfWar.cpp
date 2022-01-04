#include "./TugOfWar.h"

/**
 * @brief Construct a new Tug Of War:: Tug Of War object    // constructor
 * 
 * @param name 
 * @param description 
 */
TugOfWar::TugOfWar(std::string name, std::string description) : Game(name, description) {
    std::cout << std::endl;
    std::cout << "The next game is " << this->getName() << "!" << std::endl;
    std::cout << this->getDescription() << std::endl;
}

/**
 * @brief Method that check if a competitor is part of any Tug Of War team
 * 
 * @param competitor 
 * @param team 
 * @return if the competitor is part of the team given as parameter
 */
bool TugOfWar::isPartOfTeam(Competitor& competitor, std::vector<Competitor>& team) {
    for (Competitor& c : team) {
        if (c.getParticipantNumber() == competitor.getParticipantNumber()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Method that computes weight of competitors in a team
 * 
 * @param team 
 * @return int 
 */
int TugOfWar::computeWeights(std::vector<Competitor>& team) {
    int weight = 0;
    for (Competitor& c : team) {
        weight += c.getWeight();
    }
    return weight;
}

/**
 * @brief Method that eliminates all competitors of a team
 * 
 * @param team 
 * @param competitors 
 */
void TugOfWar::eliminateTeam(std::vector<Competitor>& team, std::vector<Competitor>& competitors) {
    for (int i = 0; i < competitors.size(); ++i) {
        if (this->isPartOfTeam(competitors[i], team)) {
            this->eliminate(competitors[i]);
        }
    }
}

/**
 * @brief Method that implements the logic of the Tug Of War game. Eliminates all competitors of a team if their weight is lower than the weight of the other team
 * 
 * @param competitors 
 */
void TugOfWar::play(std::vector<Competitor>& competitors) {
    std::cout << "The game is starting..." << std::endl;

    int remainingCompetitors = this->countRemainingCompetitors(competitors);
    int teamSize = remainingCompetitors / 4;
    std::cout << "Each team will have " << teamSize << " competitors." << std::endl;

    std::vector<Competitor> Team1;
    std::vector<Competitor> Team2;
    std::vector<Competitor> Team3;
    std::vector<Competitor> Team4;

    srand(time(NULL)); // initialize random seed

    // Randomly assign competitors that are not eliminated to teams 1-4 and make the teams have the same number of members
    for (int i = 0; i < competitors.size(); ++i) {
        if (competitors[i].getIsEliminated() == false) {
            int random = rand() % 4 + 1;
            switch (random) {
                case 1:
                    Team1.push_back(competitors[i]);
                    break;
                case 2:
                    Team2.push_back(competitors[i]);
                    break;
                case 3:
                    Team3.push_back(competitors[i]);
                    break;
                case 4:
                    Team4.push_back(competitors[i]);
                    break;
            }
        }
    }
    

    std::vector<Competitor> Winner1;
    std::vector<Competitor> Winner2;

    // Implementing the team fights
    // Team 1 is fighting team 2 then team 3 is fighting team 4
    // In the end, the winner of the first fight fights the winner of the second fight
    std::cout << "Team 1 is fighting with Team 2!" << std::endl;
    int weight1 = this->computeWeights(Team1), weight2 = this->computeWeights(Team2);
    std::cout << "Team 1 has " << weight1 << " kg!" << std::endl;
    std::cout << "Team 2 has " << weight2 << " kg!" << std::endl;

    if (weight1 > weight2) {
        std::cout << "Team 1 wins!" << std::endl;
        Winner1 = Team1;
        this->eliminateTeam(Team2, competitors);
        std::cout << "Team 2 eliminated!" << std::endl;
    }
    else {
        std::cout << "Team 2 wins!" << std::endl;
        Winner1 = Team2;
        this->eliminateTeam(Team1, competitors);
        std::cout << "Team 1 eliminated!" << std::endl;
    }

    std::cout << "Team 3 is fighting with Team 4!" << std::endl;
    int weight3 = this->computeWeights(Team3), weight4 = this->computeWeights(Team4);
    std::cout << "Team 3 has " << weight3 << " kg!" << std::endl;
    std::cout << "Team 4 has " << weight4 << " kg!" << std::endl;

    if (weight3 > weight4) {
        std::cout << "Team 3 wins!" << std::endl;
        Winner2 = Team3;
        this->eliminateTeam(Team4, competitors);
        std::cout << "Team 4 eliminated!" << std::endl;
    }
    else {
        std::cout << "Team 4 wins!" << std::endl;
        Winner2 = Team4;
        this->eliminateTeam(Team3, competitors);
        std::cout << "Team 3 eliminated!" << std::endl;
    }

    std::cout << "The winner between Team 1 and Team 2 is fighting with the winner between Team 3 and Team 4!" << std::endl;
    int weightWinner1 = this->computeWeights(Winner1), weightWinner2 = this->computeWeights(Winner2);
    std::cout << "Team 1 has " << weightWinner1 << " kg!" << std::endl;
    std::cout << "Team 2 has " << weightWinner2 << " kg!" << std::endl;

    if (weightWinner1 > weightWinner2) {
        std::cout << "Team 1 wins!" << std::endl;
        this->eliminateTeam(Winner2, competitors);
        std::cout << "Team 2 eliminated!" << std::endl;
    }
    else {
        std::cout << "Team 2 wins!" << std::endl;
        this->eliminateTeam(Winner1, competitors);
        std::cout << "Team 1 eliminated!" << std::endl;
    }
}