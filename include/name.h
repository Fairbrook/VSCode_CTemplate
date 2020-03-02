#ifndef INCLUDE_NAME_H
#define INCLUDE_NAME_H

#include <string>
#include <iostream>

class Name{
    private:
        std::string first;
        std::string last;

    public:
        Name();
        Name(const Name&);

        void setFirst(const std::string&);
        void setLast(const std::string&);

        std::string getFirst()const;
        std::string getLast()const;

        std::string toString()const;

        bool operator==(const Name&)const;
        bool operator!=(const Name&)const;
        bool operator<=(const Name&)const;
        bool operator>=(const Name&)const;
        bool operator>(const Name&)const;
        bool operator<(const Name&)const;

        friend std::ostream& operator<<(std::ostream&,const Name&);
        friend std::istream& operator>>(std::istream&, Name&);

        Name& operator=(const Name&);
};

#endif