# Opcions de compilació
CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++03
LDFLAGS = -lesin

# Arxius font i executable
SOURCES = driver_joc_par.cpp
HEADERS = anagrames.hpp diccionari.hpp iter_subset.hpp obte_paraules.hpp word_toolkit.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = program.exe

# Regla principal
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.o *.exe
