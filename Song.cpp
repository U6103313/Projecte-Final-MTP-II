#include "Song.h"
#include <string>
using namespace std;

Song::Song()
{
    this->duration = 0;
    this->year = 0;
    this->uid = 99999999;
    this->reproductions = 0;
    this->title = "XXX";
    this->artist = "XXX";
    this->gender = "XXX";
    this->mood = "XXX";
}

Song::Song(int c_uid, int c_year, int c_duration, int c_reproductions, string c_title, string c_artist, string c_gender, string c_mood)
{
    this->duration = c_duration;
    this->year = c_year;
    this->uid = c_uid;
    this->reproductions = c_reproductions;
    this->title = c_title;
    this->artist = c_artist;
    this->gender = c_gender;
    this->mood = c_mood;
}
