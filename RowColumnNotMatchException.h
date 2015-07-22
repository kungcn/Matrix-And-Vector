//  Project Stage 05 : RowColumnNotMatchException.h
//  Class RowColumnNotMatchException definition

#ifndef ROWCOLUMNNOTMATCHEXCEPTION_H
#define ROWCOLUMNNOTMATCHEXCEPTION_H

#include <stdexcept>
using namespace std;

//  RowColumnNotMatchException objects should be thrown by functions
//  upon detecting row-column-not-match exceptions
class RowColumnNotMatchException : public runtime_error {
    public :
        // constructor specifies default error message
        RowColumnNotMatchException():
        runtime_error
	  ("the column of the first matrix is not matched with the second one.") {}
};  //  end class RowColumnNotMatchException

#endif
 
