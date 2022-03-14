#include "geometry.h"
#include <cmath>

namespace geometry {
    Triangle::Triangle() : Polygon() {}
    Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Polygon({Point(p1), Point(p2), Point(p3)}) {}
    Triangle::Triangle(const Triangle& t) : Polygon(t.points) {}


    Triangle::~Triangle() {}

    double Triangle::get_area() const {
        double s1 = get_dist(points[0], points[1]);
        double s2 = get_dist(points[1], points[2]);
        double s3 = get_dist(points[0], points[2]);

        double p = (s1 + s2 + s3) / 2.;

        return sqrt(p * (p - s1) * (p - s2) * (p - s3));
    }

    Triangle& Triangle::operator=(const Triangle& t) {
        p_num = t.p_num;
        points = t.points;
        return *this;
    }
}