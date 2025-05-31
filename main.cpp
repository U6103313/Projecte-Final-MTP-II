// ENTRADA:
// SORTIDA:

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "Gestor.h"
#include "PointerArray.h"
using namespace std;

const string STICK_LINE = string(70, '-');
const string EQUAL_LINE = string(70, '=');

void reed_file(Gestor &gest)
// Pre: --
// Post:
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
        for (int i = 0; i < n_recent; i++)
        {
            int uid;
            f_in >> uid;
            uid--;
            gest.add_song_to_stack(uid);
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
{
    cout<<"[CANCO"<<endl;
    int duration, year, rep;
    string gender, mood, title, artist;
    cout<<left<<setw(18)<<"Titol:";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,title);
    cout<<left<<setw(18)<<"Artista:";
    getline(cin, artist);
    cout<<left<<setw(18)<<"Any:";
    cin >> year;
    cout<<left<<setw(18)<<"Durada:";
    cin >> duration;
    cout<<left<<setw(18)<<"Genere:"; 
    cin>>gender;
    cout<<left<<setw(18)<<"Estat d'anim:";
    cin>>mood;
    cout<<left<<setw(18)<<"N. reproduccions:";
    cin>>rep;
    cout<<"FI CANCO]"<<endl;
    Song s(gest.table_size(), year, duration, rep, title, artist,gender,mood);
    gest.add_song_to_array(s);
}

void write_catalog(const Gestor &gest)
{
    PointerArray pointer_array(gest);
    pointer_array.order("title");
    for (int i = 0; i < gest.table_size(); i++)
    {
        cout << "[ #" << setw(2) << i + 1 << " ] ";
        pointer_array[i].print("title");
        cout << endl;
    }
}

void write_gender(const Gestor &gest)
{
    PointerArray pointer_array(gest);
    pointer_array.order("gender");
    for (int i = 0; i < gest.table_size(); i++)
    {
        cout << "[ #" << setw(2) << i + 1 << " ] ";
        pointer_array[i].print("gender");
        cout << endl;
    }
}

void escriure(const Gestor &gest)
{
    PointerArray p(gest);
    for (int i = 0; i < gest.table_size(); i++)
    {
        p[i].print("title");
        cout << endl;
    }
}

void menu(Gestor &gest)
// Pre: El fitxer esta llegit i la pila, cua i taula estan omplertes
// Post:
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
        }
        else if (funcion == "seleccio")
        {
            cout<<"[CANCO"<<endl;
            gest[gest.get_selected()].print("selection");
            cout<<endl<<"FI CANCO]"<<endl;
        }
        else if (funcion == "buidar")
        {
        }
        else if (funcion == "repseleccio")
        {
        }
        else if (funcion == "repcua")
        {
        }
        else if (funcion == "seleccionar ")
        {
            cin >> funcion;
            if (funcion == "totes")
            {
            }
            else if (funcion == "artista")
            {
                cin >> funcion;
            }
            else if (funcion == "anim")
            {
                cin >> funcion;
            }
            else if (funcion == "titol")
            {
                cin >> funcion;
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
            }
            else if (funcion == "recents")
            {
            }
            else if (funcion == "top10")
            {
            }
        }
        else if (funcion == "sortir")
        {
        }
        else
        {
            cout << "[Avis] Ordre desconeguda: " << funcion << endl;
        }
        cout << EQUAL_LINE << endl;
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