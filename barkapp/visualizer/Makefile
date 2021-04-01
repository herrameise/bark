OBJS= \
	Visualizer.o \
	VisualizerCore.o \
	VisualizerForms.o \
	VisualizerPanel.o \
	VisualizerSettings.o \
	VisualizerSettingsDialog.o

CXX=`wx-config --cxx`
CXXFLAGS=`wx-config --cxxflags` -Wall -O2 -D_DEBUG=1 -std=c++11 -I../..


all : $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	-rm -f *.o
