#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <string>
#include <fstream>

#include "StorageSink.h"

class FileStorage: public pachy::StorageSink {
    private:
        std::string dir;
        std::ofstream file;
    public:
        FileStorage(std::string rootdir);
        virtual bool open(const char* path);
        virtual bool close();
        virtual std::size_t buf_avail();
        virtual void write(const char* data, size_t size);
};

#endif