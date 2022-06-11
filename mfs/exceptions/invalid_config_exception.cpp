//
// Created by Shubham Sawant on 19/01/22.
//

#include "invalid_config_exception.h"

namespace mfs {

    InvalidConfigException::InvalidConfigException(
            std::string&& error_message) :
        std::logic_error(error_message) {

    }

}