#include "row.h"
#include <iostream>
#include <iomanip>

using namespace std;

Row::Row(){
    spaceSize = 1;
}

void Row::addCell(const string &cell)
{
    cells.push_back(cell);
    if(cell.size()>spaceSize)spaceSize=cell.size();
}

void Row::print()
{
    if(cells.empty())return;

    list<string>::iterator it;
    cout << "|";
    for(it=cells.begin();it!=cells.end();++it){
        cout << setw(spaceSize) << *it << " |";
    }
    cout << endl;
}

void Row::setSpace(const int &s)
{
    this->spaceSize = s;
}

int Row::getSpace()
{
    return spaceSize;
}
