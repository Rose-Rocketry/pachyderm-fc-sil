#include "StreamSink.h"
#include <limits>

StreamSink::StreamSink(std::ostream* out_stream):
        stream(out_stream) {}
std::size_t StreamSink::buf_avail() {
    return std::numeric_limits<std::size_t>::max();
}
void StreamSink::write(const char* data, size_t size) {
    if(stream) {
        stream->write(data, size);
    }
}