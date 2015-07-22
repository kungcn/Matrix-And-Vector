mainVector:
	g++ -Wall mainVector.cpp -g -o mainVector

mainMatrix:
	g++ -Wall mainMatrix.cpp -g -o mainMatrix

clean:
	rm mainMatrix
	rm mainVector
