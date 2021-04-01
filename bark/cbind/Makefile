OBJS= \
	Bark.o \
	Logger.o \
	Manager.o \
	Specimen.o

CXX=g++
CXXFLAGS=-Wall -O2 -fPIC -std=c++11 -D_FILE_OFFSET_BITS=64 -c

all : $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean :
	-rm -f *.o