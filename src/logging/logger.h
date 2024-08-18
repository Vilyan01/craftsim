#pragma once
#include <fstream>
#include <strings.h>

namespace craftsim {
    struct position_t;
    class data_logger {
        public:
            data_logger(std::string path);
            ~data_logger();
            void log_position(double timestamp, position_t position);
        private:
            std::ofstream _file_stream;
    };
}