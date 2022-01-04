#ifndef _NAMES_READER_H
#define _NAMES_READER_H

#include "./FileReader.h"
#include <vector>
#include <string>

/**
 * @brief NamesReader class
 * This class is used to read names data from a file.
 * 
 */
class NamesReader : public FileReader {
    public:
        NamesReader(std::string filePath); // constructor

        /**
         * @brief Get the names data from the file
         * 
         * @return std::vector<std::string> of names
         */
        std::vector<std::string> getData();
};

#endif