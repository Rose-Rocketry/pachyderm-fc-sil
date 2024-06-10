#ifndef FILESINK_H
#define FILESINK_H

#include <iostream>

#include "DataSink.h"

class StreamSink: public pachy::DataSink {
    private:
        std::ostream* stream;
    public:
        StreamSink(std::ostream* stream);
        virtual std::size_t buf_avail();
        virtual void write(const char* data, size_t size);
};

#endif