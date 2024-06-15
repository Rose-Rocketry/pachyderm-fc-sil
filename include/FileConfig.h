#ifndef FILECONFIG_H
#define FILECONFIG_H

#include "ConfigSource.h"

#include "inipp.h"

class FileConfig: public pachy::ConfigSource {
    private:
        inipp::Ini<char> source;
    public:
        virtual bool open(const char* filename);
        virtual bool read(const char* section, const char* header, char* buf, size_t len);
};

#endif