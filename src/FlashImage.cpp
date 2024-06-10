#include "FlashImage.h"

#include <ios>
#include <cstring>

FlashImage::FlashImage(std::string filepath, bool prevdata):
        imgfile(filepath, std::ios_base::in | std::ios_base::out
                        | std::ios_base::binary) {
    
    // This ridiculousness is only necessary because C++ doesn't provide a file
    // specifier for "open this file if it exists, create if it doesn't, but
    // don't permanently pin the write pointer to the end of the file"
    if(!imgfile.good()) {
        imgfile.open(filepath, std::ios_base::in | std::ios_base::out
                             | std::ios_base::trunc | std::ios_base::binary);
    }

    if(prevdata) {
        imgfile.seekp(0, std::ios_base::end);
    } else {
        imgfile.seekp(0);
    }
    while(imgfile.tellp() < FLASH_SIZE) {
        imgfile.put(0x00);
    }
}

bool FlashImage::read(size_t addr, char* buffer, size_t size) {
    imgfile.seekg(addr);
    imgfile.read(buffer, size);
    return true;
}

bool FlashImage::write(size_t addr, const char* data, size_t size) {
    // This is probably very slow, but who cares, it's SIL testing
    for(size_t i = 0; i < size; i++) {
        char prev;
        // Bytes of flash erase to 0xFF, and we can't write to them twice before
        // erasing; therefore, if the byte already in the file is not 0xFF, we
        // emit a write error
        imgfile.seekg(addr + i);
        prev = imgfile.get();
        if(prev == (char) 0xFF) {
            imgfile.seekp(addr + i);
            imgfile.put(data[i]);
        } else {
            return false;
        }
    }
    return true;
}

bool FlashImage::erase(size_t addr) {
    if(!first_erase) {
        imgfile.seekp(pending_erase * ERASE_SIZE);
        for(size_t i = 0; i < ERASE_SIZE; i++) {
            imgfile.put(0xFF);
        }
    } else {
        first_erase = false;
    }
    pending_erase = addr / ERASE_SIZE;
    return true;
}