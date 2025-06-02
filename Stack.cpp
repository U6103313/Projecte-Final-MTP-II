#include "Stack.h"
#include <iostream>
#include <string>

Stack::Stack()
{
    a_top = NULL;
}

Stack::Stack(const Stack &o)
{
    a_top = NULL;
    copia(o); // crida a mètode privat
}

Stack::~Stack()
{
    allibera(); // crida a mètode privat
}

// CONSULTORS -------------------------------------------------
bool Stack::empty() const
{
    return a_top == NULL;
}

int Stack::top() const
{
    return a_top->value;
}

// MODIFICADORS -----------------------------------------------
void Stack::tostak(int s)
{
    Node *nou = new Node; // necessari reservar memoria
    nou->value = s;
    nou->next = a_top;
    a_top = nou;
}

void Stack::unstak()
{
    Node *aux = a_top;
    a_top = a_top->next;
    delete aux;
}

// OPERADORS ---------------------------------------------
Stack &Stack::operator=(const Stack &o)
{
    if (this != &o)
    {
        allibera();
        copia(o);
    }
    return *this;
}

// METODES PRIVATS ------------------------------------------
void Stack::copia(const Stack &o)
{
    if (!o.empty())
    {
        Node *p, *q, *aux;
        p = new Node;
        a_top = p;
        aux = o.a_top;
        p->value = aux->value;
        p->next = NULL;
        q = p;
        while (aux->next != NULL)
        {
            aux = aux->next;
            p = new Node;
            q->next = p;
            p->value = aux->value;
            p->next = NULL;
            q = p;
        }
    }
}

void Stack::allibera()
{
    while (!empty())
    {
        Node *aux = a_top;
        a_top = a_top->next;
        delete aux;
    }
}