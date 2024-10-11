#pragma once
#include <functional>

class NumericalMethods {
public:
    static double NewtonRaphson(double initialGuess, double tolerance, int maxIterations, 
        const std::function<double(double)>& func, double h);
};