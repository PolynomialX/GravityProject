#include "Vector.h"

namespace mathematics
{
template<typename T>
Vector<T>::Vector()
{
    // Init to an empty vector
    std::clog << "Instance of Vector constructed with default constructor" << std::endl;
    elements = nullptr;
    n = 0;
}
template<typename T>
Vector<T>::Vector(size_t N_) :
     n(N_)
{
    std::clog << "Instance of Vector constructed, using parameterised constructor (size)" << std::endl;
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
Vector<T>::Vector(const Vector<T>& vector)
{
    // Construction so we just need to alloc + copy
    // And set attributes
    n = vector.n;
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
    std::memcpy(elements, vector.elements, n * sizeof(T));
    
}


template<typename T>
Vector<T>::~Vector()
{
    // Clean up...
    std::clog << "Destructor for an instance of MathVec caled." << std::endl;
    // Deallocate dynamically allocated memory
    delete[] elements;
}

template<typename T>
size_t Vector<T>::getN() const
{
    return n;
}

template<typename T>
const T * const Vector<T>::getElements() const
{
    return elements;
}

// Explicit instantiations - need to research why this is needed - lists allowed types
template class Vector<float>;
template class Vector<double>;
template class Vector<long double>;
// Just an idea to pursue - stroboscopic evolution of particles?
template class Vector<int>;

} // namespace mathematics