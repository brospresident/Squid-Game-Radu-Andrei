#ifndef _NAMES_READER_H
#define _NAMES_READER_H

#include "./FileReader.h"
#include <vector>
#include <string>

class NamesReader : public FileReader {
    public:
        NamesReader(std::string filePath);
        std::vector<std::string> getData();
};

#endif