#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class FileReader {
    protected:
        std::fstream file;

    public:
        FileReader(std::string filePath);
        ~FileReader();
        virtual std::vector<std::string> getData() = 0;
};

#endif