#include "./Generator.h"

/**
 * @brief Construct a new Generator:: Generator object It also reads the data needed to randomly generate users    // constructor
 * 
 */
Generator::Generator() {
    this->names = NamesReader("./FileReader/names.txt").getData();
    this->cities = CityReader("./FileReader/cities.txt").getData();
}

/**
 * @brief Method that generates the numbers in the game by picking a random index in the names and cities vectors
 * 
 * @tparam T User / Supervisor / Competitor
 * @param n 
 * @return std::vector<T> of the generated users
 */
template <typename T>
std::vector<T> Generator::generateUsers(int n) {
    std::vector<T> data;
    srand(time(NULL));
    int minDebt = 10000, maxDebt = 100000;
    int minWeight = 50, maxWeight = 100;
    for (int i = 0; i < n; i++) {
        std::string firstName = this->names[rand() % this->names.size()];
        std::string lastName = this->names[rand() % this->names.size()];
        std::string city = this->cities[rand() % this->cities.size()];
        int debt = rand() % (maxDebt - minDebt + 1) + minDebt;
        int weight = rand() % (maxWeight - minWeight + 1) + minWeight;
        data.push_back(T(firstName, lastName, city, debt, weight));
    }
    return data;
}

// Specific template initialisation
template std::vector<Competitor> Generator::generateUsers<Competitor>(int);
template std::vector<Supervisor> Generator::generateUsers<Supervisor>(int);