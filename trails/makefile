SOURCES = $(wildcard *.cpp)
objects = $(SOURCES:.cpp=)

all: $(objects)

$(objects):%: %.cpp
	g++ -std=c++14 $< -o $@
