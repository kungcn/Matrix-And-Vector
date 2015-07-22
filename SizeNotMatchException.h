//  Project Stage 05 : SizeNotMatchException.h
//  Class SizeNotMatchException definition

#ifndef SIZENOTMATCHEXCEPTION_H
#define SIZENOTMATCHEXCEPTION_H

#include <stdexcept>
using namespace std;

//  SizeNotMatchException objects should be thrown by functions
//  upon detecting size-not-match exceptions
class SizeNotMatchException : public runtime_error {
    public :
        // constructor specifies default error message
        SizeNotMatchException():
        runtime_error("size of the arrays are not matched.") {}
};  //  end class SizeNotMatchException

#endif

