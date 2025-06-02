#include <iostream>
#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray()
{
    this->m = 0;
    this->m_max = 10;
    this->table = new Song[this->m_max];
}

DynamicArray::DynamicArray(int n_punts)
{
    this->m = 0;
    this->m_max = n_punts;
    this->table = new Song[this->m_max];
}

DynamicArray::DynamicArray(const DynamicArray &t)
{
    copi(t);
}

void DynamicArray::free()
{
    delete[] table;
    table = NULL;
}

void DynamicArray::copi(const DynamicArray &t)
{
    m = t.m;
    m_max = t.m_max;
    reserve();
    for (int i = 0; i < m; i++)
        table[i] = t.table[i];
}

void DynamicArray::reserve()
{
    this->table = new Song[m_max];
}

void DynamicArray::expand()
{
    Song *aux = this->table;
    if (m == 0)
    {
        this->table = new Song[1];
        m_max=1;
    }
    else
    {
        this->table = new Song[2 * m_max];
        m_max*=2;
    }
    for (int i = 0; i < m; i++)
    {
        this->table[i] = aux[i];
    }
    delete []aux;
}

int DynamicArray::size() const
{
    return this->m;
}

int DynamicArray::capacity() const
{
    return this->m_max;
}

bool DynamicArray::empty() const
{
    return 0==this->m;
}

void DynamicArray::add(const Song &p)
{
    if(m==m_max){
        expand();
    }
    this->table[this->m]=p;
    m++;
}

DynamicArray::~DynamicArray()
{
    free();
}

Song &DynamicArray::operator[](int idx)
{
    return table[idx];
}

const Song &DynamicArray::operator[](int idx) const
{
    return table[idx];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &t)
{
    if (this != &t)
    {
      free();
      copi(t);
    }
    return *this;
}