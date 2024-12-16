DEBUGOPCIONS = -std=c++14 -Wall -Wno-deprecated -g -O0
RELEASEOPCIONS = -std=c++14 -Wall -Wno-deprecated -Werror -O2
OPCIONS = $(DEBUGOPCIONS)

driver_joc_par.e: driver_joc_par.o obte_paraules.o anagrames.o word_toolkit.o diccionari.o iter_subset.o
	g++ -o driver_joc_par.e driver_joc_par.o obte_paraules.o anagrames.o word_toolkit.o diccionari.o iter_subset.o -lesin
	rm *.o 

driver_joc_par.o: driver_joc_par.cpp obte_paraules.hpp anagrames.hpp iter_subset.hpp diccionari.hpp word_toolkit.hpp
	g++ -c driver_joc_par.cpp $(OPCIONS)

obte_paraules.o: obte_paraules.cpp obte_paraules.hpp anagrames.hpp
	g++ -c obte_paraules.cpp $(OPCIONS)

anagrames.o: anagrames.cpp anagrames.hpp diccionari.hpp
	g++ -c anagrames.cpp $(OPCIONS)

word_toolkit.o: word_toolkit.cpp word_toolkit.hpp
	g++ -c word_toolkit.cpp $(OPCIONS)

diccionari.o: diccionari.cpp diccionari.hpp
	g++ -c diccionari.cpp $(OPCIONS)

iter_subset.o: iter_subset.cpp iter_subset.hpp
	g++ -c iter_subset.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.e