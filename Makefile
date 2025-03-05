WX_CONFIG = wx-config
WX_CXXFLAGS = $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS = $(shell $(WX_CONFIG) --libs)

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
	rm -f $(OBJECTS) $(OUT) $(ST_OUT)

lspflags:
	echo $(WX_CXXFLAGS) $(WX_LIBS) $(INCLUDES) $(LIBS) $(DFLAGS) $(CXXFLAGS) | sed "s/ /\n/g" > compile_flags.txt

ST_WX_CONFIG = ../wxWidgetsBuilds/3.2.6/wx-config
ST_WX_CXXFLAGS = $(shell $(ST_WX_CONFIG) --cxxflags --static=yes)
ST_WX_LIBS = $(shell $(ST_WX_CONFIG) --libs --static=yes)

ST_CXXFLAGS = -xc++ -std=c++11 -static -static-libgcc -static-libstdc++
ST_DFLAGS = -Wall -Werror

ST_INCLUDES = -I./libs/
ST_LIBS = -Wl,--as-needed

ST_OUT = wxcpicproc-static

$(ST_OUT): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(ST_OUT) $(ST_LIBS) $(ST_WX_LIBS)

%.o: %.cpp
	$(CXX) $(ST_CXXFLAGS) $(ST_WX_CXXFLAGS) $(ST_DFLAGS) $(ST_INCLUDES) -c $< -o $@

static: $(ST_OUT)