/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/
#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_
#include "Inventario.hh"
#include "Sala.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif
/** @class Almacen
    @brief Representa una almacen con varias salas estructuradas en forma de arbol.

    Desde cada sala puedes acceder a otras 2, una por la derecha, u otra por la izquierda o a ninguna.
*/
class Almacen
{
private:
    /** @brief Estructura de las salas en el almacen */
    BinTree <int> alm;
    /** @brief Vector que contiene cada una de las salas del almacen */
    vector <Sala> salas;
    /** @brief Operacion de lectura de identificadores de salas.
      \pre b esta vacio.
      \post El parametro implicito contiene identificadores de salas ordenado de forma jerarquizada.
      \coste Lineal respecto al numero de salas del almacen.
    */
    static void btree (BinTree <int>& b);
    /** @brief Operacion de distribucion
      \pre El valor cantidad es un numero natural, b no esta vacio y tiene dos identificadores adyacentes o ninguno.
      \post  Se habra distribuido el producto por todo el almacen y se devolvera el numero de unidades que no se hayan podido colocar.
      \coste Lineal respecto a la suma del tamaño de todas las estanterias de las salas del almacen.
    */
    static int distr (const BinTree <int>& b, vector <Sala>& salas, int cantidad, string producto);
    
public:
    //Constructoras
     /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un almacen.
      \pre <em>cierto</em>
      \post El resultado es una almacen sin salas
      \coste Constante
    */  
    Almacen();
    
    /** @brief Creadora por numero de salas

      Permite crear un almacen con un numero de salas
      \pre El valor de n es un numero natual
      \post El resultado es un almacen con n salas
      \coste Lineal respecto a n
    */  
    Almacen (int n);

    //Modificadores
    /** @brief Coloca una cantidad de productos en la sala "id".
      \pre Valor de id entre 1 y numero de salas.
      \post Si el producto se encuentra en el inventario, se colocaran tantos como se deseen en la sala "id", se actualizará el inventario,
      y se indicara los articulos sobrantes por el canal de salida estandar. Si el producto no está en el inventario, se producira un error.
      \coste Logaritmico respecto a la cantidad de objetos del inventario + lineal respecto al tamaño de la estanteria de la sala id.
    */
    void poner_items (int id, string producto,int cantidad, Inventario& i);
    
    /** @brief Coloca una cantidad de productos en la sala "id".
      \pre valor de id entre 1 y numero de salas.
      \post Si el producto se encuentra en el inventario, se quitaran tantos como se deseen de la sala "id", se actualizará el inventario,
      y se indicara los articulos que no se han podido quitar por el canal de salida estandar. Si el producto no está en el inventario, se producira un error.
      \coste Logaritmico respecto a la cantidad de objetos del inventario + lineal respecto al tamaño de la estanteria de la sala "id".
    */
    void quitar_items (int id, string producto,int cantidad, Inventario& i);
    /** @brief Operacion de distribucion.
      \pre "b" no esta vacio y tendra 2 identificadores de salas adyacentes o ninguno, "cantidad" es un numero natural
      \post Si el producto se encuentra en el inventario "i", se habra distribuido comenzando por la sala inicial de la siguiente forma:
      Primero se pondran todos los productos posibles en la sala en la que se encuentra.
      Si sobran unidades se repartiran de forma equitativa por las salas adyacentes a la que se encuentra, si las unidades sobrantes es impar, por la sala que esté a la izquierda una unidad más.
      Por el canal de la salida estandar se habrá escrito el numero de unidades que hayan sobrado al ir haciendo esta operacion por todo el almacen.
       \coste Lineal respecto a la suma del tamaño de todas las estanterias de las salas del almacen.
    */
    
    void distribuir (string producto, int cantidad, Inventario& i);
    
    /** @brief Compactadora de sala especifica
      \pre Valor de id entre 1 y numero de salas del parametro implicito.
      \post Se compacta la sala id desplazando los productos hacia abajo a la izquiera y sin dejar espacio entre producto y producto.
      \coste Lineal respecto al tamño de la estanteria de la sala "id".
    */
    void compactar (int id);
    
    /** @brief Reorganizadora de sala especifica
      \pre Valor de id entre 1 y numero de salas del parametro implicito.
      \post Se compacta la sala id y ademas se dejan los productos en orden alfabetico.
      \coste Lineal respecto al tamaño de la estanteria de la sala "id".
    */
    void reorganizar (int id);

    /** @brief Redimensionadora de sala especifica.
      \pre Valor de id entre 1 y numero de salas del parametro implicito, el valor de f y c es un numero natural.
      \post Se le dara un nuevo tamaño fxc a la sala id si los productos de esta caben en la nueva, en caso contrario se producirá un error.
      \coste Lineal respecto al tamaño de la estanteria de la sala "id" + lineal respecto a las dimensiones de la nueva estanteria.
    */
    void redimensionar (int id,int f, int c);
    
    //Consultoras
    /** @brief Consultora por posicion y sala.
      \pre Valor de id entre 1 y numero de salas del parametro implicito, valor de f entre 1 y numero de filas de la sala "id",  valor de c entre 1 y numero de columnas en la sala "id".
      \post Se devuelve el producto que se encuentra en la sala "id", fila "f", columna "c". En caso de no haber nada se devolvera "NULL".
      \coste Constante
    */
    void consultar_pos (int id, int f, int c)const;
    // Lectura i escritura
    
    /** @brief Da tamaño a cada una de las salas del almacen
      \pre Por el canal estandar de entrada hay tantas parejas de numeros como salas tiene el almacen.
      \post Cada una de las salas del parametro implicito estará dimensionada con las dimensiones del canal de entrada.
      \coste Lineal respecto a la suma de las dimensiones de todas las salas.
    */
    void inisalas();
    
    /** @brief Inicializa la estructura del almacen.
      \pre La distribucion de salas del parametro implicito no ha sido inicializado.
      \post El parametro implicito contiene identificadores de salas ordenado de forma jerarquizada.
    */
    void creabtree();
    
    /** @brief Operacion de escritura de la sala con identificador "id".
      \pre Valor id entre 1 y numero de salas del parametro implicito.
      \post Escribe el contenido de la sala id, la cantidad de objetos, y las unidades que hay de cada objeto por orden de existencia de estanteria en esta sala id por el canal estándar de salida.
    */
    void escribir (int id) const;
};
#endif
