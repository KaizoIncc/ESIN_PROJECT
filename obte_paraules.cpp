#include "obte_paraules.hpp"
#include "iter_subset.hpp"
#include "word_toolkit.hpp"

/* Pre:  Cert
    Post: Retorna la llista de paraules que es poden formar usant k lletres
    de la paraula s. Llança error si k és major que la longitud de
    l'string s o k < 3. */

//cost:O(s.size()^k * (k + n + m)) on n és el nombre d'anagrame, m és la mida de la llista paraules.
void obte_paraules::obte_paraules(nat k, const string& s, const anagrames& A, list<string>& paraules) throw(error) {
    
    if (k < 3 || k > s.size()) throw error(LongitudInvalida);

    iter_subset it(s.size(), k);

    string canonic = word_toolkit::anagrama_canonic(s);

    while (!it.end()) {
        subset comb = *it;  
        string combinacio = ""; 
        
        for (nat i = 0; i < comb.size(); ++i) {
            nat idx = comb[i];
            combinacio += canonic[idx - 1];  
        }

        list<string> possibles;
        A.mateix_anagrama_canonic(combinacio, possibles);

        for (list<string>::iterator it_pos = possibles.begin(); it_pos != possibles.end(); ++it_pos) {
            const string& paraula = *it_pos;
            auto pos = paraules.begin();
            while (pos != paraules.end() && *pos < paraula) {
                ++pos;  
            }

            if (pos == paraules.end() || *pos != paraula) {
                paraules.insert(pos, paraula);  
            }
        }

        ++it;  
    }
}


/* Pre:  Cert
    Post: Retorna la llista de paraules que es poden formar usant 3 o més lletres
    de la paraula s. La llista estarà ordenada de menys a més longitud; 
    a igual longitud les paraules estan en ordre alfabètic creixent. 
    Llança un error si l'string s té menys de tres lletres. */

//cost:O(s.size()^3 * (3 + n + m)) 
void obte_paraules::obte_paraules(const string& s, const anagrames& A, list<string>& paraules) throw(error) {
   
    if (s.size() < 3) throw error(LongitudInvalida);

    for (nat k = 3; k <= s.size(); ++k) {
        list<string> temp;
        obte_paraules(k, s, A, temp); 

        for (list<string>::iterator it = temp.begin(); it != temp.end(); ++it) {
            const string& paraula = *it;

            auto pos = paraules.begin();
            while (pos != paraules.end() && (*pos).size() < paraula.size()) {
                ++pos;  
            }

            while (pos != paraules.end() && (*pos).size() == paraula.size() && *pos < paraula) {
                ++pos;
            }

            if (pos == paraules.end() || *pos != paraula) {
                paraules.insert(pos, paraula);  
            }
        }
    }
}
