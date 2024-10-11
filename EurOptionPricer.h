#pragma once
#include "IPricer.h"

class OptionPricer : public IPricer {
public:
    void GetDependencies(long date, const IInstrument& instrument) override;
    void Calibrate() override;
    double Compute(const IInstrument& instrument, const std::vector<std::map<std::string, double>>& config) override;

private:
    double N(double x); // Normal cumulative distribution function
    double BlackScholesCall(double S, double K, double T, double r, double sigma);
    double BlackScholesPut(double S, double K, double T, double r, double sigma);
};
