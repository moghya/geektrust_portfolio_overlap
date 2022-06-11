cmake_minimum_required(VERSION 3.20)
project(gt_mfs)

set(CMAKE_CXX_STANDARD 14)

add_library(mfs_exceptions
            incomplete_argument_exception.cpp
            invalid_command_string_exception.cpp
            invalid_config_exception.cpp
            method_not_implemented_exception.cpp
            mfs_exceptions.cpp)