#ifndef _CITY_READER_H
#define _CITY_READER_H

#include "./FileReader.h"
#include <vector>
#include <string>

/**
 * @brief CityReader class
 *  This class is used to read city data from a file.
 */
class CityReader : public FileReader {
    public:
        CityReader(std::string filePath); // constructor

        /**
         * @brief Get the city data from the file
         * 
         * @return std::vector<std::string> of city names
         */
        std::vector<std::string> getData();
};

#endif