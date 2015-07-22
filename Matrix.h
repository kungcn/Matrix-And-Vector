//  Project Stage 05 : Matrix.h 
//  class Matrix definition and the member methods

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include "Base.h"
#include "SizeNotMatchException.h"
#include "RowColumnNotMatchException.h"
#include "NotHaveDeterminantException.h"
#include "NotSquareMatrixException.h"
#include "OutOfAbilityException.h"
#include "OutOfRangeException.h"
#define MAX 100
using namespace std;

template<typename T>
class Matrix : public Base<T> {
    public :
    //  default constructor
    Matrix(void);
    //  copy constructor
    Matrix(const Matrix &);
    //  constructor with parameter, row and column
    Matrix(int, int);
    //  return array[column][1], parameter is the column
    Matrix<T> get_Column(int);
    //  return array[1][row],parameter is the row
    Matrix<T> get_Row(int);
    //  return the companion matrix
    Matrix<T> companion_matrix(void);
    //  return the inverse of the matrix if it is invertible
    Matrix<T> Inverse_matrix(void);
    //  return the transpose of hte matrix
    Matrix<T> Transpose_matrix(void);
    //  return the determinant of the matrix
    T determinant_matrix(void);
    //  return the largest value of the array[][]
    T get_Max_val(void);
    //  return the smallest value of the array[][]
    T get_Min_val(void);
    //  addition operator
    Matrix<T> operator + (const Matrix<T> &) const;
    //  subtraction operator
    Matrix<T> operator - (const Matrix<T> &) const;
    //  multiplication operator
    Matrix<T> operator * (const Matrix<T> &) const;
    //  equality operator
    Matrix<T> operator = (const Matrix<T> &);
    //  fuctor to return the specific entry of the matrix
    T operator()(int, int);
    //  return the cofactor matrix of the matrix
    Matrix<T> cofactor_matrix(int, int);
    //  print the Matrix like / 1 2 /
    //                        / 1 2 /
    //  the friend function to overload ostream
    friend std::ostream & operator<<(std::ostream & os, const Matrix<T> & other) {
        for (int i = 0; i < other.row; i++) {
        os << "| ";
        for (int j = 0; j < other.column; j++)
	        os << other.array[i][j] << " ";
        os << "|" << endl;
        }
        return os;
    }
    //  the >> operator overloading to strore entries from the string
    Matrix<T> & operator>>(string);
    //  smart function to hear your voice
    void hear(string, const Matrix<T> &);
    //  sort by commands
    Matrix<T> Sort(const string &);
    //  print the matrix to the file
    void printToFile(const char*);
    //  read the matrix from the file
    void setByFile(const char*);
};  //  end class Matrix definition

#endif

//  default constructor
template<typename T>
Matrix<T> :: Matrix(void)
: Base<T> :: Base(2, 2) {
}  //  end Matrix default constructor

//  copy constructor
template<typename T>
Matrix<T> :: Matrix(const Matrix & other)
: Base<T> :: Base(other.row, other.column) {
      for (int i = 0; i < Base<T> :: row; i++)
	    for (int j = 0; j < Base<T> :: column; j++)
	  Base<T> :: array[i][j] = other.array[i][j]; 
}  //  end Matrix copy constructor

//  constructor with parameter, row and column
template<typename T>
Matrix<T> :: Matrix(int row_, int column_)
: Base<T> :: Base(row_, column_) {
}  //  end Matrix constructor with parameter

//  return the array[row][1], parameter is the row
template<typename T>
Matrix<T> Matrix<T> :: get_Row(int row_) {
  Matrix<T> row(1, Base<T> :: column);
    for(int j = 0; j < Base<T> :: column; j++)
      row.array[0][j] = Base<T> :: array[row_][j];
	return row;
}  //  end Matrix get_Row function

//  return an arrat that is array[1][column], the column is the parameter
template<typename T>
Matrix<T> Matrix<T> :: get_Column(int column_) {
  Matrix<T> column(Base<T> :: row, 1);
    for (int i = 0; i < Base<T> :: row; i++)
      column.array[i][0] = Base<T> :: array[i][column_];
    return column;
}  //  end Matrix get_Column funtion

//  addition operator
template<typename T>
Matrix<T> Matrix<T> :: operator + (const Matrix<T> & m1) const {
  if (m1.row == Base<T> :: row && Base<T> :: column == m1.column) {
        Matrix<T> result(m1.row, m1.column);
        result.array = new T*[result.row];
        for (int i = 0; i < result.row; i++)
            result.array[i] = new T[result.column];
        for (int i = 0; i < result.row; i++)
            for (int j = 0; j < result.column; j++)
	      result.array[i][j] = m1.array[i][j] + Base<T> :: array[i][j];
        return result;
    }
    else {
        throw SizeNotMatchException(); // terminate function
    }
}  //  end Matrix addition operator

