all: testshit
	g++ Date.cpp Date_driver.cpp -o testshit

testshit: Date.o Date_driver.o
	g++ Date.o Date_driver.o -o testshit

Date.o: Date.cpp
	g++ -c Date.cpp

Date_driver.o: Date_driver.cpp
	g++ -c Date_driver.cpp

clean:
	rm -rf *testshit