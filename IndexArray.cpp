#include "IndexArray.h"

IndexArray::IndexArray()
{
}

IndexArray::IndexArray(const Gestor &g, string filtre, string key_word)
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

void IndexArray::order(string criteria)
{
    i_order(0, this->size - 1, criteria);
}

void IndexArray::i_order(int left, int right, string criteria)
{
    int k = -1;
    if (left < right)
    {
        part(left, right, k, criteria);
        i_order(left, k - 1, criteria);
        i_order(k + 1, right, criteria);
    }
}

void IndexArray::part(int left, int right, int &pos_pivot, string criteria)
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

bool IndexArray::compare(int a, int b, string criteria)
{
    return gest[a].is_minor(gest[b], criteria);
}

void IndexArray::change(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int IndexArray::get_size() const
{
    return this->size;
}

Song &IndexArray::operator[](int inx)
{
    return gest[index_array[inx]];
}

const Song &IndexArray::operator[](int inx) const
{
    return gest[index_array[inx]];
}

IndexArray::~IndexArray()
{
    free();
}

void IndexArray::free()
{
    delete[] index_array;
    index_array = NULL;
}

void IndexArray::copi(const IndexArray &t)
{
    size = t.size;
    index_array = new int[size];
    for (int i = 0; i < size; i++)
        index_array[i] = t.index_array[i];
}

IndexArray &IndexArray::operator=(const IndexArray &t)
{
    if (this != &t)
    {
        free();
        copi(t);
    }
    return *this;
}

bool IndexArray::exist(string title, string artist) const
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

int IndexArray::pos_exist(string title, string artist) const
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