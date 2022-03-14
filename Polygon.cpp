#include "geometry.h"

namespace geometry {
    Polygon::Polygon() : Polyline() {}
    Polygon::Polygon(const std::vector<Point>& points) : Polyline(points) {}
    Polygon::Polygon(const Polygon& p) : Polyline(p.points) {
        if (is_intersect())
            throw std::logic_error("It is not a Polygon.");
    }


    Polygon::~Polygon() {}


    double Polygon::get_perimeter() const {
        double res = get_length();
        res += get_dist(points[0], points[points.size() - 1]);
        return res;
    }

    double Polygon::get_area() const {
        double res = 0;
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            sum1 += points[i].get_x() * points[i + 1].get_y();
            sum2 += points[i + 1].get_x() * points[i].get_y();
        }
        sum1 += points[points.size() - 1].get_x() * points[0].get_y();
        sum2 += points[0].get_x() * points[points.size() - 1].get_y();
        res = res + sum1 - sum2;
        return res;
    }
}