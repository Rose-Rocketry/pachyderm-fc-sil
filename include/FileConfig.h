#ifndef FILECONFIG_H
#define FILECONFIG_H

#include "ConfigSource.h"

#include "inipp.h"

#include <string>

class FileConfig: public pachy::ConfigSource {
    private:
        inipp::Ini<char> source;
        std::string dir;
    public:
        FileConfig(std::string rootdir);
        virtual bool open(const char* filename);
        virtual bool read(const char* section, const char* header, char* buf, size_t len);
};

#endif