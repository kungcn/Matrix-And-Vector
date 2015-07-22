//  Project Stage 05 : Vector.h
//  class Vector definition with inheritance from class Base

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include "Base.h"
#include "RowColumnNotMatchException.h"
#include "SizeNotMatchException.h"
#include "OutOfRangeException.h"
#define MAX 100
using namespace std;

template<typename T>
class Vector : public Base<T> {
    public :
        //  constructor
        Vector(void);
        //  copy constructor
        Vector(const Vector<T> &);
        //  another constructor
        Vector(int);
        //  return the norm of the Vector
        T getLength(void);
        //  addition operator
        Vector<T> operator +(const Vector<T> &) const;
        //  subtraction operator
        Vector<T> operator -(const Vector<T> &) const;
        //  multiplication operator
        Vector<T> operator *(const Vector<T> &) const;
        //  equality operator
        Vector<T> operator =(const Vector<T> &);
        //  functor to return the entry of the vector
        T operator()(int);
        //  the friend function to overload the ostream
        friend std::ostream & operator<<(std::ostream & os, const Vector<T> & other) {
	        os << "( ";
            for (int i = 0; i < other.column - 1; i++)
                os << other.array[0][i] << ", ";
            os << other.array[0][other.column - 1] << " )" << endl;
            return os;
        }
        //  overload the >> operator to store the entries from a string
        Vector<T> & operator>>(string n);
        //  smart class to hear our needs
        void hear(string, const Vector<T> &);
        //  sort by commands
        Vector<T> Sort(const string &);
        //  print the vector to the file
        void printToFile(const char*);
        //  read the vector from the file
        void setByFile(const char*);
};  //  end class Vector definition

//  default constructor
template<typename T>
Vector<T> :: Vector(void)
: Base<T> :: Base(1, 2) {
}  //  end Vector default constructor

//  copy constructor
template<typename T>
Vector<T> :: Vector(const Vector<T> & other)
: Base<T> :: Base(other.row, other.column) {
  for (int i = 0; i < Base<T> :: row; i++)
    for (int j = 0; j < Base<T> :: column; j++)
      Base<T> :: array[i][j] = other.array[i][j];
}  //  end Vector copy constructor

//  constructor with parameter, just column because the row will be always 0
template<typename T>
Vector<T> :: Vector(int _column)
: Base<T> :: Base(1, _column) {
}  //  end Vector constructor with parameter

//  return the norm of the Vector
template<typename T>
T Vector<T> :: getLength(void) {
    T res = 0;
    for (int i = 0; i < Base<T> :: column; i++)
      res += Base<T> :: array[0][i] * Base<T> :: array[0][i];
    res = sqrt(res);
    return res;
}  //  end Vector getLength function

//  addition operator
template<typename T>
Vector<T> Vector<T> :: operator +(const Vector<T> & v1) const {
  if (Base<T> :: column == v1.column) {
    Vector<T> result(Base<T> :: column);
    for (int i = 0; i < Base<T> :: column; i++)
      result.array[0][i] = Base<T> :: array[0][i] + v1.array[0][i];
        return result;
   }
   else {
     throw SizeNotMatchException();  //  terminate function
   }
}  //  end Vector addition operator

//  subtraction operator
template<typename T>
Vector<T> Vector<T> :: operator - (const Vector<T> & v1) const {
  if (Base<T> :: column == v1.column) {
        Vector<T> result(v1.column);
        for (int i = 0; i < Base<T> :: column; i++)
	  result.array[0][i] = Base<T> :: array[0][i] - v1.array[0][i];
        return result;
    }
  else {
      throw SizeNotMatchException();  //  terminate function
   }
}  //  end Vector subtraction operator

//  multiplication operator
template<typename T>
Vector<T> Vector<T> :: operator * (const Vector<T> & v1) const {
  if (Base<T> :: column == v1.column) {
        Vector<T> result(1);
        for (int i = 0; i < Base<T> :: column; i++) {
	  result.array[0][0] = Base<T> :: array[0][i] * v1.array[0][i] +
                                result.array[0][0];   
        }
    return result;
    }
  else  {
       throw SizeNotMatchException();  //  terminate function
   }
}  //  end multtplication operator

