#pragma once
#include "IInstrument.h"

class InstrumentBond : public IInstrument {
private:
    double Coupon;
    long Maturity;
    double Notional;

public:
    InstrumentBond(double CouponI, long MaturityI, double NotionalI)
        : Coupon(CouponI), Maturity(MaturityI), Notional(NotionalI) {}

    void Check() const override {
        std::cout << "Bond: Managing fixed income security." << std::endl;
    }

    double GetCoupon() const { return Coupon; }
    double GetMaturity() const { return Maturity; }
    double GetNotional() const { return Notional; }

    ~InstrumentBond() {
        std::cout << "Destroying Bond." << std::endl;
    }
};
