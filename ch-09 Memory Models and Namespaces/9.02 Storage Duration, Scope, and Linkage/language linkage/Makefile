language_linkage:cfile.o cppfile.o
	g++ -o language_linkage cfile.o cppfile.o
cfile.o:cfile.c
	gcc -c cfile.c
cppfile.o:cppfile.cpp
	g++ -c cppfile.cpp
clean:
	rm -f *.o
	rm -f language_linkage
