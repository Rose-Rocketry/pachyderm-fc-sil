#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "FCCore.h"
#include "StreamSink.h"
#include "FlashImage.h"
#include "FileConfig.h"
#include "FileStorage.h"

const std::string fpath = "test_files";
const std::string sdpath = fpath+"/sdcard";
const std::string flashpath = fpath+"/flash.bin";

FileConfig conf(sdpath);
StreamSink radio_sink(&std::cout);
FlashImage flash_img(flashpath, true);
FileStorage fs(sdpath);
pachy::FCCore core(&radio_sink, &flash_img, &conf, &fs);

int main(int, char**) {
    std::srand(std::time(nullptr));
    core.begin();
}