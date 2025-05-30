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

Song::~Song()
{
    // Empty destructor - no dynamic memory to clean up
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

void Song::print() const
{
    cout << "[ " << this->title << " | " << this->artist << " | " << this->year << " | " << this->transfom_second(this->duration) << " | " << this->gender << " | " << this->mood << " ]";
}

string Song::transfom_second(int time) const
{
    int min = time / 60;
    int sec = time % 60;
    string min_str = to_string(min);
    string sec_str = to_string(sec);
    return min_str + "' " + sec_str + "''";
}

bool Song::is_minor(const Song s, string criteria) const
{
    if (criteria == "title")
    {
        if (this->title < s.get_title())
        {
            return true;
        }
        else if (this->title == s.get_title())
        {
            return this->artist < s.get_artist();
        }
        return false;
    }
    // For any other criteria, return false as a default case
    return false;
}

string Song::get_title() const
{
    return this->title;
}
string Song::get_artist() const
{
    return this->artist;
}