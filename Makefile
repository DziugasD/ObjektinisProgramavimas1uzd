main: biblioteka.o
	g++ -o 1uzd 1uzd.cpp biblioteka.o -O3 
biblioteka.o: biblioteka.cpp
	g++ -c biblioteka.cpp -o biblioteka.o
clean:
	rm *.o 1uzd biblioteka
