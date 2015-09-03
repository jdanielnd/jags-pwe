#include <config.h>
#include "DPwexp.h"
#include <rng/RNG.h>
#include <util/nainf.h>

#include <JRmath.h>
#include <cmath>

using std::vector;

// #define RATE(par) (*par[0])
// #define T(par) (*par[1])

namespace pwexponential {

DPwexp::DPwexp()
      : VectorDist("dpwexp", 2)
{}

bool DPwexp::checkParameterValue (vector<double const *> const &parameters,
                          vector<unsigned int> const &lengths) const
{
    // ok
    // vector<double const *> *rate = parameters[0];
    // for(int i=0; i < rate.size(); ++i) {
    //     if(rate[i] < 0) return false;
    // }

    // TODO: pontos de corte ordenados
    // vector<double const *> *t = parameters[1];
    // for(int i=0; i < t.size(); ++i) {
    //     if(t[i] < 0) return false;
    // }

    return true;
}

double DPwexp::logDensity(double const *x, unsigned int length, PDFType type,
                          vector<double const *> const &parameters,
                          vector<unsigned int> const &lengths,
                          double const *lower, double const *upper) const 
{
    double const * f = parameters[0];
    double const * t = parameters[1];

    int size = lengths[0];

    vector<double> dif(size - 1);
    for(int i=0; i < dif.size(); ++i) {
      dif[i] = t[i+1] - t[i];
    }

    vector<double> ref(dif.size());
    ref[0] = f[0]*dif[0];
    for(int i=1; i < ref.size(); ++i) {
      ref[i] = ref[i-1] + f[i]*dif[i];
    }

    int n = size;
    for(int i=0; i < size; ++i) {
        if(*x <= t[i]) {
          n = i;
          break;
        }
    }

    double summ = 0;
    if(n > 0) {
        for(int i=0; i < (n-1); ++i) {
          summ = summ + f[i] * dif[i];
        }
    }

    return log(f[n-1]) -(summ + f[n-1] * (*x - t[n-1]));
}

void DPwexp::randomSample(double *x, unsigned int length,
                            std::vector<double const *> const &parameters,
                            std::vector<unsigned int> const &lengths,
                            double const *lbound, double const *ubound,
                            RNG *rng) const
{
  double const * f = parameters[0];
  double const * t = parameters[1];

  double u = rng->uniform();
  double w = -log(1 - u);

  int size = lengths[0];

  vector<double> dif(size - 1);
  for(int i=0; i < dif.size(); ++i) {
      dif[i] = t[i+1] - t[i];
  }

  vector<double> ref(dif.size());
  ref[0] = f[0]*dif[0];
  for(int i=1; i < ref.size(); ++i) {
      ref[i] = ref[i-1] + f[i]*dif[i];
  }

  int n = ref.size();
  for(int i=0; i < ref.size(); ++i) {
    if(w <= ref[i]) {
      n = i;
      break;
    }
  }

  double summ = 0;
  if(n > 0) {
    for(int i=0; i < n; ++i) {
      summ = summ + f[i] * dif[i];
    }
  }

  *x = t[n] + (w - summ) / f[n];
}

void DPwexp::typicalValue(double *x, unsigned int length,
                      std::vector<double const *> const &parameters,
                      std::vector<unsigned int> const &lengths,
                      double const *lbound, double const *ubound) const
{
  double const * f = parameters[0];
  double const * t = parameters[1];
  *x = f[0];
}

bool DPwexp::isDiscreteValued(vector<bool> const &mask) const
{
  return false;
}

bool DPwexp::isSupportFixed(vector<bool> const &fixmask) const
{
  return true;
}

bool DPwexp::checkParameterLength(vector<unsigned int> const &lengths) const
{
  return lengths[0] == lengths[1];
}

unsigned int DPwexp::length(vector<unsigned int> const &lengths) const
{
    return 1;
}

void DPwexp::support(double *lower, double *upper, unsigned int length,
             vector<double const *> const &par,
             vector<unsigned int> const &lengths) const
{

  for (unsigned int i = 0; i < length; ++i) {
    lower[i] = 0;
    upper[i] = JAGS_POSINF;
  }
}

}
