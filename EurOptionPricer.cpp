#include "EurOptionPricer.h"
#include "Euroption.h"
#include <iostream>
#include <cmath>

void OptionPricer::GetDependencies(long date, const IInstrument& instrument) {
    std::cout << "Getting dependencies for Option on date: " << date << std::endl;
    // Fetch market data or other dependencies here
}

void OptionPricer::Calibrate() {
    std::cout << "Calibrating OptionPricer." << std::endl;
    // Calibration logic (adjust parameters based on market data)
}

double OptionPricer::Compute(const IInstrument& instrument, const std::vector<std::map<std::string, double>>& config) {
    const InstrumentEurOption& option = static_cast<const InstrumentEurOption&>(instrument);

    // Example parameters
    double S = 100.0; // Current stock price (should be fetched from market data)
    double K = option.GetStrike(); // Strike price
    double T = option.GetMaturity(); // Time to maturity in years
    double r = 0.05; // Risk-free interest rate (example value)
    double sigma = 0.2; // Volatility (example value)

    double price = 0.0;
    if (option.GetPayoffType() == Call) {
        price = BlackScholesCall(S, K, T, r, sigma);
    }
    else {
        price = BlackScholesPut(S, K, T, r, sigma);
    }
    return price;
}

double OptionPricer::N(double x) {
    // Standard normal cumulative distribution function
    return 0.5 * std::erfc(-x * std::sqrt(0.5));
}

double OptionPricer::BlackScholesCall(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return S * N(d1) - K * std::exp(-r * T) * N(d2);
}

double OptionPricer::BlackScholesPut(double S, double K, double T, double r, double sigma) {
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return K * std::exp(-r * T) * N(-d2) - S * N(-d1);
}
