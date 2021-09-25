/** @file Sala.hh
    @brief Especificación de la clase Sala
*/
#ifndef _SALA_HH_
#define _SALA_HH_

#ifndef NO_DIAGRAM 
#include <iostream>
#include <vector>
#include <map>
#endif
using namespace std;

/** @class Sala
    @brief Representa una sala de un numero de filas y columnas.

    En esta se pueden almacenar productos, la cantidad de filas y de columnas de la sala sera mayor o igual que 1.
*/

class Sala
{
    
private:
    /** @brief Estante que contiene los productos de una sala */
    vector <string> estante;
    /** @brief Indica el numero de filas de la sala */
    int fila;
    /** @brief Indica el numero de columnas de la sala */
    int col;
    /** @brief Indica el numero de productos que hay en una sala */
    int cant_prod;
    /** @brief Diccionario que contiene la cantidad de cada producto que hay en una sala */
    map <string,int> coleccion;
public:
 
    //Constructora
    /** @brief Creadora por defecto. 
     * 
      Se ejecuta automáticamente al declarar una sala.
      \pre <em>cierto</em>
      \post El resultado es una sala vacia.
      \coste Constante.
      
    */
    Sala();
    
    /** @brief Creadora por dimensiones.

      Se ejecuta automáticamente al declarar una sala.
      \pre El valor de f y c es un numero natural
      \post El resultado es una sala de dimensiones f*c vacia (todo "NULL").
      \coste Lineal respecto a f*c.
    */
    Sala (int f,int c);
    
    //Modificadoras
    /** @brief Coloca una cantidad de productos en la sala.
      \pre El valor de cantidad es un numero natural.
      \post El parametro implicito contendra todos los productos que se hayan podido meter y se devolvera las unidades que no quepan.
      \coste Lineal respecto al tamaño de la estanteria de la sala.
    */
    int poner_items(string producto,int cantidad);
    
    /** @brief Coloca una cantidad de productos en la sala.
      \pre El valor de cantidad es un numero natural.
      \post El parametro implicito se le habra quitado una cantidad de productos y se devolvera el numero de productos que no se han quitado porque no estaban.
      \coste Logaritmico respecto a los diferentes productos que puedan haber en la estanteria + lineal respecto a f*c.
    */
    int quitar_items (string producto, int cantidad);
    
    /** @brief Compactadora
      \pre <em>cierto</em>
      \post Los productos de la sala se habran deplazado hacia abajo a la izquierda sin dejar ningun hueco entre ellos.
      \coste Lineal respecto al tamaño de la estanteria de la sala.
    */
    void compactar ();
    
    /** @brief Reorganizadora
      \pre <em>cierto</em>
      \post Los productos de la sala se habran deplazado hacia abajo a la izquierda sin dejar ningun hueco entre ellos y ademas estaran ordenados alfabeticamente.
      \coste Lineal respecto al tamaño de la estanteria de la sala.
    */
    void reorganizar ();
    
    /** @brief Redimensionadora
      \pre El valor de f y c es un numero natural.
      \post Si los productos de la sala inicial caben en una nueva sala de dimensiones f*c, se colocaran de forma compacta en esta, en caso contrario se producirá un error.
      \coste Lineal respecto al tamaño de la  nueva estanteria por crear + lineal respecto a la sala inicial.
    */
    bool redimensionar (int f, int c);
    
    //Consultoras
    /** @brief Indica cual es el producto en la posición (f,c) de la sala.
      \pre El valor de f es mayor o igual que 1 y menor o igual que el numero de filas de la sala.El valor de c es mayor o igual que 1 y menor o igual que el numero de columnas de la sala.
      \post Devuelve el nombre del producto en la fila f y columna c,si no hay ninguno, se devolverá "NULL".
      \coste Constante
    */
    string consultar_pos(int f, int c)const;
    
    //Lectura y escritura
    /** @brief Escribe el contenido de la sala.
      \pre <em>cierto</em>
      \post Escribe por el canal de salida estandar el contenido de la sala,la cantidad de objetos, y las unidades que hay de cada objeto por orden de existencia de estanteria por el canal estándar de salida.
      \coste Lineal respecto al tamaño de la estanteria de la sala.
    */
    void escribir () const;
};
#endif
