#ifndef _GENERATOR_
#define _GENERATOR_

#include "../User/User.h"
#include "../User/Supervisor.h"
#include "../User/Competitor.h"
#include "../FileReader/CityReader.h"
#include "../FileReader/NamesReader.h"
#include <vector>
#include <string>

class Generator {
    private:
        std::vector<std::string> names;
        std::vector<std::string> cities;
    public:
        Generator();
        template <typename T> std::vector<T> generateUsers(int n);
};

#endif