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
Vector<T>::Vector(size_t n_) :
     n(n_)
{
    std::clog << "Instance of Vector constructed, using parameterised constructor (size)" << std::endl;
    // Want to check that dynamic alloc has successfully occured...
    try
    {
        // Dynamically allocate an array on heap
        elements = new T[n];
        // Set to zero
        std::memset(elements, 0, n * sizeof(T));
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

template<typename T>
T * const Vector<T>::getElements()
{
    // no point in employing Effective C++ Item 3 as trivial
    return elements;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector& rhs)
{
    // First need to check dimensions match, if not throw an error?
    if(this->n != rhs.n)
    {
        throw std::length_error("Vector sizes must match for addition.");
    }
    // Else continue with calculation
    Vector<T> result(n);
    for(size_t i = 0; i < n; i++)
    {
        result.elements[i] = this->getElements()[i] + rhs.getElements()[i];
    }
    return result;
}

template<typename T>
Vector<T> Vector<T>::operator+(const T rhs)
{
    // elt. wise addition of scalar of type T - shifts all elts by rhs
    Vector<T> result(n);
    for(size_t i = 0; i < n; i++)
    {
        result.elements[i] = this->getElements()[i] + rhs;
    }
    return result;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs)
{
    os << "[";
    for(size_t i = 0; i < rhs.getN(); i++)
    {
        os << std::to_string(rhs.getElements()[i]);
        os << ", ";
    }
    os << "]";
    return os;
}

// Explicit instantiations - need to research why this is needed - lists allowed types
template class Vector<float>;
template class Vector<double>;
template class Vector<long double>;
// Just an idea to pursue - stroboscopic evolution of particles?
template class Vector<int>;


// Non-member function instantiations
template std::ostream& operator<< <float>(std::ostream& os, const Vector<float>& rhs);
template std::ostream& operator<< <double>(std::ostream& os, const Vector<double>& rhs);
template std::ostream& operator<< <long double>(std::ostream& os, const Vector<long double>& rhs);
template std::ostream& operator<< <int>(std::ostream& os, const Vector<int>& rhs);

} // namespace mathematics