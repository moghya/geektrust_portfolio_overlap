//
// Created by Shubham Sawant on 18/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_PORTFOLIO_H
#define GT_PORTFOLIO_OVERLAP_PORTFOLIO_H

#include <string>

#include "fund.h"

namespace mfs {

    class Portfolio {
    public:
        Portfolio(std::string name) : name_(name), funds_set_ptr_(std::make_shared<FundsSet>()) {}

        ~Portfolio() {}

        void AddFund(std::shared_ptr<Fund> fund) {
            funds_set_ptr_->insert(fund);
        }

        void ClearFunds() {
            funds_set_ptr_->clear();
        }

        std::shared_ptr<FundsSet> Funds() const {
            return funds_set_ptr_;
        }

    private:
        std::string name_;
        std::shared_ptr<FundsSet> funds_set_ptr_;
    };

    typedef std::unordered_map<std::string, std::shared_ptr<Portfolio>> PortfoliosMap;

}


#endif //GT_PORTFOLIO_OVERLAP_PORTFOLIO_H
