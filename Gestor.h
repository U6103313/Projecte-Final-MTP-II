#ifndef GESTOR_H
#define GESTOR_H
#include "DynamicArray.h"
#include "Stack.h"
#include "Queue.h"

class Gestor
// Descripció: Gestor de cançons que conté una taula, una pila i una cua que permet operar amb ells
{
public:
    // -------- CONSTRUCTORS ----------
    Gestor();
    // Pre: --
    // Post: S'ha creat un gestor buit amb taula, pila i cua buides
    void add_song_to_array(Song song);
    // Pre: Que song no estigui a la taula
    // Post: S'ha afegit la cançó a la taula de cançons
    void add_song_to_queue(int uid);
    // Pre: Que uid sigui un identificador de cançó vàlid
    // Post: S'ha afegit la cançó a la cua de pendents
    void add_song_to_stack(int uid);
    // Pre: Que uid sigui un identificador de cançó vàlid
    // Post: S'ha afegit la cançó a la pila de recents
    void set_name(string name);
    // Pre: --
    // Post: S'ha definit el nom del gestor
    void set_actual_song(int actual);
    // Pre: Que actual sigui un identificador de cançó vàlid
    // Post: S'ha definit la cançó seleccionada al gestor

    void delete_firs_element_queue();
    // Pre: La cua de pendents no està buida
    // Post: S'ha eliminat el primer element de la cua de pendents
    
    // ---------- CONSULTORS ----------
    int table_size() const;
    // Pre: --
    // Post: Retorna la mida de la taula de cançons
    int get_selected() const;
    // Pre: --
    // Post: Retorna l'identificador de la cançó seleccionada
    void delete_recent();
    // Pre: La pila de recents no està buida
    // Post: S'ha eliminat tots els elements de la pila de recents
    Queue copy_queue() const;
    // Pre: --
    // Post: Retorna una còpia de la cua de pendents
    Stack copy_recent() const;
    // Pre: --
    // Post: Retorna una còpia de la pila de recents
    Song &operator[](int idx);
    // Pre: idx < table_size()
    // Post: Retorna la cançó a la posició idx de la taula
    const Song &operator[](int idx) const;
    // Pre: idx < table_size()
    // Post: Retorna la cançó a la posició idx de la taula
    
    private:
    string name;
    int selected;
    DynamicArray table;
    Stack recent;
    Queue pending;


};

#endif