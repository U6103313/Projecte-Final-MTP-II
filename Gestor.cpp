#include "Gestor.h"

Gestor::Gestor()
{
    this->name = "XXX";
    this->selected = 0;
}

void Gestor::add_song_to_array(Song s)
{
    this->table.add(s);
}

void Gestor::add_song_to_queue(int code_song)
{
    this->pending.inqueue(code_song);
}

void Gestor::add_song_to_stack(int code_song)
{
    this->recent.tostak(code_song);
}

void Gestor::set_name(string name_file)
{
    this->name = name_file;
}

void Gestor::set_actual_song(int actual)
{
    this->selected = actual;
}

Song &Gestor::operator[](int idx)
{
    return this->table[idx];
}

const Song &Gestor::operator[](int idx) const
{
    return this->table[idx];
}

int Gestor::table_size() const
{
    return this->table.size();
}

int Gestor::get_selected() const
{
    return this->selected;
}

void Gestor::delete_recent()
{
    while (!this->recent.empty())
    {
        this->recent.unstak();
    }
}
Queue Gestor::copy_queue() const
{
    Queue copy = this->pending;
    return copy;
}

Stack Gestor::copy_recent() const
{
    Stack copy = this->recent;
    return copy;
}

void Gestor::delete_firs_element_queue()
{
    this->pending.outqueue();
}