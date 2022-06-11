//
// Created by Shubham Sawant on 18/01/22.
//

#include<string>

#include "stock.h"

namespace mfs {

    Stock::Stock(const std::string& ticker) :
        Instrument(ticker),
        ticker_(ticker) {
    }

    Stock::~Stock() {
    }

    std::string Stock::Ticker() const {
        return ticker_;
    }

}