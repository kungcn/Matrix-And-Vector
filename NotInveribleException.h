//  Project Stage 05 : NotInveribleException.h
//  Class NotInveribleException definition

#ifndef NOTSQUAREMATRIXEXCEPTION_H
#define NOTSQUAREMATRIXEXCEPTION_H

#include <stdexcept>
using namespace std;

//  NotInveribleException objects should be thrown by functions
//  upon detecting not-inverible exceptions
class NotInveribleException : public runtime_error {
    public :
        // constructor specifies default error message
        NotInveribleException():
        runtime_error("This matrix is not inverible."){}
};  //  end class NotInveribleException

#endif
