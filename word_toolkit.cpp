#include "word_toolkit.hpp"
#include <algorithm>

/**
 *  Pre: Cert
 *  Post: Retorna true si les lletres de l'string s
 *        estan en ordre lexicogràfic ascendent. Altrament,
 *        retorna false.
 *  Cost: O(n)
 */
bool word_toolkit::es_canonic(const string& s) throw() {
    
    for(int i = 1; i < (int)s.size(); ++i) {
        if(s[i] < s[i - 1]) return false;
    }

    return true;
}

/*  Pre: Cert
 *  Post: Retorna l'anagrama canònic del string s.
 *  Cost: O(n log n)
 */
string word_toolkit::anagrama_canonic(const string& s) throw() {
    string res = s;
    sort(res.begin(), res.end());
    return res;
}

/*  Pre: L és una llista no buida de paraules formades exclusivament
 *  amb lletres majúscules de la 'A' a la 'Z' (excloses la 'Ñ', 'Ç',
 *  majúscules accentuades, ...). 
 *  Post: Retorna el caràcter que no apareix a l'string excl i és
 *  el més freqüent en la llista de paraules L.
 *  En cas d'empat, es retorna el caràcter alfabèticament menor.
 *  Si l'string excl inclou totes les lletres de la 'A' a la 'Z' es 
 *  retorna el caràcter '\0', és a dir, el caràcter de codi ASCII 0.
 *  Cost:  O(m + n * k) on m es la mida de excl, n és nombre de paraules 
 *         a la llista L i k es la mida promig de les paraules de la llista L
 */
char word_toolkit::mes_frequent(const string& excl, const list<string>& L) throw() {
    int freq[26] = {0};

    for(int i = 0; i < (int)excl.size(); ++i) {
        char c = excl[i];

        if(c >= 'A' && c <= 'Z') freq[c - 'A'] = -1;
    }

    for(list<string>::const_iterator it = L.begin(); it != L.end(); ++it) {
        const string paraula = *it;
        for(int i = 0; i < (int)paraula.size(); ++i) {
            char c = paraula[i];

            if(c >= 'A' && c <= 'Z' && freq[c - 'A'] != -1) freq[c - 'A']++;
        }
    }

    char resultat = '\0';
    int max_freq = 0;
    for(int i = 0; i < 26; ++i) {
        
        if(freq[i] > max_freq) {
            max_freq = freq[i];
            resultat = 'A' + i;
        }
        else if(freq[i] == max_freq and max_freq > 0) {
            if (resultat == '\0' || 'A' + i < resultat) resultat = 'A' + i;
        }
    }

    return resultat;
}
