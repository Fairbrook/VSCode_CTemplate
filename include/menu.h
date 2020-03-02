#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <string>

#include "list.h"
#include "song.h"

class Menu {
public:
    void start(List<Song,50>&);

    void showMenu(List<Song,50>);

    void addSong(List<Song,50>&);
    void deleteSong(List<Song,50>&);

    static char inputOpt();
    static int inputPos();
    static std::string inputCad(const std::string&);

    static void wait();
};

#endif // MENU_H_INCLUDED
