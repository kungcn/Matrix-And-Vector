//  Project Stage 05 : Base.h
//  Base class definitions and member methods 

#ifndef BASE_H 
#define BASE_H

#include <iostream>
using namespace std;

template<typename T>
class Base {
    protected :
        int row;  //  the row of the array[][]
        int column;  //  the column of the array[][]
        T** array;  //  the array to store the data

    public :
        //  default constructor
        Base(void);
        //  copy constructor
        Base(const Base &);
        //  constructor with parameters, row and column
        Base(int, int);
        //  destructor of Base
        ~Base(void);
        //  set all elements of the array
        void set_all_elements(T**, int, int);
        //  set specified element in the array
        void set_specified_element(int, int, T);
        //  return the size of the array in the form "row column" when it is a 
        //  2D raw array, otherwise just in the form "column"
        int *get_Size(void);
        //  return the entry of the array
        T get_Entry(int, int);
        //  check whether all entries in the parameter is in the array
        bool check_all_element(T *, int);
        //  check whether a entries existing in the parameter is in the array
        bool check_some_element(T *, int);
	    //  return the row as an integer
	    int get_ro(void);
	    //  return the column as an integer
        int get_co(void);
};  //  end Base class definitions

#endif

template<typename T>
Base<T> :: Base(void)  //  default constructor
    : row(2), column(2) {
    array = new T*[row];
    for (int i = 0; i < row; i++)
        array[i] = new T[column];
    for (int i = 0; i < row; i++) { 
        for (int j = 0; j < column; j++) {
            array[i][j] = 0;
        }
    } 
}  //  end Base default constructor

//  copy constructor
template<typename T>
Base<T> :: Base(const Base<T> & other)
    : row(other.row), column(other.column) {
    array = new T*[row];
    for (int i = 0; i < row; i++)
        array[i] = new T[column];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            array[i][j] = other.array[i][j];
}  //  end Base copy constructor

//  constructor with parameters, row and column
template<typename T>
Base<T> :: Base(int _row, int _column)
    : row(_row), column(_column) {
    array = new T*[row];
    for (int i = 0; i < row; i++)
        array[i] = new T[column];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                array[i][j] = 0;
}  //  end Base constructor

//  desturctor
template<typename T>
Base<T> :: ~Base(void) {
    for (int i = 0; i < row; i++)
        delete []array[i];
    delete []array;
}  //  end destructor

//  set all elements of the array
template<typename T>
void Base<T> :: set_all_elements(T **_raw_array, int _row, int _column) {
    row = _row;
    column = _column;
    for (int i = 0; i < row; i++)
        delete []array[i];
    delete []array;
    array = new T*[row];
    for (int i = 0; i < row; i++)
        array[i] = new T[column];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            array[i][j] = *((T*)_raw_array + i * column + j);
}  //  end set_all_elements funtion

//  set specified element in the array
template<typename T>
void Base<T> :: set_specified_element(int row_, int column_, T specied_entry) {
    array[row_][column_] = specied_entry;
}  //  end set_specified_element funtion

//  return the size of the array in the form "row column" when it is a 2D raw
//  array, otherwise just in the form "column"
template<typename T>
int * Base<T> ::get_Size(void) {
    int *rc_array;
    rc_array = new int[2];
    rc_array[0] = row;
    rc_array[1] = column;
    if (rc_array[0] == 1) {
        int * tmp;
        tmp = new int[1];
        tmp[0] = rc_array[1];
        delete []rc_array;
        return tmp; 
    }
    return rc_array;
}  //  end get_Size definition

//  return the entry of the array
template<typename T>
T Base<T> :: get_Entry(int row_, int column_) {
    return array[row_][column_];
}  //  end get_Entry definition

//  check whether all entries in the parameter is in the array
template<typename T>
bool Base<T> :: check_all_element(T * temp, int size) {  //  temp is an array   
    int k = 0, i = 0, j = 0, counter = 0;          //  size is the size of temp
    for (k = 0; k < size; k++)
        for (i = 0; i < row; i++)
            for (j = 0; j < column; j++)
                if (array[i][j] == temp[k])
                    counter++;
    if (counter == size)
        return true;
    return false;
}  //  end check_all_element funtion

//  check whether a entries existing in the parameter is in the array
template<typename T>
bool Base<T> :: check_some_element(T * temp, int size) {  //  temp is an array,
                                                  //   size is the size of temp
    for (int k = 0; k < size; k++)
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                if (array[i][j] == temp[k])
                    return true;
    return false;
}  //  end check_some_element funtion

//  return the row as the integer
template<typename T>
int Base<T> :: get_ro(void) {
    return row;
}  //  end Base get_Row funtion

//  return the column as the integer
template<typename T>
int Base<T> :: get_co(void) {
    return column;
}  //  end Base get_Column funtion

