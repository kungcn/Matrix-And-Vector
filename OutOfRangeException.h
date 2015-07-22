//  Project Stage 05 : OutOfRangeException.h
//  Class OutOfRangeException definition

#ifndef OUTOFRANGEEXCEPTION_H
#define OUTOFRANGEEXCEPTION_H

#include <stdexcept>
using namespace std;

//  OutOfRangeException objects should be thrown by functions
//  upon detecting out-of-range exceptions
class OutOfRangeException : public logic_error {
    public :
        // constructor specifies default error message
        OutOfRangeException():
        logic_error("Out of Range!") {}
};  //  end class OutOfRangeException

#endif

