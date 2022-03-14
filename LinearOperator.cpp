#include "geometry.h"

namespace geometry {

    LinearOperator::LinearOperator() : linear_operator({{0, 0}, {0, 0}}) {}
    LinearOperator::LinearOperator(std::vector<std::vector<double>>& lo) : linear_operator(lo) {}
    LinearOperator::LinearOperator(const LinearOperator& lo) : linear_operator(lo.linear_operator) {}

    LinearOperator::~LinearOperator() {}

    double LinearOperator::operate_first_coordinate(std::pair<double, double> p) const {
        return p.first * linear_operator[0][0] + p.second * linear_operator[0][1];
    }

    
    double LinearOperator::operate_second_coordinate(std::pair<double, double> p) const {
        return p.first * linear_operator[1][0] + p.second * linear_operator[1][1];
    }

    LinearOperator& LinearOperator::operator=(const LinearOperator& op) {
        linear_operator = op.linear_operator;
        return *this;
    }

}