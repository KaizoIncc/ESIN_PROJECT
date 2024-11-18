#include "word_toolkit.hpp"

/*  Pre:  Cert 
    Post: Retorna cert si i només si les lletres de l'string s estan 
    en ordre lexicogràfic ascendent. */
bool word_toolkit::es_canonic(const string& s) throw() {
    
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] < s[i - 1]) return false;
    }

    return true;
}

