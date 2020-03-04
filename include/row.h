#ifndef ROW_H_INCLUDED
#define ROW_H_INCLUDED
#include <list>
#include <string>

class Row{
private:
    std::list<std::string> cells;
    int spaceSize;

public:
    Row();
    void addCell(const std::string&);
    void print();

    void setSpace(const int&);
    int getSpace();

    int countCells(){return cells.size(); }
};

#endif // ROW_H_INCLUDED
