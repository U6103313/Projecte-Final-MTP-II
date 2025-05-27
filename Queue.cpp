#include "Queue.h"
Queue::Queue()
{
    start = end = NULL;
}

Queue::Queue(const Queue &o)
{
    start = end = NULL;
    copi(o); // crida a metode privat
}

Queue::~Queue()
{
    free();
}

// CONSULTORS -------------------------------------------------

bool Queue::empty() const 
{
    return start == NULL;
}

int Queue::first() const
{
    return start->value;
}

// MODIFICADORS -----------------------------------------------

void Queue::outqueue()
{
    Node *aux = start;
    if (start == end) // nom�s hi ha un element
        start = end = NULL;
    else
        start = start->next;
    delete aux;
}

// OPERADOR ASSIGNACIO
Queue &Queue::operator=(const Queue &o)
{
    if (this != &o)
    {
        free();
        copi(o);
    }
    return *this;
}

// METODES PRIVATS
void Queue::copi(const Queue &o)
{
    Node *i = o.start;
    while (i != NULL)
    {                    // recorrem cua o
        inqueue(i->value); // this->inqueue(i->valor)
        i = i->next;
    }
}

void Queue::free()
{
    while (start != NULL)
    { //! buida()
        Node *aux = start;
        start = start->next;
        delete aux;
    }
    end = NULL;
}

void Queue::inqueue(int s)
{
    Node *a = new Node;
    if (this->empty())
    {
        this->start = a;
        this->end = a;
    }
    else
    {
        end->next = a;
        end = a;
    }
    a->next = NULL;
    a->value = s;
}