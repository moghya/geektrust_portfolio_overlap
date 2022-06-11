//
// Created by Shubham Sawant on 04/04/22.
//

#include "add_stock_command.h"

namespace mfs {
    AddStockCommand::AddStockCommand(std::istringstream &command_str_stream) :
    Command(mfs::CommandType::AddStock) {
        command_str_stream >> fund_name_;
        stock_ticker_ = command_str_stream.str();
        if (fund_name_.empty()) {
            throw mfs::InvalidCommandStringException(
                    "Fund name not found in AddStock Command.");
        }
        if (stock_ticker_.empty()) {
            throw mfs::InvalidCommandStringException(
                    "Stock Ticker not found in AddStock Command.");
        }
    }
}