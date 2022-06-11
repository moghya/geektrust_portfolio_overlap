//
// Created by Shubham Sawant on 19/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_INVALID_CONFIG_EXCEPTION_H
#define GT_PORTFOLIO_OVERLAP_INVALID_CONFIG_EXCEPTION_H

#include <exception>
#include <string>

namespace mfs {
    class InvalidConfigException : public std::logic_error {
        public:
            InvalidConfigException(std::string&& error_message);
            ~InvalidConfigException() {}
    };
}

#endif //GT_PORTFOLIO_OVERLAP_INVALID_CONFIG_EXCEPTION_H
