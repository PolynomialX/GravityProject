#ifndef VECTOR_H
#define VECTOR_H
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>


// Custom mathematical vector library
// Let's template it - we may want
// to swap out different floating point 
// types to compare performance or
// precision...
// Aware of the existence of std::vector this is more of a starting exercise
namespace mathematics
{
template <typename T>
class Vector
{
public:
    // Default c'tor
    Vector();
    // Construct a N_ by 1 zero vector
    Vector(size_t n_);
    // Copy constructor
    Vector(const Vector<T>& vector);
    // Currently torn between this being a base class
    // and just having instances of MathVec for all quantities
    ~Vector();

    // Calculate the Euclidean norm of the vector and return the value

    // Operators to overload: =,+,+=,-,[],/,* - this can rep
    // both elt-wise mult. and dot prod??
    Vector<T> operator+(const Vector<T>& rhs);
    Vector<T> operator+(const T rhs);
    Vector<T> operator-(const Vector<T> &rhs);
    Vector<T> operator-(const T rhs);
    Vector<T>& operator=(const Vector<T>& rhs);
    // Returns the dot product
    T operator*(const Vector<T>& rhs);

    // Getters & setters
    size_t getN() const;
    const T * const getElements() const;
    void setElement(size_t idx, T val);
    double getMagnitude() const;



private:
    // Calcs the Euclidean norm of the vector
    double calculateMagnitude() const;
    // Number of dimensions of the vector
    size_t n;
    // Magnitude of vector - make this mutable as calculating this does not fundamentally change
    // the vector itself and allows for const calcMag function.
    mutable double magnitude;
    // Raw pointer to elements
    // Not using a smart pointer here as we 
    // may want to employ IPP routines
    // or try our hand at vectorising code...
    T * elements;
};

// Output operator overload
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs);

// Explicit instantiations - need to research why this is needed - lists allowed types
extern template class Vector<float>;
extern template class Vector<double>;
extern template class Vector<long double>;
// Just an idea to pursue - stroboscopic evolution of particles?
extern template class Vector<int>;

template<typename T>
static double calculateMagnitude(const Vector<T>& vector);
} // namespace mathematics 
#endif // MATHVEC_H