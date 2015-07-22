//  Project Stage 05 : OutOfAbilityException.h
//  Class OutOfAbilityException definition

#ifndef OUTOFABILITYEXCEPTION_H
#define OUTOFABILITYEXCEPTION_H

#include <stdexcept>
using namespace std;

//  OutOfAbilityException objects should be thrown by functions
//  upon detecting out-of-ability exceptions
class OutOfAbilityException : public runtime_error {
    public :
        // constructor specifies default error message
        OutOfAbilityException():
        runtime_error("Sorry, it needs so much time to calculate it that I can't get its result.") {}
};  //  end class OutOfAbilityException

#endif

