#include "geometry.h"
#include <cmath>

namespace geometry {
    
    RegularPolygon::RegularPolygon() : Polygon() {}
    RegularPolygon::RegularPolygon(const std::vector<Point>& points) : Polygon(points) {
        double d = get_dist(points[0], points[1]);
        for (int i = 2; i < points.size(); ++i) {
            double t = get_dist(points[i], points[i - 1]);
            if (t != d) {
                throw std::logic_error("It's not regular.");
                break;
            }
        }
    }
    RegularPolygon::RegularPolygon(const RegularPolygon& rp) : Polygon(rp.points) {}

    RegularPolygon::~RegularPolygon() {}

    double RegularPolygon::get_area() const {
        double d = get_dist(points[0], points[1]);
        double s = (p_num * pow(d, 2)) / (4 * tan(3.14 / p_num));
        return s;
    }

    RegularPolygon& RegularPolygon::operator=(const RegularPolygon& rp) {
        p_num = rp.p_num;
        points = rp.points;
        return *this;
    }
}