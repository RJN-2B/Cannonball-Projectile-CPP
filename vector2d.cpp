//
//

#include "vector2d.h"

//
//  vector2d.cpp
//
//
#include "vector2d.h"
#include <iomanip>

namespace cosc3000
{
    vector2d::vector2d():x(0),y(0){
    }

    vector2d::vector2d(double xi,double yi):x(xi),y(yi){
    }

    void vector2d::set_xy(double xi,double yi){
        x = xi;
        y = yi;
    }

    double vector2d::get_x(void ) const
    {
        return x;
    }

    double vector2d::get_y(void ) const
    {
        return y;
    }

    double vector2d::norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    double vector2d::dot(const vector2d& p2)
    {
        return x * p2.get_x() + y * p2.get_y();
    }

    // Operators
    vector2d operator+(const vector2d& p1,const vector2d& p2)
    {
        vector2d p0(p1.x + p2.x, p1.y + p2.y);
        return p0;
    }

    vector2d operator-(const vector2d& p1,const vector2d& p2)
    {
        vector2d p0(p1.x - p2.x, p1.y - p2.y);
        return p0;
    }

    vector2d operator+=(vector2d& p1,const vector2d& p2)
    {
        p1.x += p2.x;
        p1.y += p2.y;
        return p1;
    }

    vector2d operator-=(vector2d& p1,const vector2d& p2)
    {
        p1.x -= p2.x;
        p1.y -= p2.y;
        return p1;
    }

    vector2d operator*(const vector2d& p1, const double& d)
    {
        vector2d p0(p1.x * d,p1.y * d);;
        return p0;
    }


    vector2d operator/(const vector2d& p1, const double& d)
    {
        vector2d p0(p1.x / d, p1.y / d);
        return p0;
    }
    vector2d operator*=(vector2d& p1, const double& d){
        p1.x *= d;
        p1.y *= d;
        return p1;
    }

    vector2d operator/=(vector2d& p1, const double& d)
    {
        p1.x /= d;
        p1.y /= d;
        return p1;
    }

    vector2d operator*(const double& d, const vector2d& p)
    {
        return p * d;
    }

    std::ostream& operator<<(std::ostream& strm, const vector2d& p)
    {
        strm << p.x << std::setw(16) << p.y;
        return strm;
    }
    std::istream& operator>>(std::istream& strm, vector2d& p)
    {
        strm >> p.x >> p.y;
        return strm;
    }

}
