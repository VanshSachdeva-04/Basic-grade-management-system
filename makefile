grade: driver.o student.o
	g++ -std=c++11 -o grade driver.o student.o -g

driver.o: driver.cpp linkedlist.h student.h
	g++ -std=c++11 -c driver.cpp -g

student.o: student.cpp student.h
	g++ -std=c++11 -c student.cpp -g

clean:
	rm *.o grade
