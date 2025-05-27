#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

class Stack {
    // Descripcio: una pila d�strings

public:
    // CONSTRUCTORS I DESTRUCTOR ----------------------------------
    Stack();
    // Pre: --; Post: pila empty
    Stack(const Stack& o);  // const. de copia
    // Pre: --; Post: aquesta pila es copia de la pila o
    ~Stack();
    // Pre: --; Post: memoria alliberada (inclosa la din�mica)
    
    // CONSULTORS -------------------------------------------------
    bool empty() const;
    // Pre: -- ; Post: retorna cert si la pila es buida; fals en c.c.
    string top() const;
    // Pre: pila no buida; Post: retorna el valor del cim de la pila
    
    // MODIFICADORS -----------------------------------------------
    void tostak(int s);
    // Pre: --; 
    //Post: ha afegit s a dalt de la pila
    void unstak();
    // Pre: pila no buida; 
    //Post: ha eliminat element de dalt de la pila
    
    // OPERADORS REDEFINITS ---------------------------------------
    Stack& operator=(const Stack& o);
    // Pre: -- ; Post: aquesta pila es copia de la pila o i la seva mem�ria din�mica ha estat pr�viament alliberada

private:
    struct Node {
        string value;
        Node* next;
    };
    
    // ATRIBUTS
        Node* a_top; // punter al cim de la pila

    // METODES PRIVATS
    void copia(const Stack& o);
    // Pre: pila buida; Post: aquesta pila es copia de la pila o
    void allibera();
    // Pre: --; Post: memoria din�mica alliberada
};

#endif // PILASTRING_H