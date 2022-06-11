//
// Created by Shubham Sawant on 04/04/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_CURRENT_PORTFOLIO_COMMAND_H
#define GT_PORTFOLIO_OVERLAP_CURRENT_PORTFOLIO_COMMAND_H

#include "command.h"

namespace mfs {

class CurrentPortfolioCommand : public mfs::Command {
    public:
        CurrentPortfolioCommand(std::istringstream& command_str_stream);
        const std::set<std::string>& FundNames() const {
            return fund_names_;
        }
    private:
        std::set<std::string> fund_names_;
};

}

#endif //GT_PORTFOLIO_OVERLAP_CURRENT_PORTFOLIO_COMMAND_H
