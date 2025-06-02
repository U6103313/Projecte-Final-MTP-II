// ENTRADA: L'usuari el nom d'un cataleg i les funcions que vol realitzar sobre aquest catàleg.
// SORTIDA: El programa llegeix el catàleg, i permet a l'usuari afegir cançons, reproduir-les, veure les recents, pendents, etc.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "Gestor.h"
#include "IndexArray.h"
using namespace std;

const string STICK_LINE = string(70, '-');
const string EQUAL_LINE = string(70, '=');

void reed_file(Gestor &gest)
// Pre: --
// Post: La taula de cançons, la pila de recents i la cua de pendents estan omplertes
{
    cout << "Nom del fitxer de cataleg: ";
    string name_file;
    cin >> name_file;
    ifstream f_in(name_file.c_str());
    if (!f_in.is_open())
    {
        cout << "Fitxer mal escrit";
    }
    else
    {
        gest.set_name(name_file);
        cout << "Fitxer " << name_file << endl;
        string a;
        f_in >> a;
        int actual_song;
        f_in >> actual_song;
        actual_song--;
        gest.set_actual_song(actual_song);
        f_in >> a;
        int n_songs;
        f_in >> n_songs;
        for (int i = 0; i < n_songs; i++)
        {
            int uid, duration, year, rep;
            string gender, mood, title, artist;
            f_in >> uid;
            uid--;
            f_in.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(f_in, title);
            getline(f_in, artist);
            f_in >> year;
            f_in >> duration;
            f_in >> gender;
            f_in >> mood;
            f_in >> rep;
            Song s(uid, year, duration, rep, title, artist, gender, mood);
            gest.add_song_to_array(s);
        }
        f_in >> a;
        int n_recent;
        f_in >> n_recent;
        int recent_table[n_recent];
        for (int i = 0; i < n_recent; i++)
        {
            int uid;
            f_in >> uid;
            uid--;
            recent_table[i] = uid;
        }
        for (int i = n_recent - 1; i >= 0; i--)
        {
            gest.add_song_to_stack(recent_table[i]);
        }
        f_in >> a;
        int n_pending;
        f_in >> n_pending;
        for (int i = 0; i < n_pending; i++)
        {
            int uid;
            f_in >> uid;
            uid--;
            gest.add_song_to_queue(uid);
        }
        f_in.close();
    }
}

void add_new_song(Gestor &gest)
// Pre: El gestor esta creat
// Post: S'ha afegit una nova cançó al gestor
{
    int duration, duration_s, duration_m, year;
    string gender, mood, title, artist;
    cout << "Titol: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);
    cout << "Artista: ";
    getline(cin, artist);
    IndexArray index_array(gest);
    index_array.order("title");
    if (!index_array.exist(title, artist))
    {
        cout << "Any: ";
        cin >> year;
        cout << "Durada [' \"]: ";
        cin >> duration_m >> duration_s;
        duration = Song::duration_minutes_to_seconds(duration_m, duration_s);
        cout << "Genere: ";
        cin >> gender;
        cout << "Estat d'anim: ";
        cin >> mood;
        Song s(gest.table_size(), year, duration, 0, title, artist, gender, mood);
        gest.add_song_to_array(s);
        gest.set_actual_song(gest.table_size() - 1);
    }
    else
    {
        cout << "[Avis] Aquest tema ja es al cataleg." << endl;
        gest.set_actual_song(index_array[index_array.pos_exist(title, artist)].get_uid());
    }
}

void write_catalog(const Gestor &gest)
// Pre: gest taula de cançons omplerta
// Post: S'escriu el catàleg de cançons ordenat per títol
{
    cout << EQUAL_LINE << endl;
    IndexArray index_array(gest);
    index_array.order("title");
    for (int i = 0; i < gest.table_size(); i++)
    {
        cout << "[ #" << right << setw(2) << i + 1 << " ] ";
        index_array[i].print("title");
        cout << endl;
    }
    cout << EQUAL_LINE << endl;
}

void write_gender(const Gestor &gest)
// Pre: gest taula de cançons omplerta
// Post: S'escriu el catàleg de cançons ordenat per gènere
{
    cout << EQUAL_LINE << endl;
    IndexArray index_array(gest);
    index_array.order("gender");
    for (int i = 0; i < gest.table_size(); i++)
    {
        cout << "[ #" << right << setw(2) << i + 1 << " ] ";
        index_array[i].print("gender");
        cout << endl;
    }
    cout << EQUAL_LINE << endl;
}

void write_top10(const Gestor &gest)
// Pre: gest taula de cançons omplerta
// Post: S'escriu el top 10 de cançons ordenat per reproduccions
{
    cout << EQUAL_LINE << endl;
    IndexArray index_array(gest);
    index_array.order("reproductions");
    for (int i = 0; i < 10; i++)
    {
        cout << "[ #" << right << setw(2) << i + 1 << " ] ";
        index_array[i].print("reproductions");
        cout << endl;
    }
    cout << EQUAL_LINE << endl;
}

void write_reproduccion(const int &uid, Gestor &gest)
// Pre: uid es un identificador de cançó valid i gest taula de cançons omplerta
// Post: S'escriu la cançó seleccionada i s'actualitzen les reproduccions
{
    cout << "Reproduint..." << endl;
    gest[uid].print("title");
    cout << endl;
    gest[uid].update_reproductions();
    gest.add_song_to_stack(uid);
}

