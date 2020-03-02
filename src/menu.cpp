#include "menu.h"

using namespace std;

void Menu::start(List<Song> &l) {
    char opt;
    do {
        try {
            showMenu(l);
            opt = inputOpt();
            cout << endl;
            switch(opt) {
            case 'a':
                addSong(l);
                break;
            case 'b':
                deleteSong(l);
                break;
            case 's':
                cout << "Bye" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                wait();
                break;
            }
        } catch(ListException &ex) {
            cout << "Error de Lista: " << ex.what() << endl;
            wait();
        } catch(...) {
            cout << "Error inesperado";
            wait();
        }
    } while(opt!='s');
}

void Menu::showMenu(List<Song> l) {
    cout << endl;
    cout << "== Actividad 3. Lista Estatica ==" << endl;
    cout << "Lista actual:"<<endl;
    cout << l.toString() << endl;
    cout << " * Menu *" << endl;
    cout << "[a] Insertar una nueva cancion" << endl
         << "[b] Borar una cancion" << endl
         << "[s] Salir" << endl;
}

void Menu::wait() {
    cout << "Presione [Enter] para continuar";
    while(cin.get()!='\n');
}

void Menu::addSong(List<Song> &l) {
    int pos;
    if(l.isEmpty())pos = -1;
    else pos = inputPos();
    Song song;
    int rankPos;

    song.setName(inputCad("Introduzca el Nombre: "));
    song.setSinger(inputCad("Introduzca el Cantante: "));
    song.setAuthor(inputCad("Introduzca el Autor: "));
    cout << "Introduzca la posicion del ranking: ";
    cin >> rankPos;
    while(cin.get()!='\n');
    song.setRank(rankPos);
    l.insertData(song,pos);

    cout << endl << "*Cancion guardada correctamente*"<<endl;
    wait();
}

void Menu::deleteSong(List<Song> &l) {
    int pos = inputPos();
    l.deleteData(pos);
}

char Menu::inputOpt() {
    char opt;
    cout << "Elige una Opcion: ";
    cin.get(opt);
    while(cin.get()!='\n');
    return tolower(opt);
}

int Menu::inputPos() {
    int opt;
    cout << "Introduzca una posicion: ";
    cin >> opt;
    while(cin.get()!='\n');
    return opt;
}

string Menu::inputCad(const string& msn) {
    char aux[50];
    cout << msn;
    cin.getline(aux,50,'\n');
    string name(aux);
    return name;
}
