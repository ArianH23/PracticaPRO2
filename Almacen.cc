/** @file Almacen.cc
    @brief Código de la clase Almacen 
*/
#include "Almacen.hh"

void Almacen::btree (BinTree<int>& b){
    int x;
    cin>>x;
    if (x!=0){
        BinTree<int> l;
        btree (l);
        BinTree<int> r;
        btree (r);
        
        b = BinTree <int> (x,l,r);
    }
}
int Almacen::distr (const BinTree <int>& b,vector <Sala>& salas, int cantidad, string producto){
    cantidad = salas[b.value()-1].poner_items(producto,cantidad);
    
    if (not b.left().empty()){
        int left;
        int right;
        
        if (cantidad%2 == 0){
            left = distr (b.left(),salas,cantidad/2,producto);
            right = distr (b.right(),salas,cantidad/2,producto);
        }
        else{
            left = distr(b.left(),salas,(cantidad/2)+1,producto);
            right = distr(b.right(),salas,cantidad/2,producto);
        }
        
        return left+right;
    }
    return cantidad;
}
//Constructores
Almacen::Almacen(){
    salas = vector <Sala> (0);
}
    
Almacen::Almacen (int n){
    salas = vector<Sala>(n);
}

//Modificadores
    
void Almacen::poner_items (int id, string producto,int cantidad, Inventario& i){
    map <string,int>::iterator it;
    if (i.exist_prod(it,producto)){
        int sobras = salas[id-1].poner_items(producto,cantidad);
        i.actualizar_inven(it, cantidad - sobras, 1);
        cout << "  " << sobras << endl;
    }
    else cout << "  error" << endl;
}
    
void Almacen::quitar_items (int id, string producto,int cantidad, Inventario& i){
    map <string,int>::iterator it;
    if (i.exist_prod(it, producto)){
        int no_encontrados = salas[id-1].quitar_items(producto,cantidad);
        i.actualizar_inven(it, cantidad - no_encontrados, 0);
        cout << "  " << no_encontrados << endl;
    }
    else cout << "  error" << endl;
}
    
void Almacen::distribuir (string producto, int cantidad, Inventario& i){
    map <string,int>::iterator it;
    if (i.exist_prod(it, producto)){
        int sobras = distr(alm,salas,cantidad,producto);
        i.actualizar_inven(it, cantidad-sobras,1);
        cout << "  " << sobras << endl;
    }
    else cout << "  error" << endl;
}
    
void Almacen::compactar (int id){
    salas[id-1].compactar();
}
   
void Almacen::reorganizar (int id){
    salas[id-1].reorganizar();
}

void Almacen::redimensionar (int id,int f, int c){
    if (not salas[id-1].redimensionar(f,c)) cout << "  error" << endl;
}
    
//Consultoras
    
void Almacen::consultar_pos (int id, int f, int c)const{
    cout << "  " << salas[id-1].consultar_pos(f,c) << endl;
}

// Lectura i escritura    
    
void Almacen::inisalas(){
    int n = salas.size();
    for (int i = 0;i < n; ++i){
        int f,c;
        cin >> f >> c;
        salas[i] = Sala (f,c);
    }
}
    
void Almacen::creabtree(){
    btree (alm);
}

void Almacen::escribir (int id) const{
    salas[id-1].escribir();
}
