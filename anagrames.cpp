#include "anagrames.hpp"
#include "word_toolkit.hpp"

//  PRE: No s'especifica cap condició prèvia, ja que inicialitza l'objecte.
//  POST: L'objecte 'anagrames' es crea sense elements dins.
//cost:O(1)
anagrames::anagrames() throw(error) {

}

//  PRE: L'objecte A ha de ser un objecte vàlid de la classe 'anagrames'.
//  POST: Es crea una nova instància de 'anagrames' amb els mateixos elements que l'objecte A.
//O(n), on n és el nombre d'elements dins de la llista anagram
anagrames::anagrames(const anagrames& A) throw(error) {
   anagram = A.anagram;    
}

//  PRE: L'objecte 'anagrames' existeix.
//  POST: L'objecte 'anagrames' es destruye i allibera els recursos associats.
//cost:O(1)
anagrames::~anagrames() throw() {

}

//  PRE: L'objecte A ha de ser un objecte vàlid de la classe 'anagrames'.
//  POST: Els elements de l'objecte 'anagrames' s'assignen a l'objecte de destí, 
//        substituint els elements previs si no és el mateix objecte.
//cost:O(1)
anagrames& anagrames::operator=(const anagrames& A) throw(error) {
    if (this != &A) anagram = A.anagram;  
    return *this;
}

//  PRE: La cadena 'p' és vàlida i no buida. La funció 'anagrama_canonic' de 'word_toolkit' ha de ser accessible.
//  POST: La paraula 'p' s'afegeix a la llista corresponent dins de 'anagram' segons el seu anagrama canònic. 
//        Si l'anagrama canònic no existeix, es crea una nova entrada.
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

//  PRE: La cadena 'a' és vàlida. Si 'a' és un anagrama canònic, es realitzarà la cerca, en cas contrari es llança un error.
//  POST: La llista 'L' conté totes les paraules associades a l'anagrama canònic de 'a', o es llança una excepció si 'a' no és canònic.
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

