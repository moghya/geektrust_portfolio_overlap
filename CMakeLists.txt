cmake_minimum_required(VERSION 3.20)
project(gt_portfolio_overlap)

set(CMAKE_CXX_STANDARD 14)
include_directories(third_party)

add_subdirectory(mfs)

add_executable(gt_portfolio_overlap main.cpp)
target_link_libraries(gt_portfolio_overlap mfslib)
