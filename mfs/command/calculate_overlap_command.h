//
// Created by Shubham Sawant on 04/04/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_CALCULATE_OVERLAP_COMMAND_H
#define GT_PORTFOLIO_OVERLAP_CALCULATE_OVERLAP_COMMAND_H

#include "command.h"

namespace mfs {

    class CalculateOverlapCommand : public mfs::Command {
        public:
            CalculateOverlapCommand(std::istringstream& command_str_stream);
            const std::string FundName() const {
                return fund_name_;
            }
        private:
            std::string fund_name_;
    };
}

#endif //GT_PORTFOLIO_OVERLAP_CALCULATE_OVERLAP_COMMAND_H
