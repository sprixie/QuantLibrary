#pragma once
#include "IInstrument.h"
#include <vector>
#include <string>
#include <map>

class IPricer {
public:
    virtual void GetDependencies(long date, const IInstrument& instrument) = 0;
    virtual void Calibrate() = 0;
    virtual double Compute(const IInstrument& instrument, const std::vector<std::map<std::string, double>>& config) = 0;
    virtual double PriceToYield(const IInstrument& instrument, double marketPrice, double tolerance = 1e-6) const = 0;
    virtual double YieldToPrice(const IInstrument& instrument, double yield) const = 0;
    virtual ~IPricer() {}
};
