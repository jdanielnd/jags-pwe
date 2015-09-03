#include <Module.h> // JAGS module base class
#include <distributions/DPwexp.h> // Piece-wise Exponential distribution class

namespace pwexponential { // module namespace

class PWEXPModule : public Module { // module class
  public:
    PWEXPModule(); // constructor
    ~PWEXPModule(); // destructor
};

PWEXPModule::PWEXPModule() : Module("pwexponential") {
  insert(new DPwexp); // inherited function to load JAGS objects
}
PWEXPModule::~PWEXPModule() {
  std::vector<Distribution*> const &dvec = distributions();
  for (unsigned int i = 0; i < dvec.size(); ++i) {
    delete dvec[i];
  } // deletes instantiated distribution objects
}

}

pwexponential::PWEXPModule _pwexponential_module;
