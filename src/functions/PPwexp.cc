#include <config.h>
#include "PPwexp.h"
#include <cmath>

using std::vector;

namespace jags{
namespace pwexponential {

    PPwexp::PPwexp ()
      : ScalarVectorFunction ("ppwexp", 3)
    {
    }

    double PPwexp::scalarEval (std::vector<double const *> const &args,
                               std::vector<unsigned int> const &dims) const
    {
      double const * x = args[0];
      double const * f = args[1];
      double const * t = args[2];

      int size = dims[1];

      vector<double> dif(size - 1);
      for(int i=0; i < dif.size(); ++i) {
        dif[i] = t[i+1] - t[i];
      }

      int n = size;
      for(int i=0; i < size; ++i) {
          if(x[0] <= t[i]) {
            n = i;
            break;
          }
      }

      double summ = 0;
      if(n > 0) {
          for(int i=0; i < (n-1); ++i) {
            // Why this sum uses t[i-1] insteal of dif[i] ?
            // Based on http://www.ime.unicamp.br/sinape/sites/default/files/DemarquiSinape2010.pdf
            // I changed it to t[i-1] and it worked, but the logDensity calculations
            // uses the dif[i]. Not sure, why!
            summ = summ + f[i] * t[i-1];
          }
      }

      double st = summ + f[n-1] * (x[0] - t[n-1]);

      return 1 - exp(-st);
    }

    bool PPwexp::isScale(vector<bool> const &mask, vector<bool> const &fix) const
    {
      return true;
    }

}}
