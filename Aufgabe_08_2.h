/*** Aufgabe_08_2.h ***/
#include <iostream>
#include <cstdlib>

template<typename T>
class Schlange {
private:
    struct Objekt {	// interner Datentyp
        Objekt *tail;	// Zeiger auf Schlangenschwanz
        T data;	// Datenfeld
    } *sz, *ez;

    void error(char *info);	// Fehlermeldung

public:
    Schlange();	// Konstruktor
    Schlange(const Schlange<T>& s);
    Schlange<T>& operator= (const Schlange<T>& s);
    bool operator == (const Schlange<T>& s);
    void enq(T& x);
    void deq();
    T front();
    Objekt * frontObj();
    void print();
    bool empty();	// Schlange leer?
    void clear();	// loescht alle Eintraege
    ~Schlange();	// Destruktor

    // Verlangte Methoden (siehe Dateiende)
    void manifold();
    Objekt * insertAfter(Objekt *e, T const &d);
};

template<typename T>
Schlange<T>::Schlange() {
    sz = nullptr;
	ez = nullptr;
}

template<typename T>
Schlange<T>::Schlange(const Schlange<T>& s){
    ez = nullptr;
    Objekt *ptr = s.sz;
    while (ptr != nullptr) {
        enq(ptr->data);
        ptr = ptr->tail;
    }
}

template<typename T>
Schlange<T>& Schlange<T>::operator= (const Schlange<T>& s) {
    if (this == &s)
        return *this;
    clear();	// Speicher freigeben
    Objekt *ptr = s.sz;
    while (ptr != nullptr) {
        enq(ptr->data);
        ptr = ptr->tail;
    }
    return *this;
}

template<typename T>
Schlange<T>::~Schlange() {
    clear();
}

template<typename T>
bool Schlange<T>::operator== (const Schlange& s) {
    if (this == &s)
        return true;
    Objekt *ptr1 = sz;	// this->sz
    Objekt *ptr2 = s.sz;
    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->data != ptr2->data)
            return false;
        ptr1 = ptr1->tail;
        ptr2 = ptr2->tail;
    }
    return (ptr1 == ptr2);
}

template<typename T>
T Schlange<T>::front() {
    if (empty())
        error("leer");
    return sz->data;
}

template<typename T>
typename Schlange<T>::Objekt * Schlange<T>::frontObj() {
    if (empty())
        error("leer");
    return sz;
}

template<typename T>
bool Schlange<T>::empty() {
    return (ez == nullptr);
}

template<typename T>
void Schlange<T>::clear() {
    while (!empty())
        deq();
}

template<typename T>
void Schlange<T>::error(char *info) {
    std::cerr << info << std::endl;
    exit(1);
}

template<typename T>
void Schlange<T>::enq(T& x) {
    Objekt *obj = new Objekt;	// neues Objekt anlegen
    obj->data = x;	// Nutzdaten speichern
    obj->tail = nullptr;
    if (empty())
        sz = obj;	// falls leer nach vorne,
    else
        ez->tail = obj;	// sonst hinten anhaengen
    ez = obj;	// Endezeiger aktualisieren
}

template<typename T>
void Schlange<T>::deq() {
    if (empty())
        error("leer");
    Objekt *obj = sz;	// Zeiger auf Kopf retten
    sz = sz->tail;	// Start auf 2. Element
    if (sz == nullptr)
        ez = nullptr;	// Schlange leer!
    delete obj;	// ehemaliges 1. Element loeschen
}

template<typename T>
void Schlange<T>::print() {
    if(empty()){
        return;
    }
    Objekt * obj = sz;
	while(obj != nullptr){
		if(obj != sz) std::cout << ", ";
        std::cout << obj->data;
		obj = obj->tail;
    }
    std::cout << std::endl;
}

// Verlangte Methode: insertAfter(Objekt *e)
// Hilfsschlange und umkopieren nicht erlaubt
template<typename T>
typename Schlange<T>::Objekt* 
Schlange<T>::insertAfter(Objekt *e, T const &d) {

}

// Verlangte Methode: manifold()
template<typename T>
void Schlange<T>::manifold() {

}
/********* Ende *********/
