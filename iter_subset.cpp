#include "iter_subset.hpp"

// Métodes auxiliars de la part privada
void iter_subset::initialize_first_subset() {
    current_subset.clear();
    for (nat i = 1; i <= _k; ++i) {
        current_subset.push_back(i);
    }
    is_end = (_k > _n); // Si k > n, no hay subconjuntos posibles
}

bool iter_subset::generate_next_subset() {
    if (is_end) return false; // Ya se ha alcanzado el final

    // Encuentra la posición más a la derecha que pueda incrementarse
    int i = _k - 1;
    while (i >= 0 && current_subset[i] == _n - _k + i + 1) {
        --i;
    }

    if (i < 0) {
        is_end = true; // No quedan más subconjuntos
        return false;
    }

    // Incrementa el elemento en la posición encontrada
    ++current_subset[i];

    // Ajusta los elementos posteriores para mantener el orden lexicográfico
    for (nat j = i + 1; j < _k; ++j) {
        current_subset[j] = current_subset[j - 1] + 1;
    }

    return true;
}

// Métodes de la part pública

/* Pre:  Cert
    Post: Construeix un iterador sobre els subconjunts de k elements
    de {1, ..., n}; si k > n no hi ha res a recórrer. */
iter_subset::iter_subset(nat n, nat k) throw(error) : _n(n), _k(k), is_end(false) {
    if (k > n) is_end = true;   // Si k > n, no hi ha subconjunts possibles
    else initialize_first_subset(); // Inicialitza el primer subconjunt
}

/* Tres grans. Constructor per còpia. */
iter_subset::iter_subset(const iter_subset& its) throw(error) {
    this->_n = its._n;
    this->_k = its._k;
    this->current_subset = its.current_subset;
    this->is_end = its.is_end;
}

/* Tres grans. Operador d'assignació. */
iter_subset &iter_subset::operator=(const iter_subset& its) throw(error) {
    if(this != &its) {
        _n = its._n;
        _k = its._k;
        current_subset = its.current_subset;
        is_end = its.is_end;
    }

    return *this;
}

/* Tres grans. Destructor. */
iter_subset::~iter_subset() throw() {

}

/*  Pre:  Cert
    Post: Retorna cert si l'iterador ja ha visitat tots els subconjunts
    de k elements presos d'entre n; o dit d'una altra forma, retorna
    cert quan l'iterador apunta a un subconjunt sentinella fictici
    que queda a continuació de l'últim subconjunt vàlid. */
bool iter_subset::end() const throw() {
    return is_end;
}

/*  Operador de desreferència.
    Pre:  Cert
    Post: Retorna el subconjunt apuntat per l'iterador;
    llança un error si l'iterador apunta al sentinella. */
subset iter_subset::operator*() const throw(error) {
    if(is_end) throw error(IterSubsetIncorr);
    return current_subset;
}

iter_subset &iter_subset::operator++() throw() {
    if (!is_end) {
        generate_next_subset(); // Genera el siguiente subconjunto
        if (current_subset.empty()) {
            // Si no hay más subconjuntos, establece el iterador en el estado final
            is_end = true;
        }
    }
    return *this;
}

iter_subset iter_subset::operator++(int) throw() {
    iter_subset temp = *this; // Crea una copia del iterador actual
    ++(*this);               // Utiliza el preincremento para avanzar al siguiente subconjunto
    return temp;             // Devuelve la copia que contiene el estado previo
}

bool iter_subset::operator==(const iter_subset& other) const throw() {
    return is_end == other.is_end && current_subset == other.current_subset && _n == other._n && _k == other._k;
}

bool iter_subset::operator!=(const iter_subset& other) const throw() {
    return !(*this == other);
}
