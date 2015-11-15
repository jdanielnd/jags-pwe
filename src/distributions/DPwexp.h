#ifndef DPWEXP_H_
#define DPWEXP_H_
#include <distribution/VectorDist.h>

namespace jags{
namespace pwexponential {

class DPwexp : public VectorDist
{
  public:
    DPwexp(); // constructor
    double logDensity(double const *x, unsigned int length, PDFType type,
                      std::vector<double const *> const &parameters,
                      std::vector<unsigned int> const &lengths,
                      double const *lower, double const *upper) const;
    void randomSample(double *x, unsigned int length,
                      std::vector<double const *> const &parameters,
                      std::vector<unsigned int> const &lengths,
                      double const *lbound, double const *ubound,
                      RNG *rng) const;
    void typicalValue(double *x, unsigned int length,
                      std::vector<double const *> const &parameters,
                      std::vector<unsigned int> const &lengths,
                      double const *lbound, double const *ubound) const;
    /** Checks that p lies in the open interval (0,1) */
    bool checkParameterValue(std::vector<double const*> const &parameters,
                      std::vector<unsigned int> const &lengths) const;
    /** Distribution is discrete valued */
    bool isDiscreteValued(std::vector<bool> const &mask) const;
    bool isSupportFixed(std::vector<bool> const &fixmask) const;
    bool checkParameterLength(std::vector<unsigned int> const &lengths) const;
    unsigned int length(std::vector<unsigned int> const &lengths) const;
    void support(double *lower, double *upper, unsigned int length,
     std::vector<double const *> const &parameters,
     std::vector<unsigned int> const &lengths) const;
};

}}

#endif /* DPWEXP_H_ */
