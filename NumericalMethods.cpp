#include "NumericalMethods.h"
#include <functional>
#include <stdexcept>
#include <cmath>

double NumericalMethods::NewtonRaphson(double initialGuess, double tolerance, int maxIterations, const std::function<double(double)>& func, double h) {
    double x = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double fValue = func(x);
        double fDerivative = (func(x + h) - func(x)) / h;
        if (std::abs(fValue) < tolerance) {
            return x;
        }
        if (fDerivative == 0) {
            throw std::runtime_error("Derivative is zero, cannot proceed with Newton-Raphson method.");
        }
        x = x - fValue / fDerivative;
    }
    throw std::runtime_error("Max iterations reached without convergence.");
}
