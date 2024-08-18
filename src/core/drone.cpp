#include "drone.h"

namespace craftsim {

    drone::drone()
    {
        _mass = 1.5;
        _wingArea = 0.3;
        _propArea = 0.1;
        _frontalArea = 0.02;
        _liftCoeff = 1.0;
        _dragCoeff = 0.5;
        _propEff = 0.7;
        _rpm = 2000;
        _velocity = 0.0;
        _position = {
            .lat = 0.0,
            .lon = 0.0,
            .elev = 0.0
        };
    }

    drone::~drone()
    {
    }

    double drone::get_mass()
    {
        return _mass;
    }

    double drone::get_wing_area()
    {
        return _wingArea;
    }

    double drone::get_frontal_area()
    {
        return _frontalArea;
    }

    double drone::get_lift_coefficient()
    {
        return _liftCoeff;
    }

    double drone::get_drag_coefficient()
    {
        return _dragCoeff;
    }

    double drone::get_prop_efficiency()
    {
        return _propEff;
    }

    double drone::get_rpm()
    {
        return _rpm;
    }

    double drone::get_velocity()
    {
        return _velocity;
    }

    position_t drone::get_position()
    {
        return _position;
    }
}