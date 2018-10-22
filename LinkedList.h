#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include <iostream>

using namespace std;

template<typename D>
class SingleNode {
    public:
        D* item;
        SingleNode* next;

        SingleNode() {
            this->item = nullptr;
            this->next = nullptr; 
        }

        SingleNode( D* d, SingleNode* c){
            this->item = d;
            this->next = c;
        }

        SingleNode(const SingleNode& orig) {
            this->item = orig->item;
            this->next = orig->next;
        }

        virtual ~SingleNode(){
            delete this->item;
        }
};


template<typename D, typename P>
class LinkedList : public List<D, P > {
    public:
        LinkedList(){
            this->first = this->last = nullptr;
            this->n=0;
        };
        ~LinkedList(){};


        void insert(D d) {
            SingleNode<D>* ptr = new SingleNode<D>(new D(d),nullptr); // Se crea el primer nodo
            if (this->n == 0)
            {
                this->first = this-> last = ptr;
            } else
            {
                this->last->next = ptr;
                this->last = ptr;
            }
            this->n++;
        }

        void remove(D delete_d) {
            if (this->n == 1 && *(this->first->item) == delete_d) { //Solo un elemento
                delete first;
                this->n = 0;
            } else {
                P* del = nullptr;
                P* pre = nullptr;
                if (*(this->first->item) == delete_d) {
                    del = this->first;
                    this->first = del->next;
                    delete del;
                    this->n--;
                }
                pre = this->first;
                del = this->first;

                while(del != nullptr) {
	        	if (*(del->item) == delete_d) {
	        		pre->next = del->next;
	        		if (del == this->last)
	        			this->last = pre;
	        		delete del;
	        		this->n -= 1;
	        		break;
	        	}
	        	pre = del;
	        	del = del->next;
	        }
            }
        }

        D& get(P& node) { 
            return *(node.item);
        }

        P& next(P& node) {
        //se evita el caso de la celda last
        if (&(node) != &(*(this->last)))
            return *(node.next);
        }


        void printList() {
        //si la lista esta vacia, se  imprime dicha situacion
        if (this->n == 0)
            cout << "List is empty..!" << endl;
        else {
            P* temp = this->first;
            cout << "Printing list: "; //mensaje de que se va a imprimir la lista
            for (int index = 0; index < this->n; ++index) {
                cout << get(*temp) << "  ";
                if (temp->next != nullptr) 
                	temp = &(next(*temp));
            }
            cout << endl;
        }
    }


    P& find(D data) {
        cout << "Looking for: " << data << " on the list." << endl;

    	P* temp = this->first;
    	for (int index = 0; index < this->n; ++index) {
    		if (*(temp->data) == data){
                cout << "Number " << data << " was found on the list!!\n" << endl; //mensaje de exito
    			return *temp;
            }
            if (temp->next != nullptr) 
                temp = &(next(*temp));
    	}

        cout << "Number " << data << " was not found on the list...\n" << endl; //mensaje que no se encontro
    }

        int n;
        P* first;
        P* last;
};


#endif