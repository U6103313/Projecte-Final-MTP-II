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

void Song::print(string tipe) const
{
    if (tipe == "title")
    {
        cout << "[ " << this->title << " | " << this->artist << " | " << this->year << " | " << this->transfom_second(this->duration) << " | " << this->gender << " | " << this->mood << " ]";
    }
    else if (tipe == "gender")
    {
        cout << this->gender << setw(5) << "[ " << this->title << " | " << this->artist << " ]";
    }
    else if (tipe == "selection")
    {
        cout << left << setw(18) << "Titol:"<< this->title << endl;
        cout << left << setw(18) << "Artista:"<< this->artist << endl;
        cout << left << setw(18) << "Any:"<< this->year << endl;
        cout << left << setw(18) << "Durada:"<<this->transfom_second(this->duration) << endl;
        cout << left << setw(18) << "Genere:"<<this->gender << endl;
        cout << left << setw(18) << "Estat d'anim:"<<this->mood << endl;
        cout << left << setw(18) << "N. reproduccions:"<<this->reproductions;
        
    }
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
    else if (criteria == "gender")
    {
        if (this->gender < s.get_gender())
        {
            return true;
        }
        else if (this->gender == s.get_gender())
        {
            return is_minor(s, "title");
        }
        else
        {
            return false;
        }
    }
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
string Song::get_gender() const
{
    return this->gender;
}