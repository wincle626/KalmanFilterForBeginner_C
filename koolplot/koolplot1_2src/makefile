CC = gcc.exe

libkoolplot.a: plotdata.o plotstream.o koolplot.o bgi_util.o
	ar -rv libkoolplot.a plotdata.o plotstream.o koolplot.o bgi_util.o

clean:
	rm *.o 
	rm *.exe 
	rm libkoolplot.a

CC_FLAGS = -x c++ -O3 -fno-rtti -fno-exceptions -fno-common -fshort-enums -pedantic-errors

LINK_FLAGS = -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lstdc++ -lsupc++ 

plotdata.o: Plotdata.cxx Plotdata.h
	$(CC) $(CC_FLAGS) -c  Plotdata.cxx -o plotdata.o

plotstream.o: Plotstream.cxx Plotstream.h Plotdata.h
	$(CC) $(CC_FLAGS) -c  Plotstream.cxx -o plotstream.o

koolplot.o: koolplot.c koolplot.h Plotstream.h Plotdata.h
	$(CC) $(CC_FLAGS) -c  koolplot.c -o koolplot.o
	
bgi_util.o: bgi_util.cpp bgi_util.h
	$(CC) $(CC_FLAGS) -c  bgi_util.cpp -o bgi_util.o

kplot.o: kplot.c
	$(CC) $(CC_FLAGS) -c  kplot.c -o kplot.o

kplot.exe: kplot.o libkoolplot.a
	$(CC)  -mwindows -o kplot.exe -s kplot.o libkoolplot.a $(LINK_FLAGS)

all: kplot.exe

