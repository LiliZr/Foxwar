CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

main: main.cpp animal.o coordonnees.o deplacement.o ensemble.o grille.o tools.o

animal.o: animal.hpp animal.cpp
coordonnees.o: coordonnees.hpp coordonnees.cpp
deplacement.o: deplacement.hpp deplacement.cpp
ensemble.o: ensemble.hpp ensemble.cpp
grille.o: grille.hpp grille.cpp
tools.o: tools.hpp tools.cpp

clean:
	rm -f main *.o
	rm -r images
