#include "logger.h"
#include "../core/position.h"
#include <fstream>
#include <strings.h>
#include <iostream>
#include <filesystem>

namespace craftsim {
    data_logger::data_logger(std::string path) {
        std::filesystem::remove(path);

        _file_stream.open(path);
        _file_stream << "timestamp,lat,lon,elev" << std::endl;
    }

    data_logger::~data_logger() {
        _file_stream.close();
    }

    void data_logger::log_position(double timestamp, position_t position) {
        _file_stream << timestamp << "," << position.lat << "," << position.lon << "," << position.elev << std::endl;
    }
}