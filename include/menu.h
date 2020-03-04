#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <string>

#include "list.h"
#include "song.h"
#include "table.h"

class Menu {
public:
    void start(List<Song>&);

    static void showMenu(const List<Song>&);

    void addSong(List<Song>&);
    void deleteSong(List<Song>&);

    static char inputOpt();
    static int inputPos();
    static std::string inputCad(const std::string&);
    static Name inputName();
    static Date inputDate();
    static Duration inputDuration();
    static void formatList(const List<Song>&);

    static void wait();
};

#endif // MENU_H_INCLUDED
