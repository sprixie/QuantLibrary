#pragma once
#include <iostream>

enum Payoff {
    Call,   
    Put,    
};

class IInstrument {
public:
    virtual void Check() const {
        std::cout << "Check that the instrument is supported." << std::endl;
    }

    virtual ~IInstrument() {
        std::cout << "Destroying Instrument." << std::endl;
    }
};

