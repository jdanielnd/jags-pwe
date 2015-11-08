#include <config.h>
#include "PPwexp.h"

using std::vector;

namespace pwexponential {

    PPwexp::PPwexp ()
      : VectorFunction ("ppwexp", 3)
    {
    }

    void PPwexp::evaluate (double *x, std::vector<double const *> const &args,
        std::vector<unsigned int> const &dims) const
    {
      double const * y = args[0];
      double const * f = args[1];
      double const * t = args[2];

      int size = dims[1];

      vector<double> dif(size - 1);
      for(int i=0; i < dif.size(); ++i) {
        dif[i] = t[i+1] - t[i];
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

      *x = summ + f[n-1] * (y[0] - t[n-1]);
    }

    bool PPwexp::checkParameterLength(std::vector<unsigned int> const &len) const
    {
      return true;
    }

    bool PPwexp::isScale(vector<bool> const &mask, vector<bool> const &fix) const
    {
      return true;
    }

}
