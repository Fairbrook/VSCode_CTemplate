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
                search(l);
                break;
            case 'c':
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
        } catch(List<Song>::Exception &ex) {
            cout << "Error de Lista: " << ex.what() << endl;
            wait();
        } catch(exception &ex) {
            cout << "Error inesperado "<< ex.what() << endl;
            wait();
        }
    } while(opt!='s');
}

void Menu::showMenu(const List<Song> &l) {
    cout << endl;
    cout << "== Actividad 5. Metodos de Busqueda ==" << endl;
    cout << "Lista actual:"<<endl;
    formatList(l);
    cout << " * Menu *" << endl;
    cout << "[a] Insertar una nueva cancion" << endl
         << "[b] Buscar cancion" << endl
         << "[c] Borar una cancion" << endl
         << "[s] Salir" << endl;
}

void Menu::wait() {
    cout << "Presione [Enter] para continuar";
    while(cin.get()!='\n');
}

// inline int title(const Song&a, const Song&b){
//     return a.getTitle().compare(b.getTitle());
// }

// inline int artist(const Song&a, const Song&b){ 
//     return a.getArtist().compare(b.getArtist());
// }


void Menu::search(const List<Song> &l){
    char opt,met;
    int pos(-1);
    Song aux;
    int (*artist)(const Song&, const Song&) = [](const Song&a, const Song&b)->int{
        return a.getArtist().compare(b.getArtist());
    };
    int (*title)(const Song&, const Song&) = [](const Song&a, const Song&b)->int{
        return a.getTitle().compare(b.getTitle());
    };

    cout << endl << endl
         << "Buscar por: "<<endl
         << "[a] Artista"<<endl
         << "[b] Titulo" <<endl;
    opt = inputOpt();
    if(opt=='a')
        aux.setArtist(inputCad("Introduzca el nombre del artista: "));
    else if(opt=='b')
        aux.setTitle(inputCad("Introduzca el titulo: "));
    else{
        cout << "Opcion invalida";
        return;
    }

    cout << endl
         << "Metodo: "<<endl
         << "[a] Lineal"<<endl
         << "[b] Binario" <<endl;
    met = inputOpt();

    if(met=='a')pos = l.linearSearch(aux,(opt=='a')?artist:title);
    else if(met=='b')pos = l.binarySearch(aux,(opt=='a')?artist:title);

    if(pos==-1){
        cout << "Elemento no encontrado\n";
    }else{
        aux = l.retrieve(pos);
        cout << "Elemento Encontrado: \n";
        cout << aux.toString() << "\n";
    }

    wait();
}

void Menu::addSong(List<Song> &l) {
    int pos;
    if(l.isEmpty())pos = -1;
    else pos = inputPos();
    Song song;
    int rankPos;
    song.setTitle(inputCad("Introduzca el Nombre: "));
    song.setArtist(inputCad("Introduzca el Nombre del artista: "));
    song.setAlbum(inputCad("Introduzca el Album: "));
    song.setDate(inputDate());
    song.setFile(inputCad("Introduzca el nombre del archivo: "));
    song.setDuration(inputDuration());
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
    return string (aux);
}

Date Menu::inputDate(){
    char aux[50];
    Date date;
    int m,d,y;
    cout << "Ingrese la fecha (dd/mm/yyyy): ";
    cin.getline(aux,50,'\n');
    try{
        sscanf(aux,"%d/%d/%d",&m,&d,&y);
        date.setDay(d);
        date.setMonth(m);
        date.setYear(y);
    }catch(Date::Exception &ex){
        cout << ("\nFormato de fecha incorrecto -> " + string(ex.what()))<<endl;
        return inputDate();
    }
    return date;
}

Duration Menu::inputDuration(){
    char aux[50];
    Duration duration;
    int h,m,s;
    cout << "Ingrese la duracion (h:mm:ss): ";
    cin.getline(aux,50,'\n');
    try{
        sscanf(aux,"%i:%i:%i",&h,&m,&s);
        duration.setHours(h);
        duration.setMinutes(m);
        duration.setSeconds(s);
    }catch(Duration::Exception &ex){
        cout << ("\nFormato de duracion incorrecto -> " + string(ex.what()))<<endl;
        return inputDuration();
    }
    return duration;
}

void Menu::formatList(const List<Song>&l){
    Table table;
    Song aux;
    Row *row = new Row();
    row->addCell("N");
    row->addCell("TITULO");
    row->addCell("ARTISTA");
    row->addCell("ALBUM");
    row->addCell("FECHA");
    row->addCell("DURACION");
    row->addCell("ARCHIVO");
    row->addCell("RANK");
    table.addRow(*row);
    delete row;
    if(!l.isEmpty()){
        int i(l.getFirstPos());
        do{
            aux = l.retrieve(i);
            row = new Row();
            row->addCell(to_string(i));
            row->addCell(aux.getTitle());
            row->addCell(aux.getArtist());
            row->addCell(aux.getAlbum());
            row->addCell(aux.getDate().toString());
            row->addCell(aux.getDuration().toString());
            row->addCell(aux.getFile());
            row->addCell(to_string(aux.getRank()));
            table.addRow(*row);
            delete row;
            i = l.getNextPos(i);
        }while(i!=-1);
    }
    table.print();

}
