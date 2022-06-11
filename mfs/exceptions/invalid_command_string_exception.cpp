//
// Created by Shubham Sawant on 19/01/22.
//

#include <exception>
#include <string>

#include "invalid_command_string_exception.h"

namespace mfs {
    InvalidCommandStringException::InvalidCommandStringException(
            std::string&& error_message) :
        std::runtime_error(error_message) {}
}