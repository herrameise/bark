OBJS= \
	Bark.o \
	Blade.o \
	BladeEntry.o \
	Debug.o \
	Logger.o \
	Manager.o \
	ManagerOpaque.o \
	Packet.o \
	Specimen.o \
	SpecimenOpaque.o

TARGET=../bin/libbark.so
CXX=g++
CXXFLAGS=-Wall -O0 -fPIC -std=c++11 -D_FILE_OFFSET_BITS=64
LIBS=-ldl



all : $(OBJS)
	$(MAKE) -C appstub
	$(MAKE) -C cbind
	$(CXX) $(CXXFLAGS) -shared $(LIBS) *.o appstub/*.o cbind/*.o -o $(TARGET)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

install :
	cp $(TARGET) /usr/local/lib/
	mkdir -p /usr/local/include/bark
	cp *.h /usr/local/include/bark/

uninstall :
	-rm -rf /usr/local/include/bark
	-rm -f /usr/local/lib/libbark.so

clean :
	$(MAKE) -C appstub clean
	$(MAKE) -C cbind clean
	-rm -f *.o
	-rm -f $(TARGET)
