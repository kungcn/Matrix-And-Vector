//  Project Stage 05 : mainMatrix.cpp
//  test codes to test the class Matrix
#include <iostream>
#include "Matrix.h"  //  definition of the class Matrix and the methods of the class
using namespace std;

int main(void) {
    Matrix<int> oop;
    cout << "test the default constructor" << endl;
    cout << oop;
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> m1(3, 3);
    m1 >> "1,2,3;4,5,6;7,8,9";
    cout << "The Matrix is : " << endl;
    cout << m1;
    int tr[2] = {1, 2};
    cout << "The test to check whether all entries in {1, 2} is in the matrix";
    cout << "or not : " << endl; 
    if (m1.check_all_element(tr, 2) != 0)
        cout << "True" << endl;
    else cout << "False" << endl;
    cout << "The test to check whether any entry in {1, 2} is in the ";
    cout << "matrix or not : " << endl;
    if (m1.check_some_element(tr, 2))
        cout << "True" << endl;
    else cout << "False" << endl; 
    cout << "The largest value of the matrix is : ";
    cout << m1.get_Max_val() << endl;  //  print the largest value
    cout << "The smallest value of the matrix is : ";
    cout << m1.get_Min_val() << endl;  //  print the smallest value
    cout << "The size of the matrix in the form row column is : " << endl;
    int *c;
    c = m1.get_Size();
    for (int i = 0; i < 2; i++)
      cout << c[i] << endl;  //  print the row and column of the Matrix
    m1.set_specified_element(1, 1, 6);  //  set the speicified entry of the Matrix
    cout << "After setting the matrix[1][1], the matrix is : " << endl;
    cout << m1;
    Matrix<int> m2(3, 3);
    m2.set_all_elements((int **)a, 3, 3);
    Matrix<int> ef(1, 3);
    ef = m2.get_Row(1);
    Matrix<int> jg(3, 1);
    jg = m2.get_Column(2);
    cout << "The second row of the matrix is : " << endl;
    cout << ef;  //  print the row of the Matrix
    cout << "The second column of the matrix is : " << endl;
    cout << jg;  //  print the column of the Matrix
    cout << "The entry at the first row and the first column is : " << endl;
    cout << m1.get_Entry(0, 0) << endl;  //  print the entry of the Matrix
    Matrix<int> m3;
    try {
        m3 = m1 + m2;
        cout << "The result of the addition is :" << endl;
        cout << m3;  //  print the result of the additiion
    }  //  end try
    catch (SizeNotMatchException & sizeNotMatchException) {
      cout << "Exception occurred: "
           << sizeNotMatchException.what() << endl;
    }  //  end catch
    Matrix<int> merr;
    Matrix<int> mert(4,4);
    mert >> "1,2,3,4;5,6,7,8;9,10,11,12";
    try {
      merr = m1 + mert;
      cout << "The test code to verify the SizeNotMatchException :";
      cout << merr;
    }  //  end try
    catch (SizeNotMatchException & sizeNotMatchException) {
      cout << "Exception occurred: "
           << sizeNotMatchException.what() << endl;
    }  //  end catch
    try {
        m3 = m1 - m2;
        cout << "The result of the subtraction is :" << endl;
        cout << m3;  //  print the result of the additiion
    }  //  end try
    catch (SizeNotMatchException & sizeNotMatchException) {
      cout << "Exception occurred: "
           << sizeNotMatchException.what() << endl;
    }  //  end catch
    try {
        m3 = m1 * m2;
        cout << "The result of the multiplication is :" << endl;
        cout << m3;  //  print the result of the additiion
    }  //  end try
    catch (RowColumnNotMatchException & rowColumnNotMatchException) {
      cout << "Exception occurred: "
           << rowColumnNotMatchException.what() << endl;
    }  //  end catch
    try {
        merr = m1 * mert;
        cout << "The result of the multiplication is :" << endl;
        cout << merr;  //  print the result of the additiion
    }  //  end try
    catch (RowColumnNotMatchException & rowColumnNotMatchException) {
      cout << "Exception occurred: "
           << rowColumnNotMatchException.what() << endl;
    }  //  end catch
    try {
    cout << "The functor is tested here : " << endl;  //  test whether the functor is working or not
        cout << "m1(1, 3) is ";
        cout << m1(1, 2) << endl;
    }  //  end try
    catch (OutOfRangeException & outOfRangeException) {
      cout << "Exception occurred: "
           << outOfRangeException.what();
    }  //  end catch
    try {
    cout << "The functor is tested here : " << endl;  //  test whether the OutOfRangeException class is working or not
        cout << m1(5, 5) << endl;
    }  //  end try
    catch (OutOfRangeException & outOfRangeException) {
      cout << "Exception occurred: "
           << outOfRangeException.what() << endl;
    }  //  end catch
    cout << "The transpose of the matrix is : " << endl;  //  the transpose of m1
    Matrix<int> test2(3, 3);
    test2 = m1.Transpose_matrix();
    cout << test2;
    Matrix<int> test3(3, 3);
    try {
    cout << "The inverse of the matrix is : " << endl;  //  the inverse of m1
    test3 = m1.Inverse_matrix();
    cout << test3;
    }  //  end try
    catch (NotSquareMatrixException & notSquareMatrixException){
      cout << "Exception occurred:"
           << notSquareMatrixException.what() << endl;
    }  //  end catch
    try {
    cout << "The inverse of the matrix is : " << endl;  //  the inverse of m1
    test3 = m1.Inverse_matrix();
    cout << test3;
    }  //  end try
    catch (OutOfAbilityException & outOfAbilityException) {
      cout << "Exception occurred:"
           << outOfAbilityException.what() << endl;
    }  //  end catch
    Matrix<int> oa(4, 4);  //  the row and column is larger than 3
    Matrix<int> oat;
    oa >> "1,2,3,4;5,6,7,8;9,10,11,12,13";
    try {
      cout << "The inverse of the matrix is : " << endl;
    oat = oa.Inverse_matrix();
    cout << oa;
    }  //  end try
    catch (OutOfAbilityException & outOfAbilityException) {
      cout << "Exception occurred:"
           << outOfAbilityException.what() << endl;
    }  //  end catch
    Matrix<int> nin(2,3);
    Matrix<int> nint;
    nin >> "1,-1,7;1,-1,8";  //  the row is not equal to the column
    try {
      cout << "The inverse of the matrix is : " << endl;
    nint = nin.Inverse_matrix();
    cout << nint;
    }  //  end try
    catch (NotSquareMatrixException & notSquareMatrixException) {
      cout << "Exception occurred:"
           << notSquareMatrixException.what() << endl;
    }  //  end catch
    Matrix<int> kkk(2,2);
    Matrix<int> ggg;
    kkk >> "1,-1;-1,1";
    ggg = kkk.Inverse_matrix();  //  the matrix which is not inverible
    int test4;
    try {
    test4 = m1.determinant_matrix();
    cout << "The determinant of the matrix is : " << endl;  //  the determinant of the m1
    cout << test4 << endl;
    }  //  end try
    catch (NotHaveDeterminantException & notHaveDeterminantException) {
      cout << "Exception occurred: "
           << notHaveDeterminantException.what() << endl;
    }  //  end catch
    Matrix<int> rl(2,3);  //  the row is not equal to the column
    rl >> "1,2,3;4,5,6";
    try {
      test4  = rl.determinant_matrix();
      cout << "The determinant of the matrix is : " << endl;
    cout << test4 << endl;
    }  //  end try
    catch (NotHaveDeterminantException & notHaveDeterminantException) {
      cout << "Exception occurred: "
	   << notHaveDeterminantException.what();
    }  //  end catch 
    cout << "The double matrix is : " << endl;  //  check if double matrix can be accepted
    Matrix<double> test5(3, 3);
    test5 >> "1.1,2.2,3.3;4.4,5.5,6.6;7.7,8.8,9.9";
    cout << test5;
    Matrix<char> test6(3, 3);  //  check if the char matrix can be accepted
    test6 >> "a,b,c;d,e,f;g,h,i";
    cout << "The char matrix is : " << endl;
    cout << test6;
    Matrix<int> test7(3, 3);
    test7 >> "1,5,7;6,2,4;9,0,3";
    cout << "The result of ascending sort is: " << endl;
    cout << test7.Sort("ascending");
    cout << "The result of descending sort is: " << endl;
    cout << test7.Sort("descending");
    test7.printToFile("matrix.txt");
    cout << "The matrix read by the matrixtoread.txt is: " << endl;
    Matrix<int> test8(3, 3);
    test8.setByFile("matrixtoread.txt");
    cout << test8;
    m1.hear("I love", m1);
    cout << "The result of saying I love is:" << endl;
    cout << m1;
    cout << "The result of sating I hate is:" << endl;
    m1.hear("I hate", m1);
    cout << m1 << endl;
    return 0;
}
