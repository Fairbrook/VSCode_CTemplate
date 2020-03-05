#include "date.h"

using namespace std;

Date::Date(){
    time_t aux = time(0);
    tm *helper = gmtime(&aux);
    day = helper->tm_mday;
    month = helper->tm_mon+1;
    year = helper->tm_year+1900;
}

Date::Date(const Date&d):day(d.day),month(d.month),year(d.year){}

int Date::toInt()const{
    return year*10000 + month*100 + day;
}


void Date::setDay(const int& d) {
    if(d > 31 || d < 1)
        throw Exception("[setDay] Valor invalido");
    this->day = d;
}

void Date::setMonth(const int& m) {
    if(m > 12 || m < 1)
        throw Exception("[setMonth] Valor invalido");
    this->month = m;
}

void Date::setYear(const int& y) {
    if(y < 0)
        throw Exception("[setYear] Valor invalido");
    this->year = y;
}

int Date::getDay() const{
    return this->day;
}

int Date::getMonth() const{
    return this->month;
}

int Date::getYear() const{
    return this->year;
}

string Date::toString()const{
    char aux[12];
    sprintf(aux,"%02i/%02i/%04i",day,month,year);
    return string(aux);
}

bool Date::operator==(const Date&d)const{
    return toInt() == d.toInt();
}
bool Date::operator!=(const Date&d)const{
    return toInt() != d.toInt();
}
bool Date::operator<=(const Date&d)const{
    return toInt() <= d.toInt();
}
bool Date::operator>=(const Date&d)const{
    return toInt() >= d.toInt();
}
bool Date::operator<(const Date&d)const{
    return toInt() < d.toInt();
}
bool Date::operator>(const Date&d)const{
    return toInt() > d.toInt();
}

ostream& operator << (ostream&os, const Date&d){
    os << d.toString();
    return os;
}

istream& operator>> (istream&is, Date&d){
    char helper[10];
    is.getline(helper,10,'\n');

    try{
        sscanf(helper,"%i/%i/%i",&d.day,&d.month,&d.year);
    }catch(exception &ex){
        throw Date::Exception("[Date] Error de formato de lectura");
    }
    return is;
}

Date& Date::operator=(const Date &d) {
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
    return *this;
}
