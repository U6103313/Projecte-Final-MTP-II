#include <iostream>
#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray()
{
    this->m = 0;
    this->m_max = 10;
    this->taula = new Song[this->m_max];
}

DynamicArray::DynamicArray(int n_punts)
{
    this->m = 0;
    this->m_max = n_punts;
    this->taula = new Song[this->m_max];
}

DynamicArray::DynamicArray(const DynamicArray &t)
{
    copi(t);
}

void DynamicArray::free()
{
    delete[] taula;
    taula = NULL;
}

void DynamicArray::copi(const DynamicArray &t)
{
    m = t.m;
    m_max = t.m_max;
    reserve();
    for (int i = 0; i < m; i++)
        taula[i] = t.taula[i];
}

void DynamicArray::reserve()
{
    this->taula = new Song[m_max];
}

void DynamicArray::expand()
{
    Song *aux = this->taula;
    if (m == 0)
    {
        this->taula = new Song[1];
        m_max=1;
    }
    else
    {
        this->taula = new Song[2 * m_max];
        m_max*=2;
    }
    for (int i = 0; i < m; i++)
    {
        this->taula[i] = aux[i];
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
    this->taula[this->m]=p;
    m++;
}

DynamicArray::~DynamicArray()
{
    free();
}

Song &DynamicArray::operator[](int idx)
{
    return taula[idx];
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