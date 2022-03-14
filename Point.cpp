#include "geometry.h"
#include <cmath>

namespace geometry {

    Point::Point() : x(0), y(0) {}
    Point::Point(double x, double y) : x(x), y(y) {}
    Point::Point(const Point& p) : x(p.x), y(p.y) {}


    Point::~Point() {}

    double Point::get_y() const {
        return y;
    }

    double Point::get_x() const {
        return x;
    }

    double get_dist(const Point& p1, const Point& p2) {
        double x1 = p1.x;
        double y1 = p1.y;
        double x2 = p2.x;
        double y2 = p2.y;

        return sqrt(pow(x1 - x2, 2) + pow(y1- y2, 2));
    }

    void Point::linear_transformation(const LinearOperator& op) {
        double tx = x, ty = y;
        x = op.operate_first_coordinate(std::make_pair(tx, ty));
        y = op.operate_second_coordinate(std::make_pair(tx, ty));
    }

    Point& Point::operator=(const Point& p) {
        x = p.x;
        y = p.y;
        return *this;
    }

    bool Point::operator==(const Point& p) {
        return x == p.get_x() && y == p.get_y();
    }

    bool Point::operator!=(const Point& p) {
        return !(x == p.get_x() && y == p.get_y());
    }

    std::istream &operator>>(std::istream &in, Point &p)
    {
        in >> p.x >> p.y;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Point &p)
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
}