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
            string word = "XXX";
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
    free();
}

void PointerArray::free()
{
    delete[] index_array;
    index_array = NULL;
}

void PointerArray::copi(const PointerArray &t)
{
    size = t.size;
    index_array = new int[size];
    for (int i = 0; i < size; i++)
        index_array[i] = t.index_array[i];
}

PointerArray &PointerArray::operator=(const PointerArray &t)
{
    if (this != &t)
    {
        free();
        copi(t);
    }
    return *this;
}

bool PointerArray::exist(string title, string artist) const
{
    int left = 0;
    int right = this->size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (gest[index_array[mid]].get_title() == title && gest[index_array[mid]].get_artist() == artist)
        {
            return true;
        }
        else if (gest[index_array[mid]].get_title() < title || (gest[index_array[mid]].get_title() == title && gest[index_array[mid]].get_artist() < artist))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
} 

int PointerArray::pos_exist(string title, string artist) const
{
    int left = 0;
    int right = this->size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (gest[index_array[mid]].get_title() == title && gest[index_array[mid]].get_artist() == artist)
        {
            return mid;
        }
        else if (gest[index_array[mid]].get_title() < title || (gest[index_array[mid]].get_title() == title && gest[index_array[mid]].get_artist() < artist))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Not found
}