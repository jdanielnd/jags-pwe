#include <config.h>
#include "DExp.h"
#include <rng/RNG.h>
#include <util/nainf.h>

#include <JRmath.h>
#include <cmath>

using std::vector;

#define RATE(par) (*par[0])

namespace exponential {

DExp::DExp() : ScalarDist("dexp2", 1, DIST_POSITIVE)
{}

bool DExp::checkParameterValue (vector<double const *> const &parameters) const
{
    return (RATE(parameters) >= 0.0);
}

double DExp::logDensity(double x, PDFType type,
       vector<double const *> const &parameters,
       double const *lbound, double const *ubound) const 
{
    return log(RATE(parameters)) - x*RATE(parameters);
}

double DExp::randomSample(vector<double const *> const &parameters, 
         double const *lbound, double const *ubound,
         RNG *rng) const
{
    return -log(1 - rng->uniform())/RATE(parameters);
}

double DExp::typicalValue(vector<double const *> const &parameters,
         double const *lbound, double const *ubound) const
{
    return 1/RATE(parameters);

bool DExp::isDiscreteValued(vector<bool> const &mask) const
{
    return false;
}

}
