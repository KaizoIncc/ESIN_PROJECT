#include "diccionari.hpp"

diccionari::diccionari() throw(error) {

}

/* Tres grans. Constructor per c�pia, operador d'assignaci� i destructor. */
diccionari::diccionari(const diccionari& D) throw(error) {

}

diccionari& diccionari::operator=(const diccionari& D) throw(error) {
    return *this;
}

diccionari::~diccionari() throw() {

}

/* Pre:  Cert
   Post: Afegeix la paraula p al diccionari; si la paraula p ja
   formava part del diccionari, l'operaci� no t� cap efecte. */
void diccionari::insereix(const string& p) throw(error) {

}

/* Pre:  Cert
   Post: Retorna el prefix m�s llarg de p que �s una paraula que
   pertany al diccionari, o dit d'una forma m�s precisa, retorna la
   paraula m�s llarga del diccionari que �s prefix de p. */
string diccionari::prefix(const string& p) const throw(error) {
    return "alo";
}

/* Pre:  Cert
   Post: Retorna la llista de paraules del diccionari que satisfan
   el patr� especificat en el vector d'strings q, en ordre
   alfab�tic ascendent. */
void diccionari::satisfan_patro(const vector<string>& q, list<string>& L) const throw(error) {

}

/* Pre:  Cert
   Post: Retorna una llista amb totes les paraules del diccionari
   de longitud major o igual a k en ordre alfab�tic ascendent. */
void diccionari::llista_paraules(nat k, list<string>& L) const throw(error) {

}

/* Pre:  Cert
   Post: Retorna el nombre de paraules en el diccionari. */
nat diccionari::num_pal() const throw() {
    return _paraules;
}