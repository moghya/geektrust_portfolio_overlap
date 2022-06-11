cmake_minimum_required(VERSION 3.20)
project(gt_mfs)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(command)
#add_subdirectory(data_parser)
add_subdirectory(exceptions)
#add_subdirectory(instrument)
#add_subdirectory(porfolio)
#add_subdirectory(utils)

include_directories(${CMAKE_SOURCE_DIR}/utils
                    ${CMAKE_SOURCE_DIR}/command
                    ${CMAKE_SOURCE_DIR}/data_parser
                    ${CMAKE_SOURCE_DIR}/exceptions
                    ${CMAKE_SOURCE_DIR}/instruments
                    ${CMAKE_SOURCE_DIR}/portfolio)

add_library(mfslib
            utils/utils.cpp
            instruments/instrument.cpp
            instruments/stock.cpp
            porfolio/fund.cpp
            porfolio/portfolio.cpp
            data_parser/data_parser.cpp
            porfolio/portfolio_overlap_calculator.cpp
            mfs_lib.cpp)
target_link_libraries(mfslib mfs_commands)
target_link_libraries(mfslib mfs_exceptions)
