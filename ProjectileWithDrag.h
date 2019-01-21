//
//

#ifndef HW11_PROJECTILEWITHDRAG_H
#define HW11_PROJECTILEWITHDRAG_H
#include "Projectile.h"

namespace cosc3000 {
    class ProjectileWithDrag : public Projectile {
    public:
        ProjectileWithDrag();

        ProjectileWithDrag(double weight, double init_speed, double angle, double drag_coeff);

        ProjectileWithDrag(double weight, vector2d initial_velocity, double drag_coeff);

        virtual void update(double dt);

    private:
        double drag_coeff;
    };
}


#endif //HW11_PROJECTILEWITHDRAG_H
