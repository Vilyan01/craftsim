#include "physics.h"
#include <iostream>

namespace craftsim {
    physics::physics(double gravity) : _gravity(gravity) {}

    physics::~physics() {}

    void physics::log() const {
        std::cout << "gravity: " << _gravity << std::endl;
    }
}