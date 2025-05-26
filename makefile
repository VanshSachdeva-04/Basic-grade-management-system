grade: driver.o student.o
	g++ -o grade driver.o student.o -g
driver.o: driver.cpp linkedlist.h student.h
	g++ -c driver.cpp -g
student.o: student.h student.cpp
	g++ -c student.cpp -g
clean:
	rm *.o grade