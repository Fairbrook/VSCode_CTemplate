#ifndef Duration_H_INCLUDED
#define Duration_H_INCLUDED

#include <iostream>
#include <ctime>
#include <string>

class Duration{
private:
    int hours;
    int minutes;
    int seconds;
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

    Duration();
    Duration(const Duration&);

    void setHours(const int&);
    void setMinutes(const int&);
    void setSeconds(const int&);

    int getHours()const;
    int getMinutes()const;
    int getSeconds()const;

    std::string toString()const;

    bool operator==(const Duration&)const;
    bool operator!=(const Duration&)const;
    bool operator<=(const Duration&)const;
    bool operator>=(const Duration&)const;
    bool operator<(const Duration&)const;
    bool operator>(const Duration&)const;

    friend std::ostream& operator<<(std::ostream&,const Duration&);
    friend std::istream& operator>>(std::istream&, Duration&);

    Duration& operator=(const Duration&);
};


#endif // Duration_H_INCLUDED
