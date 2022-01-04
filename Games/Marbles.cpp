#include "./Marbles.h"

Marbles::Marbles(std::string name, std::string description) : Game(name, description) {
    std::cout << std::endl;
    std::cout << "The next game is " << this->getName() << "!" << std::endl;
    std::cout << this->getDescription() << std::endl;
}

void Marbles::play(std::vector<Competitor>& competitors) {
    std::vector<Competitor> remainingCompetitors = this->getRemainingCompetitors(competitors);

    srand(time(NULL));

    std::cout << "The Marbles game is starting..." << std::endl;
    
    for (int i = 0; i < remainingCompetitors.size(); i += 2) {
        Competitor& comp1 = remainingCompetitors[i];
        Competitor& comp2 = remainingCompetitors[i + 1];

        int comp1Score = rand() % 100;
        int comp2Score = rand() % 100;

        std::cout << comp1.getFirstName() << " " << comp1.getLastName() << " (" << comp1.getParticipantNumber() << ") has " << comp1Score << " points." << std::endl;
        std::cout << comp2.getFirstName() << " " << comp2.getLastName() << " (" << comp2.getParticipantNumber() << ") has " << comp2Score << " points." << std::endl;

        if (comp1Score < comp2Score) {
            std::cout << comp1.getFirstName() << " " << comp1.getLastName() << " (" << comp1.getParticipantNumber() << ") has won the game!" << std::endl;
            this->eliminate(comp2, competitors);
        } 
        else if (comp1Score > comp2Score) {
            std::cout << comp2.getFirstName() << " " << comp2.getLastName() << " (" << comp2.getParticipantNumber() << ") has won the game!" << std::endl;
            this->eliminate(comp1, competitors);
        } 
        else {
            i -= 2;
        }
    }
}