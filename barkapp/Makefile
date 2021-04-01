OBJS= \
	BladeEntriesListCtrl.o \
	ColorTemplate.o \
	DeployBladeDialog.o \
	Logger.o \
	LoggerForms.o \
	LoggerPanel.o \
	main.o \
	MainWindow.o \
	MainWindowForms.o \
	Manager.o \
	ManagerForms.o \
	Specimen.o

TARGET=../bin/barkapp

CXX=`wx-config --cxx`
CXXFLAGS=`wx-config --cxxflags` -Wall -O2 -std=c++11 -I../
LIBS=-L../bin -lbark -ldl -lboost_system -lboost_filesystem `wx-config --libs core,base,adv,aui,richtext,html`


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(MAKE) -C editor
	$(MAKE) -C visualizer
	$(CXX) *.o editor/*.o visualizer/*.o $(LIBS) -o $(TARGET)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	$(MAKE) -C visualizer clean
	$(MAKE) -C editor clean
	-rm -f *.o
	-rm -f $(TARGET)
