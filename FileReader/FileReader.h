#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

/*
    * FileReader abstract class
    *
    * This class is used to read data from a file.
    *
*/
class FileReader {
    protected:
        std::fstream file; // file stream

    public:
        FileReader(std::string filePath); // constructor
        ~FileReader(); // destructor

        /**
         * @brief Get the data from the file
         * 
         * @return std::vector<std::string> 
         */
        virtual std::vector<std::string> getData() = 0; // pure virtual function
};

#endif