#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "FCCore.h"
#include "StreamSink.h"
#include "FlashImage.h"
#include "FileConfig.h"

FileConfig conf;
StreamSink radio_sink(&std::cout);
FlashImage flash_img("test_files/flash.bin", true);
pachy::FCCore core(&radio_sink, &flash_img, &conf);

int main(int, char**) {
    std::srand(std::time(nullptr));
    core.begin();
}