// equality sign operator
template<typename T>
Vector<T> Vector<T> :: operator = (const Vector<T> & v2) {
  if (Base<T> :: array != NULL) {
    delete []Base<T> :: array[0];
    delete []Base<T> :: array;
    }
  Base<T> :: row = v2.row;
  Base<T> :: column = v2.column;
  Base<T> :: array = new T*[Base<T> :: row];
  for (int i = 0; i < Base<T> :: row; i++)
    Base<T> :: array[i] = new T[Base<T> :: column];
    for (int i = 0; i < v2.column; i++) {
      Base<T> :: array[0][i] = v2.array[0][i];
    }
    return *this;
} //  end Vector equality operator

//  functor to return the specific entry of the vector
template<typename T>
T Vector<T> :: operator()(int x) {
    if (x < Base<T> :: column) {
        return Base<T> :: array[0][x];
    } else {
      throw OutOfRangeException();
    }
}  //  end Vector functor

//  the friend to overload ostream
template<typename T>
std::ostream & operator<<(std::ostream & os, const Vector<T> & other) {
    os << "( ";
    for (int i = 0; i < other.column - 1; i++)
      os << other.array[0][i] << ", ";
    os << other.array[0][other.column - 1] << " )" << endl;
    return os;
}  //  end << operator function

//  overload the >> operator to store entries from a string
template<typename T>
Vector<T> & Vector<T> :: operator>>(string a) {
    int i = 0, j = 0, flag = 0;
    T temp = 0;
    string tmp;
    for (int k = 0; k < a.size();  k++) {
        if (a[k] == ',') {
            tmp = a.substr(flag, k - flag);
            stringstream ss(tmp);
            ss >> temp;
            Base<T> :: array[i][j] = temp;
            j++;
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
}

//  smart function to hear our needs
template<typename T>
void Vector<T> :: hear(string feeling, const Vector<T> & other) {
  if (feeling == "I love")
    *this = *this + other;
  else if (feeling == "I hate")
    *this = *this - other;
}  //  end hear function

//  sort by verifying the commands
template<typename T>
Vector<T> Vector<T> :: Sort(const string & commands) {
  Vector<T> result(*this);
    if (commands == "ascending")
      sort((T*)result.array[0], (T*)result.array[0] + result.column, less<T>());
    else if (commands == "descending")
      sort((T*)result.array[0], (T*)result.array[0] + result.column, greater<T>());
	return result;
}  //  end sort function

//  print the vector to the file
template<typename T>
void Vector<T> :: printToFile(const char* filename) {
  ofstream ofs;
  ofs.open(filename, std :: ofstream :: out);
  for (int i = 0; i < this -> column - 1; i++)
    ofs << this -> array[0][i] << " ";
  ofs << this -> array[0][this -> column - 1] << endl;
  if (ofs.good())
    cout << "OK to print" << endl;
  ofs.close();
}  //  end printToFile function

//  read the matrix from the vector
template<typename T>
void Vector<T> :: setByFile(const char* filename) {
  ifstream ifs;
  ifs.open(filename, std :: ifstream :: in);
  char c[MAX];
  int i = 0, j = 0;;
  while (ifs.good()) {
    c[i] = ifs.get();
    i++;
  }
  i = 0;
  string tmp(c);
  int flag = 0;
    T temp = 0;
    string _data;
    for (int k = 0; k < tmp.size();  k++) {
        if (tmp[k] == ' ') {
          _data = tmp.substr(flag, k - flag);
          stringstream ss(_data);
          ss >> temp;
          this -> array[i][j] = temp;
          j++;
          flag = k + 1;
        }
       else if (k == tmp.size() - 1) {
            _data = tmp.substr(flag, k - flag + 1);
            stringstream ss(_data);
            ss >> temp;
            this -> array[i][j] = temp;
        }
    }
}

#endif
