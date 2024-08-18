#pragma once
#include "position.h"

namespace craftsim {
    class drone {
        public:
          drone();
          ~drone();
          double get_mass();
          double get_wing_area();
          double get_frontal_area();
          double get_lift_coefficient();
          double get_drag_coefficient();
          double get_prop_efficiency();
          double get_rpm();
          double get_velocity();
          position_t get_position();
        private:
            double _mass; // kg
            double _wingArea; // m^2
            double _propArea; // m^2
            double _frontalArea; // m^2
            double _liftCoeff;
            double _dragCoeff;
            double _propEff;
            double _rpm;
            double _velocity; // m/s
            position_t _position;
    };
}