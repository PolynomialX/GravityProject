// C++ includes
#include <iostream>

// Custom includes
// CMake config include
#include "NBodyDynamicsConfig.h"
#include "Vector.h"

int main()
{
    std::cout << "Launching NBodyDynamics Version " << NBodyDynamics_VERSION_MAJOR << "."
                                                    << NBodyDynamics_VERSION_MINOR << "\n";

    mathematics::Vector<double> testVector(10);
    mathematics::Vector<double> testVector2(10);

    mathematics::Vector<double> testVector3(2);
    try
    {
        testVector = testVector3 + testVector2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    testVector.getElements()[0] = 1.0;
    testVector.getElements()[1] = 2.0;

    std::cout << "testVector: " << testVector << "\n";
    
    return 0;
}