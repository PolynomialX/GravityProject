#include "Vector.h"

namespace mathematics
{
template<typename T>
Vector<T>::Vector()
{
    // Init to an empty vector
    std::clog << "Instance of MathVec constructed with default constructor" << std::endl;
    elements = nullptr;
    n = 0;
}
template<typename T>
Vector<T>::Vector(size_t N_) :
     n(N_)
{
    // Want to check that dynamic alloc has successfully occured...
    try
    {
        // Dynamically allocate an array on heap
        elements = new T[n];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<typename T>
Vector<T>::Vector(const MathVec<T>& mathVec)
{
    // Construction so we just need to alloc + copy
    // And set attributes
    n = mathVec.n;
    try
    {
        elements = new T[n];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // Copy contents via memcpy
    // This is ok for built in-types
    std::memcpy(elements, mathVec.elements, n * sizeof(T));
    
}


template<typename T>
Vector<T>::~Vector()
{
    // Clean up...
    std::clog << "Destructor for an instance of MathVec caled." << std::endl;
    // Deallocate dynamically allocated memory
    delete[] elements;
}

} // namespace mathematics