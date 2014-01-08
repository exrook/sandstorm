CXXFLAGS = -g -std=gnu++0x $(shell pkg-config --cflags sdl2 SDL2_image) -Wall -pedantic
LDFLAGS =  -g $(shell pkg-config --libs sdl2 SDL2_image)

SOURCES = main.cpp util.cpp Game.cpp Sandstorm.cpp Entity.cpp Platforms.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = sandstorm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean doc

clean:
	rm -f $(OBJECTS) $(LIBOBJECTS)
	rm -rf Space2D/.libs/ GameControl/.libs/ SurfaceX/.libs/ Entity/.libs/

doc: 
	rm -r doc/
	doxygen
