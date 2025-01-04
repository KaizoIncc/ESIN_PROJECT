#include "anagrames.hpp"

/* FUNCIONS PUBLIQUES */

// Constructor per defecte
anagrames::anagrames() throw(error) : diccionari() {}

// Constructor per còpia
anagrames::anagrames(const anagrames& A) throw(error) : diccionari(A), grups(A.grups) {}

// Destructor
anagrames::~anagrames() throw() {
    grups.clear(); // Allibera els grups d'anagrames
}

// Operador d'assignació
anagrames& anagrames::operator=(const anagrames& A) throw(error) {
    if (this != &A) { // Evitem l'autoassignació
        diccionari::operator=(A); // Assignem la part base
        grups = A.grups;          // Copiem els grups d'anagrames
    }
    return *this;
}

void anagrames::insereix(const string& p) throw(error) {
    diccionari::insereix(p);
    string canonic = anagrama_canonic(p);
    GrupAnagrames* grup = busca_grup(canonic);
    if (grup) grup->paraules.push_back(p);
    else {
        GrupAnagrames nouGrup;
        nouGrup.canonic = canonic;
        nouGrup.paraules.push_back(p);
        grups.push_back(nouGrup);
    }
}

void anagrames::mateix_anagrama_canonic(const string& a, list<string>& L) const throw(error) {
    L.clear(); // Assegura que la llista passada està buida abans d'afegir elements
    for (const auto& grup : grups) {
        if (grup.canonic == a) {
            L.insert(L.end(), grup.paraules.begin(), grup.paraules.end());
            return;
        }
    }
}

/* FUNCIONS PRIVADES */

// Genera l'anagrama canònic d'una paraula
string anagrames::anagrama_canonic(const string& paraula) const {
    string ordenat = paraula;
    ordena_string(ordenat);
    return ordenat;
}

// Cerca el grup d'anagrames pel canònic
typename anagrames::GrupAnagrames* anagrames::busca_grup(const string& canonic) {
    for (auto& grup : grups) {
        if (grup.canonic == canonic) return &grup;
    }
    return nullptr;
}

// Ordena un string de manera alfabètica
void anagrames::ordena_string(string& s) const {
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = 0; j < s.size() - i - 1; ++j) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}