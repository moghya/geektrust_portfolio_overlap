//
// Created by Shubham Sawant on 18/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_FUND_H
#define GT_PORTFOLIO_OVERLAP_FUND_H

#include <string>

#include "../instruments/instrument.h"
#include "../instruments/stock.h"

namespace mfs {

    class Fund {

        public:
            ~Fund() {}

            std::string Name() const {
                return name_;
            }

        protected:
            Fund(std::string name) :
                    name_(name) {
            }

            void AddInstrument(InstrumentPtr instrument) {
                instrument_set_.insert(instrument);
            }

        protected:
            std::string name_;
            InstrumentPtrSet instrument_set_;
    };
    typedef std::unordered_map<std::string, std::shared_ptr<Fund>> FundsMap;
    typedef std::unordered_set<std::shared_ptr<Fund>> FundsSet;

    class EquityFund : public Fund {
        public:
            EquityFund(std::string name,
                       std::shared_ptr<StocksCreator> stocks_creator_ptr) :
                Fund(name),
                stocks_creator_ptr_(stocks_creator_ptr) {
            }

            void AddStock(std::string stock_ticker) {
                auto stock = stocks_creator_ptr_->CreateStock(stock_ticker);
                AddStock(stock);
            }

            void AddStock(StockPtr stock) {
                AddInstrument((InstrumentPtr)stock);
            }

            InstrumentPtrSet Stocks() const {
                return instrument_set_;
            }

        private:
            std::shared_ptr<StocksCreator> stocks_creator_ptr_;
    };
}

#endif //GT_PORTFOLIO_OVERLAP_FUND_H
