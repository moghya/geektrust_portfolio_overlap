//
// Created by Shubham Sawant on 04/04/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_ADD_STOCK_COMMAND_H
#define GT_PORTFOLIO_OVERLAP_ADD_STOCK_COMMAND_H

#include "command.h"

namespace mfs {
    class AddStockCommand : public mfs::Command {
    public:
        AddStockCommand(std::istringstream &command_str_stream);

        const std::string& FundName() const {
            return fund_name_;
        }

        const std::string& Ticker() const {
            return stock_ticker_;
        }
    private:
        std::string fund_name_;
        std::string stock_ticker_;
    };
}
#endif //GT_PORTFOLIO_OVERLAP_ADD_STOCK_COMMAND_H
