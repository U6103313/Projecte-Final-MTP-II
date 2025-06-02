#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

class Queue
// Descripcio: cua implementada amb nodes encadenats
{
private:
  struct Node
  {
    int value;
    Node *next;
  };
  // ATRIBUTS

  Node *start; // punter al primer element de la cua
  Node *end;   // punter al darrer element de la cua

  // METODES PRIVATS
  void copi(const Queue &o);
  // Pre: empty()
  // Post: *this és una còpia de o

  void free();
  // Pre: cert
  // Post: empty()

public:
  // CONSTRUCTORS I DESTRUCTOR ----------------------------------

  Queue();
  // Pre: cert
  // Post: s'ha creat una cua buida

  Queue(const Queue &o); // const. de copia
  // Pre: cert
  // Post: *this és una còpia de o

  ~Queue();
  // Pre: cert
  // Post: memoria alliberada

  // CONSULTORS -------------------------------------------------
  bool empty() const;
  // Pre: cert
  // Post: resultat = cert si i només si la cua és buida

  int first() const;
  // Pre: not empty()
  // Post: resultat = primer string de la cua

  // MODIFICADORS -----------------------------------------------
  void inqueue(int s);
  // Pre: cert
  // Post: s'ha afegit s al final de la cua

  void outqueue();
  // Pre: cert
  // Post: s'ha eliminat el primer element de la cua

  // OPERADORS REDEFINITS --------------------------------------
  Queue &operator=(const Queue &o);
  // Pre: cert
  // Post: *this és una còpia de o
};

#endif // CUA_STRING_H
