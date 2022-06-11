//
// Created by Shubham Sawant on 19/01/22.
//

#include <exception>
#include <string>

#include "incomplete_argument_exception.h"

namespace mfs {

    IncompleteArgumentException::IncompleteArgumentException(
            std::string&& error_message) :
        std::logic_error(error_message) {

    }

}