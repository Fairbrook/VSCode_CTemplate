#include "name.h"

using namespace std;

Name::Name(){}
Name::Name(const Name&n):first(n.first),last(n.last){}

void Name::setFirst(const std::string&s){this->first = s;}
void Name::setLast(const std::string&s){this->last = s;}

string Name::getFirst()const{return this->first;}
string Name::getLast()const{return this->last;}

string Name::toString()const{
    string result;
    result = first + " " + last;
    return result;
}

bool Name::operator==(const Name&n)const{
    return this->toString().compare(n.toString())==0;
}
bool Name::operator!=(const Name&n)const{
    return this->toString().compare(n.toString())!=0;
}
bool Name::operator<=(const Name&n)const{
    return this->toString().compare(n.toString())<=0;
}
bool Name::operator>=(const Name&n)const{
    return this->toString().compare(n.toString())>=0;
}
bool Name::operator>(const Name&n)const{
    return this->toString().compare(n.toString())>0;
}
bool Name::operator<(const Name&n)const{
    return this->toString().compare(n.toString())<0;
}

ostream& operator<<(ostream&os,const Name&n){
    os << n.first<< endl;
    os << n.last;
    return os;
}
istream& operator>>(istream&is,Name &n){
    getline(is,n.first);
    getline(is,n.last);
    return is;
}

Name& Name::operator=(const Name&n){
    this->first = n.first;
    this->last = n.last;
    return *this;
}