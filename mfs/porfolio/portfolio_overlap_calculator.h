//
// Created by Shubham Sawant on 18/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_PORTFOLIO_OVERLAP_CALCULATOR_H
#define GT_PORTFOLIO_OVERLAP_PORTFOLIO_OVERLAP_CALCULATOR_H

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

#include "../command/command.h"
#include "../command/calculate_overlap_command.h"
#include "../command/current_portfolio_command.h"
#include "../command/add_stock_command.h"
#include "../instruments/stock.h"
#include "../data_parser/data_parser.h"
#include "../exceptions/invalid_config_exception.h"
#include "fund.h"
#include "portfolio.h"

namespace mfs {
    class PortfolioOverlapCalculator {
        public:
            PortfolioOverlapCalculator(std::shared_ptr <StocksCreator> stocks_creator_ptr,
                                       std::shared_ptr <FundsMap> funds_map_ptr) :
                    stocks_creator_ptr(stocks_creator_ptr),
                    funds_map_ptr_(funds_map_ptr),
                    portfolio_(std::make_unique<Portfolio>("my_portfolio")) {
//                for(auto fund : *funds_map_ptr) {
//                    std::cout << fund.first << "\n";
//                    auto equity_fund = std::static_pointer_cast<EquityFund>(fund.second);
//                    for(auto stock : *equity_fund->Stocks()) {
//                        std::cout << stock->Ticker() << "\n";
//                    }
//                    std::cout << "______________________________________\n";
//                }
            }

            ~PortfolioOverlapCalculator() {}


        void ProcessCommand(Command* command) {
            switch (command->Type()) {
                case CommandType::CalculateOverlap:
                    return ProcessCalculateOverlap(static_cast<CalculateOverlapCommand *>(command));
                case CommandType::AddStock:
                    return ProcessAddStock(static_cast<AddStockCommand *>(command));
                case CommandType::CurrentPortfolio:
                    return ProcessCurrentPortfolio(static_cast<CurrentPortfolioCommand *>(command));
                case CommandType::Unknown:
                    std::cout << "Invalid Command: " << command. << "\n";
                    return;
                default:
                    // CommandNotSupportedException
                    throw InvalidCommandStringException(
                            "Command Not Supported by PortfolioOverlapCalculator");
            }
        }

    private:
            void ProcessCalculateOverlap(CalculateOverlapCommand* command) {
                auto& fund_name = command->FundName();
                auto it = funds_map_ptr_->find(fund_name);
                if (it == funds_map_ptr_->end()) {
                    // FundNotFoundException
                    throw InvalidCommandStringException(fund_name + " fund not found.");
                }
                auto equity_fund = std::static_pointer_cast<EquityFund>(it->second);
                if (!equity_fund) {
                    // FundNotFoundException
                    throw InvalidCommandStringException(fund_name + " is not equity fund.");
                }
                auto equity_fund_stock_ptr_set = equity_fund->Stocks();
                auto equity_fund_stock_ptr_set_size = equity_fund_stock_ptr_set.size();
                auto& current_funds_set = *portfolio_->Funds();
                for(auto current_fund_ptr : current_funds_set) {
                    auto current_equity_fund_ptr = std::static_pointer_cast<EquityFund>(current_fund_ptr);
                    auto current_equity_fund_stock_ptr_set = current_equity_fund_ptr->Stocks();
                    auto current_equity_fund_stock_ptr_set_size = current_equity_fund_stock_ptr_set.size();

                    auto set_with_less_elements = equity_fund_stock_ptr_set;
                    auto set_with_more_elements = current_equity_fund_stock_ptr_set;

                    if (current_equity_fund_stock_ptr_set_size < equity_fund_stock_ptr_set_size) {
                        std::swap(set_with_less_elements, set_with_more_elements);
                    }
                    double common_count = 0;
                    for(auto stock : set_with_less_elements) {
                       if (set_with_more_elements.count(stock)) {
                           common_count++;
                       }
                    }
                    double total_stocks_count =
                            (double)(equity_fund_stock_ptr_set_size + current_equity_fund_stock_ptr_set_size);
                    double overlap_percentage = ((2*common_count)/total_stocks_count)*100;
                    std::cout   << equity_fund->Name() << " "
                                << current_equity_fund_ptr->Name() << " "
//                                << 2*common_count << " "
//                                << total_stocks_count << " "
                                << overlap_percentage << "%\n";
                }
            }

            void ProcessAddStock(AddStockCommand* command) {
                auto& fund_name = command->FundName();
                auto& stock_ticker = command->Ticker();
                auto it = funds_map_ptr_->find(fund_name);
                if (it == funds_map_ptr_->end()) {
                    // FundNotFoundException
                    throw InvalidCommandStringException(fund_name + " fund not found.");
                }
                auto equity_fund = std::static_pointer_cast<EquityFund>(it->second);
                if (!equity_fund) {
                    // FundNotFoundException
                    throw InvalidCommandStringException(fund_name + " is not equity fund.");
                }
                equity_fund->AddStock(stock_ticker);
            }

            void ProcessCurrentPortfolio(CurrentPortfolioCommand* command) {
                portfolio_->ClearFunds();
                for(auto fund_name : command->FundNames()) {
                    auto it = funds_map_ptr_->find(fund_name);
                    if (it == funds_map_ptr_->end()) {
                        // FundNotFoundException
                        throw InvalidCommandStringException(fund_name + " fund not found.");
                    }
                    portfolio_->AddFund(it->second);
                }
            }

    private:
            std::shared_ptr <StocksCreator> stocks_creator_ptr;
            std::shared_ptr <FundsMap> funds_map_ptr_;
            std::unique_ptr <Portfolio> portfolio_;
    };

    class PortfolioOverlapCalculatorBuilder {
        public:
            struct Config {
                std::string data_file_name = "";
                FileFormatType data_file_type = FileFormatType::UNKNOWN;
                DataParserType data_parser_type = DataParserType::Unknown;
            };

            static std::unique_ptr<PortfolioOverlapCalculator> GetCalculator(Config config) {
                auto stocks_creator_ptr = std::make_shared<mfs::StocksCreator>(
                                std::make_shared<mfs::StockPtrMap>());
                auto funds_map_ptr = std::make_shared<mfs::FundsMap>();
                if (!config.data_file_name.empty() &&
                    config.data_file_type != FileFormatType::UNKNOWN &&
                    config.data_parser_type != DataParserType::Unknown) {
                    DataParser* data_parser = mfs::DataParserBuilder::GetParser(config.data_parser_type);
                    ParsedData parsed_data{stocks_creator_ptr, funds_map_ptr, nullptr};
                    data_parser->Parse(config.data_file_name, config.data_file_type, parsed_data);
                } else if (!config.data_file_name.empty() ||
                            config.data_file_type != FileFormatType::UNKNOWN ||
                            config.data_parser_type != DataParserType::Unknown) {
                    throw InvalidConfigException(
                            "PortfolioOverlapCalculatorBuilder Config is incomplete.");
                }
                return std::make_unique<PortfolioOverlapCalculator>(stocks_creator_ptr, funds_map_ptr);
            }
    };
}

#endif //GT_PORTFOLIO_OVERLAP_PORTFOLIO_OVERLAP_CALCULATOR_H
