#include "diccionari.hpp"

diccionari::diccionari() throw(error) {
   // _arrel = nullptr;
    //_paraules=0;

}

/* Tres grans. Constructor per copia, operador d'assignacio i destructor. */
diccionari::diccionari(const diccionari &D) throw(error) {

    //_arrel=copia_nodes(D._arrel);
    //_paraules=D._paraules;
}

diccionari &diccionari::operator=(const diccionari &D) throw(error) {
    //_arrel = copia_nodes(D._arrel);
    //_paraules=D._paraules;

   return *this;
}


diccionari::~diccionari() throw() {
   // esborra_nodes(_arrel);
}

/* Pre:  Cert
   Post: Afegeix la paraula p al diccionari; si la paraula p ja
   formava part del diccionari, l'operaci� no t� cap efecte. */
void diccionari::insereix(const string &p) throw(error) {
    if(busca(p)) return;

    else{
        if (_arrel == nullptr) {
            _arrel = new node;
            _arrel->_c = p[0];
            _arrel->_fe = _arrel->_fd = _arrel->_cen = nullptr;
        }

        node* actual = _arrel;
        int i = 0;

        while (i < p.size()) {
            char c = p[i];

            if (c < actual->_c) {
                if (actual->_fe == nullptr) {
                    actual->_fe = new node;
                    actual->_fe->_c = c;
                    actual->_fe->_fe = actual->_fe->_fd = actual->_fe->_cen = nullptr;
                }
                actual = actual->_fe;
            }
            else if (c > actual->_c) {
                if (actual->_fd == nullptr) {
                    actual->_fd = new node;
                    actual->_fd->_c = c;
                    actual->_fd->_fe = actual->_fd->_fd = actual->_fd->_cen = nullptr;
                }
                actual = actual->_fd;
            }
            else { // Si el caràcter coincideix...
                if (i == p.size() - 1) { // Si és l'últim caràcter.
                    if (actual->_cen == nullptr) {
                        actual->_cen = new node;
                        actual->_cen->_c = '#';
                        actual->_cen->_fe = actual->_cen->_fd = actual->_cen->_cen = nullptr;
                        _paraules++; // Incrementem només si afegim un final de paraula.
                    }
                    break;
                }
                else {
                    if (actual->_cen == nullptr) {
                        actual->_cen = new node;
                        actual->_cen->_c = p[i + 1];
                        actual->_cen->_fe = actual->_cen->_fd = actual->_cen->_cen = nullptr;
                    }
                    actual = actual->_cen;
                    i++;
                }
            }
        }

    }

}


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



/* void diccionari::esborra_nodes(node *t) {
   if (t != nullptr) {
      esborra_nodes(t->_fd);
      esborra_nodes(t->_fe);
      esborra_nodes(t->_cen) delete t;
   }
} */

/*node* diccionari::copia_nodes(const node* t) {

    if (t == nullptr) return nullptr; 

    // Creem un nou node amb la mateixa informació del node original.
    node* nou = new node;
    nou->_c = t->_c;
    nou->_fd = copia_nodes(t->_fd); // Copiem el fill dret.
    nou->_fe = copia_nodes(t->_fe); // Copiem el fill esquerre.
    nou->_cen = copia_nodes(t->_cen); // Copiem el fill central.

    return nou; 
}
*/

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