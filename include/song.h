#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#include <string>

#include "name.h"
#include "date.h"
#include "duration.h"

class Song {
private:
    std::string title;
    std::string artist;
    std::string album;
    Date date;
    std::string file;
    Duration duration;
    int rankPos;

public:
    Song();
    Song(const Song&);

    std::string getTitle()const;
    std::string getArtist()const;
    std::string getAlbum()const;
    Date getDate()const;
    std::string getFile()const;
    Duration getDuration()const;
    int getRank()const;

    std::string toString()const;

    void setTitle(const std::string&);
    void setArtist(const std::string&);
    void setAlbum(const std::string&);
    void setDate(const Date&);
    void setFile(const std::string&);
    void setDuration(const Duration&);
    void setRank(const int&);

    bool operator==(const Song&)const;
    bool operator!=(const Song&)const;
    bool operator<=(const Song&)const;
    bool operator>=(const Song&)const;
    bool operator<(const Song&)const;
    bool operator>(const Song&)const;

    friend std::ostream& operator<<(std::ostream&,const Song&);
    friend std::istream& operator>>(std::istream&, Song&);

    Song& operator=(const Song&);
};

#endif // SONG_H_INCLUDED
