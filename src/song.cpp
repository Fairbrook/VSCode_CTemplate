#include "song.h"

using namespace std;

Song::Song() {}

Song::Song(const Song&s):
    title(s.title),
    artist(s.artist),
    album(s.album),
    date(s.date),
    file(s.file),
    duration(s.duration),
    rankPos(s.rankPos) {}

string Song::getTitle()const{return title;}
string Song::getArtist()const{return artist;}
string Song::getAlbum()const{return album;}
Date Song::getDate()const{return date;}
string Song::getFile()const{return file;}
Duration Song::getDuration()const{return duration;}
int Song::getRank()const{return rankPos;}

string Song::toString() const{
    string result;
    result+=title;
    result+=" | ";
    result+=artist;
    result+=" | ";
    result+=album;
    result+=" | ";
    result+=date.toString();
    result+=" | ";
    result+=file;
    result+=" | ";
    result+=duration.toString();
    result+=" | ";
    result+=to_string(rankPos);
    return result;
}

void Song::setTitle(const string&t){title = t;}
void Song::setArtist(const string&n){artist = n;}
void Song::setAlbum(const std::string&a){album = a;}
void Song::setDate(const Date&d){date = d;}
void Song::setFile(const std::string&f){file = f;}
void Song::setDuration(const Duration&d){duration = d;}
void Song::setRank(const int&r){rankPos = r;}

bool Song::operator==(const Song&s)const{
    return title == s.title;
}

bool Song::operator!=(const Song&s)const{
    return !(*this == s);
}
bool Song::operator<=(const Song&s)const{
    return title <= s.title;
}
bool Song::operator>=(const Song&s)const{
    return title >= s.title;
}
bool Song::operator<(const Song&s)const{
    return title < s.title;
}
bool Song::operator>(const Song&s)const{
    return title > s.title;
}

ostream& operator<<(ostream&os,const Song&s){
    os << s.title << endl
        << s.artist << endl
        << s.album << endl
        << s.date.toString() << endl
        << s.file << endl
        << s.duration.toString() << endl
        << s.rankPos;
    return os;
}

istream& operator>>(istream &is,Song&s){
    getline(is,s.title);
    getline(is,s.artist);
    getline(is,s.album);
    is >> s.date;
    getline(is,s.file);
    is >> s.duration;
    is >> s.rankPos;
    while(is.good() && is.get()!='\n');
    return is;
}

Song& Song::operator=(const Song&s) {
    title = s.title;
    artist = s.artist;
    album = s.album;
    date = s.date;
    file = s.file;
    duration = s.duration;
    rankPos = s.rankPos;
    return *this;
}
