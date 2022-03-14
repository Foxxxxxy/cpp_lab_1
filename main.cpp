#include "geometry.h"
#include <iostream>
#include <cmath>
#include "polynominal.h"

using namespace std;

int main () {
    vector<vector<double>> op = {{sqrt(3) / 2, -0.5}, {0.5, sqrt(3) / 2}};
    geometry::LinearOperator _operator = geometry::LinearOperator(op);

    geometry::Point p1 = geometry::Point(1, 1);
    geometry::Point p2 = geometry::Point(2, 2);
    geometry::Point p3 = geometry::Point(1, 1);

    cout << p1 << "\n";
    cout << p2 << "\n";

    cout << get_dist(p1, p2) << "\n";
    
    cout << (p1 == p2) << "\n";
    cout << (p1 == p3) << "\n";

    p1.linear_transformation(_operator);
    cout << p1 << "\n";

    geometry::Point p4 = p2;
    cout << (p1 != p4) << "\n";

    geometry::Point p5 = geometry::Point(-5, 0);
    geometry::Point p6 = geometry::Point(5, 0);
    geometry::Segment s1 = geometry::Segment(p5, p6);

    geometry::Point p7 = geometry::Point(2.5, 5);
    geometry::Point p8 = geometry::Point(2.5, -5);
    geometry::Segment s2 = geometry::Segment(p7, p8);

    cout << s1.get_length() << " " << s2.get_length() << "\n";
    cout << segments_intersect(s1, s2) << "\n";
    s1.linear_transformation(_operator);
    cout << s1 << s2 << "\n";

    cout << "-----------------------------------------------\n";

    geometry::Polyline polyline = geometry::Polyline({p1, p2, p3, p8});
    cout << polyline << polyline.get_points_number() << "\n";

    geometry::Point p9 = geometry::Point(1, 3);

    polyline.add_point(p9);
    cout << polyline << polyline.get_points_number() << "\n";
    cout << polyline.is_intersect() << "\n";
    cout << polyline.get_length() << "\n";

    cout << "-----------------------------------------------\n";

    
    return 0;
}