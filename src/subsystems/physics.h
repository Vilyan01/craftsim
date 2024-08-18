#pragma once
#include "subsystem.h"

namespace craftsim {
    class physics : public subsystem {
    public:
        physics(double gravity);
        ~physics();
        void log() const;
    private:
        double _gravity;
    };
}