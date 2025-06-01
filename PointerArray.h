#ifndef POINTERARRAY_H
#define POINTERARRAY_H
#include "Gestor.h"

class PointerArray
{
public:
    PointerArray();
    PointerArray(const Gestor &g, string filtre = "all", string key_word = "XXX");
    void order(string criteria = "title");
    int get_size() const;
    Song &operator[](int inx);
    const Song &operator[](int inx) const;
    PointerArray &operator=(const PointerArray &t);
    bool exist (string title, string artist) const;
    int pos_exist (string title, string artist) const;
    ~PointerArray();

private:
    int *index_array;
    int size;
    Gestor gest;
    void i_order(int left, int right, string criteria);
    void part(int left, int right, int &pos_pivot, string criteria);
    void change(int &a, int &b);
    bool compare(int a, int b, string criteria);
    void free();
    void copi(const PointerArray &t);
};

#endif