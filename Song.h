#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <iomanip>
using namespace std;

class Song
// Descripció: Classe que representa una cançó amb atributs com títol, artista, gènere, any, durada i reproduccions
{
public:
    // ----- Constructors ------
    Song();
    // Pre: --
    // Post: S'ha creat una cançó buida
    Song(int uid, int year, int duration, int reproductions, string title, string artist, string gendre, string mood);
    // Pre: --
    // Post: S'ha creat una cançó amb els atributs especificats
    void print(string tipe) const;
    // Pre: tipe pot ser "title", "gender", "selection", "reproductions"
    // Post: S'ha imprès la cançó segons el tipus especificat

    // ----- Consultors -----
    bool is_minor(const Song s, string criteria = "title") const;
    // Pre:
    // Post:
    string get_title() const;
    // Pre: --
    // Post: S'ha retornat el títol de la cançó
    string get_artist() const;
    // Pre: --
    // Post: S'ha retornat l'artista de la cançó
    string get_gender() const;
    // Pre: --
    // Post: S'ha retornat el gènere de la cançó
    int get_uid() const;
    // Pre: --
    // Post: S'ha retornat l'identificador de la cançó
    string get_mood() const;
    // Pre: --
    // Post: S'ha retornat l'estat d'ànim de la cançó
    void update_reproductions();
    // Pre: --
    // Post: S'ha incrementat el nombre de reproduccions de la cançó en + 1
    string transfom_second(int time) const;
    // Pre: time és un enter que representa la durada en segons
    // Post: Retorna una cadena de text que representa la durada en format " mm' ss'' "

    // ------ Statics ------
    static int duration_minutes_to_seconds(int minutes, int seconds = 0);
    // Pre: minutes i seconds són enters que representen minuts i segons respectivament
    // Post: Retorna la durada en segons de la cançó

private:
    int uid, year, duration, reproductions;
    string title, artist, gender, mood;
};

#endif