#ifndef FUNC_QPWEXP_H_
#define FUNC_QPWEXP_H_
#include <function/ScalarVectorFunction.h>

namespace jags{
namespace pwexponential {

    /**
     * @short Quantile function of Piece-wise Exponential
     */
    class QPwexp : public ScalarVectorFunction
    {
        public:
          QPwexp ();
          double scalarEval(std::vector<double const *> const &args,
                          std::vector<unsigned int> const &dims) const;
          bool isScale(std::vector<bool> const &mask,
                       std::vector<bool> const &fix) const;
    };

}}

#endif /* FUNC_QPWEXP_H_ */
