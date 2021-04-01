OBJS= \
	Editor.o \
	EditorCore.o \
	EditorForms.o \
	EditorPanel.o \
	EditorSettings.o \
	EditorSettingsDialog.o \
	EditorTextCtrl.o \
	FillValueDialog.o \
	MaskValueDialog.o

CXX=`wx-config --cxx`
CXXFLAGS=`wx-config --cxxflags` -Wall -O2 -D_DEBUG=1 -std=c++11 -I../..


all : $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	-rm -f *.o
