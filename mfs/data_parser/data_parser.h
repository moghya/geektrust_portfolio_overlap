//
// Created by Shubham Sawant on 18/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_DATA_PARSER_INTERFACE_H
#define GT_PORTFOLIO_OVERLAP_DATA_PARSER_INTERFACE_H

#include <string>

#include "../porfolio/fund.h"
#include "../porfolio/portfolio.h"
#include "../instruments/stock.h"
#include "../utils/utils.h"

namespace mfs {

    enum FileFormatType { UNKNOWN, JSON, CSV, TSV };

    struct ParsedData {
        std::shared_ptr<StocksCreator> stocks_creator_ptr;
        std::shared_ptr<FundsMap> funds_map_ptr;
        std::shared_ptr<PortfoliosMap> portfolios_map_ptr;
    };

    class DataParser {
        public:
            virtual void Parse(std::string file_name,
                               FileFormatType file_format_type,
                               ParsedData parsed_data) = 0;
    };

    class FundsDataParser : public DataParser {
        public:
            FundsDataParser() {}
            ~FundsDataParser() {}
            virtual void Parse(std::string file_name, FileFormatType file_format_type,
                               ParsedData parsed_data) override;
    };

    enum class DataParserType { Unknown, FundsData };

    class DataParserBuilder {
        public:
            static DataParser* GetParser(DataParserType type) {
                switch(type) {
                    case mfs::DataParserType::FundsData: {
                        return new FundsDataParser();
                    }
                    default:
                        return nullptr;
                }
            }
    };

}
#endif //GT_PORTFOLIO_OVERLAP_DATA_PARSER_INTERFACE_H
