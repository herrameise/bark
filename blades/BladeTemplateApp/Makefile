OBJS= \
	Blade.o \
	BladeTemplateForms.o \
	Loader.o \
	MainPanel.o

CXX=`wx-config --cxx`
CXXFLAGS=-Wall -O2 -fPIC -std=c++11 -I../.. `wx-config --cxxflags`
LIBS=-L../../bin -lbark `wx-config --libs core,base,adv,aui,richtext,html`
TARGET=../../bin/BladeTemplateApp.so



all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -shared $(OBJS) $(LIBS) -o $(TARGET)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean :
	-rm -f *.o
	-rm -f $(TARGET)
