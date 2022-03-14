#include "geometry.h"

namespace geometry {
    ClosedPolyline::ClosedPolyline() : Polyline() {}
    ClosedPolyline::ClosedPolyline(std::vector<Point>& points) : Polyline(points) {
        if (points[0] != points[points.size() - 1])
            throw std::logic_error("Polyline is not closed.");
    }
    ClosedPolyline::ClosedPolyline(const ClosedPolyline& c) : Polyline(c.points) {}


    ClosedPolyline::~ClosedPolyline() {}

    void ClosedPolyline::add_point(const Point& p) {
        if (points[points.size() - 1] != p)
            std::cout << "Polyline won't be closed!\n";
    }

    bool ClosedPolyline::is_intersect() const {
        for (int i = 0; i < p_num - 1; ++i) {
            const Segment& s1 = Segment{points[i], points[i + 1]};
            for (int j = i + 1; j < p_num - 1; ++j) {
                if (i == 0 && j == p_num - 2)
                    break;
                const Segment& s2 = Segment{points[j], points[j + 1]};
                if (segments_intersect(s1, s2))
                    return true;
            }
        }
        return false;
    }

    ClosedPolyline& ClosedPolyline::operator=(const ClosedPolyline& c) {
        this->p_num = c.p_num;
        this->points = c.points;
        return *this;
    }
}