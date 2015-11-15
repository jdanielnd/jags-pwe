#ifndef FUNC_PPWEXP_H_
#define FUNC_PPWEXP_H_
#include <function/ScalarVectorFunction.h>

namespace jags{
namespace pwexponential {

    /**
     * @short Probability function of Piece-wise Exponential
     * Mean calculates the mean of the elements of an array
     * @see SD
     * <pre>
     * y <- mean(x[])
     * </pre>
     */
    class PPwexp : public ScalarVectorFunction
    {
        public:
          PPwexp ();
          double scalarEval(std::vector<double const *> const &args,
                          std::vector<unsigned int> const &dims) const;
          bool isScale(std::vector<bool> const &mask,
                       std::vector<bool> const &fix) const;
    };

}}

#endif /* FUNC_PPWEXP_H_ */
