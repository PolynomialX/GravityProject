#ifndef MATHVEC_H
#define MATHVEC_H

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
    // Currently torn between this being a base class
    // and just having instances of MathVec for all quantities
    ~MathVec();

    // Calculate the Euclidean norm of the vector and return the value

    // We need to overload the [] operator

private:
    // Number of dimensions of the vector
    size_t N;
    // Magnitude of vector
    unsigned double magnitude;
    

};

#endif // MATHVEC_H