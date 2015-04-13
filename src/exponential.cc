#include <Module.h> // JAGS module base class
#include <distributions/DExp.h> // Exponential distribution class

namespace exponential { // module namespace

class EXPModule : public Module { // module class
  public:
    EXPModule(); // constructor
    ~EXPModule(); // destructor
};

EXPModule::EXPModule() : Module("exponential") {
  insert(new DExp); // inherited function to load JAGS objects
}
EXPModule::~EXPModule() {
  std::vector<Distribution*> const &dvec = distributions();
  for (unsigned int i = 0; i < dvec.size(); ++i) {
    delete dvec[i];
  } // deletes instantiated distribution objects
}

}

exponential::EXPModule _exponential_module;
