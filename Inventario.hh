/** @file Inventario.hh
    @brief Especificación de la clase Inventario
*/
#ifndef _INVENTARIO_HH_
#define _INVENTARIO_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif
#include "Sala.hh" //redundante
using namespace std;

/** @class Inventario
    @brief Representa el inventario de los productos de un almacen.

    Contiene la cantidad de productos que hay en todo un almacen.
*/
class Inventario
{
private:
    /** @brief Diccionario con los objetos de un almacen */
    map <string,int> inven;
    
public:
    //Constructora
    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un inventario.
      \pre <em>cierto</em>
      \post El resultado es un inventario vacio.
      \coste Constante
    */  
    Inventario ();
    //Destructora
    ~Inventario();
    
    //Modificadoras
    /** @brief Pone un producto en el inventario si no existia antes.

      \pre <em>cierto</em>
      \post Se pondra el producto en el inventario si este no existia antes. En caso contario, se producirá un error.
      \coste Logaritmico dependiendo de los elementos que ya hayan el inventario.
    */  
    void poner_prod(string producto);
    
    /** @brief Quita un producto del inventario si quedan 0 unidades de este en el almacen.

      \pre <em>cierto</em>
      \post Se quitara el producto del inventario o no dependiendo de si este se encontraba en él y ademas no quedaban unidades. En caso contrario se producirá un error.
      \coste Logaritmico dependiendo de los elementos que hayan en el inventario.
    */ 
    void quitar_prod(string producto);
    
    /** @brief Indica si el producto esta en el inventario.

      \pre <em>cierto</em>
      \post Devolvera true en caso de que el producto se encuentre en el inventario e "it" apuntara al producto, en caso contrario devuelve false e "it" apuntara a inven.end().
      \coste Logaritmico dependiendo de los elementos que hayan en el inventario.
    */
    bool exist_prod (map<string,int>::iterator& it, string producto);
    
    /** @brief Actualiza la cantidad de productos que hay en el inventario

      \pre "it" apunta a un elemento de inven.
      \post Se habra puesto o quitado una cantidad determinada del producto que "it" señala en inven.
      \coste Constante
    */
    void actualizar_inven (map<string,int>::iterator& it, int cantidad, bool poner);
    
    //Consultoras
    /** @brief Indica las unidades que hay de un producto en el almacen.
      \pre <em>cierto</em>
      \post Si el producto a consultar se encuentra en el inventario, muestra el producto y su cantidad por el canal estandar de salida. En caso contrario se producirá un error.
      \coste Logaritmico dependiendo de los elementos que hayan en el inventario.
    */
    
    void consultar_prod (string producto)const;
    
     /** @brief  Muestra los productos que hay en el inventario y su cantidad
      \pre <em>cierto</em>
      \post Muestra por el canal de salida estandar los elementos que hay en el inventario además de su cantidad.
      \coste Lineal dependiendo de los elementos que hayan en el inventario.
    */     
    void consultar_inven ()const;
};
#endif
