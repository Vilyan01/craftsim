#pragma once

namespace craftsim {
    class cancellation;
    class data_logger;
    class drone;
    class world {
    public:
      // Constructor and destructor
      world(double, data_logger*, drone*);
      ~world();
      
      // Run the simulation until the cancellation source is cancelled
      void run(const cancellation*);
    private:
      double _tickRate;
      data_logger* _logger;
      drone *_drone;
    };
}