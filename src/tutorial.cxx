// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

#include "TutorialConfig.h"

// should we include the MathFunctions header?
#ifdef USE_MYMATH
#  include "MathFunctions.h"
#endif

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Square root program ...." << endl;

  if (argc < 2) {
    // report version
    cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << endl;
    cout << "Usage: " << argv[0] << " number" << endl;
    return 1;
  }

  // convert input to double
  const double inputValue = stod(argv[1]);

  // which square root function should we use?
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif

  cout << "The square root of " << inputValue << " is " << outputValue
            << endl;
  return 0;
}
