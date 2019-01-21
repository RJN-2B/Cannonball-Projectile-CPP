#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Projectile.h"
#include "ProjectileWithDrag.h"


/** Modified HW 13
 * Roland Nguyen COSC3000 HW 12
 */
using namespace cosc3000;



double positionDiff(Projectile *p1, vector2d xt, double dt) {

    p1->update(dt);
    vector2d xl = p1->get_coordinate();
    std::cout << "The input projectile position is xt : " << xt << std::endl;
    std::cout << "My projectile position is xl : " << p1->get_coordinate() << std::endl;
    return abs(xl.get_x() - xt.get_x());
}



bool continueOrNo(void){
    char inp[256];
    std::cin >> inp;
    if ((inp[0] == 'Y') || (inp[0] == 'y')){
        return true;
    }
    return false;
}

double didHit (double v1){
    if (v1 < 1){
        std::cout << "You hit the target!" <<std::endl;
        return v1;
    }
    std::cout << "You missed!" << std::endl;
    return 100;
}


    int main(int argc, const char *argv[]) {
        while (1) {
            try {
                double x;
                double y = 0;

                std::cout << "Input target x coordinate" << std::endl;
                std::cin >> x;
                std::cout << std::endl;
                vector2d targetPos = vector2d(x, y);

                if (targetPos.get_x() <= 0) throw targetPos;






                while (1) {


                    double myspeed, myangle;

                    std::cout << "Input initial speed" << std::endl;
                    std::cin >> myspeed;
                    std::cout << std::endl;

                    if (myspeed > 100 || myspeed < 50) {
                        throw myspeed;
                    }

                    std::cout << "Input initial angle" << std::endl;
                    std::cin >> myangle;
                    std::cout << std::endl;



                    if (myangle >= 90 || myangle <= 0) {
                        throw myangle;
                    }

                    ProjectileWithDrag *pw1 = new ProjectileWithDrag(50, myspeed, myangle, 1.0);

                    double difference = positionDiff(pw1, targetPos, .09);
                    std::cout << difference << std::endl;
                    double diff = didHit(difference);
                    if (diff < 1) {
                        break;
                    } else {
                        std::cout << "Do you want to try again?" << std::endl;
                        if (!continueOrNo()){
                            std::cout << "Program end." << std::endl;
                            return 0;
                        }
                    }
                }

                std::cout << "Start Over?" << std::endl;
                if (!continueOrNo()) break;

            }
            catch (vector2d x1) {
                std::cout << x1.get_x() << " must be > 0!" << std::endl;
                exit(0);
            }
            catch (double speAng) {
                std::cout << "Speed must be between 50 and 100. Angle must be between 0 degrees and 90 degrees." << std::endl;
                exit(0);
            }

        }
        return 0;
    }

