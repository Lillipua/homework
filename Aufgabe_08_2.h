/*** Aufgabe_08_2.h ***/
#include <iostream>
#include <cstdlib>

template<typename T>
class Queue {
private:
    struct Object {	// interner Datentyp
        Object *tail;	// Zeiger auf Queuenschwanz
        T data;	// Datenfeld
    } *sz, *ez;

    void error(char *info);	// Fehlermeldung

public:
    Queue();	// Konstruktor
    Queue(const Queue<T>& s);
    Queue<T>& operator= (const Queue<T>& s);
    bool operator == (const Queue<T>& s);
    void enq(T& x);
    void deq();
    T front();
    Object * frontObj();
    void print();
    bool empty();	// Queue leer?
    void clear();	// loescht alle Eintraege
    ~Queue();	// Destruktor

    // Verlangte Methoden (siehe Dateiende)
    void manifold();
    Object * insertAfter(Object *e, T const &d);
};

template<typename T>
Queue<T>::Queue() {
    sz = nullptr;
	ez = nullptr;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& s){
    ez = nullptr;
    Object *ptr = s.sz;
    while (ptr != nullptr) {
        enq(ptr->data);
        ptr = ptr->tail;
    }
}

template<typename T>
Queue<T>& Queue<T>::operator= (const Queue<T>& s) {
    if (this == &s)
        return *this;
    clear();	// Speicher freigeben
    Object *ptr = s.sz;
    while (ptr != nullptr) {
        enq(ptr->data);
        ptr = ptr->tail;
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    clear();
}

template<typename T>
bool Queue<T>::operator== (const Queue& s) {
    if (this == &s)
        return true;
    Object *ptr1 = sz;	// this->sz
    Object *ptr2 = s.sz;
    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->data != ptr2->data)
            return false;
        ptr1 = ptr1->tail;
        ptr2 = ptr2->tail;
    }
    return (ptr1 == ptr2);
}

template<typename T>
T Queue<T>::front() {
    /*if (empty())
        error("leer");*/
    return sz->data;
}

template<typename T>
typename Queue<T>::Object * Queue<T>::frontObj() {
    //if (empty())
    //    //error("leer");
    return sz;
}

template<typename T>
bool Queue<T>::empty() {
    return (ez == nullptr);
}

template<typename T>
void Queue<T>::clear() {
    while (!empty())
        deq();
}

template<typename T>
void Queue<T>::error(char *info) {
    std::cerr << info << std::endl;
    exit(1);
}

template<typename T>
void Queue<T>::enq(T& x) {
    Object *obj = new Object;	// neues Object anlegen
    obj->data = x;	// Nutzdaten speichern
    obj->tail = nullptr;
    if (empty())
        sz = obj;	// falls leer nach vorne,
    else
        ez->tail = obj;	// sonst hinten anhaengen
    ez = obj;	// Endezeiger aktualisieren
}

template<typename T>
void Queue<T>::deq() {
	if (empty())
		exit(1);
    Object *obj = sz;	// Zeiger auf Kopf retten
    sz = sz->tail;	// Start auf 2. Element
    if (sz == nullptr)
        ez = nullptr;	// Queue leer!
    delete obj;	// ehemaliges 1. Element loeschen
}

template<typename T>
void Queue<T>::print() {
    if(empty()){
        return;
    }
    Object * obj = sz;
	while(obj != nullptr){
		if(obj != sz) std::cout << ", ";
        std::cout << obj->data;
		obj = obj->tail;
    }
    std::cout << std::endl;
}

// Verlangte Methode: insertAfter(Object *e)
// HilfsQueue und umkopieren nicht erlaubt
template<typename T>
typename Queue<T>::Object* 
Queue<T>::insertAfter(Object *e, T const &d) {

	Object *toInsert = new Object;

	toInsert->data = d;
	toInsert->tail = e->tail;

	e->tail = toInsert;

	return toInsert;
}

// Verlangte Methode: manifold()
template<typename T>
void Queue<T>::manifold() {
	if (empty()) {
		return;
	}
	Object * obj = sz;
	while (obj != nullptr) {
		Object *toInsert = new Object;

		toInsert->data = obj->data;
		toInsert->tail = obj->tail;

		obj->tail = toInsert;

		obj = toInsert->tail;
	}
}
/********* Ende *********/
