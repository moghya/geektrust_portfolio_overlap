//
// Created by Shubham Sawant on 18/01/22.
//

#include <exception>
#include <string>

#include "method_not_implemented_exception.h"

namespace mfs {

    MethodNotImplementedException::MethodNotImplementedException(
            std::string&& error_message) :
        std::logic_error(error_message) {
    }

}