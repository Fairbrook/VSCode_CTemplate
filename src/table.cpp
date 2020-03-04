#include "table.h"
#include <iostream>

using namespace std;

void Table::addRow(const Row &row)
{
    rows.push_back(row);
}

void Table::print(){
    if(rows.empty())return;

    list<Row>::iterator it;
    int counter, space = 0;
    Row aux;

    for(it=rows.begin();it!=rows.end();++it){
        aux = *it;
        if(aux.getSpace()>space)space = aux.getSpace();
    }

    for(it=rows.begin();it!=rows.end();++it){
        aux = *it;
        aux.setSpace(space);
        counter = aux.countCells();
        counter*= space+2;
        counter++;
        for(int i=0;i<counter;i++)cout << "-";
        cout << endl;
        aux.print();
    }
    for(int i=0;i<counter;i++)cout << "-";
    cout << endl;
}
