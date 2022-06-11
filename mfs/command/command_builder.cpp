//
// Created by Shubham Sawant on 04/04/22.
//

#include "command_builder.h"
#include "add_stock_command.h"
#include "calculate_overlap_command.h"
#include "current_portfolio_command.h"

namespace mfs {
    CommandBuilder::CommandBuilder() :
        CommandNameToCommandTypeMap({
            {mfs::Constants::kCalculateOverlap, mfs::CommandType::CalculateOverlap},
            {mfs::Constants::kAddStock,         mfs::CommandType::AddStock},
            {mfs::Constants::kCurrentPortfolio, mfs::CommandType::CurrentPortfolio}
        }) {
    }

    mfs::CommandType CommandBuilder::GetCommandType(const std::string& command) {
        auto it = CommandNameToCommandTypeMap.find(command);
        if (it == CommandNameToCommandTypeMap.end()) {
            return mfs::CommandType::Unknown;
        } else {
            return it->second;
        }
    }

    mfs::Command* CommandBuilder::Build(std::string command_str) {
        std::istringstream command_str_stream(command_str);
        std::string command;
        command_str_stream >> command;
        auto command_type = GetCommandType(command);
        try {
            switch (command_type) {
                case mfs::CommandType::CurrentPortfolio:
                    return new CurrentPortfolioCommand(command_str_stream);
                case mfs::CommandType::AddStock:
                    return new AddStockCommand(command_str_stream);
                case mfs::CommandType::CalculateOverlap:
                    return new CalculateOverlapCommand(command_str_stream);
                default:
                    return new mfs::Command(command_str);
            }
        } catch (mfs::InvalidCommandStringException e) {
            std::cout << "InvalidCommandStringException:: " << e.what() << "\n";
            return new mfs::Command();
        }
    }
}