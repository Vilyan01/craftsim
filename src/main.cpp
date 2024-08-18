#include <stdio.h>
#include <string>
#include <csignal>
#include "logging/logger.h"
#include "core/container.h"
#include "core/cancellation.h"
#include "core/world.h"
#include "core/drone.h"
#include "subsystems/physics.h"

const double kGravityConstant = 9.80665;
const double kTickRate = 0.33;
static craftsim::cancellation cancel;

using namespace craftsim;

void signalHandler(int signum) {
    cancel.cancel();
}

int main(int, char**){
    std::signal(SIGINT, signalHandler);

    data_logger logger("test.csv");
    drone drone;

    std::shared_ptr<physics> physicsSubsystem = std::make_shared<physics>(kGravityConstant);
    container::shared().add("physics", physicsSubsystem);

    std::shared_ptr<world> wrld = std::make_shared<world>(kTickRate, &logger, &drone);
    wrld->run(&cancel);

    return 0;
}
