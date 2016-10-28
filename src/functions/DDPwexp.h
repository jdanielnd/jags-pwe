#ifndef FUNC_DDPWEXP_H_
#define FUNC_DDPWEXP_H_
#include <function/ScalarVectorFunction.h>

namespace jags{
namespace pwexponential {

    /**
     * @short Density function of Piece-wise Exponential
     */
    class DDPwexp : public ScalarVectorFunction
    {
        public:
          DDPwexp ();
          double scalarEval(std::vector<double const *> const &args,
                          std::vector<unsigned int> const &dims) const;
          bool isScale(std::vector<bool> const &mask,
                       std::vector<bool> const &fix) const;
    };

}}

#endif /* FUNC_DDPWEXP_H_ */
