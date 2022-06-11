//
// Created by Shubham Sawant on 04/04/22.
//

#include "current_portfolio_command.h"

namespace mfs {
    CurrentPortfolioCommand::CurrentPortfolioCommand(std::istringstream& command_str_stream) :
        Command(mfs::CommandType::CurrentPortfolio) {
        std::string fund_name;
        while (command_str_stream >> fund_name) {
            fund_names_.insert(fund_name);
        }
        if (fund_names_.empty()) {
            throw mfs::InvalidCommandStringException("Fund names not found in CurrentPolio Command");
        }
    }
}