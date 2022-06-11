//
// Created by Shubham Sawant on 04/04/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_COMMAND_BUILDER_H
#define GT_PORTFOLIO_OVERLAP_COMMAND_BUILDER_H

#include "command.h"

namespace mfs {
    class CommandBuilder {
    private:
        std::unordered_map <std::string, mfs::CommandType> CommandNameToCommandTypeMap;

        mfs::CommandType GetCommandType(const std::string &command);

    public:
        CommandBuilder();

        mfs::Command *Build(std::string command_str);
    };
}



#endif //GT_PORTFOLIO_OVERLAP_COMMAND_BUILDER_H
