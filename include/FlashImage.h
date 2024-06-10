#ifndef FLASHIMAGE_H
#define FLASHIMAGE_H

#include <string>
#include <fstream>
#include <bitset>

#include "FlashDevice.h"

class FlashImage: public pachy::FlashDevice {
    private:
        std::fstream imgfile;
        bool first_erase = true;
        std::size_t pending_erase = -1;
    public:
        FlashImage(std::string filepath, bool prevdata);
        virtual bool read(size_t addr, char* buffer, size_t size);
        virtual bool write(size_t addr, const char* data, size_t size);
        virtual bool erase(size_t addr);
};

#endif