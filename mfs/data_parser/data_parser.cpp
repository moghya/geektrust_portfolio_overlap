//
// Created by Shubham Sawant on 18/01/22.
//


#include <fstream>
#include <string>

#include "json.hpp"

#include "data_parser.h"
#include "../exceptions/incomplete_argument_exception.h"
#include "../exceptions/method_not_implemented_exception.h"

namespace mfs {
    void FundsDataParser::Parse(std::string file_name,
                                FileFormatType file_format_type,
                                ParsedData parsed_data) {
        if (!parsed_data.stocks_creator_ptr || !parsed_data.funds_map_ptr) {
            throw IncompleteArgumentException(
                    "Either stocks_map_ptr or funds_map_ptr not present in parsed_data");
        }

        switch (file_format_type) {
            case FileFormatType::JSON: {
                std::ifstream file_input_stream(file_name);
                nlohmann::json json_funds_data;
                file_input_stream >> json_funds_data;
                for(auto fund : json_funds_data["funds"]) {
                    auto fund_ptr = std::make_shared<EquityFund>(fund["name"], parsed_data.stocks_creator_ptr);
                    for(auto&& stock_ticker : fund["stocks"]) {
                        fund_ptr->AddStock(stock_ticker);
                    }
                    parsed_data.funds_map_ptr->insert({fund["name"], fund_ptr});
                }
                break;
            }
            default:
                throw MethodNotImplementedException(
                        "FundsDataParser not implemented for file_format_type: " + std::to_string(file_format_type));
        }
    }
}