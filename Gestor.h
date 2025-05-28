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
    void add_song_to_queue(int uid);
    void add_song_to_stack(int uid);
    void set_name(string name);
    void set_actual_song(int actual);
    Song &operator[](int idx);
    const Song &operator[](int idx) const;
    int table_size() const;

private:
    string name;
    int uid;
    DynamicArray table;
    Stack recent;
    Queue pending;


};

#endif