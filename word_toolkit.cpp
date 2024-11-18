#include "word_toolkit.hpp"

/**
 * Pre: Cert
 * Post: @return true si les lletres de l'string s
 *       estan en ordre lexicogràfic ascendent. Altrament,
 *       @return false 
 */
bool word_toolkit::es_canonic(const string& s) throw() {
    
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] < s[i - 1]) return false;
    }

    return true;
}

/**
 * Pre: Cert
 * Post: @return l'anagrama canònic del string s.
 */
string word_toolkit::anagrama_canonic(const string& s) throw() {
    string res = s;
    sort(res.begin(), res.end());
    return res;
}

/** Pre: L és una llista no buida de paraules formades exclusivament
 *  amb lletres majúscules de la 'A' a la 'Z' (excloses la 'Ñ', 'Ç',
 *  majúscules accentuades, ...). 
 *  Post: @return el caràcter que no apareix a l'string excl i és
 *  el més freqüent en la llista de paraules L.
 *  En cas d'empat, es retornaria el caràcter alfabèticament menor.
 *  Si l'string excl inclou totes les lletres de la 'A' a la 'Z' es 
 *  retorna el caràcter '\0', és a dir, el caràcter de codi ASCII 0. */
char word_toolkit::mes_frequent(const string& excl, const list<string>& L) throw() {

}