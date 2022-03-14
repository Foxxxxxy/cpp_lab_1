#include "geometry.h"
#include <cmath>

namespace geometry {

    Trapezoid::Trapezoid() : Polygon() {}
    Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : Polygon({Point(p1), Point(p2), Point(p3), Point(p4)}) {}
    Trapezoid::Trapezoid(const Trapezoid& tr) : Polygon(tr.points) {}

    Trapezoid::~Trapezoid() {}

    double get_coeff(double x1, double y1, double x2, double y2) {
        return (abs(y2 - y1) / abs(x2 - x1));
    }

    bool Trapezoid::is_trapezoid (const Point& p1, const Point& p2, const Point& p3, const Point& p4) const {
        double k1 = get_coeff(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
        double k2 = get_coeff(p1.get_x(), p1.get_y(), p4.get_x(), p4.get_y());

        double k3 = get_coeff(p2.get_x(), p2.get_y(), p3.get_x(), p3.get_y());
        double k4 = get_coeff(p3.get_x(), p3.get_y(), p4.get_x(), p4.get_y());

        if ((k1 == k4 && k2 != k3) || (k1 != k4 && k2 == k3))
            return true;
        else
            return false;
    }

    double Trapezoid::get_area () const {
        double s1 = get_dist(points[0], points[1]);
        double s2 = get_dist(points[1], points[2]);
        double s3 = get_dist(points[2], points[3]);
        double s4 = get_dist(points[3], points[0]);

        double t = pow(s1 - s3, 2);
        double s = ((s1 + s3) / 2.) * sqrt(pow(s4, 2) - pow((t + pow(s4, 2) - pow(s2, 2)) / (2*t), 2));
        return s;
    }

    Trapezoid& Trapezoid::operator=(const Trapezoid& tr) {
        p_num = tr.p_num;
        points = tr.points;
        return *this;
    }
}