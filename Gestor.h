#ifndef GESTOR_H
#define GESTOR_H
#include "DynamicArray.h"
#include "Stack.h"
#include "Queue.h"

class Gestor
{
public:
    Gestor();
    ~Gestor();
    void add_song_to_array(Song song);
    // Pre:
    // Post:
    void add_song_to_queue(int uid);
    // Pre:
    // Post: 
    void add_song_to_stack(int uid);
    // Pre:
    // Post: 
    void set_name(string name);
    // Pre:
    // Post: 
    void set_actual_song(int actual);
    // Pre:
    // Post: 
    Song &operator[](int idx);
    // Pre:
    // Post: 
    const Song &operator[](int idx) const;
    // Pre:
    // Post: 
    int table_size() const;
    // Pre:
    // Post: 

private:
    string name;
    int uid;
    DynamicArray table;
    Stack recent;
    Queue pending;


};

#endif