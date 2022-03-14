#include "geometry.h"

namespace geometry {
    Polyline::Polyline() : p_num(0) , points({}) {}
    Polyline::Polyline(const std::vector<Point>& points) : p_num(points.size()), points(points) {}
    Polyline::Polyline(const Polyline& polyline) : p_num(polyline.points.size()), points(polyline.points) {}

    Polyline::~Polyline() {}

    int Polyline::get_points_number() const {
        return p_num;
    }

    void Polyline::add_point(const Point& p) {
        points.push_back(p);
        ++p_num;
    }

    double Polyline::get_length() const {
        double res = 0;
        for (int i = 1; i < points.size(); ++i)
            res += get_dist(points[i], points[i - 1]);
        return res;        
    }

    bool Polyline::is_intersect() const {
        for (int i = 0; i < p_num - 1; ++i) {
            const Segment& s1 = Segment{points[i], points[i + 1]};
            for (int j = i + 1; j < p_num - 1; ++j) {
                const Segment& s2 = Segment{points[j], points[j + 1]};
                if (segments_intersect(s1, s2))
                    return true;
            }
        }
        return false;
    }

    void Polyline::linear_transformation(const LinearOperator& op) {
        for (int i = 0; i < p_num; ++i)
            points[i].linear_transformation(op);
    }

    Polyline& Polyline::operator=(const Polyline& polyline) {
        p_num = polyline.p_num;
        points = polyline.points;
        return *this;
    }

    std::ostream& operator<<(std::ostream& out, const Polyline& polyline) {
        for (int i = 0; i < polyline.p_num; ++i)
            out << polyline.points[i] << " ";
        out << "\n";
        return out;
    }

    Point& Polyline::operator[](int i) {
        return points[i];
    }
}