#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include "List.h"

using namespace std;

template <typename D>
class ArrayList : public List<D, int> {
    public:
    //! Constructor ArrayList.
    /*! Crea el objeto de tipo ArrayList.
     * Se inicializan los atributos de la clase a un valor neutral.
    */
        ArrayList(){
            this->items = nullptr;
            this->size = 0;
            this->arraySize = 0;
        };
    //! Contructor ArrayList con parámetro maxSize
    /*! Crea un objeto de tipo ArrayList con capacidad de almacenar maxSize datos.
     * \param maxSize, tamaño del arreglo a crear.
     */
        ArrayList(int maxSize) {
            this->items = new D[maxSize]();
            this->size = 0;
            this->arraySize = maxSize;
        };

    //! Constructor por copia de ArrayList.
    /*! Es una buena práctica de programación en C++ crean los contructores por copia.
    */
        ArrayList(const ArrayList& orig){
            this->items = orig.items;
            this->size = orig.size;
            this->arraySize = orig.arraySize;
        };
        
    //! Destructor de la clase ArrayList
    /*! Se encarga de liberar el espacio en memoria utilizado para almacenar los datos.*/
        ~ArrayList() {
            delete[] this->items;
        };

    //! Inserción de elemento del tipo d en la lista.
    /*! Si la lista se encuentra vacía se crea un arreglo de tamaño 10, donde 10 es la
     * es la cantidad máxima de elementos en la lista. Posteriormente se guarda el dato
     * d en la posición 0 del arreglo creado.
     * Si la lista no se encuentra vacía y todavía cuenta con capacidad para almacenar
     * más elementos se guarda el dato d en la última posición, es decir, end.
     * En caso de que la lista se encuentre llena, se crea un nuevo arreglo con el doble
     * del tamaño, se copian los datos del arreglo inicial y se inserta el nuevo dato. Se
     * debe eliminar el arreglo anterior para liberar memoria.*/
        void insert(D d) { // insertar dato
            if (this->getSize() == 0) { // Arreglo vacío
                this->items = new D[10];
                this->size = 1;
                this->end = 1;
                this->arraySize = 10;
                this->items[0] = d;
            } else {    // Arreglo no vacío
                // if (this->getSize() -1 != end ){ //Arreglo no lleno
                if (this->getSize() != arraySize ){ //Arreglo no lleno
                    this->items[end] = d;
                    this->size++;
                    this->end++;
                } else { // Arreglo lleno
                    D* tmp = new D[this->getSize()*2]; // arreglo del doble de tamaño
                    
                    for(int i = 0; i < this->getSize(); i++) // copia el arreglo viejo
                    {
                        tmp[i] = this->get(i);
                    }
                    this->arraySize = this->getSize()*2;
                    delete this->items;
                    this->items = tmp;
                    this->items[end] = d;
                    this->end++;
                    this->size++;
                }
            }
        };

    //! Eliminación elemento del tipo d en la lista.
    /*! Se busca el elemento d en la lista. Si este existe, se elimina
     * reacomodando la lista 
     */

  void remove(D d) { //remover
              int i = this->find(d);
              if (i != -1) {
                  for (i; i< this->getSize() - 1; i++) {
                      this->assign(i, this->get(i + 1));
                  }
                  this->size--;
                  this->end--;
              }
          }

    //! Encontrar un elemento en el arreglo
    /*! Busca un elemento cuyo valor sea igual a d, si retorna un número natural
    * este valor se encuentra almacenado en el arreglo, si devuelve -1 no se encuentra.
    * \param d, elemento que se desea buscar.
    * \return posición en la que se encuentra.
    * */
        int find(D d) {
            for (int i = 0; i < this->getSize(); i++) {
                if (d == this->get(i))
                    return i;
                }
                return -1;
        };

    //! Retornar elemento
    /*! Retorna el contenido en el arreglo de una posición determinada.
    \param k posición de la que se desea obtener el valor.
    \return valor de la posición k*/
        D get(int k) {
            return this->items[k];
        };
    

    //! Asignación, a la posición k se le asigna el valor d.
    /*! \param k, posición a la cual se le asigna el valod deseado.
     * \param d, valor que se le asigna a k
     */
        void assign(int k, D d) {
            this->items[k] = d;
        }; 


    //! Sort, 


     /*! Retorna la cantidad de elementos de la lista
     \return n, es posible determinar el tamaño de la lista con el atributo n.*/
        int getSize() {
            return this->size;
        };

     /*! Retorna la cantidad de elementos que se pueden guardar en la lista
     \return ArraySize, cantidad de elementos que se pueden guardar en array size.*/
        int getArraySize() {
            return this->arraySize;
        };

    //! Imprimir lista.
    /*! Se imprimen todos los elementos de la lista.
    */
        void printList() { //imprimir
            cout << "|------------------------------|" << "\n";
            cout << "|  Posición   |      Valor     |" << "\n";
            cout << "|------------------------------|" << "\n";
            for(int i = 0; i < this->getSize(); i++)
            {
                cout<<"\t" <<i<<"\t\t" << this->get(i) << "\n";
            }
            
        }

    //! Metodo Sort
    /*! Mediante el algoritmo de ordenamiento Bubble Sort, se ordenan los
    * elementos de la lista en orden creciente.
    */
        void sort() {
	        for(int i=0;i<this->getSize();i++){
		        for(int j=0;j< this->getSize()-1 ;j++){
			        if( this->items[j] >  this->items[j+1]){
				        D tmp= this->items[j];
			            this->items[j] =  this->items[j+1];
			            this->items[j+1] = tmp;
			        }

		        }
	        }

        }




    //! Metodo next.
    /*! Encuentra el siguiente elemento en la lista.
    \param k, referencia para encontrar el siguiente elemento
    \return k+1 en caso de que k no sea el último elemento. -1 si k es
    * el último elemento de la lista.
    */
        int next(int k) {
            if (k < this->getSize())
                return k + 1;
            else
                return -1;
        }

    //! Metodo prev.
    /*! Encuentra el elemento anterior en la lista.
    \param k, referencia para encontrar el elemento anterior
    \return k-1 en caso de que k no sea el primer elemento. -1 si k es
    * el primer elemento de la lista.
    */
        int prev(int k) {
            if (k < this->getSize())
                return k - 1;
            else
                return -1;
        }

    //! Metodo emptyList.
    /*! Este metodo vacía el arreglo.
    * La cantidad de elementos se asigna como  0.
    */
        void emptyList() { //vaciar
            this->size = 0;
        }

    

    private:
        D* items;
        int size;
        int arraySize;
        int end;
};
#endif