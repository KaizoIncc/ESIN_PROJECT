#include "diccionari.hpp"

/* FUNCIONS PUBLIQUES */

// Constructor
diccionari::diccionari() throw(error) {
    _arrel = new TrieNode();
}

// Destructor
diccionari::~diccionari() throw() {
    deleteTrie(_arrel);
}

// Constructor por copia
diccionari::diccionari(const diccionari& D) throw(error) {
    // Copiamos el Trie
    _arrel = copyTrie(D._arrel);
}

// Operador de asignación
diccionari& diccionari::operator=(const diccionari& D) throw(error) {
    if (this != &D) {  // Comprobamos que no estamos asignando el mismo objeto
        // Liberamos la memoria del diccionario actual
        deleteTrie(_arrel);
        // Copiamos la nueva información
        _arrel = copyTrie(D._arrel);
    }
    return *this;
}

// Inserción de una palabra
void diccionari::insereix(const string& p) throw(error) {
    TrieNode* node = _arrel;

    for (size_t i = 0; i < p.length(); ++i) {
        char c = p[i];
        if (node->_children[c - 'a'] == nullptr) node->_children[c - 'a'] = new TrieNode();
        node = node->_children[c - 'a'];
    }

    if (!node->isEndOfWord) node->isEndOfWord = true; // Only mark if it's not already marked
}


// Buscar el prefijo más largo
string diccionari::prefix(const string& p) const throw(error) {
    TrieNode* node = _arrel;
    string longestPrefix;
    string currentPrefix;

    for (size_t i = 0; i < p.length(); ++i) {
        char c = p[i];
        if (node->_children[c - 'a'] == nullptr) break;

        node = node->_children[c - 'a'];
        currentPrefix += c;

        if (node->isEndOfWord) longestPrefix = currentPrefix;
    }

    return longestPrefix;
}

// Función de patrón
void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {
    satisfan_patroRecursive(_arrel, q, 0, "", L);
}

// Lista de palabras de longitud >= k
void diccionari::llista_paraules(unsigned int k, list<string>& L) const throw(error) {
    llista_paraulesRecursive(_arrel, k, "", L);
}

// Número de palabras
nat diccionari::num_pal() const throw() {
    return countWords(_arrel);
}

/* FUNCIONS PRIVADES */

// Contar las palabras
nat diccionari::countWords(TrieNode* node) const throw() {
    nat count = 0;
    if (node->isEndOfWord) count++;
    for (int i = 0; i < 26; i++) {
        if (node->_children[i] != nullptr) count += countWords(node->_children[i]);
    }
    return count;
}

// Recursiva para buscar palabras que coincidan con el patrón
void diccionari::satisfan_patroRecursive(TrieNode* node, const vector<string>& q, size_t index, string current, list<string>& L) const throw() {
    if (index == q.size()) {
        if (node->isEndOfWord) L.push_back(current);
        return;
    }

    string pattern = q[index];
    for (char c : pattern) {
        int idx = c - 'A';
        if (node->_children[idx] != nullptr) satisfan_patroRecursive(node->_children[idx], q, index + 1, current + c, L);
    }
}

// Recursiva para encontrar palabras de longitud >= k
void diccionari::llista_paraulesRecursive(TrieNode* node, nat k, string current, list<string>& L) const throw() {
    if (current.size() >= k && node->isEndOfWord) L.push_back(current);
    for (int i = 0; i < 26; i++) {
        if (node->_children[i] != nullptr) llista_paraulesRecursive(node->_children[i], k, current + char('A' + i), L);
    }
}

typename diccionari::TrieNode* diccionari::copyTrie(TrieNode* node) const {
    if (node == nullptr) return nullptr;

    TrieNode* newNode = new TrieNode();
    newNode->isEndOfWord = node->isEndOfWord;
    for (int i = 0; i < 26; ++i) {
        if (node->_children[i] != nullptr) newNode->_children[i] = copyTrie(node->_children[i]);
    }
    return newNode;
}

void diccionari::deleteTrie(TrieNode* node) {
    if (node == nullptr) return;
    for (int i = 0; i < 26; ++i) {
        if (node->_children[i] != nullptr) deleteTrie(node->_children[i]);
    }
    delete node;
}