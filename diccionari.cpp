#include "diccionari.hpp"

using namespace std;

// Constructor per defecte
// COST: O(1)
diccionari::diccionari() throw(error) {
    _arrel = new TrieNode{'\0', nullptr, nullptr, nullptr};
    _paraules=0;
}

// Constructor per còpia
// COST: O(n), on n és el nombre de nodes del diccionari D.
diccionari::diccionari(const diccionari& D) throw(error) {
    _arrel = copia(D._arrel);
    _paraules=D._paraules;
}

// Operador d'assignació
// COST: O(n), on n és el nombre de nodes del diccionari D.
diccionari& diccionari::operator=(const diccionari& D) throw(error) {
    if (this != &D) {
        allibera(_arrel);
        _arrel = copia(D._arrel);
        _paraules=D._paraules;
    }
    return *this;
}

// Destructor
// COST: O(n), on n és el nombre de nodes del diccionari.
diccionari::~diccionari() throw() {
    allibera(_arrel);
    _paraules=0;
}

// Mètode per inserir una paraula
// COST: O(m), on m és la longitud de la paraula p.
void diccionari::insereix(const string& p) throw(error) {
    string paraula = p;
    paraula += '#';
    _arrel = insereix(_arrel, paraula, 0);
}


// Mètode per obtenir el prefix més llarg
// COST: O(m), on m és la longitud de la paraula p.
string diccionari::prefix(const string& p) const throw(error) {
    
    TrieNode* actual = _arrel;
    string resultat;
    string millor_prefix;

    for (size_t i = 0; i < p.size(); ++i) {
        char c = p[i];

        while (actual && actual->_c != c) {
            actual = (c < actual->_c) ? actual->_esq : actual->_dre;
        }

        if (!actual) {
            actual = nullptr;
            i = p.size();
        } 
        else {
            resultat += c;

            TrieNode* temp = actual->_cen;
            bool found = false;
            while (temp && !found) {
                if (temp->_c == '#') {
                    millor_prefix = resultat;
                    found = true;
                } 
                else temp = temp->_esq;
            }

            actual = actual->_cen;
        }
    }

    return millor_prefix.empty() ? "" : millor_prefix;
}


// Mètode per obtenir paraules que satisfan un patró
// COST: O(n + m * k), on n és el nombre de nodes del Trie, m és la mida de L i k és la longitud màxima de les paraules a la llista.
void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
    
    llista_paraules(q.size(), L);

    for (auto it = L.begin(); it != L.end(); ) {
        if (it->size() != q.size()) it = L.erase(it);
        else ++it;
    }

    for (auto it = L.begin(); it != L.end(); ) {
        bool compleix = true;

        for (size_t i = 0; i < q.size() && compleix; ++i) {
            if (q[i] != "*" && q[i].find((*it)[i]) == string::npos) compleix = false;
        }

        if (!compleix) it = L.erase(it);
        else ++it;
    }
}

// Mètode per obtenir paraules amb longitud >= k
// COST: O(n), on n és el nombre de nodes del Trie.
void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {
    L.clear();
    string paraula_actual;
    obtindre_paraules(_arrel, paraula_actual, k, L);
}

// Mètode per obtenir el nombre de paraules
// COST: O(1)
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

// Funció recursiva per inserir una paraula `p` a un arbre.
// PRE: 0 <= i < p.size(), node és l'arrel d'un subarbre vàlid o nullptr
// POST: Insereix el sufix p[i:] al trie representat per node i retorna l'arrel de l'arbre actualitzat
// COST: O(n), on n = p.size(), en el pitjor cas
typename diccionari::TrieNode* diccionari::insereix(TrieNode* node, const string& p, nat i) {
    
    if(!node) {
        node = new TrieNode{p[i], nullptr, nullptr, nullptr};
        if(i < p.size() - 1) node->_cen = insereix(node->_cen, p, i + 1);
    }
    else {
        if(node->_c > p[i]) node->_esq = insereix(node->_esq, p, i);
        else if(node->_c < p[i]) node->_dre = insereix(node->_dre, p, i);
        else node->_cen = insereix(node->_cen, p, i + 1);
    }

    return node;
}