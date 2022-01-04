#include "./FileReader.h"

FileReader::FileReader(std::string filePath) {
    try {
        this->file = std::fstream(filePath, std::ios::in);

        if (!this->file) {
            throw std::runtime_error("File not found");
        }
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}

FileReader::~FileReader() {
    this->file.close();
}