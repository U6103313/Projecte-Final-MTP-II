#include "PointerArray.h"

PointerArray::PointerArray()
{
}

PointerArray::PointerArray(Gestor g)
{
    this->size = g.table_size();
    this->pointer_array = new Song *[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->pointer_array[i] = &g[i];
    }
}

void PointerArray::order(string criteria)
{
    i_order(0, this->size - 1, criteria);
}

void PointerArray::i_order(int left, int right, string criteria)
{
    int k = -1;
    if (left < right)
    {
        part(left, right, k, criteria);
        i_order(left, k - 1, criteria);
        i_order(k + 1, right, criteria);
    }
}

void PointerArray::part(int left, int right, int &pos_pivot, string criteria)

{
    Song *pivot = this->pointer_array[right];
    pos_pivot = left;
    for (int i = left; i <= right - 1; i++)
    {
        if (pointer_array[i]->is_minor(*pivot, criteria))
        {
            change(pointer_array[i], pointer_array[pos_pivot]);
            pos_pivot++;
        }
    }
    change(pointer_array[right],pointer_array[pos_pivot]);
}

void PointerArray::change(Song *&a, Song *&b)
{
    Song *temp = a;
    a = b;
    b = temp;
}

Song &PointerArray::operator[](int inx)
{
    return *this->pointer_array[inx];
}

const Song &PointerArray::operator[](int inx) const
{
    return *this->pointer_array[inx];
}

PointerArray::~PointerArray()
{
}