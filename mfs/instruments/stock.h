//
// Created by Shubham Sawant on 18/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_STOCK_H
#define GT_PORTFOLIO_OVERLAP_STOCK_H

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "instrument.h"

namespace mfs {
    class Stock : public Instrument {
        public:
            Stock(const std::string& ticker);
            ~Stock();
            std::string Ticker() const;
        private:
            std::string ticker_;
    };
    typedef std::shared_ptr<Stock> StockPtr;
    typedef std::unordered_map<std::string, StockPtr> StockPtrMap;
    typedef std::unordered_set<StockPtr> StockPtrSet;

    class StocksCreator {
        public:
            StocksCreator(std::shared_ptr<StockPtrMap> stocks_map_ptr) :
                    stocks_map_ptr_(stocks_map_ptr) {}

            std::shared_ptr<Stock> CreateStock(const std::string& ticker) {
                auto it = stocks_map_ptr_->find(ticker);
                std::shared_ptr<Stock> stock;
                if (it == stocks_map_ptr_->end()) {
                    stock = std::make_shared<Stock>(ticker);
                    stocks_map_ptr_->insert({ticker, stock});
                } else {
                    stock = it->second;
                }
                return stock;
            }
        private:
            std::shared_ptr<StockPtrMap> stocks_map_ptr_;
    };

}

#endif //GT_PORTFOLIO_OVERLAP_STOCK_H
