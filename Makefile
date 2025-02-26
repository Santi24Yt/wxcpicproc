WX_CONFIG 	= wx-config
WX_CXXFLAGS = $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS 		= $(shell $(WX_CONFIG) --libs)

CXX = g++
CXXFLAGS = -xc++ -std=c++11
DFLAGS = -Wall -Werror
 
INCLUDES = -I./libs/
LIBS =

# Max depth 3
SOURCES = $(filter-out $(wildcard resources/*),$(wildcard */*.cpp */*/*.cpp */*/*/*.cpp))
OBJECTS = $(SOURCES:.cpp=.o)

OUT = wxcpicproc

all: lspflags $(OUT)

$(OUT): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(OUT) $(WX_LIBS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(WX_CXXFLAGS) $(DFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OUT)

lspflags:
	echo $(WX_CXXFLAGS) $(WX_LIBS) $(INCLUDES) $(LIBS) $(DFLAGS) $(CXXFLAGS) | sed "s/ /\n/g" > compile_flags.txt
