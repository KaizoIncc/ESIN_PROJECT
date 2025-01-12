#include "anagrames.hpp"
#include "word_toolkit.hpp"

//cost:O(1)
anagrames::anagrames() throw(error) {

}

//O(n), on n és el nombre d'elements dins de la llista anagram
anagrames::anagrames(const anagrames& A) throw(error) {
   anagram = A.anagram;
    
}
//cost:O(1)
anagrames::~anagrames() throw() {

}

//cost:O(1)
anagrames& anagrames::operator=(const anagrames& A) throw(error) {
    if (this != &A) anagram = A.anagram;  
    return *this;
}

//cost:O(log n + k log k + m + n) m és el nombre d'anagrames canònics ja existents dins de anagram
//n és la mida de la llista de paraules d'un mateix anagrama
//k és la longitud de la cadena p
void anagrames::insereix(const string& p) throw(error) {
    
    diccionari::insereix(p);

    
    string a = word_toolkit::anagrama_canonic(p);

  
    auto it = anagram.begin();
    while (it != anagram.end() && it->first < a) {
        ++it;
    }

    if (it == anagram.end() || it->first != a) {
        pair<string, list<string>> nou(a, {p});
        anagram.insert(it, nou);
    } else {
        
        auto& llista = it->second; 
        auto pos = llista.begin();
        while (pos != llista.end() && *pos < p) {
            ++pos;
        }
        if (pos == llista.end() or *pos != p) llista.insert(pos, p); 
    }
}

//cost:O(m) on m es el nombre d'anagrames canònics en anagram
void anagrames::mateix_anagrama_canonic(const string& a, list<string>& L) const throw(error) {
	if(word_toolkit::es_canonic(a)){
		
		auto it = anagram.begin();
       		while (it != anagram.end() && it->first < a) {
           		++it;
        	}

        	if (it != anagram.end() && it->first == a) L = it->second;
	
	
	}
	else throw error(NoEsCanonic);
}

