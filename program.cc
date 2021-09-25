/**
 * @mainpage Diseño modular: TreeKEA
 
    Tendremos un programa con un menú de opciones que se encuentra en program.cc para gestionar un almacen con salas y un inventario sobre todos sus productos. Las clases utilizadas son: <em>Almacen</em>, <em>Inventario</em> y <em>Sala</em>.
    
    - Para que el diagrama modular quede bien se han hecho "includes" redundantes.
*/

/** @file program.cc
    @brief Programa principal para la practica <em>TreeKEA</em>.
*/


#include "Almacen.hh"
#include "Inventario.hh"
#include "Sala.hh" //redundante

/** @brief Programa principal para la practica <em>TreeKEA</em>.
    
    Los datos que se leeran seran siempre correctos respecto al enunciado de la practica. No hay ninguna comprobacion al respecto (ejemplo: consultar sala 8 en un almacen de 7 salas).
    Aqui se leeran y ejecutaran las instrucciones escritas por el usuario.


*/
int main(){
    int n;
    cin>>n;
    
    Almacen a (n);
    a.creabtree();
    a.inisalas();
    
    Inventario inven;
    
    string op;
    while (cin>>op and op != "fin"){
        cout << op ;
        
        if (op == "poner_prod"){
            string p;
            cin >> p;
            cout << " " << p << endl;
            inven.poner_prod(p);
        }
        
        else if (op == "quitar_prod"){
            string p;
            cin >> p;
            cout << " " << p << endl;
            inven.quitar_prod(p);
        }
        
        else if (op == "poner_items"){
            int id,cant;
            string prod;
            cin >> id >> prod >> cant;
            cout << " " << id << " "<< prod << " " << cant << endl;
            a.poner_items(id, prod, cant, inven);
        }
        
        else if (op == "quitar_items"){
            int id,cant;
            string prod;
            cin >> id >> prod >> cant;
            cout << " " << id << " " << prod << " " << cant << endl;
            a.quitar_items(id, prod, cant, inven);
        }
        
        else if (op == "distribuir"){
            string prod;
            int cant;
            cin >> prod >> cant;
            cout << " " << prod << " " << cant << endl;
            a.distribuir(prod, cant, inven);
        }
        
        else if (op == "compactar"){
            int id;
            cin >> id;
            cout << " " << id << endl;
            a.compactar(id);
        }
        
        else if (op == "reorganizar"){
            int id;
            cin >> id;
            cout <<  " " << id << endl;
            a.reorganizar(id);
        }
        
        else if (op == "redimensionar"){
            int id, f, c;
            cin >> id >> f >> c;
            cout << " " << id << " " << f << " " << c << endl;
            a.redimensionar(id, f ,c);
        }
        
        else if (op == "inventario"){
            cout << endl;
            inven.consultar_inven();
        }
        
        else if (op == "escribir"){
            int id;
            cin>>id;
            cout<< " " << id << endl;
            a.escribir(id);
        }
        
        else if (op == "consultar_pos"){
            int id, f ,c;
            cin >> id >> f >> c;
            cout << " " << id << " "<< f << " " << c <<endl;
            a.consultar_pos(id, f, c);
        }
        
        else if (op == "consultar_prod"){
            string prod;
            cin >> prod;
            cout << " " << prod << endl;
            inven.consultar_prod(prod);
        }
    }
    
    cout << op << endl;
}
