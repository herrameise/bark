OBJS= \
	Blade.o \
	Loader.o \

CXX=g++
CXXFLAGS=-Wall -O2 -fPIC -std=c++11 -D_FILE_OFFSET_BITS=64 -I../..
LIBS=-L../../bin -lbark
TARGET=../../bin/BladeTemplateCore.so



all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -shared $(CXXFLAGS) $(LIBS) -o $(TARGET) $(OBJS) 

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	-rm -f *.o
	-rm -f $(TARGET)