void write_pending(const Gestor &gest)
// Pre: gest taula de cançons omplerta i cua de pendents omplerta
// Post: S'escriu la cua de cançons pendents
{
    cout << EQUAL_LINE << endl;
    Queue pending = gest.copy_queue();
    int i = 1;
    if (pending.empty())
    {
        cout << "Cap coincidencia." << endl;
    }
    while (!pending.empty())
    {
        cout << "[ #" << right << setw(2) << i << " ] ";
        gest[pending.first()]   .print("title");
        cout << endl;
        pending.outqueue();
        i++;
    }
    cout << EQUAL_LINE << endl;
}

void write_recents(const Gestor &gest)
// Pre: gest taula de cançons omplerta i pila de recents omplerta
// Post: S'escriu la pila de cançons recents
{
    cout << EQUAL_LINE << endl;
    Stack recent = gest.copy_recent();
    int i = 1;
    if (recent.empty())
    {
        cout << "Cap coincidencia." << endl;
    }
    while (!recent.empty())
    {
        cout << "[ #" << right << setw(2) << i << " ] ";
        gest[recent.top()].print("title");
        cout << endl;
        recent.unstak();
        i++;
    }
    cout << EQUAL_LINE << endl;
}

void seleccion_song(Gestor &gest, string funcion, string key_word)
// Pre: gest taula de cançons omplerta, funcion es una de les següents: "totes", "artista", "anim", "titol" , key_word es una cadena de text per fer de filtre
// Post: S'ha fet una selecció de cançons segons la funció i la paraula clau, i s'ha actualitzat la cançó seleccionada al gestor
{
    IndexArray selececcion_opt(gest, funcion, key_word);
    selececcion_opt.order("title");
    if (selececcion_opt.get_size() == 1)
    {
        cout << "Seleccio automatica (un sol resultat)." << endl;
        gest.set_actual_song(selececcion_opt[0].get_uid());
    }
    else if (selececcion_opt.get_size() == 0)
    {
        cout << "Cap coincidencia." << endl;
    }
    else
    {
        for (int i = 0; i < selececcion_opt.get_size(); i++)
        {
            cout << "[ #" << right << setw(2) << i + 1 << " ] ";
            selececcion_opt[i].print("title");
            cout << endl;
        }
        cout << "Seleccio [ 1.." << selececcion_opt.get_size() << " ]? ";
        int seleccion;
        cin >> seleccion;
        gest.set_actual_song(selececcion_opt[seleccion - 1].get_uid());
    }
}

void menu(Gestor &gest)
// Pre: El fitxer esta llegit i la pila, cua i taula estan omplertes
// Post: S'ha mostrat el menú i s'han executat les ordres introduïdes per l'usuari fins que es selecciona "sortir"
{
    string funcion = "XXX";
    while (funcion != "sortir")
    {
        cout << "MTP? ";
        cin >> funcion;
        if (funcion == "afegir")
        {
            add_new_song(gest);
        }
        else if (funcion == "encuar")
        {
            gest.add_song_to_queue(gest.get_selected());
        }
        else if (funcion == "buidar")
        {
            gest.delete_recent();
        }
        else if (funcion == "seleccio")
        {
            cout << STICK_LINE << endl;
            cout << "[CANCO" << endl;
            gest[gest.get_selected()].print("selection");
            cout << endl
                 << "FI CANCO]" << endl;
            cout << STICK_LINE << endl;
        }
        else if (funcion == "repseleccio")
        {
            write_reproduccion(gest.get_selected(), gest);
        }
        else if (funcion == "repcua")
        {
            if (gest.copy_queue().empty())
            {
                cout << "[Avis] Res a reproduir." << endl;
            }
            else
            {
                write_reproduccion(gest.copy_queue().first(), gest);
                gest.delete_firs_element_queue();
            }
        }
        else if (funcion == "seleccionar")
        {
            cin >> funcion;
            string key_word = "XXX";
            if (funcion == "totes")
            {
                seleccion_song(gest, funcion, key_word);
            }
            else if (funcion == "artista")
            {
                cin >> key_word;
                seleccion_song(gest, funcion, key_word);
            }
            else if (funcion == "anim")
            {
                cin >> key_word;
                seleccion_song(gest, funcion, key_word);
            }
            else if (funcion == "titol")
            {
                cin >> key_word;
                seleccion_song(gest, funcion, key_word);
            }
        }
        else if (funcion == "escriure")
        {
            cin >> funcion;
            if (funcion == "cataleg")
            {
                write_catalog(gest);
            }
            else if (funcion == "genere")
            {
                write_gender(gest);
            }
            else if (funcion == "pendents")
            {
                write_pending(gest);
            }
            else if (funcion == "recents")
            {
                write_recents(gest);
            }
            else if (funcion == "top10")
            {
                write_top10(gest);
            }
            else
            {
                cout << "[Avis] Subordre desconeguda: " << funcion << endl;
            }
        }
        else if (funcion == "sortir")
        {
        }
        else
        {
            cout << "[Avis] Ordre desconeguda: " << funcion << endl;
        }
    }
}

int main()
{
    Gestor gest;
    reed_file(gest);
    cout << "Benvingut a MTP: Music-To-Play." << endl
         << "Entra les ordres que vulguis!" << endl;
    menu(gest);
    cout << "Fins aviat!";
    return 0;
}