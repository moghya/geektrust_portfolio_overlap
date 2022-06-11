cmake_minimum_required(VERSION 3.20)
project(gt_mfs)

set(CMAKE_CXX_STANDARD 14)

add_library(mfs_commands
            command.cpp
            add_stock_command.cpp
            calculate_overlap_command.cpp
            current_portfolio_command.cpp
            command_builder.cpp
            mfs_commands.cpp)
