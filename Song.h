#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <iomanip>
using namespace std;

class Song
{
public:
    Song();
    Song(int uid, int year, int duration, int reproductions, string title, string artist, string gendre, string mood);
    ~Song();
    void print(string tipe) const;
    bool is_minor (const Song s, string criteria = "title") const;
    string get_title() const;
    string get_artist() const;
    string get_gender() const;

private:
    string transfom_second(int time) const;
    int uid, year, duration, reproductions;
    string title, artist, gender, mood;
};

#endif