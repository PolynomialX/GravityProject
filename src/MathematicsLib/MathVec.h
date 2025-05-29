#ifndef MATHVEC_H
#define MATHVEC_H
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

template <typename T>
class MathVec
{
public:
    // Default c'tor
    MathVec();
    // Construct a N_ by 1 zero vector
    MathVec(size_t N_);
    // Copy constructor
    MathVec(const MathVec<T>& mathVec);
    // Currently torn between this being a base class
    // and just having instances of MathVec for all quantities
    ~MathVec();

    // Calculate the Euclidean norm of the vector and return the value

    // Operators to overload: =,+,+=,-,[],/,* - this can rep
    // both elt-wise mult. and dot prod??



    // Getters & setters
    const T& getN();
    const T * const getElements();

private:
    // Number of dimensions of the vector
    size_t n;
    // Magnitude of vector
    unsigned double magnitude;
    // Raw pointer to elements
    // Not using a smart pointer here as we 
    // may want to employ IPP routines
    // or try our hand at vectorising code...
    T * elements;

};

#endif // MATHVEC_H