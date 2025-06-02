#ifndef INDEXARRAY_H
#define INDEXARRAY_H
#include "Gestor.h"

class IndexArray
// Descripció: Classe que representa un array d'índexs per accedir a les cançons del Gestor
{
public:
    // ----- Constructor ------
    IndexArray();
    // Pre: --
    // Post: S'ha creat un array d'índexs buit
    IndexArray(const Gestor &g, string filtre = "totes", string key_word = "XXX");
    // Pre: g és un Gestor amb cançons, filtre és un dels següents: "totes", "artista", "anim", "titol", i key_word és una cadena de text per filtrar les cançons
    // Post: S'ha creat un array d'índexs amb les cançons del Gestor segons el filtre i la paraula clau
    void order(string criteria = "title");
    // Pre: criteria és un dels següents: "title", "gender", "reproductions"
    // Post: S'ha ordenat l'array d'índexs segons el criteri especificat
    ~IndexArray();
    // Pre : --
    // Post: S'ha alliberat la memòria de l'array d'índexs

    // ----- Constultors ------
    int get_size() const;
    // Pre: --
    // Post: Retorna la mida de l'array d'índexs
    Song &operator[](int inx);
    // Pre: inx < get_size()
    // Post: Retorna la cançó a la posició inx de l'array d'índexs
    const Song &operator[](int inx) const;
    // Pre: --
    // Post: Retorna la cançó a la posició inx de l'array d'índexs
    IndexArray &operator=(const IndexArray &t);
    // Pre: t és un objecte IndexArray vàlid
    // Post: S'ha copiat el contingut de t a l'objecte actual
    bool exist(string title, string artist) const;
    // Pre: title i artist són cadenes de text que representen el títol i l'artista d'una cançó
    // Post: Retorna cert si existeix una cançó amb el títol i l'artista especificats, fals en cas contrari
    int pos_exist(string title, string artist) const;
    // Pre: title i artist són cadenes de text que representen el títol i l'artista d'una cançó
    // Post: Retorna la posició de la cançó amb el títol i l'artista especificats a l'array d'índexs, -1 si no existeix

private:
    int *index_array;
    int size;
    Gestor gest;
    void i_order(int left, int right, string criteria);
    // Pre: left i right són els límits de l'array d'índexs, criteria és un dels següents: "title", "gender", "reproductions"
    // Post: S'ha ordenat l'array d'índexs entre left i right segons el criteri especificat
    void part(int left, int right, int &pos_pivot, string criteria);
    // Pre: left i right són els límits de l'array d'índexs, criteria és un dels següents:  "title", "gender", "reproductions"
    // Post: S'ha partit l'array d'índexs entre left i right, col·locant el pivot a la posició pos_pivot segons el criteri especificat
    void change(int &a, int &b);
    // Pre: a i b són enters que representen posicions a l'array d'índexs
    // Post: S'han intercanviat els valors de a i b
    bool compare(int a, int b, string criteria);
    // Pre: a i b són posicions a l'array d'índexs, criteria és un dels següents:  "title", "gender", "reproductions"
    // Post: Retorna cert si la cançó a la posició a és menor que la cançó a la posició b segons el criteri especificat, fals en cas contrari
    void free();
    // Pre: --
    // Post: S'ha alliberat la memòria de l'array d'índexs
    void copi(const IndexArray &t);
    // Pre: t és un objecte IndexArray vàlid
    // Post: S'ha copiat el contingut de t a l'objecte actual
};

#endif