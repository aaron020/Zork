#ifndef STORAGE_H
#define STORAGE_H
#include "vector"
#include "QString"


using std::vector;

template <class T>
class Storage
{
private:
    vector<T> storage;
public:
    void add(T &);
    bool remove(T &);
    T* find(QString name);
};

#endif // STORAGE_H
