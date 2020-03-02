#include <iostream>

#include "menu.h"
#include "song.h"

using namespace std;

int main() {
    List<Song,50> lista;
    Menu menu;
    menu.start(lista);
    return 0;
}
