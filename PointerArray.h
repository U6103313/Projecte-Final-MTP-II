#ifndef POINTERARRAY_H
#define POINTERARRAY_H
#include "Gestor.h"

class PointerArray
{
public:
    PointerArray();
    PointerArray(Gestor g);
    void quick_sort(string criteria = "title");
    Song &operator[](int inx);
    const Song &operator[](int inx) const;
    ~PointerArray();

private:
    Song **pointer_array;
    int size;
    void i_quick_sort(int left, int right, string criteria);
    void partition(int left, int right, int &pos_pivot, string criteria);
    void change(Song *&a, Song *&b);
};

#endif