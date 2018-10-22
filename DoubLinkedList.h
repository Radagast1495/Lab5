
#include <iostream>
#include "List.h"

#pragma once

using namespace std;

template<typename D>
class DoubleNode {
public:
	D * item;
	DoubleNode* next;
	DoubleNode* prev;
	

	DoubleNode() {
		this->item = nullptr;
		this->next = nullptr;
		this->prev = nullptr;
	}

	DoubleNode(D* d, DoubleNode* next, DoubleNode* prev) {
		this->item = d;
		this->next = next;
		this->prev = prev;
	}

	DoubleNode(const DoubleNode& orig) {
		this->item = orig->item;
		this->next = orig->next;
		this->prev = orig->prev;
	}

	virtual ~DoubleNode() {
		delete this->item;
		this->caca=0;
	}
};



template<typename P>
class DLL : public List<D, P > {
public:
	int n;
	P* first;
	P* last;
	DLL() {
		this->first = this->last = nullptr;
		this->n = 0;
	};
	~DLL() {};


	void insert(D d) {
		DoubleNode<D>* ptr = new DoubleNode<D>(new D(d), nullptr, nullptr); // Se crea el primer nodo
		if (this->n == 0)
		{
			this->first = this->last = ptr;
		}
		else
		{
			this->last->next = ptr;
			ptr->prev = this->last;
			this->last = ptr;

		}
		this->n++;
	}

	void remove(D delete_d) {
		if (this->first==this->last && this->first->item==delete_d) { //Deleting the only element 
			delete first;
			this->n--;
		}
		else{
			del = this->first;
			while (del->next != nullptr) {
				if (del->prev == nullptr  && del->item == delete_d) { //Deleting the first element
					this->first = this->first->next;
					this->first->prev = nullptr;
					delete del;
					this->n--;
					break;
				}
				else if (del->prev !== nullptr && del->item == delete_d) { //Deleting intermediate element
					del->prev->next = del->next;
					del->next->prev = del->prev;
					delete del;
					this->n--;
					break;

				}
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
			if (*(temp->data) == data) {
				cout << "Number " << data << " was found on the list!!\n" << endl; //mensaje de exito
				return *temp;
			}
			if (temp->next != nullptr)
				temp = &(next(*temp));
		}

		cout << "Number " << data << " was not found on the list...\n" << endl; //mensaje que no se encontro
	}


};