#pragma once
#include <iostream>
#include <map>
#include <vector>

namespace polynominal {

    class Polynominal final {
    private:
        std::map<int, double> coeff;

    public:
        Polynominal();
        explicit Polynominal(const std::vector<double>&);
        explicit Polynominal(const std::vector<std::pair<int, double>>&);
        explicit Polynominal(const std::map<int, double>&);
        Polynominal(const Polynominal&);

        ~Polynominal();

        int get_degree() const;
        void show_coeffs() const;
        double get_coeff(int) const;
        void insert_coeff(int, double);

        void deg_mult(int);


        Polynominal& operator=(const Polynominal&);

        Polynominal operator+(double) const;
        Polynominal operator+(const Polynominal&) const;
        Polynominal& operator+=(double);
        Polynominal& operator+=(const Polynominal&);


        Polynominal operator-() const;
        Polynominal operator-(double) const;
        Polynominal operator-(const Polynominal&) const;
        Polynominal& operator-=(double);
        Polynominal& operator-=(const Polynominal&);


        Polynominal operator*(double) const;
        Polynominal operator*(const Polynominal&) const;
        Polynominal& operator*=(double);
        Polynominal& operator*=(const Polynominal&);

        Polynominal operator/(double) const;
        Polynominal& operator/=(double);

        bool operator==(const Polynominal&) const;
        bool operator!=(const Polynominal&) const;

        friend std::istream& operator>>(std::istream&, Polynominal&);
        friend std::ostream& operator<<(std::ostream&, const Polynominal&);
    };
    
}