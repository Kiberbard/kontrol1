all:	kontrol1
kontrol1: main.o kontrol1.o
		g++ main.o kontrol1.o -o kontrol1
main.o:	main.cpp
		g++ -c main.cpp
kontrol1.o: kontrol1.cpp
		g++ -c kontrol1.cpp
clean: 
		rm -rf *.o kontrol1
