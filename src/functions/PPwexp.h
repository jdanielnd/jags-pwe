#ifndef FUNC_PPWEXP_H_
#define FUNC_PPWEXP_H_
#include <function/VectorFunction.h>

namespace pwexponential {

    /**
     * @short Probability function of Piece-wise Exponential
     * Mean calculates the mean of the elements of an array
     * @see SD
     * <pre>
     * y <- mean(x[])
     * </pre>
     */
    class PPwexp : public VectorFunction
    {
        public:
          PPwexp ();
          void evaluate(double *x, std::vector<double const *> const &args,
              std::vector<unsigned int> const &dims) const;
          bool checkParameterLength (std::vector<unsigned int> const &len) const;
          bool isScale(std::vector<bool> const &mask,
                     std::vector<bool> const &fix) const;
    };

}

#endif /* FUNC_PPWEXP_H_ */
