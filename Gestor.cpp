#include "Gestor.h"

Gestor::Gestor()
{
    this->name = "XXX";
    this->uid = 0;
}

// ------Funcions per afegir valors a les estructures de dades------
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

Gestor::~Gestor()
{
}

//--- Funcions per definir valors a les variable -----
void Gestor::set_name(string name_file)
{
    this->name = name_file;
}

void Gestor::set_actual_song(int actual)
{
    this->uid = actual;
}