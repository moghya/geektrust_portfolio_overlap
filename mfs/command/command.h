//
// Created by Shubham Sawant on 18/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_COMMAND_H
#define GT_PORTFOLIO_OVERLAP_COMMAND_H

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>

#include "../utils/utils.h"
#include "../exceptions/invalid_command_string_exception.h"

namespace mfs {

    enum class CommandType {
        Unknown = 0,
        CalculateOverlap = 1,
        AddStock = 2,
        CurrentPortfolio = 3,
    };

    class Command {
        public:
            Command(CommandType type = CommandType::Unknown) :
                type_(type) {}
            Command(std::string text,
                    CommandType type = CommandType::Unknown) :
                    text_(text),
                    type_(type) {}
            ~Command() = default;
            CommandType Type() const {
                return type_;
            }
            std::string Text() const {
                return text_;
            }
        private:
            CommandType type_;
            std::string text_;
    };


}


#endif //GT_PORTFOLIO_OVERLAP_COMMAND_H
