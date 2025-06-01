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
    // try
    // {
    //     testVector = testVector3 + testVector2;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    testVector.setElement(0, 1.0);
    testVector.setElement(1, 2.0);
    testVector2.setElement(0, 1.0);
    testVector2.setElement(1, 1.0);

    mathematics::Vector<double> testVector4(3);
    testVector4 = testVector + testVector2;

    std::cout << "testVector: " << testVector << "\n";
    std::cout << "The dot product between " << testVector 
    << "\n and " << testVector2 << "\n is " << testVector * testVector2 << "\n";

    std::cout << "The vector sum of " << testVector << " and " << testVector2 <<
    " is: " << testVector4 << "\n";

    std::cout << "The vector subtraction of " << testVector << " take away " << testVector2 <<
    " is: " << testVector - testVector2 << "\n";

    std::cout << "The magnitude of " << testVector << " is: " << testVector.getMagnitude() << "\n";

    testVector.setElement(2, 300);

    std::cout << "The magnitude of " << testVector << " is " << testVector.getMagnitude() << "\n";
    return 0;
}




void displayLaunchText()
{
    std::cout << "-----------------------------------\n";
    std::cout << "Launching NBodyDynamics Version " << NBodyDynamics_VERSION_MAJOR << "."
                                                    << NBodyDynamics_VERSION_MINOR << "\n";
    std::cout << "-----------------------------------\n";
}