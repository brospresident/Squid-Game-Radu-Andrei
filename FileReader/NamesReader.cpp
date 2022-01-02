#include "./NamesReader.h"

NamesReader::NamesReader(std::string filePath) : FileReader(filePath) {
    std::cout << "Reading names..." << std::endl;   
}

std::vector<std::string> NamesReader::getData() {
    std::vector<std::string> names;
    std::string name;
    while (this->file >> name) {
        names.push_back(name);
    }
    return names;
}