//  subtraction operator
template<typename T>
Matrix<T> Matrix<T> :: operator - (const Matrix<T> & m1) const {
  if (m1.row == Base<T> :: row && Base<T> :: column == m1.column) {
        Matrix<T> result(m1.row, m1.column);
        result.array = new T*[result.row];
        for (int i = 0; i < result.row; i++)
            result.array[i] = new T[result.column];
        for (int i = 0; i < result.row; i++)
            for (int j = 0; j < result.column; j++)
	      result.array[i][j] = Base<T> :: array[i][j] - m1.array[i][j];
        return result;
    }
    else {
        throw SizeNotMatchException(); // terminate function
    }
}  //  end Matrix subtraction operator

//  multiplication operator
template<typename T>
Matrix<T> Matrix<T> :: operator * (const Matrix<T> & m1) const{
  if (Base<T> :: column == m1.row) {
    Matrix<T> result(Base<T> :: row, m1.column);
    for(int i = 0; i < Base<T> :: row; i++)
            for(int j = 0; j < m1.column; j++)
                for(int k = 0; k < m1.column; k++)
		  result.array[i][j] = Base<T> :: array[i][k] * m1.array[k][j] + result.array[i][j];
    return result;
    }
    else {
        throw RowColumnNotMatchException(); // terminate function
    }
}  //  end Matrix multplication operator

//  equality operator
template<typename T>
Matrix<T> Matrix<T> :: operator = (const Matrix<T> & m2) {
  for (int i = 0; i < Base<T> :: row; i++)
    delete Base<T> :: array[i];
  delete []Base<T> :: array;
  Base<T> :: row = m2.row;
  Base<T> :: column = m2.column;
  Base<T> :: array = new T*[Base<T> :: row];
  for (int i = 0; i < Base<T> :: row; i++)
    Base<T> :: array[i] = new T[Base<T> :: column];
  for (int i = 0; i < Base<T> :: row; i++) {
    for (int j = 0; j < Base<T> :: column; j++)
      Base<T> :: array[i][j] = m2.array[i][j];
    }
    return *this;
}  //  end Matrix equality operator

//  return the largest value of the Base
template<typename T>
T Matrix<T> :: get_Max_val(void) {
  T max = Base<T> :: array[0][0];
  for (int i = 0; i < Base<T> :: row; i++)
    for (int j = 0; j < Base<T> :: column; j++) {
      if (max < Base<T> :: array[i][j]) {
	max = Base<T> :: array[i][j];
            }
        }
    return max;
}  //  end Matrix get_Max_val funtion

//  return the smallest value of the Base
template<typename T>
T Matrix<T> :: get_Min_val(void) {
  T  min = Base<T> :: array[0][0];
    for (int i = 0; i < Base<T> :: row; i ++)
      for (int j = 0; j < Base<T> :: column; j++) {
	if (min > Base<T> :: array[i][j])
	  min = Base<T> :: array[i][j];
        }
    return min;
}  //  end Matrix get_Min_val funtion

//  return the companion matrix
template<typename T>
Matrix<T> Matrix<T> :: companion_matrix(void) {
    if (Base<T> :: row != Base<T> :: column) {
      throw NotSquareMatrixException();  //  terminate function
    }
  Matrix result(Base<T> :: row, Base<T> :: column);
  for(int i = 0; i < Base<T> :: row; i++)
    for(int j = 0; j < Base<T> :: column; j++)
            result.array[i][j] = pow(-1, i + j) *
        cofactor_matrix(i, j).determinant_matrix();
    return result;
}  //  end Matrix companion_matrix function

//  return the inverse of the matrix if it is invertible
template<typename T>
Matrix<T> Matrix<T> :: Inverse_matrix(void) {
  if (Base<T> :: row > 3 && Base<T> :: column > 3) {
    throw OutOfAbilityException();  //  terminate function
  }
  if (Base<T> :: row != Base<T> :: column) {
        throw NotSquareMatrixException(); // terminate function
    } else {
    Matrix<T> result(Base<T> :: row, Base<T> :: column);
        T n = this -> determinant_matrix();
        int k = n;
        if (k == 0) {      //  still confused on how to write it with Exception,
	  cout << "Not Inverible!" << endl;  //  becasue I write a class for it but CE
	  return result;
        } else {
        result = this -> companion_matrix();
        for(int i = 0; i < Base<T> :: row; i++) 
	  for(int j = 0; j < Base<T> :: column; j++) 
                result.array[i][j]/=n;
        return result;
        }
    }
}  //  end Matrix Inverse_matrix function

//  return the transpose of the matrix
template<typename T>
Matrix<T> Matrix<T> :: Transpose_matrix(void) {
  Matrix<T> result(Base<T> :: row, Base<T> :: column);
    for (int i = 0; i < result.row; i++)
        for (int j = 0; j < result.column; j++)
	  result.array[i][j] = Base<T> :: array[j][i];
    return result;
}  //  end Matrix Transpose_matrix function

//  return the determinant of the matrix
template<typename T>
T Matrix<T> :: determinant_matrix(void) {
  if (Base<T> :: row != Base<T> :: column) {
    throw NotHaveDeterminantException();  // terminate function
    }
  else if (Base<T> :: row == 1 && Base<T> :: column == 1)
    return Base<T> :: array[0][0];
    T sum = 0;
    for (int j = 0; j < Base<T> :: column; j++)
      sum = sum + pow(-1, j) * Base<T> :: array[0][j] *
       cofactor_matrix(0, j).determinant_matrix();
    return sum;
}  //  end Matrix determinant_matrix function

