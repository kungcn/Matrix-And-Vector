# Matrix & Vector
Sorry because I just learn how to use GitHub today, and finally I upload it because this is the project of my C++ course. I have written a Readme file in my version and I think they are specific so I don't write so much on each stage of the project.
Totally, the project can solve common problems of matrix and vector. What I think is a pity is that I didn't know how to use the previous code to realize some functions in OpenGL. I am so sad...
Maybe the following part is confusing because I just copy the previous stages' Readme.md in the following one. But I think it exerts any impact on your understanding. Right?
## What I have done in the source codes
### Stage 01
*  Create two classes, one is called the Matrix while the others is called the Vector. The data member in the classes are **array, row, column in Matrix, and the *array, dimension in Vector.
* The Matrix can set all entries in the matrix or just some entries in the matrix. The Vector one too.
*  Both of them have their own addition, subtraction and multiplication which are come true with the help of operator overloading. What is worth paying attention to is that the multiplication in the Matrix is not element - wise multiplication, while in the Vector it is.
*  In the Matrix class, there are three constructors and one destructor, allowing us to call the class in need. It also allows us to get the maximum, minimum, the row and the column of the matrix. And then, it can also get the size of the matrix with the form in "row column", get the specified entry.
*  In the Vector class, it also allows us to get the norm and the dimension of the vector, which are useful in the application. Meanwhile, it helps us to know the norm of the vector, and there are also 3 constructors and 1 destructor in the class.
*  Finally, the destrctors are called to free the memory.

### Stage 02
* There is a Base class for vector and matrix which is intended to contain the common collections of methods and members that used for both of matrix and vector.
* The class Vector and Matrix will get the methods as well as the members by heritance. Meanwhile, they have their unique methods respectively.

### Stage 03
* Besides the method functions achieved in the project stage 02, which makes the class Matrix and Vector have the basic skills respectively with the inheritance from the class Base.
* In the stage 03, polymorphism, template are used to let the codes more ample and can accept the datas with many types, like int, double and char.

### Stage 04
 There is a Base class for vector and matrix which is intended to contain the common collections of methods and members that used for both of matrix and vector.
 * The class Vector and Matrix will get the methods as well as the members by inheritance. Meanwhile, they have their unique methods respectively.
 * The input and output are different before, it is ok to get the entries of the matrix or the vector like the following form:

 `Sample Input`
 `1, 2, 3; 4, 5, 6; 7, 8, 9` 
` Sample Output`
 `| 1, 2, 3 |`
 `| 4, 5, 6 |`
 `| 7, 8, 9 |`

 * Exception appears in the the files written by myself, which helps managing the condition out of expectation.
 
### Stage 05
 * This stage codes allows us to print the result or read the matrix or the vector from a .txt file, helping the program not to get the data only through the keyboard.
*  They are also smart classes now, because they can hear your voice if you send it through the key board, they will answer you with the addition, subtraction operation or the descending, ascending sort. 

### Stage 06
* After finishing all the functions required by the previous documents in both the Vector and the Matrix classes, it allows us to use the codes with OpenGL. And the codes just show the change when you input some characters from the keyboard. However, unfortunately, the codes given by the TAs can not be used directly when the input is any string. So, I have no alternative but to use the characters input instead of the string one which given in the table in the document. The following table will show the relationship with the changes.

| Input      |     Required String |   Description   |
| :--------: | :--------:| :------: |
| z    |   qz |  All joints zero  |
| r    |   qr |  Keep right angle arm  |
| n    |   qn |  Keep a normal pose  |
| d    |   qd |  Arm falling down  |

## The organizations of the files
In my files, you can see the folder named src and the readme.md. In the src folder, there are many files there, both .cpp and .h. Some are the class prototype and the definition of the Matrix and the Vector class and some are the exceptions which may be discovered when executing the code.Others are the test codes write by myself before. Most importantly, there is a makefile to help you execute the codes when using Linux. In these two stage, stage 06 and 07, a file called Final.cpp was created to accomplish the functions required.
## The Special things in my file
* First of all, I want to say sorry for I don't understand the document well and some functions weren't realized. I have tested it before, but just when I input "z" or "d", then it display the result, but I don't verify the result is right or not. However, when I just input any other character mentioned as before, the display disappears but it doesn't show out another result. Say more is tear and I want to cry when I test it. Eventually, I discuss it with classmates and they told me another algorithm to realize the functions because I just displayed the final result without the process. Whereas when I tested it on the way to finish it, I found no reaction when I input something. Therefore, I just use the /* ,*/ to let such codes become the comments...
* Although I don't finish the requirement for the reason that I don't know well on the API and the principle and time limitation, I still learn something in STL when doing the project. map and something good, I think it is good for us to do the project but it was nearly the final exam now. 

