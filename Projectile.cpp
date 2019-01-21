
//
//  Projectile.cpp
//  ProjectileNoDrag
//
//

#include <iostream>
#include <iomanip>
#include "Projectile.h"


Projectile::Projectile():Projectile(1.0, 0.0, 0.0)
{
}

Projectile::Projectile(double weight, vector2d initial_velocity)
        :cord(0,0),time(0),velocity(initial_velocity),acceleration(0.0,gravity),weight(weight)
{
}

Projectile::Projectile(double weight, double initial_speed, double angle)
        :cord(0,0),velocity(initial_speed*cos(angle),initial_speed*sin(angle)),acceleration(0.0,gravity),time(0),weight(weight)
{
}

Projectile::~Projectile(){
    /// Do nothing
}

void Projectile::update(double dt){

    /// update coordinate $\overrightarrow{x}\left(t+\Delta t\right)=\overrightarrow{x}\left(t\right)+\overrightarrow{v}\Delta t$
    cord += velocity * dt;

    /// update velocity $\overrightarrow{v}\left(t+\Delta t\right)=\overrightarrow{v}\left(t\right)+\overrightarrow{a}\Delta t$
    velocity += acceleration * dt;

    /// update time $t_{next} = t_{current} + \Delta t$
    time += dt;
}

vector2d Projectile::get_acceleration() const
{
    return acceleration;
}

vector2d Projectile::get_velocity() const
{
    return velocity;
}

vector2d Projectile::get_coordinate() const
{
    return cord;
}

double Projectile::get_time() const
{
    return time;
}


std::ostream& operator<<(std::ostream& strm, const Projectile& p)
{
    strm << std::setprecision(8);
    strm << std::scientific;
    strm << p.time
         << std::setw(16) << p.cord
         << std::setw(16) << p.velocity
         << std::setw(16) << p.acceleration;

    return strm;
}