//  return the cofactor matrix of the matrix
template<typename T>
Matrix<T> Matrix<T> :: cofactor_matrix(int x, int y) {
  Matrix<T> result(Base<T> :: row - 1, Base<T> :: column - 1);
    int l = 0, k = 0;
    for (int i = 0; i < Base<T> :: row; i++) {
        l = 0;
        for (int j = 0; j < Base<T> :: column; j++) {
            if (i != x && j != y)
	      result.array[k][l] = Base<T> :: array[i][j];
            if (j != y)
                l++;
        }
        if (i != x)
            k++;
    }
    return result;
}  //  end Matrix cofactor_matrix function

//  functor to return the specific entry of the matrix
template<typename T>
T Matrix<T> :: operator()(int x, int y) {
    if (x < Base<T> :: row && y < Base<T> :: column) {
        return Base<T> :: array[x][y];
    } else {
      throw OutOfRangeException();
    }
}  //  end vector functor

//  overload the >> operator to store entries from string
template<typename T>
Matrix<T> & Matrix<T> :: operator>>(string a) {
    int i = 0, j = 0, flag = 0;
    T temp = 0;
    string tmp;
    for (int k = 0; k < a.size(); k++) {
        if (a[k] == ',') {
            tmp = a.substr(flag, k - flag);
            stringstream ss(tmp);
            ss >> temp;
            Base<T> :: array[i][j] = temp;
            j++;
            flag = k + 1;
        }
        else if (a[k] == ';') {
            tmp = a.substr(flag, k - flag);
            stringstream ss(tmp);
            ss >> temp;
            Base<T> :: array[i][j] = temp;
            i++;
            j = 0;
            flag = k + 1;
        }
        else if (k == a.size() - 1) {
            tmp = a.substr(flag, k - flag + 1);
            stringstream ss(tmp);
            ss >> temp;
            Base<T> :: array[i][j] = temp;
        }
    }
    return *this;
}  //  end >> operator overloading function

//  smart function to hear your voice
template<typename T>
void Matrix<T> :: hear(string feeling, const Matrix<T> & other) {
  if (feeling == "I love")
    *this = *this + other;
  else if (feeling == "I hate")
    *this = *this - other;
}  //  end hear function

//  sort by commands
template<typename T>
Matrix<T> Matrix<T> :: Sort(const string & commands) {
  Matrix<T> result(*this);
  T *tmp;
  T _size = this -> column * this -> row;
  tmp = new T[_size];
  int k = 0, t = 0;
  for (int i = 0; i < _size; i++)
    tmp[i] = 0;
  for (int i = 0; i < this -> row; i++)
    for (int j = 0; j < this -> column; j++)
      tmp[k++] = this -> array[i][j];
  if (commands == "ascending")
    sort((T*)tmp, (T*)tmp + _size, less<T>());
  else if (commands == "descending")
    sort((T*)tmp, (T*)tmp + _size, greater<T>());
  for (int i = 0; i < this -> row; i++)
    for (int j = 0; j < this -> column; j++)
      result.array[i][j] = tmp[t++];
  delete []tmp;
  return result;
}  //  end Sort function

//  print the matrix to the function
template<typename T>
void Matrix<T> :: printToFile(const char* filename) {
  ofstream ofs;
  ofs.open(filename, std :: ofstream :: out | std :: ofstream :: app);
  for (int i = 0; i < this -> row; i++) {
    for (int j = 0; j < this -> column - 1; j++) {
      ofs << this -> array[i][j] << " ";
    }
    ofs << this -> array[i][this -> column - 1];
    ofs << endl;
  }
  if (ofs.good())
    cout << "OK to print to the file" << endl;
  ofs.close();
}  //  end printToFile function

//  read the matrix from the file
template<typename T>
void Matrix<T> :: setByFile(const char* filename) {
  ifstream ifs;
  ifs.open(filename, std :: ifstream :: in);
  char c[MAX];
  int i = 0;
  while (ifs.good()) {
    c[i] = ifs.get();
    i++;
  }
  for (int k = 0; k < i - 2; k++)
    if (c[k] == '\n')
      c[k] = ';';
  i = 0;
  string tmp(c);
  int j = 0, flag = 0;
    T temp = 0;
    string _data;
    for (int k = 0; k < tmp.size(); k++) {
        if (tmp[k] == ' ') {
            _data = tmp.substr(flag, k - flag);
            stringstream ss(_data);
            ss >> temp;
            this ->  array[i][j] = temp;
            j++;
            flag = k + 1;
        }
        else if (tmp[k] == ';') {
            _data = tmp.substr(flag, k - flag);
            stringstream ss(_data);
            ss >> temp;
            this -> array[i][j] = temp;
            i++;
            j = 0;
            flag = k + 1;
	    }
        else if (k == tmp.size() - 1) {
            _data = tmp.substr(flag, k - flag + 1);
            stringstream ss(_data);
            ss >> temp;
            this -> array[i][j] = temp;
	    }
    }
}  //  end setByFile function
