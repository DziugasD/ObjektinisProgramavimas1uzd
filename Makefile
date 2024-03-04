main: biblioteka.o 
	g++ -o 1uzd 1uzd.cpp biblioteka.o -O3
biblioteka: 
	g++ -c biblioteka.cpp 
clean: 
	rm *.o 1uzd
