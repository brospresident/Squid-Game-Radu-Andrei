#ifndef _CITY_READER_H
#define _CITY_READER_H

#include "./FileReader.h"
#include <vector>
#include <string>

class CityReader : public FileReader {
    public:
        CityReader(std::string filePath);
        std::vector<std::string> getData();
};

#endif