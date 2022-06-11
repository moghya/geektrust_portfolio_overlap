//
// Created by Shubham Sawant on 19/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_INCOMPLETE_ARGUMENT_EXCEPTION_H
#define GT_PORTFOLIO_OVERLAP_INCOMPLETE_ARGUMENT_EXCEPTION_H

#include <exception>
#include <string>

namespace mfs {
    class IncompleteArgumentException : public std::logic_error {
        public:
            IncompleteArgumentException(std::string&& error_message);
            ~IncompleteArgumentException() {}
    };
}

#endif //GT_PORTFOLIO_OVERLAP_INCOMPLETE_ARGUMENT_EXCEPTION_H
