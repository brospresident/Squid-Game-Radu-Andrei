#include "./CityReader.h"

CityReader::CityReader(std::string filePath) : FileReader(filePath) {
    std::cout << "Reading cities..." << std::endl;
}

std::vector<std::string> CityReader::getData() {
    std::vector<std::string> cities;
    std::string city;
    while (this->file >> city) {
        cities.push_back(city);
    }
    return cities;
}