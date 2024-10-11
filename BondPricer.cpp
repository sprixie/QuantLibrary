#include "Bond.h"
#include "NumericalMethods.h"
#include "BondPricer.h"


void BondPricer::GetDependencies(long date, const IInstrument& instrument) {
    // Example: Fetch market data or rate based on the given date and instrument type
    std::cout << "Getting dependencies for date: " << date << " and instrument." << std::endl;

    // Assuming we need interest rates or market data for pricing
    // Add more complex logic to pull specific dependencies if necessary
}

double BondPricer::Compute(const IInstrument& instrument, 
    const std::vector<std::map<std::string, double>>& config) {
    if (config.empty()) {
        std::cerr << "Config is empty. Unable to determine pricing type." << std::endl;
        return 0.0;
    }

    // Check if instrument is a bond (dynamic cast to Bond type)
    const InstrumentBond* bond = dynamic_cast<const InstrumentBond*>(&instrument);
    if (!bond) {
        std::cerr << "Instrument is not a bond. Cannot compute." << std::endl;
        return 0.0;
    }

    // Iterate over config and apply pricing logic accordingly
    for (const auto& optionMap : config) {
        if (optionMap.find("YTP") != optionMap.end()) {
            double yield = optionMap.at("YTP");
            double price = YieldToPrice(*bond, yield);
            std::cout << "Yield to Price for bond with maturity: " << bond->GetMaturity() << " is: " << price << std::endl;
            return price;
        }
        else if (optionMap.find("PTY") != optionMap.end()) {
            double marketPrice = optionMap.at("PTY");
            double yield = PriceToYield(*bond, marketPrice);
            std::cout << "Price to Yield for bond with maturity: " << bond->GetMaturity() << " is: " << yield << std::endl;
            return yield;
        }
        else {
            std::cerr << "Unknown pricing configuration in map." << std::endl;
        }
    }

    // Placeholder return value
    return 0.0;
}

double BondPricer::PriceToYield(const IInstrument& instrument, double marketPrice, double tolerance) const {
    const InstrumentBond* bond = dynamic_cast<const InstrumentBond*>(&instrument);
    if (!bond) {
        throw std::invalid_argument("Instrument is not a bond.");
    }
    auto priceFunction = [&bond, marketPrice, this](double yield) {
        return YieldToPrice(*bond, yield) - marketPrice;
        };

    double initialGuess = 0.05;
    double h = 1e-5;
    int maxIterations = 100;
    return NumericalMethods::NewtonRaphson(initialGuess, tolerance, maxIterations, priceFunction, h);
}

double BondPricer::YieldToPrice(const IInstrument& instrument, double yield) const {
    const InstrumentBond* bond = dynamic_cast<const InstrumentBond*>(&instrument);
    if (!bond) {
        throw std::invalid_argument("Instrument is not a bond.");
    }
    // Implement the logic to calculate the bond price given a yield
    double price = 0.0;
    double coupon = bond->GetNotional() * bond->GetCoupon();
    for (int t = 1; t <= bond->GetMaturity(); ++t) {
        price += coupon / std::pow(1 + yield, t);
    }
    price += bond->GetNotional() / std::pow(1 + yield, bond->GetMaturity());
    return price;
}
