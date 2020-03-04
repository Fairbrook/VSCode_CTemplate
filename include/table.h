#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <list>
#include "row.h"

class Table{
private:
    std::list<Row>rows;

public:
    void addRow(const Row &row);
    void print();
};

#endif // TABLE_H_INCLUDED
