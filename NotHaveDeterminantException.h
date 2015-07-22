//  Project Stage 05 : NotHaveDeterminantException.h
//  Class NotHaveDeterminantException definition

#ifndef NOTHAVEDETERMINANTEXCEPTION_H
#define NOTHAVEDETERMINANTEXCEPTION_H

#include <stdexcept>
using namespace std;

//  NotHaveDeterminantException objects should be thrown by functions
//  upon detecting not-have-determinant  exceptions
class NotHaveDeterminantException : public runtime_error {
    public :
        // constructor specifies default error message
        NotHaveDeterminantException():
        runtime_error("This matrix doesn't have determinant.") {}
};  //  end class NotHaveDeterminantException

#endif

