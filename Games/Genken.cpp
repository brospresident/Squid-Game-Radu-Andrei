#include "./Genken.h"

Genken::Genken(std::string name, std::string description) : Game(name, description) {
    std::cout << std::endl;
    std::cout << "The last game is " << this->getName() << "." << std::endl;
    std::cout << this->getDescription() << std::endl;   
}

void Genken::play(std::vector<Competitor>& competitors) {
    std::cout << "The game " << this->getName() << " is starting." << std::endl;
    
    std::vector<Competitor> remainingCompetitors = this->getRemainingCompetitors(competitors);

    srand(time(NULL));

    while (remainingCompetitors.size() != 1) {
        std::sort(remainingCompetitors.begin(), remainingCompetitors.end(), [](Competitor& c1, Competitor& c2) {
            return c1.getParticipantNumber() > c2.getParticipantNumber();
        });

        for (int i = 0; i < remainingCompetitors.size(); i += 2) {
            Competitor& comp1 = remainingCompetitors[i];
            Competitor& comp2 = remainingCompetitors[i + 1];

            int comp1Score = rand() % 3 + 1;
            int comp2Score = rand() % 3 + 1;

            if (comp1Score == comp2Score) continue;
            int winner = this->rockPaperScissors(comp1Score, comp2Score);
            if (winner == 1) {
                this->eliminate(comp2, competitors);
            }
            else this->eliminate(comp1, competitors);
        }
        remainingCompetitors = this->getRemainingCompetitors(competitors);
    }
}

/**
 * @brief Returns which competitor won at rock paper scissors
 * Rock is 1, paper is 2, scissors is 3
 * 
 * @param competitor1 
 * @param competitor2 
 * @return int 
 */
int Genken::rockPaperScissors(int competitor1, int competitor2) {
    if (competitor1 == 1 && competitor2 == 3) return 1;
    if (competitor1 == 2 && competitor2 == 1) return 1;
    if (competitor1 == 3 && competitor2 == 2) return 1;
    return 2;
}