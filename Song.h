#ifndef SONG_H
#define SONG_H
#include <iostream>
using namespace std;

class Song
{
public:
    Song();
    Song(int uid, int year, int duration, int reproductions, string title, string artist, string gendre, string mood);
    ~Song();

private:
    int uid, year, duration, reproductions;
    string title, artist, gender, mood;
};

#endif