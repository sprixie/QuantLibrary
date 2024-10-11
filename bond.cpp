#include <math.h>
#include "bond.h"

extern "C" double __stdcall PriceCpp(double Coupon, double Yield, double Notional, long Maturity)
{
    //Coupon = 0.03; // 3%
    //Yield = 0.035;  // 3%
    //Notional = 100;    // $1000
    //Maturity = 10;      // 10 years
    double result = 0.0;

    // Sum the present value of coupon payments
    for (int i = 1; i <= Maturity; i++) {
        result += Notional * Coupon * pow(1 + Yield, -i);
    }

    // Add the present value of the Notional payment at maturity
    result += Notional * pow(1 + Yield, -Maturity);

    return result;
}