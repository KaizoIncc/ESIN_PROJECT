#include "diccionari.hpp"

using namespace std;

// Constructor per defecte
// PRE: Cert
// POST: Es crea un diccionari buit amb una arrel inicialitzada.
// COSTE: O(1)
diccionari::diccionari() throw(error) {
    _arrel = new TrieNode{'\0', nullptr, nullptr, nullptr};
}

// Constructor per còpia
// PRE: Cert
// POST: El diccionari actual és una còpia exacta del diccionari D.
// COSTE: O(n), on n és el nombre de nodes del diccionari D.
diccionari::diccionari(const diccionari& D) throw(error) {
    _arrel = copia(D._arrel);
}

// Operador d'assignació
// PRE: Cert
// POST: El diccionari actual és una còpia exacta del diccionari D.
// COSTE: O(n), on n és el nombre de nodes del diccionari D.
diccionari& diccionari::operator=(const diccionari& D) throw(error) {
    if (this != &D) {
        allibera(_arrel);
        _arrel = copia(D._arrel);
    }
    return *this;
}

// Destructor
// PRE: Cert
// POST: Allibera tota la memòria ocupada pel diccionari.
// COSTE: O(n), on n és el nombre de nodes del diccionari.
diccionari::~diccionari() throw() {
    allibera(_arrel);
}

// Mètode per inserir una paraula
// PRE: p.size() > 0
// POST: La paraula p ha estat afegida al diccionari. Si ja existia, el diccionari no canvia.
// COSTE: O(m), on m és la longitud de la paraula p.
void diccionari::insereix(const string& p) throw(error) {
    
    TrieNode* actual = _arrel;
    
    for (size_t i = 0; i < p.size(); ++i) {
        char c = p[i];
        TrieNode* anterior = nullptr;
        
        while (actual && actual->_c != c) {
            anterior = actual;
        
            if (c < actual->_c) {
                if (!actual->_esq) actual->_esq = new TrieNode{c, nullptr, nullptr, nullptr};
                actual = actual->_esq;
            } else {
                if (!actual->_dre) actual->_dre = new TrieNode{c, nullptr, nullptr, nullptr};
                actual = actual->_dre;
            }
        }
        
        if (!actual) {
            if (anterior && c < anterior->_c) {
                anterior->_esq = new TrieNode{c, nullptr, nullptr, nullptr};
                actual = anterior->_esq;
            } else if (anterior) {
                anterior->_dre = new TrieNode{c, nullptr, nullptr, nullptr};
                actual = anterior->_dre;
            }
        }

        if (!actual->_cen) actual->_cen = new TrieNode{'\0', nullptr, nullptr, nullptr};
        actual = actual->_cen;
    }

    if (!actual->_cen) actual->_cen = new TrieNode{'#', nullptr, nullptr, nullptr};
    ++_paraules;
}

// Mètode per obtenir el prefix més llarg
// PRE: Cert
// POST: Retorna el prefix més llarg de p que es troba al diccionari. Si cap prefix és trobat, retorna "".
// COSTE: O(m), on m és la longitud de la paraula p.
string diccionari::prefix(const string& p) const throw(error) {
    TrieNode* actual = _arrel;
    string resultat;
    string millor_prefix;

    for (size_t i = 0; i < p.size(); ++i) {
        char c = p[i];
        
        while (actual && actual->_c != c) {
            actual = (c < actual->_c) ? actual->_esq : actual->_dre;
        }
        
        if (!actual) break;
        
        resultat += c;
        
        if (actual->_cen && actual->_cen->_c == '\0') millor_prefix = resultat;
        
        actual = actual->_cen;
    }

    return millor_prefix.empty() ? "" : millor_prefix;
}

// Mètode per obtenir paraules que satisfan un patró
// PRE: q.size() > 0
// POST: La llista L conté totes les paraules que compleixen el patró q.
// COSTE: O(n + m * k), on n és el nombre de nodes del Trie, m és la mida de L i k és la longitud màxima de les paraules a la llista.
void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
    
    llista_paraules(q.size(), L);

    for (auto it = L.begin(); it != L.end(); ) {
        if (it->size() != q.size() + 1) it = L.erase(it);
        else ++it;
    }

    for (auto it = L.begin(); it != L.end(); ) {
        bool compleix = true;

        for (size_t i = 0; i < q.size(); ++i) {
            
            if (q[i] == "*") continue;
            else if (q[i].find((*it)[i]) == string::npos) {
                compleix = false;
                break;
            }
        }

        if (!compleix) it = L.erase(it);
        else ++it;
    }

    L.sort();
}

// Mètode per obtenir paraules amb longitud >= k
// PRE: k > 0
// POST: La llista L conté totes les paraules del diccionari amb longitud >= k.
// COSTE: O(n), on n és el nombre de nodes del Trie.
void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {
    L.clear();
    string paraula_actual;
    obtindre_paraules(_arrel, paraula_actual, k, L);
}

// Mètode per obtenir el nombre de paraules
// PRE: Cert
// POST: Retorna el nombre total de paraules emmagatzemades al diccionari.
// COSTE: O(1)
nat diccionari::num_pal() const throw() {
    return _paraules;
}

// Funció recursiva per copiar el Trie
// PRE: node és un punter a un subarbre vàlid o nullptr.
// POST: Retorna una còpia exacta del subarbre apuntat per node. Si node == nullptr, retorna nullptr.
// COST: O(n), on n és el nombre de nodes en el subarbre apuntat per node.
typename diccionari::TrieNode* diccionari::copia(TrieNode* node) {

    if (!node) return nullptr;
    
    TrieNode* nou_node = new TrieNode{node->_c, nullptr, nullptr, nullptr};
    
    nou_node->_esq = copia(node->_esq);
    nou_node->_cen = copia(node->_cen);
    nou_node->_dre = copia(node->_dre);
    
    return nou_node;
}

// Funció recursiva per alliberar memòria
// PRE: node és un punter a un subarbre vàlid o nullptr.
// POST: Allibera tota la memòria associada al subarbre apuntat per node. Si node == nullptr, no fa res.
// COST: O(n), on n és el nombre de nodes en el subarbre apuntat per node.
void diccionari::allibera(TrieNode* node) {

    if (!node) return;

    allibera(node->_esq);
    allibera(node->_cen);
    allibera(node->_dre);
    
    delete node;
}

// Funció recursiva per obtenir paraules amb longitud >= k
// PRE: node és un punter a un subarbre vàlid o nullptr. k >= 0.
// POST: Afegeix a L totes les paraules del subarbre apuntat per node amb longitud >= k.
// COST: O(n), on n és el nombre de nodes en el subarbre apuntat per node.
void diccionari::obtindre_paraules(TrieNode* node, string& actual, nat k, list<string>& L) const {

    if (!node) return;
    obtindre_paraules(node->_esq, actual, k, L);

    actual.push_back(node->_c);
    if (node->_c == '#' && actual.size() - 1 >= k) L.push_back(actual.substr(0, actual.size() - 1));

    obtindre_paraules(node->_cen, actual, k, L);
    actual.pop_back();

    obtindre_paraules(node->_dre, actual, k, L);
}
