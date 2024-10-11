//#include <iostream>
//#include "Bond.h"
//#include "BondPricer.h"
//#include "Euroption.h"
//#include "EurOptionPricer.h"
//
//int main() {
//    InstrumentBond myBond(5.0, 20231010, 1000000.0); // Example bond
//    BondPricer myPricer;
//
//    // Get dependencies for pricing
//    long date = 20231010;
//    myPricer.GetDependencies(date, myBond);
//
//    // Compute price using Yield to Put (YTP) and Price to Yield (PTY)
//    std::vector<std::string> config = { "YTP", "PTY" };
//    double bondPrice = myPricer.Compute(myBond, config);
//
//    std::cout << "Computed Bond Price: " << bondPrice << std::endl;
//
//    // Example for Option
//    InstrumentEurOption option(100.0, 1.0, Call); // 100 strike, 1 year maturity, call option
//    OptionPricer optionPricer;
//
//    option.Check();
//
//    optionPricer.GetDependencies(20230101, option); // Example date
//    optionPricer.Calibrate();
//
//    std::vector<std::string> optionConfig; 
//    double optionPrice = optionPricer.Compute(option, optionConfig);
//
//    std::cout << "Computed Option Price: " << optionPrice << std::endl;
//
//    return 0;
//}
#include "Bond.h"
#include "BondPricer.h"
#include <vector>
#include <string>
#include <map>

int main() {
    double Coupon = 0.03;
    double Yield = 0.05;
    double Notional = 100;
    long Maturity = 10;
    InstrumentBond myBond(Coupon, Maturity, Notional); // Coupon = 3%, maturity = 10 years, notional = 100
    BondPricer myBondPricer;

    // Configuration for Price to Yield
    std::map<std::string, double> ptyConfig = { {"PTY", 95.0} }; // Market price = 95
    std::vector<std::map<std::string, double>> config = { ptyConfig };
    double yield = myBondPricer.Compute(myBond, config);
    std::cout << "Computed yield: " << yield << std::endl;

    // Configuration for Yield to Price
    std::map<std::string, double> ytpConfig = { {"YTP", 0.04} }; // Yield = 4%
    config = { ytpConfig };
    double price = myBondPricer.Compute(myBond, config);
    std::cout << "Computed price: " << price << std::endl;

    return 0;
}
