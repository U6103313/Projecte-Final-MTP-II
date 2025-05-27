// ENTRADA:
// SORTIDA:

#include <iostream>
#include <fstream>
#include <limits>
#include "Gestor.h"
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
            if (i < actual_song)
            {
                gest.add_song_to_stack(uid);
            }
            else if (i > actual_song)
            {
                gest.add_song_to_queue(uid);
            }
        }
        f_in.close();
    }
}

void menu(Gestor &gest)
// Pre: El fitxer esta llegit i la pila, cua i taula estan omplertes
// Post:
{
    cout << "MTP? " << endl;
    string funcion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, funcion);
    if (funcion == "afegir")
    {
    }
    else if (funcion == "encuar")
    {
    }
    else if (funcion == "buidar")
    {
    }
    else if (funcion == "seleccio")
    {
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
    else if (funcion == "")
    {
    }
    else if (funcion == "")
    {
    }
    else if (funcion == "sortir")
    {
    }
}

int main()
{
    Gestor gest;
    reed_file(gest);
    cout << "Benvingut a MTP: Music-To-Play." << endl
         << "Entra les ordres que vulguis!" << endl;
    menu(gest);
    return 0;
}