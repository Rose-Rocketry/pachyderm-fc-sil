#include "FileStorage.h"

#include <ios>
#include <limits>

FileStorage::FileStorage(std::string rootdir): dir(rootdir) {}

bool FileStorage::open(const char *path) {
    file.open(dir + "/" + path);
    return file.is_open();
}

bool FileStorage::close() {
    file.close();
    return true;
}

std::size_t FileStorage::buf_avail() {
    return file.is_open() ? std::numeric_limits<size_t>::max() : 0;
}

void FileStorage::write(const char *data, size_t size) {
    file.write(data, size);
}
