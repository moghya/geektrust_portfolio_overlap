//
// Created by Shubham Sawant on 19/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_INSTRUMENT_H
#define GT_PORTFOLIO_OVERLAP_INSTRUMENT_H

#include <string>
#include <unordered_set>

namespace mfs {
    class Instrument {
        public:
            Instrument(const std::string& name);
            ~Instrument() {}
            std::string Name() const;
        private:
            std::string name_;
    };
    typedef std::shared_ptr<Instrument> InstrumentPtr;
    typedef std::unordered_set<InstrumentPtr> InstrumentPtrSet;
}

#endif //GT_PORTFOLIO_OVERLAP_INSTRUMENT_H
