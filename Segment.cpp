#include "geometry.h"

namespace geometry {
    Segment::Segment() : p1(Point{0, 0}), p2(Point{0, 1}) {}
    Segment::Segment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}
    Segment::Segment(const Segment& s) : p1(s.p1), p2(s.p2) {}

    Segment::~Segment() {}

    double Segment::get_length() const {
        return get_dist(p1, p2);
    }

    double det (double a, double b, double c, double d) {
        return a*d - b*c;
    }

    bool between (double a, double b, double c) {
	    return std::min(a,b) < c + 1e-9 && c < std::max(a,b) + 1e-9;
    }
 
    bool intersect (double a, double b, double c, double d) {
	    if (a > b)  std::swap (a, b);
	    if (c > d)  std::swap (c, d);
	    return std::max(a,c) < std::min(b,d);
    }

    bool segments_intersect (const Segment& s1, const Segment& s2) {
        Point p1 = Point(s1.p1);
        Point p2 = Point(s1.p2);
        Point p3 = Point(s2.p1);
        Point p4 = Point(s2.p2);

        if (p1 == p3 && p2 == p4 || p1 == p4 && p2 == p3)
            throw std::logic_error("Segments are equal");

        double a1 = p1.get_y() - p2.get_y(), b1 = p2.get_x() - p1.get_x(), c1 = -a1*p1.get_x() - b1*p1.get_y();
        double a2 = p3.get_y() - p4.get_y(), b2 = p4.get_x() - p3.get_x(), c2 = -a2*p3.get_x() - b2*p3.get_y();
        double zn = det(a1, b1, a2, b2);
        if (zn != 0) {
            double x = -det(c1, b1, c2, b2) * 1. / zn;
            double y = -det(a1, c1, a2, c2) * 1. / zn;

            Point k = Point(x, y);

            if (k == p1 || k == p2 || k == p3 || k == p4)
                return false;

            bool b1 = between(p1.get_x(), p2.get_x(), x);
            bool b2 = between(p1.get_y(), p2.get_y(), y);
            bool b3 = between (p3.get_x(), p4.get_x(), x);
            bool b4 = between (p3.get_y(), p4.get_y(), y);

            return b1 && b2 && b3 && b4;
        } else {
            return det(a1, c1, a2, c2) == 0 && det(b1, c1, b2, c2) == 0 &&
                intersect(p1.get_x(), p2.get_x(), p3.get_x(), p4.get_x()) &&
                intersect(p1.get_y(), p2.get_y(), p3.get_y(), p4.get_y());
        }
    }

    void Segment::linear_transformation(const LinearOperator& op) {
        p1.linear_transformation(op);
        p2.linear_transformation(op);
    }

    Segment& Segment::operator=(const Segment& s) {
        this->p1 = s.p1;
        this->p2 = s.p2;
        return *this;
    }

    std::ostream& operator<<(std::ostream& out, const Segment& s) {
        out << "( " << s.p1 << ", " << s.p2 << " )\n";
        return out;
    }
}