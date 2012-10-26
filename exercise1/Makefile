#
#	Simple makefile
#

TARGET=example1
SRC=example1.cpp
OBJ=$(SRC:%.cpp=%.o)

CFLAGS=-g3
CPP=g++

%.o : %.cpp
	$(CPP) -c $(CFLAGS) -o $*.o $*.cpp
	
$(TARGET) : $(OBJ)
	$(CPP) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:	
	rm -rf $(OBJ) $(TARGET)	
	
