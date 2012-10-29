#
#	Simple makefile
#

TARGET=example10
SRC=example10.cpp threedObject.cpp complexObject.cpp
OBJ=$(SRC:%.cpp=%.o)

CFLAGS=-g3
CPP=g++

%.o : %.cpp %.h
	$(CPP) -c $(CFLAGS) -o $*.o $*.cpp
	
$(TARGET) : $(OBJ)
	$(CPP) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:	
	rm -rf $(OBJ) $(TARGET)	
	
