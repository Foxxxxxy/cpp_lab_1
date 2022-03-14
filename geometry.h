#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

namespace geometry {

    class LinearOperator final {
        private:
            std::vector<std::vector<double>> linear_operator;

        public:
            LinearOperator();
            explicit LinearOperator(std::vector<std::vector<double>>&);
            LinearOperator(const LinearOperator&);

            ~LinearOperator();

            double operate_first_coordinate(std::pair<double, double>) const;
            double operate_second_coordinate(std::pair<double, double>) const;

            LinearOperator& operator=(const LinearOperator&);
    };

    class Point final {
        private:
            double x;
            double y;

        public:
            Point();
            explicit Point(double, double);
            Point(const Point&);

            ~Point();

            double get_x() const;
            double get_y() const;
            void linear_transformation(const LinearOperator&);
            friend double get_dist(const Point&, const Point&);

            Point& operator=(const Point&);
            bool operator==(const Point&);
            bool operator!=(const Point&);
            friend std::istream& operator>>(std::istream&, Point&);
            friend std::ostream& operator<<(std::ostream&, const Point&);
    };

    class Segment final {
        private:
            Point p1;
            Point p2;

        public:
            Segment();
            explicit Segment(const Point&, const Point&);
            Segment(const Segment&);

            ~Segment();

            double get_length() const;
            friend bool segments_intersect (const Segment&, const Segment&);
            void linear_transformation(const LinearOperator&);

            Segment& operator=(const Segment&);
            friend std::ostream& operator<<(std::ostream&, const Segment&);
    };

    class Polyline {
        protected:
            int p_num;
            std::vector<Point> points;
            
        public:
            Polyline();
            explicit Polyline(const std::vector<Point>&);
            Polyline(const Polyline&);

            ~Polyline();

            virtual void add_point(const Point&);
            int get_points_number() const;
            virtual bool is_intersect() const;
            void linear_transformation(const LinearOperator&);
            double get_length() const;

            Polyline& operator=(const Polyline&);
            friend std::ostream& operator<<(std::ostream&, const Polyline&);
            Point& operator[](int);
    };

    class ClosedPolyline final : public Polyline {
    public:
        ClosedPolyline();
        explicit ClosedPolyline(std::vector<Point>&);
        ClosedPolyline(const ClosedPolyline&);

        ~ClosedPolyline();

        void add_point(const Point&) override;
        bool is_intersect() const override;

        ClosedPolyline& operator=(const ClosedPolyline&);
    };

    class Polygon : public Polyline {
    public:
        Polygon();
        explicit Polygon(const std::vector<Point>&);
        Polygon(const Polygon&);

        ~Polygon();

        double get_perimeter() const;
        virtual double get_area() const;

        Polygon& operator=(const Polygon&);
    };

    class Triangle final : public Polygon {
        Triangle();
        explicit Triangle(const Point&, const Point&, const Point&);
        Triangle(const Triangle&);

        ~Triangle();
        virtual double get_area() const override;

        Triangle& operator=(const Triangle&);
    };

    class Trapezoid final : public Polygon {
    private:
        bool is_trapezoid(const Point&, const Point&, const Point&, const Point&) const;
    public:
        Trapezoid();
        explicit Trapezoid(const Point&, const Point&, const Point&, const Point&);
        Trapezoid(const Trapezoid&);   

        ~Trapezoid();
        virtual double get_area() const override;

        Trapezoid& operator=(const Trapezoid&);
    };

    class RegularPolygon final : public Polygon {
    public:
        RegularPolygon();
        explicit RegularPolygon(const std::vector<Point>&);
        RegularPolygon(const RegularPolygon&);

        ~RegularPolygon();
        virtual double get_area() const override;

        RegularPolygon& operator=(const RegularPolygon&);
    };

}