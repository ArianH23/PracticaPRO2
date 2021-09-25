/** @file Inventario.cc
    @brief Código de la clase Inventario 
*/

#include "Inventario.hh"

Inventario::Inventario (){}

Inventario::~Inventario (){}

void Inventario::poner_prod(string producto){
    if (inven.find(producto)==inven.end()){
        inven[producto]=0;
    }
    else cout << "  error" <<endl;
}
    
void Inventario::quitar_prod(string producto){
    map <string,int>::iterator it;
    it = inven.find(producto);
    if (it!=inven.end() and it->second == 0){
        inven.erase(it);
    }
    else cout << "  error" << endl;
}
    
bool Inventario::exist_prod (map<string,int>::iterator& it, string producto){
    it = inven.find(producto);
    return (it!=inven.end());
}
    
void Inventario::actualizar_inven (map<string,int>::iterator& it, int cantidad, bool poner){
    if (poner) it->second+=cantidad;
    else it->second-=cantidad;
}

//Consultoras
void Inventario::consultar_prod (string producto)const{
    map <string,int>::const_iterator it;
    it = inven.find(producto);
    if (it!=inven.end()){
        cout << "  " << it->second << endl;
    }
    else cout << "  error" << endl;
}
    
void Inventario::consultar_inven ()const{
    for(map<string,int>::const_iterator it = inven.begin(); it != inven.end(); ++it){
        cout << "  " << it->first << " " << it->second << endl;
    }
}
