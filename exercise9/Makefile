#
#	Simple makefile
#

TARGET=example9
SRC=example9.cpp simpleObject.cpp complexObject.cpp
OBJ=$(SRC:%.cpp=%.o)

CFLAGS=-g3
CPP=g++

%.o : %.cpp
	$(CPP) -c $(CFLAGS) -o $*.o $*.cpp
	
$(TARGET) : $(OBJ)
	$(CPP) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:	
	rm -rf $(OBJ) $(TARGET)	
	
