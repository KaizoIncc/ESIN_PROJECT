#include "iter_subset.hpp"

// Métodes auxiliars de la part privada

//  PRE: Cert
//  POST: Inicialitza el primer subconjunt de k elements de {1, ..., n}
//        Si k > n, el subconjunt és buit.
//  Cost: O(k) per inicialitzar el subconjunt.
void iter_subset::initialize_first_subset() {
    current_subset.clear();
    for (nat i = 1; i <= _k; ++i) {
        current_subset.push_back(i);
    }
    is_end = (_k > _n);
}

//  PRE: Cert
//  POST: Genera el següent subconjunt lexicogràfic de k elements de {1, ..., n}.
//        Retorna fals si s'ha arribat al final (no queden més subconjunts).
//  Cost: O(k) en el pitjor cas, quan hem de reajustar tots els elements després de la posició incrementada.
bool iter_subset::generate_next_subset() {
    if (is_end) return false;

    int i = _k - 1;
    while (i >= 0 && current_subset[i] == _n - _k + i + 1) {
        --i;
    }

    if (i < 0) {
        is_end = true;
        return false;
    }

    ++current_subset[i];

    for (nat j = i + 1; j < _k; ++j) {
        current_subset[j] = current_subset[j - 1] + 1;
    }

    return true;
}

// Métodes de la part pública

//  PRE: Cert
//  POST: Construeix un iterador sobre els subconjunts de k elements
//        de {1, ..., n}; si k > n no hi ha res a recórrer. 
//  Cost: O(k) per inicialitzar el primer subconjunt.
iter_subset::iter_subset(nat n, nat k) throw(error) : _n(n), _k(k), is_end(false) {
    if (k > n) is_end = true;
    else initialize_first_subset();
}

//  PRE: Cert
//  POST: Crea una còpia de l'iterador iter_subset.
//  Cost: O(k) per copiar el subconjunt actual.
iter_subset::iter_subset(const iter_subset& its) throw(error) {
    this->_n = its._n;
    this->_k = its._k;
    this->current_subset = its.current_subset;
    this->is_end = its.is_end;
}

//  PRE: Cert
//  POST: Assigna el contingut de l'iterador other a l'iterador actual.
//  Cost: O(k) per copiar el subconjunt actual.
iter_subset &iter_subset::operator=(const iter_subset& its) throw(error) {
    if(this != &its) {
        _n = its._n;
        _k = its._k;
        current_subset = its.current_subset;
        is_end = its.is_end;
    }

    return *this;
}

//  PRE: Cert
//  POST: Destrueix l'iterador iter_subset.
//  Cost: O(1).
iter_subset::~iter_subset() throw() {

}

//  PRE: Cert
//  POST: Retorna cert si l'iterador ja ha visitat tots els subconjunts
//        de k elements presos d'entre n; retorna fals si encara queden subconjunts.
//  Cost: O(1).
bool iter_subset::end() const throw() {
    return is_end;
}

//  PRE: Cert
//  POST: Retorna el subconjunt apuntat per l'iterador;
//          llança un error si l'iterador apunta al sentinella. 
//  Cost: O(k) per copiar el subconjunt.
subset iter_subset::operator*() const throw(error) {
    if(is_end) throw error(IterSubsetIncorr);
    return current_subset;
}

//  PRE: Cert
//  POST: Avança l'iterador a la següent posició del conjunt;
//        si s'arriba al final, l'iterador entra en el mode final.
//  Cost: O(k).
iter_subset &iter_subset::operator++() throw() {
    if (!is_end) {
        generate_next_subset();
        if (current_subset.empty()) is_end = true;
    }
    return *this;
}

//  PRE: Cert
//  POST: Retorna una còpia de l'iterador abans de l'increment. 
//  Cost: O(k).
iter_subset iter_subset::operator++(int) throw() {
    iter_subset temp = *this;
    ++(*this);
    return temp;
}

//  PRE: Cert
//  POST: Compara si dos iteradors apunten a la mateixa posició.
//        Retorna cert si són iguals, fals altrament.
//  Cost: O(k).
bool iter_subset::operator==(const iter_subset& other) const throw() {
    if (_k == 0 && other._k == 0) return is_end == other.is_end;

    if (_n != other._n || _k != other._k) return false;
    
    if (is_end != other.is_end) return false;

    return current_subset == other.current_subset;
}

//  PRE: Cert
//  POST: Retorna cert si els iteradors no són iguals.
//  Cost: O(k).
bool iter_subset::operator!=(const iter_subset& other) const throw() {
    return !(*this == other);
}
