#include <iostream>

#include "menu.h"
#include "song.h"

using namespace std;

int main() {
    List<Song> lista;
    Menu::start(lista);
    return 0;
}
