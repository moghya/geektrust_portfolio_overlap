//
// Created by Shubham Sawant on 04/04/22.
//

#include "calculate_overlap_command.h"

namespace mfs {
    CalculateOverlapCommand::CalculateOverlapCommand(std::istringstream &command_str_stream) :
            Command(mfs::CommandType::CalculateOverlap) {
        command_str_stream >> fund_name_;
        if (fund_name_.empty()) {
            throw mfs::InvalidCommandStringException(
                    "Fund name not found in CalculateOverlap Command.");
        }
        if (!command_str_stream.str().empty()) {
            throw mfs::InvalidCommandStringException(
                    "Unexpected extra chars found in CalculateOverlap Command.");
        }
        valid_ = true;
    }
}