
//
//  vector2d.h
//
//
#ifndef vector2d_h
#define vector2d_h
#include <iostream>
#include <cmath>

namespace cosc3000
{
    class vector2d
    {
    public:
        /// default constructor sets (0,0)
        vector2d();
        /// Assign component (x,y)
        vector2d(double x,double y);

        // set (xi, yi)->(x,y)
        void set_xy(double xi,double yi);

        /// Get x component
        double get_x(void ) const;
        /// Get y component
        double get_y(void ) const;

        /// compute l^2 norm
        double norm() const;
        /// compute dot product, (*this).p1
        double dot(const vector2d& p2);

        /// frined function to compute p1 + p2
        friend vector2d operator+(const vector2d& p1,const vector2d& p2);
        /// frined function to compute p1 - p2
        friend vector2d operator-(const vector2d& p1,const vector2d& p2);
        /// frined function to compute p1 += p2
        friend vector2d operator+=(vector2d& p1, const vector2d& p2);
        /// frined function to compute p1 -= p2
        friend vector2d operator-=(vector2d& p1, const vector2d& p2);
        /// frined function to compute vector-scalar multiplication, p1 * d
        friend vector2d operator*(const vector2d& p1, const double& d);
        /// frined function to compute vector-scalar multiplication, d * p1
        friend vector2d operator*(const double& d, const vector2d& p);
        /// frined function to compute vector-scalar division, p1 / d
        friend vector2d operator/(const vector2d& p1, const double& d);
        /// frined function to compute vector-scalar multiplication, p1 *= d
        friend vector2d operator*=(vector2d& p1, const double& d);
        /// frined function to compute vector-scalar division, p1 /= d
        friend vector2d operator/=(vector2d& p1, const double& d);

        /// out-stream
        friend std::ostream& operator<<(std::ostream& strm, const vector2d& p);
        /// in-stream
        friend std::istream& operator>>(std::istream& strm, vector2d& p);
    private:
        double x;///< x component
        double y;///< y component
    };
}

#endif /* vector2d_hpp */
