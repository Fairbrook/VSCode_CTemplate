#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <iostream>



template <class T, int ASIZE = 1024>
class List {
private:
    T data[ASIZE];
    int counter;

    static void swapData(T&,T&);
public:
    class Exception : public std::exception {
    private:
        std::string msg;

    public:
        explicit Exception(const std::string &str):msg(str) {}
        explicit Exception(const char* str):msg(str){}
        ~Exception() {}
        const char* what() {
            return msg.c_str();
        }
    };

    List();
    List(const List<T,ASIZE>&);
    bool isEmpty()const;
    bool isFull()const;

    void insertData(const T&,const int&);
    void deleteData(const int&);

    T retrieve(const int&)const;

    std::string toString()const;

    int getFirstPos()const;
    int getLastPos()const;
    int getNextPos(const int&)const;
    int getPrevPos(const int&)const;

    void deleteAll();

    int linearSearch(const T&,int (*)(const T&,const T&))const;
    int binarySearch(const T&,int (*)(const T&,const T&))const;

    List<T,ASIZE>& operator=(const List&);

    void bubbleSort(int (*)(const T&,const T&));
    void selectSort(int (*)(const T&,const T&));
    void insertSort(int (*)(const T&,const T&));
    void shellSort(int (*)(const T&,const T&));
};

template <class T, int ASIZE>
List<T,ASIZE>::List():counter(-1) {}

template <class T, int ASIZE>
List<T,ASIZE>::List(const List<T,ASIZE> &l) {
    for(int i = 0; i < ASIZE ; i++)
        data[i] = l.data[i];
    counter = l.counter;
}

template <class T, int ASIZE>
void List<T,ASIZE>::swapData(T&a,T&b){
    T aux(a);
    a = b;
    b = aux;
}

template <class T, int ASIZE>
int List<T,ASIZE>::linearSearch(const T&t,int (*compare)(const T&,const T&))const{
    int i(0);
    while(i<=counter){
        if(compare(data[i],t)==0)return i;
        i++;
    }
    return -1;
}

template <class T, int ASIZE>
int List<T,ASIZE>::binarySearch(const T&t,int (*compare)(const T&,const T&))const{
    int i(0),j(counter),m;
    while(i<=j){
        m = (i+j)/2;
        if(compare(data[m],t)==0)return m;
        if(compare(t,data[m])<0)j=m-1;
        else i=m+1;
    }
    return -1;
}



template <class T, int ASIZE>
bool List<T,ASIZE>::isEmpty()const{
    return (counter == -1);
}

template <class T, int ASIZE>
bool List<T,ASIZE>::isFull() const{
    return (counter == ASIZE-1);
}

template <class T, int ASIZE>
void List<T,ASIZE>::insertData(const T& d,const int& pos) {
    if(isFull())
        throw Exception("insertData: Desbordamiento de datos");

    if((pos!=-1) && (pos < -1 || pos > counter))
        throw Exception("insertData: Insuficiencia de datos");

    int i = counter;
    while(i >= pos+1) {
        data[i+1] = data[i];
        i--;
    }
    data[pos+1] = d;
    counter++;
}

template <class T, int ASIZE>
void List<T,ASIZE>::deleteData(const int &pos) {
    if(pos < 0 || pos > counter)
        throw Exception("deleteData: Insuficiencia de datos");
    int i = pos;
    while(i < counter) {
        data[i] = data[i+1];
        i++;
    }
    counter--;
}

template <class T, int ASIZE>
T List<T,ASIZE>::retrieve(const int&pos) const{
    if(counter == -1 || pos < 0 || pos > counter)
        throw Exception("retrive: Insuficiencia de datos");
    return data[pos];

}

template <class T, int ASIZE>
int List<T,ASIZE>::getFirstPos() const{
    return (counter == -1)? -1 : 0;
}

template <class T, int ASIZE>
int List<T,ASIZE>::getLastPos() const{
    return counter;
}

template <class T, int ASIZE>
int List<T,ASIZE>::getNextPos(const int &pos) const{
    if(counter == -1) return -1;
    return (pos < 0 || pos > counter-1)? -1 : pos+1;
}

template <class T, int ASIZE>
int List<T,ASIZE>::getPrevPos(const int &pos) const{
    if(counter == -1) return -1;
    return (pos < 1 || pos > counter)? -1 : pos-1;
}

template <class T, int ASIZE>
void List<T,ASIZE>::deleteAll() {
    counter = -1;
}

template <class T, int ASIZE>
std::string List<T,ASIZE>::toString() const{
    std::string result;
    if(this->isEmpty())
        return "Lista Vacia\n";

    int i = getFirstPos();
    do {
        result += "[" ;
        result += std::to_string(i);
        result += "] ";
        result += data[i].toString();
        result += "\n";
    } while((i=getNextPos(i))!=-1);
    return result;
}


template <class T, int ASIZE>
void List<T,ASIZE>::bubbleSort(int (*compare)(const T&,const T&)){
    bool flag;
    int i = counter,j = 0;
    T aux;
    do{
        flag = false;
        j=0;
        while(j<i){
            if(compare(data[j],data[j+1])>0){
                swapData(data[j],data[j+1]);
                flag = true;
            }
            j++;
        }
        i--;
    }while(flag);
}

template <class T, int ASIZE>
void List<T,ASIZE>::selectSort(int (*compare)(const T&,const T&)){
    int i(0),m,j;
    while(i<counter){
        m=i;
        j=i+1;
        while(j<=counter){
            if(compare(data[j],data[m])<0)m=j;
            j++;
        }
        if(m!=i)swapData(data[i],data[m]);
        i++;
    }
}

template <class T, int ASIZE>
void List<T,ASIZE>::insertSort(int (*compare)(const T&,const T&)){
    int i(1),j;
    T aux;
    while(i<=counter){
        aux = data[i];
        j=i;
        while(j>0 and data[j-1]>aux){
            data[j] = data[j-1];
            j--;
        }
        if(i!=j)data[j] = aux;
        i++;
    }
}

template <class T, int ASIZE>
void List<T,ASIZE>::shellSort(int (*compare)(const T&,const T&)){
    int i(1),dif(counter/2),j;
    while(dif > 0){
        i = 0;
        while(i<=(counter - dif)){
            if(compare(data[i],data[i+dif])>0){
                swapData(data[i],data[i+dif]);
                j = i;
                while(j>=dif){
                    if(compare(data[j],data[j-dif])>0)break;
                    swapData(data[j],data[j-dif]);
                    j-=dif;
                }
            }
            i++;
        }
        dif/=2;
    }
}


template <class T, int ASIZE>
List<T,ASIZE>& List<T,ASIZE>::operator=(const List&l){
    for(int i = 0; i < ASIZE ; i++)
        data[i] = l.data[i];
    counter = l.counter;
}

#endif // LIST_H_INCLUDED
