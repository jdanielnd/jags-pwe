#include <config.h>
#include "QPwexp.h"
#include <cmath>

using std::vector;

namespace jags{
namespace pwexponential {

    QPwexp::QPwexp ()
      : ScalarVectorFunction ("qpwexp", 3)
    {
    }

    double QPwexp::scalarEval (std::vector<double const *> const &args,
                               std::vector<unsigned int> const &dims) const
    {
      double const * x = args[0];
      double const * f = args[1];
      double const * t = args[2];

      double w = -log(1 - x[0]);

      int size = dims[1];

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

      return t[n] + (w - summ) / f[n];
    }

    bool QPwexp::isScale(vector<bool> const &mask, vector<bool> const &fix) const
    {
      return true;
    }

}}
