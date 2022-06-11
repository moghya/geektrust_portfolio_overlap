#include <iostream>
#include <unordered_map>
#include "mfs/mfs_lib.h"

int main() {
    // some issue in
    const std::string file_name = "/Users/shubhamsawant/CLionProjects/gt_portfolio_overlap/stock_data.json";
    mfs::PortfolioOverlapCalculatorBuilder::Config config{file_name,
                                                          mfs::FileFormatType::JSON,
                                                          mfs::DataParserType::FundsData};
    auto overlap_calculator = mfs::PortfolioOverlapCalculatorBuilder::GetCalculator(config);
    std::string command_str;
    auto command_builder = mfs::CommandBuilder();
    while(std::getline(std::cin, command_str)) {
        try {
            auto command = command_builder.Build(command_str);
            overlap_calculator->ProcessCommand(command);
        } catch (mfs::InvalidCommandStringException e) {
            std::cout << e.what() << "\n";
        }
    }
    return 0;
}
