#ifndef SMARTENTITY_H
#define SMARTENTITY_H
#include <iostream>
using namespace std;


template <typename T>
class smartentity
{
    T entity;
public:
    smartentity();
    smartentity(T _entity);
    ~smartentity();
    void display_info() const;
    T get_entity() const;
};
#endif

template <typename T>
smartentity<T>::smartentity() : entity()
{
}
template <typename T>
smartentity<T>::smartentity(T _entity) : entity(_entity)
{
}
template <typename T>
smartentity<T>::~smartentity()
{
}
template <typename T>
void smartentity<T>::display_info() const
{
    entity.display_info();
}
template <typename T>
T smartentity<T>::get_entity() const
{
    return entity;
}
