/** @file Sala.cc
    @brief Código de la clase Sala 
*/
#include "Sala.hh"

//Constructora

Sala::Sala(){
    fila = 0;
    col = 0;
    cant_prod = 0;
}

Sala::Sala (int f,int c){
    estante = vector <string> (f*c,"NULL");
    fila = f;
    col = c;
    cant_prod = 0;
}

//Modificadoras

int Sala::poner_items(string producto,int cantidad){
    int tam = fila * col;
    int cant_inicial_por_quitar = cantidad;
    for (int i = tam-1;cantidad > 0 and cant_prod < tam; --i){
        if (estante[i] == "NULL"){
            estante[i] = producto;
            ++cant_prod;
            --cantidad;
        }
    }
    if (cant_inicial_por_quitar - cantidad != 0) coleccion[producto] += (cant_inicial_por_quitar - cantidad);
    return cantidad;
}

int Sala::quitar_items (string producto, int cantidad){
    map <string,int> :: iterator it = coleccion.find(producto);
    if (it!= coleccion.end()){
        int iniciales = it->second;
        for (int i = (fila*col)-1; it->second > 0 and cantidad > 0; --i){
            if (estante[i] == producto){
                estante[i] = "NULL";
                --it->second;
                --cantidad;
            }
        }
        cant_prod -=(iniciales - it->second);
        if (it->second == 0) coleccion.erase(it);
    }
    return cantidad;
}

void Sala::compactar (){
    if (cant_prod != fila*col){
        int npos = (fila*col)-1;
        int contador = 0;

        for (int i = npos; contador < cant_prod; --i){
            if (estante[i] != "NULL"){
                ++contador;
                if (i != npos){
                    estante[npos] = estante[i];
                    estante[i] = "NULL";
                }
            }
            if (estante[npos] != "NULL")--npos;
        }
    }
}

void Sala::reorganizar (){
    map <string,int> :: const_iterator it = coleccion.begin();
    int npos = estante.size()-1;

    while (it!= coleccion.end()){
        string prod = it->first;
        int cant = it->second;

        while (cant != 0){
            estante[npos] = prod;
            --npos;
            --cant;
        }
        ++it;
    }

    while (npos >= 0){
        estante[npos] = "NULL";
        --npos;
    }
}

bool Sala::redimensionar (int f, int c){
    if (cant_prod > f*c) return false;

    else{
        int npos = (f*c)-1;
        int contador = 0;
        vector <string> nestante (f*c,"NULL");

        for (int i = (fila*col)-1; contador < cant_prod; --i){
            if (estante[i]!="NULL"){
                nestante[npos] = estante[i];
                ++contador;
                --npos;
            }
        }

        estante = nestante;
        fila = f;
        col = c;
        return true;
    }
}

//Consultoras

string Sala::consultar_pos(int f, int c)const{
    return estante[col * (f-1) + (col - c)];
}

//Lectura y escritura

void Sala::escribir () const{
    int n = fila*col;

    for (int i = col-1;i < n;i = i + col){
        for (int j = 0;j < col;++j){
            if(j>0) cout << " " << estante[i-j];
            else cout << "  " << estante[i-j];
        }
        cout << endl;
    }

    cout << "  " << cant_prod << endl;

    for (map<string,int>::const_iterator it = coleccion.begin();it != coleccion.end();++it){
        cout << "  " << it->first << " " << it->second << endl;
    }
}
