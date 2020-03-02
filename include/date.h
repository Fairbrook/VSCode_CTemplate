#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <ctime>
#include <string>

class Date{
private:
    int day;
    int month;
    int year;
    int toInt()const;

public:
    class Exception:public std::exception{
        private:
            std::string msg;
        public:
            explicit Exception(const std::string&m):msg(m){}
            explicit Exception(const char*m):msg(m){}
            ~Exception(){}
            const char* what(){return msg.c_str();}
    };

    Date();
    Date(const Date&);

    void setDay(const int&);
    void setMonth(const int&);
    void setYear(const int&);

    int getDay()const;
    int getMonth()const;
    int getYear()const;

    std::string toString()const;

    bool operator==(const Date&)const;
    bool operator!=(const Date&)const;
    bool operator<=(const Date&)const;
    bool operator>=(const Date&)const;
    bool operator<(const Date&)const;
    bool operator>(const Date&)const;

    friend std::ostream& operator<<(std::ostream&,const Date&);
    friend std::istream& operator>>(std::istream&, Date&);

    Date& operator=(const Date&);
};


#endif // DATE_H_INCLUDED
