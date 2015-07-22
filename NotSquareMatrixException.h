//  Project Stage 05 : NotSquareMatrixException.h
//  Class NotSquareMatrix definition

#ifndef NOTSQUAREMATRIXEXCEPTION_H
#define NOTSQUAREMATRIXEXCEPTION_H

#include <stdexcept>
using namespace std;

//  NotSquareMatrix objects should be thrown by functions
//  upon detecting not-square-matrix exceptions
class NotSquareMatrixException : public runtime_error {
    public :
        // constructor specifies default error message
        NotSquareMatrixException():
        runtime_error("This parameter matrix is not the square matrix.") {}
};  //  end class SizeNotMatchException

#endif
