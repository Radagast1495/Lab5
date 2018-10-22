#ifndef LIST
#define LIST


template<typename Dat, typename Pos>
class List {
    public:
        List(){};
        ~List(){};
		unsigned long long int getSize() { return size ; };
		// virtual void insert(Dat d) = 0;
		// virtual void insert(Dat d, Pos p) = 0;
		// virtual void remove(Dat d) = 0;
		// virtual void remove(Pos p) = 0;
		// virtual Dat find(Dat x) = 0;
		// virtual Dat find(Pos k) = 0;
		// virtual void print() = 0;
		// virtual Dat next(Pos p) = 0;
		// virtual Dat prev(Pos p) = 0;

    
        unsigned long long int size;
};




#endif