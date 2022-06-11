//
// Created by Shubham Sawant on 19/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_INVALID_COMMAND_STRING_EXCEPTION_H
#define GT_PORTFOLIO_OVERLAP_INVALID_COMMAND_STRING_EXCEPTION_H

#include <exception>
#include <string>

namespace mfs {
    class InvalidCommandStringException : public std::runtime_error {
    public:
        InvalidCommandStringException(std::string&& error_message);
        ~InvalidCommandStringException() {}
    };
}


#endif //GT_PORTFOLIO_OVERLAP_INVALID_COMMAND_STRING_EXCEPTION_H
