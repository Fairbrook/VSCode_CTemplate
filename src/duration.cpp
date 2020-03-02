#include "duration.h"

using namespace std;

Duration::Duration(){
    time_t aux = time(0);
    tm *helper = gmtime(&aux);
    hours = helper->tm_hour;
    minutes = helper->tm_min;
    seconds = helper->tm_sec;
}

Duration::Duration(const Duration&t):hours(t.hours),minutes(t.minutes),seconds(t.seconds){}

int Duration::toInt()const{
    return hours*10000 + minutes*100 + seconds;
}


void Duration::setHours(const int& h) {
    if(h < 0)
        throw Exception("[setHours] Valor invalido");
    this->hours = h;
}

void Duration::setMinutes(const int& m) {
    if(m > 59 || m < 0)
        throw Exception("[setMinutes] Valor invalido");
    this->minutes = m;
}

void Duration::setSeconds(const int& s) {
    if(s > 59 || s < 0)
        throw Exception("[setSeconds] Valor invalido");
    this->seconds = s;
}

int Duration::getHours() const{
    return this->hours;
}

int Duration::getMinutes() const{
    return this->minutes;
}

int Duration::getSeconds() const{
    return this->seconds;
}

string Duration::toString()const{
    char aux[10];
    sprintf(aux,"%01i:%02i:%02i",hours,minutes,seconds);
    return string(aux);
}

bool Duration::operator==(const Duration&d)const{
    return toInt() == d.toInt();
}
bool Duration::operator!=(const Duration&d)const{
    return toInt() != d.toInt();
}
bool Duration::operator<=(const Duration&d)const{
    return toInt() <= d.toInt();
}
bool Duration::operator>=(const Duration&d)const{
    return toInt() >= d.toInt();
}
bool Duration::operator<(const Duration&d)const{
    return toInt() < d.toInt();
}
bool Duration::operator>(const Duration&d)const{
    return toInt() > d.toInt();
}

ostream& operator << (ostream&os, const Duration&d){
    os << d.toString();
    return os;
}

istream& operator>> (istream&is, Duration&d){
    char helper[10];
    is.getline(helper,10,'\n');

    try{
        sscanf(helper,"%i:%i:%i",&d.hours,&d.minutes,&d.seconds);
        // int pos = helper.find(":");
        // d.hours = stoi(helper.substr(0,pos));
        // d.minutes = stoi(helper.substr(pos+1,2));
        // d.seconds = stoi(helper.substr(pos+4,2));
    }catch(exception &ex){
        throw Duration::Exception("[Duration] Error de formato de lectura");
    }
}

Duration& Duration::operator=(const Duration &d) {
    this->hours = d.hours;
    this->minutes = d.minutes;
    this->seconds = d.seconds;
    return *this;
}
