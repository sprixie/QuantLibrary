#pragma once
#include "IPricer.h"
#include "IInstrument.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>

class BondPricer : public IPricer {
public:
    // Override GetDependencies method to fetch relevant data
    void GetDependencies(long date, const IInstrument& instrument) override; //return config

    // Implement the Calibrate method
    void Calibrate() override {
        std::cout << "BondPricer calibration logic here." << std::endl;
    }

    // Override Compute method to support different pricing configurations
    double Compute(const IInstrument& instrument, const std::vector<std::map<std::string, double>>& config) override;

    // Override PriceToYield and YieldToPrice to match IPricer interface
    double PriceToYield(const IInstrument& instrument, double marketPrice, double tolerance = 1e-6) const override;
    double YieldToPrice(const IInstrument& instrument, double yield) const override;
};
