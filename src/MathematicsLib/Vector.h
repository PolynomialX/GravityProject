#ifndef VECTOR_H
#define VECTOR_H
#include <memory>
#include <iostream>
#include <stdlib.h>
// We anticipate that this class will be
// a base class

// Custom mathematical vector library
// Let's template it - we may want
// to swap out different floating point 
// types to compare performance or
// precision...
namespace mathematics
{
template <typename T>
class Vector
{
public:
    // Default c'tor
    Vector();
    // Construct a N_ by 1 zero vector
    Vector(size_t N_);
    // Copy constructor
    Vector(const Vector<T>& vector);
    // Currently torn between this being a base class
    // and just having instances of MathVec for all quantities
    ~Vector();

    // Calculate the Euclidean norm of the vector and return the value

    // Operators to overload: =,+,+=,-,[],/,* - this can rep
    // both elt-wise mult. and dot prod??
    Vector operator+(const Vector& rhs);


    // Getters & setters
    size_t getN() const;
    const T * const getElements() const;

private:
    // Number of dimensions of the vector
    size_t n;
    // Magnitude of vector
    double magnitude;
    // Raw pointer to elements
    // Not using a smart pointer here as we 
    // may want to employ IPP routines
    // or try our hand at vectorising code...
    T * elements;


};

// Explicit instantiations - need to research why this is needed - lists allowed types
extern template class Vector<float>;
extern template class Vector<double>;
extern template class Vector<long double>;
// Just an idea to pursue - stroboscopic evolution of particles?
extern template class Vector<int>;

} // namespace mathematics 
#endif // MATHVEC_H