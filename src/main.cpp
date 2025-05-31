// C++ includes
#include <iostream>

// Custom includes
// CMake config include
#include "NBodyDynamicsConfig.h"
#include "Vector.h"

void displayLaunchText();

int main()
{
    displayLaunchText();

    mathematics::Vector<double> testVector(3);
    mathematics::Vector<double> testVector2(3);

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
    testVector2.getElements()[0] = 1.0;
    testVector2.getElements()[1] = 1.0;

    std::cout << "testVector: " << testVector << "\n";
    std::cout << "The dot product between " << testVector 
    << "\n and " << testVector2 << "\n is " << testVector * testVector2 << "\n";
    return 0;
}




void displayLaunchText()
{
    std::cout << "-----------------------------------\n";
    std::cout << "Launching NBodyDynamics Version " << NBodyDynamics_VERSION_MAJOR << "."
                                                    << NBodyDynamics_VERSION_MINOR << "\n";
    std::cout << "-----------------------------------\n";
}