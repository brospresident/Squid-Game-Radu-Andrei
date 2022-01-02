#include "./Generator.h"

Generator::Generator() {
    this->names = NamesReader("./FileReader/names.txt").getData();
    this->cities = CityReader("./FileReader/cities.txt").getData();
}

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

template std::vector<Competitor> Generator::generateUsers<Competitor>(int);
template std::vector<Supervisor> Generator::generateUsers<Supervisor>(int);