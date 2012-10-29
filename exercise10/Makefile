#
#	Simple makefile
#

TARGET=example10
SRC=example10.cpp threedObject.cpp complexObject.cpp
OBJ=$(SRC:%.cpp=%.o)

SDL_CFLAGS=$(shell sdl-config --cflags)
SDL_LDFLAGS=$(shell sdl-config --libs)

#   Get SDL library headers & libraries
CFLAGS=-g3 $(SDL_CFLAGS)
LDFLAGS=$(SDL_LDFLAGS) -lSDL_gfx -lSDL_ttf

CPP=g++

%.o : %.cpp
	$(CPP) -c $(CFLAGS) -o $*.o $*.cpp
	
$(TARGET) : $(OBJ)
	$(CPP) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:	
	rm -rf $(OBJ) $(TARGET)	

# DO NOT DELETE

complexObject.o: threedObject.h geometry.h complexObject.h
example10.o: threedObject.h geometry.h complexObject.h sprite.h
threedObject.o: threedObject.h geometry.h
