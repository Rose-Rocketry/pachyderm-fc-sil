#include "FileConfig.h"

#include <fstream>
#include <ios>

FileConfig::FileConfig(std::string rootdir): dir(rootdir) {}

bool FileConfig::open(const char *filename) {
    std::ifstream data_in(dir + "/" + filename, std::ios_base::in);
    if(data_in.is_open()) {
        source.parse(data_in);
        return true;
    } else {
        return false;
    }
}

bool FileConfig::read(const char* section, const char* key, char* buf, size_t len) {
    std::string strbuf;
    if(inipp::get_value(source.sections[std::string(section)], std::string(key), strbuf)) {
        buf[strbuf.copy(buf, len-1)] = '\0';
        return true;
    } else {
        return false;
    }
}