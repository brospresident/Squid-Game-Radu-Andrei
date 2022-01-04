#include "./Marbles.h"

/**
 * @brief Construct a new Marbles:: Marbles object    // constructor
 * 
 * @param name 
 * @param description 
 */
Marbles::Marbles(std::string name, std::string description) : Game(name, description) {
    std::cout << std::endl;
    std::cout << "The next game is " << this->getName() << "!" << std::endl;
    std::cout << this->getDescription() << std::endl;
}

/**
 * @brief Method that implements the logic of the Marbles game
 * 
 * @param competitors 
 */
void Marbles::play(std::vector<Competitor>& competitors) {
    std::vector<Competitor> remainingCompetitors = this->getRemainingCompetitors(competitors); // getting the remaining competitors

    srand(time(NULL)); // setting the seed for the random number generator

    std::cout << "The Marbles game is starting..." << std::endl;
    
    for (int i = 0; i < remainingCompetitors.size(); i += 2) { // playing marbles with every pair of competitors
        Competitor& comp1 = remainingCompetitors[i];
        Competitor& comp2 = remainingCompetitors[i + 1];

        int comp1Score = rand() % 100; // generating the score for 1st competitor
        int comp2Score = rand() % 100; // generating the score for 2nd competitor

        // printing the scores they got
        std::cout << comp1.getFirstName() << " " << comp1.getLastName() << " (" << comp1.getParticipantNumber() << ") has " << comp1Score << " points." << std::endl;
        std::cout << comp2.getFirstName() << " " << comp2.getLastName() << " (" << comp2.getParticipantNumber() << ") has " << comp2Score << " points." << std::endl;

        if (comp1Score < comp2Score) { // if 1st competitor won print that and eliminate the loser
            std::cout << comp1.getFirstName() << " " << comp1.getLastName() << " (" << comp1.getParticipantNumber() << ") has won the game!" << std::endl;
            this->eliminate(comp2, competitors);
        } 
        else if (comp1Score > comp2Score) { // if 2nd competitor won print that and eliminate the loser
            std::cout << comp2.getFirstName() << " " << comp2.getLastName() << " (" << comp2.getParticipantNumber() << ") has won the game!" << std::endl;
            this->eliminate(comp1, competitors);
        } 
        else { // if it is a tie redo the iteration and make them play again
            i -= 2;
        }
    }
}