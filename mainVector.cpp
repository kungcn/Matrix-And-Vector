//  Project Stage 05 :¡¡mainVector.cpp
//  test codes to test the class Vector

#include <iostream>
#include "Vector.h"  //  the definition of the class Vector
using namespace std;

int main(void) {
    Vector<int> test1(3);
    int b[1][3] = {1, 2, 3};
    test1.set_all_elements((int**)b, 1, 3);  //  set the test1.array is equal to the array b
                                            // the other parameter is the size of the array b
    cout << "The vector is : " << endl;
    cout << test1;  //  print the vector like (1, 2, 3)
    int *c;
    c = test1.get_Size();
    cout << "The dimension of the vector is : ";
    cout << c[0] << endl;  //  get the dimension 3
    cout << "The norm of the vector is : ";
    cout << test1.getLength() << endl;  //  get the norm sqrt 14
    Vector<int> a(3);
    try {
        a = test1 + test1;
        cout << "The result of the vector addition is : " << endl;
        cout << a;  //  print the result of test1 + test1
    }  //  end try
    catch (SizeNotMatchException & sizeNotMatchException) {
      cout << "Exception occurred: "
           << sizeNotMatchException.what() << endl;
    }  //  end catch
    Vector<int> ert(6);
    Vector<int> err;
    ert >> "1,2,3,4,5,6";
    try {
      err = test1 - ert;
      cout << "The result to verify the exception:";
      cout << err;
    }  //  end try
    catch (SizeNotMatchException & sizeNotMatchException) {
      cout << "Exception occurred: "
           << sizeNotMatchException.what() << endl;
    }  //  end catch
    try {
        a = test1 - test1;
    cout << "The result of the vector substraction is : " << endl;
    cout << a;  //  print the result of test1 - test1
    }  //  end try
    catch (SizeNotMatchException & sizeNotMatchException) {
      cout << "Exception occurred: "
           << sizeNotMatchException.what() << endl;
    }  //  end catch
    Vector<int> d(1);
    Vector<int> test2(3);
    test2 >> "1,9,4";
    cout << "The ascending vector is: " << endl;
    cout << test2.Sort("ascending");
    cout << "The descending vector is: " << endl;
     cout << test2.Sort("descending");
    try {
        d = test1 * test2;
    cout << "The result of the vector multiplication is : " << endl;
    cout << d.get_Entry(0, 0) << endl;  //  print the result of test1 * test2
    }  //  end try
    catch (RowColumnNotMatchException & rowColumnNotMatchException) {
      cout << "Exception occurred: "
           << rowColumnNotMatchException.what() << endl;
    }  //  end catch
    try {
        err = test1 * ert;
        cout << "The result of the multiplication is :" << endl;
        cout << err;
    }  //  end try
    catch (SizeNotMatchException & sizeNotMatchException) {
      cout << "Exception occurred: "
           << sizeNotMatchException.what() << endl;
    }  //  end catch
    cout << "funtor is tested here" << endl;
    try {
    cout << "test1(1, 3) is : ";
    cout << test1(2) << endl;
    }  //  end try
    catch (OutOfRangeException & outOfRangeException) {
      cout << "Exception occurred: "
           << outOfRangeException.what() << endl;
    }  //  end catch
    try {
      cout << test1(6) << endl;
    }  //  end try
    catch (OutOfRangeException & outOfRangeException) {
      cout << "Exception occurred: "
           << outOfRangeException.what() << endl;
    }  //  end catch
    Vector<double> test4(3);
    test4 >> "1.1,2.2,3.3";
    cout << "The double vector is : " << endl;
    cout << test4;  //  print the vector like (1, 2, 3)
    Vector<char> test5(3);
    test5 >> "a,b,c";
    cout << "The char vector is : " << endl;
    cout << test5;
    test1.printToFile("vector.txt");
    cout << "The vector read by vetcor.txt is:" << endl;
    Vector<int> test6(3);
    test6.setByFile("vectortoread.txt");
    cout << test6;
    cout << "The result of saying I love is:" << endl;
    test1.hear("I love", test1);
    cout << test1;
    cout << "The result of saying I hate is:" << endl;
    test1.hear("I hate", test1);
    cout << test1 << endl;
    return 0;
}  //  end the main funtion

