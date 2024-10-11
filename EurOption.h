#pragma once
#include "IInstrument.h"

class InstrumentEurOption : public IInstrument {
private:
    double Strike;
    double Maturity;
    Payoff OptPayoff;

public:
    InstrumentEurOption(double StrikeI, double MaturityI, Payoff PayoffType)
        : Strike(StrikeI), Maturity(MaturityI), OptPayoff(PayoffType) {}

    void Check() const override {
        std::cout << "Option: Managing option security." << std::endl;
    }

    double GetStrike() const { return Strike; }
    double GetMaturity() const { return Maturity; }
    Payoff GetPayoffType() const { return OptPayoff; }

    ~InstrumentEurOption() {
        std::cout << "Destroying Option." << std::endl;
    }
};
