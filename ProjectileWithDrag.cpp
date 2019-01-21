//
//




#include "ProjectileWithDrag.h"
#include <iomanip>

namespace cosc3000
{
    vector2d grav(0.0,-9.8);
    ProjectileWithDrag::ProjectileWithDrag() : Projectile(), drag_coeff(0.0) {
        this->weight = 0.0; //Since default Projectile() sets weight to 1
    }

    ProjectileWithDrag::ProjectileWithDrag(double weight, double init_speed, double angle, double drag_coeff) : Projectile(weight, init_speed, angle), drag_coeff(drag_coeff){}

    ProjectileWithDrag::ProjectileWithDrag(double weight, vector2d initial_velocity, double drag_coeff)
            : Projectile(weight, initial_velocity), drag_coeff(drag_coeff)
    {
    }

    void ProjectileWithDrag::update(double dt){
        Projectile::update(dt);
        acceleration = grav - drag_coeff * velocity.norm() * velocity / weight;

    }

}
