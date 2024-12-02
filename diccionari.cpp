#include "diccionari.hpp"

diccionari::diccionari() throw(error) {
   // _arrel = nullptr;
}

/* Tres grans. Constructor per copia, operador d'assignacio i destructor. */
diccionari::diccionari(const diccionari &D) throw(error) {
}

diccionari &diccionari::operator=(const diccionari &D) throw(error) {
   return *this;
}

/* void diccionari::esborra_nodes(node *t) {
   if (t != nullptr) {
      esborra_nodes(t->_fd);
      esborra_nodes(t->_fe);
      esborra_nodes(t->_cen) delete t;
   }
} */

diccionari::~diccionari() throw() {
   // esborra_nodes(_arrel);
}

/* Pre:  Cert
   Post: Afegeix la paraula p al diccionari; si la paraula p ja
   formava part del diccionari, l'operaci� no t� cap efecte. */
void diccionari::insereix(const string &p) throw(error) {
    if(busca(p)) return;
    else{


    }

}

// Pre:p no es buit
// Post:retorna true si p esta dins el diccionari, false al contrari
/* bool diccionari::busca(node* n, string p) { 
   node n = _arrel;
   int i = 0;

   while (p != nullptr) {
      char c = p[i];
      if( c < n->_c ) n=n->_fe;
      else if(c > n->_c) n=n->_fd;
      else{
        if(i==p.size()-1){
            return n->_c=='#';
        }
        else{
            n=n->_cen;
            i++;
        }

      }
   }
} */

/* Pre:  Cert
   Post: Retorna el prefix m�s llarg de p que �s una paraula que
   pertany al diccionari, o dit d'una forma m�s precisa, retorna la
   paraula m�s llarga del diccionari que �s prefix de p. */
string diccionari::prefix(const string &p) const throw(error) {
   return "alo";
}

/* Pre:  Cert
   Post: Retorna la llista de paraules del diccionari que satisfan
   el patr� especificat en el vector d'strings q, en ordre
   alfab�tic ascendent. */
void diccionari::satisfan_patro(const vector<string> &q, list<string> &L) const throw(error) {

}

/* Pre:  Cert
   Post: Retorna una llista amb totes les paraules del diccionari
   de longitud major o igual a k en ordre alfab�tic ascendent. */
void diccionari::llista_paraules(nat k, list<string> &L) const throw(error) {

}

/* Pre:  Cert
   Post: Retorna el nombre de paraules en el diccionari. */
nat diccionari::num_pal() const throw() {
   return _paraules;
}