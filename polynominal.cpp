#include "polynominal.h"

namespace polynominal {

    Polynominal::Polynominal() : coeff({}) {}

    Polynominal::Polynominal(const std::vector<double>& coeffs) {
        for (int i = 0; i < coeffs.size(); ++i)
            coeff.insert({i, coeffs[i]});
    }

    Polynominal::Polynominal(const std::vector<std::pair<int, double>>& coeffs) {
        for (auto it : coeffs) 
            coeff.insert({it.first, it.second});
    }

    Polynominal::Polynominal(const std::map<int, double>& coeff) : coeff(coeff) {}

    Polynominal::Polynominal(const Polynominal& pol) : coeff(pol.coeff) {}


    Polynominal::~Polynominal() {}

    int Polynominal::get_degree() const {
        return coeff.size() - 1;
    }

    void Polynominal::show_coeffs () const {
        for (auto it = coeff.begin(); it != coeff.end(); ++it)
            std::cout << it->first << " degree: " << it->second << "\n";
    }

    double Polynominal::get_coeff(int deg) const {
        return coeff.find(deg)->second;
    }

    void Polynominal::insert_coeff(int key, double val) {
        if (coeff.find(key) != coeff.end())
            coeff.at(key) = val;
        else
            coeff.insert({key, val});
    }

    void Polynominal::deg_mult(int deg) {
        Polynominal t = Polynominal();

        for (auto it : coeff) {
            t.coeff.insert({it.first+deg, it.second});
        }

        *this = t;
    }

    Polynominal& Polynominal::operator=(const Polynominal& pol) {
        coeff = pol.coeff;
        return *this;
    }

    Polynominal Polynominal::operator+(double d) const {
        Polynominal res = Polynominal(*this);
        res.coeff.begin()->second += d;
        return res;
    }

    Polynominal Polynominal::operator+(const Polynominal& pol) const {
        Polynominal res = Polynominal(*this);
        for (int i = 0; i < pol.coeff.size(); ++i) {
            auto it = pol.coeff.find(i);
            if (it != pol.coeff.end())
                res.coeff.find(i)->second += it->second;
        }
             
        return res;
    }

    Polynominal& Polynominal::operator+=(double d){
        coeff.begin()->second += d;
        return *this;
    }

    Polynominal& Polynominal::operator+=(const Polynominal& pol){
        for (auto it : pol.coeff) {
            if (coeff.find(it.first) != coeff.end()) {
                coeff.at(it.first) += pol.coeff.at(it.first);
            } else {
                coeff.insert({it.first, pol.coeff.at(it.first)});
            }
        }

        return *this;
    }

    Polynominal Polynominal::operator-() const{
        Polynominal res = Polynominal(*this);
        for (auto it : res.coeff) {
            it.second *= -1;
        }
        return res;
    }

    Polynominal Polynominal::operator-(double d) const {
        Polynominal res = Polynominal(*this);
        res.coeff.begin()->second -= d;
        return res;
    }

    Polynominal Polynominal::operator-(const Polynominal& pol) const {
        Polynominal res = Polynominal(*this);
        for (int i = 0; i < pol.coeff.size(); ++i) {
            auto it = pol.coeff.find(i);
            if (it != pol.coeff.end())
                res.coeff.find(i)->second -= it->second;
        }
             
        return res;
    }

    Polynominal& Polynominal::operator-=(double d){
        coeff.begin()->second -= d;
        return *this;
    }

    Polynominal& Polynominal::operator-=(const Polynominal& pol){
        for (int i = 0; i < pol.coeff.size(); ++i) {
            auto it = pol.coeff.find(i);
            if (it != pol.coeff.end())
                coeff.find(i)->second -= it->second;
        }

        return *this;
    }

    Polynominal Polynominal::operator*(double d) const {
        Polynominal res = Polynominal(*this);
        for (auto it : res.coeff)
            res.coeff.at(it.first) *= d;
        
        return res;
    }

    Polynominal Polynominal::operator*(const Polynominal& pol) const {
        Polynominal res = Polynominal();
        Polynominal cur = Polynominal(*this);

        for (auto it : pol.coeff) {
            cur.deg_mult(it.first);
            res += cur * it.second;
            cur = Polynominal(*this);
        }

        return res;
    }

    Polynominal& Polynominal::operator*=(double d){
        for (auto it : coeff)
            coeff.at(it.first) *= d;

        return *this;
    }

    Polynominal& Polynominal::operator*=(const Polynominal& pol){
        Polynominal res = Polynominal();
        Polynominal cur = Polynominal(*this);

        for (auto it : pol.coeff) {
            cur.deg_mult(it.first);
            res += cur * it.second;
            cur = Polynominal(*this);
        }

        *this = res;
        return *this;
    }

    Polynominal Polynominal::operator/(double d) const {
        Polynominal res = Polynominal(*this);
        for (auto it : res.coeff)
            res.coeff.at(it.first) /= d;
        
        return res;
    }

    Polynominal& Polynominal::operator/=(double d) {
        Polynominal res = Polynominal(*this);
        for (auto it : coeff)
            coeff.at(it.first) /= d;
        
        return *this;
    }

    bool Polynominal::operator==(const Polynominal& pol) const {
        return coeff == pol.coeff;
    }

    bool Polynominal::operator!=(const Polynominal& pol) const {
        return !(coeff == pol.coeff);
    }

    std::istream& operator>>(std::istream& in, Polynominal& pol) {
        int key;
        double val;
        while (key != -1) {
            in >> key >> val;
            pol.insert_coeff(key, val);
        }

        return in;
    }

    std::ostream& operator<<(std::ostream& out, const Polynominal& pol) {
        pol.show_coeffs();
        return out;
    }
}