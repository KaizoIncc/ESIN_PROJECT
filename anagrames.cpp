#include "anagrames.hpp"
#include "word_toolkit.hpp"

anagrames::anagrames() throw(error) {

}

anagrames::anagrames(const anagrames& A) throw(error) {
   anagram = A.anagram;
    
}

anagrames::~anagrames() throw() {

}

anagrames& anagrames::operator=(const anagrames& A) throw(error) {
    return *this;
}

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
