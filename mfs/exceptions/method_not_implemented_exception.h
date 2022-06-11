//
// Created by Shubham Sawant on 18/01/22.
//

#ifndef GT_PORTFOLIO_OVERLAP_METHODNOTIMPLEMENTEDEXCEPTION_H
#define GT_PORTFOLIO_OVERLAP_METHODNOTIMPLEMENTEDEXCEPTION_H

#include <exception>

namespace mfs {
    class MethodNotImplementedException : public std::logic_error {
        public:
            MethodNotImplementedException(std::string &&error_message);
            ~MethodNotImplementedException() {}
    };
}
#endif //GT_PORTFOLIO_OVERLAP_METHODNOTIMPLEMENTEDEXCEPTION_H
