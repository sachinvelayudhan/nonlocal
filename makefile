incPath= $(CURDIR)/inc/
neigh:
	g++ -std=c++17 -g -c mainNeighEle.cpp -I$(incPath)
	g++ -std=c++17 -o main.exe mainNeighEle.o
	./main.exe
nonlocal:
	g++ -std=c++17 -g -c mainNonlocal.cpp -I$(incPath)
	g++ -std=c++17 -o main.exe mainNonlocal.o
	./main.exe
neigh3D:
	g++ -std=c++17 -g -c mainNonlocal3D.cpp -I$(incPath)
	g++ -std=c++17 -o main.exe mainNonlocal3D.o
	./main.exe
clean:
	rm -v *.o
	rm -v *.exe
