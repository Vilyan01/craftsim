#include "world.h"
#include "cancellation.h"
#include "container.h"
#include "../subsystems/physics.h"
#include "../logging/logger.h"
#include "drone.h"
#include "position.h"
#include <iostream>
#include <chrono>
#include <thread>

const double kMaxRuntime = 60.0;

namespace craftsim {
    world::world(double tickRate, data_logger *logger, drone *drone) : _tickRate(tickRate), _logger(logger), _drone(drone) {}
    world::~world() {}

    void world::run(const cancellation *cancellation) {
        std::shared_ptr<craftsim::physics> physics = container::shared().get<craftsim::physics>("physics");
        physics->log();

        double currentTime = 0.0;
        while(!cancellation->cancel_requested() && currentTime < kMaxRuntime) {
            currentTime += _tickRate;
            // Run simulation for current time

            _logger->log_position(currentTime, _drone->get_position());
            // Keep things reasonable by sleeping for 10 milliseconds each iteration.
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << "sim ran for " << currentTime << " virtual seconds." << std::endl;
    }
}