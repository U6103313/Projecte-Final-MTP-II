#include "PointerArray.h"

PointerArray::PointerArray()
{
}

PointerArray::PointerArray(const Gestor &g, string filtre, string key_word)
{
    this->size = g.table_size();
    this->gest = g;
    this->index_array = new int[this->size];
    int pos = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (filtre == "totes")
        {
            this->index_array[i] = gest[i].get_uid();
            pos++;
        }
        else
        {
            string word="XXX";
            if (filtre == "artista")
            {
                word = gest[i].get_artist();
            }
            else if (filtre == "anim")
            {
                word = gest[i].get_mood();
            }
            else if (filtre == "titol")
            {
                word = gest[i].get_title();
            }
            if (word.find(key_word) != string::npos)
            {
                this->index_array[pos] = gest[i].get_uid();
                pos++;
            }
        }
    }
    size = pos;
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
    int pivot = this->index_array[right];
    pos_pivot = left;
    for (int i = left; i <= right - 1; i++)
    {
        if (compare(index_array[i], pivot, criteria))
        {
            change(index_array[i], index_array[pos_pivot]);
            pos_pivot++;
        }
    }
    change(index_array[right], index_array[pos_pivot]);
}

bool PointerArray::compare(int a, int b, string criteria)
{
    return gest[a].is_minor(gest[b], criteria);
}

void PointerArray::change(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int PointerArray::get_size() const
{
    return this->size;
}

Song &PointerArray::operator[](int inx)
{
    return gest[index_array[inx]];
}

const Song &PointerArray::operator[](int inx) const
{
    return gest[index_array[inx]];
}

PointerArray::~PointerArray()
{
}