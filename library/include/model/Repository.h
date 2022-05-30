#ifndef ROSLINY_REPOSITORY_H
#define ROSLINY_REPOSITORY_H


#include <list>
#include <string>

using namespace std;

template <class T>
class Repository {
protected:
    list<T> items;
public:
    virtual void add(T t)
    {
        items.push_back(t);
    }
    virtual void remove(T t)
    {
        items.remove(t);
    }
    virtual list<T> getAll()
    {
        return items;
    }
    virtual T find(int id)=0;

    Repository() {}

    virtual ~Repository() {

    }

};


#endif //ROSLINY_REPOSITORY_H
