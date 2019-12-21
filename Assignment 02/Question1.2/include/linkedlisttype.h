#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include <iostream>
#include <cassert>
#include "nodetype.h"
#include "linkedlistiterator.h"

using namespace std;

template <class T>
class linkedListType
{
public:
    const linkedListType<T>& operator=(const linkedListType<T> &);
    void initializerList();
    bool isEmpty() const;
    void print() const;
    int length() const;
    void destroyList();
    T front() const;
    T back() const;
    virtual bool search(const T &item) const = 0;
    virtual void insertFirst(const T &item) = 0;
    virtual void insertLast(const T &item) = 0;
    virtual void deleteNode(const T &item) = 0;

    T getItemAt(int index) const;
    void deleteItemAt(int index);

    linkedListIterator<T> begin();
    linkedListIterator<T> end();

    linkedListType();
    linkedListType(const linkedListType<T> &otherList);

    ~linkedListType();

protected:
    int count;
    nodeType<T> *first;
    nodeType<T> *last;

private:
    void copyList(const linkedListType<T> &otherList);
};

template <class T>
T linkedListType<T>::getItemAt(int index) const
{
    assert(index <= count && index > 0);

    int i = 0;
    nodeType<T> *current = first;

    while (i++ < index-1)
    {
        current = current->link;
    }

    return current->info;
}

template <class T>
void linkedListType<T>::deleteItemAt(int index)
{
    if (index < 1 || index > count)
    {
        cout << "There is no element at position " << index << endl;
        return;
    }

    int i = 0;
    nodeType<T> *current = first;
    nodeType<T> *previous = NULL;

    while (i++ < index-1)
    {
        previous = current;
        current = current->link;
    }

    //If we are not deleting the first node
    if (previous != NULL)
    {
        previous->link = current->link;
    }
    else //we are deleting the first node
    {
        first = first->link;
    }
    current->link = NULL;
    delete current;
    current = NULL;

    --count;
}

template <class T>
const linkedListType<T>& linkedListType<T>::operator=(const linkedListType<T> &otherList)
{
    if (this != &otherList)
    {
        copyList(otherList);
    }

    return *this;
}

template <class T>
void linkedListType<T>::initializerList()
{
    destroyList();
}

template <class T>
bool linkedListType<T>::isEmpty() const
{
    return (first == NULL);
}

template <class T>
void linkedListType<T>::print() const
{
    nodeType<T> *current;

    current = first;
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
}

template <class T>
int linkedListType<T>::length() const
{
    return count;
}

template <class T>
void linkedListType<T>::destroyList()
{
    nodeType<T> *temp;

    while (first != NULL)
    {
        temp = first;
        first = first->link;
        delete temp;
        temp = 0;
    }

    last = NULL;
    count = 0;
}

template <class T>
T linkedListType<T>::front() const
{
    assert(first != NULL);
    return first->info;
}

template <class T>
T linkedListType<T>::back() const
{
    assert(last != NULL);
    return last->info;
}

template <class T>
linkedListIterator<T> linkedListType<T>::begin()
{
    linkedListIterator<T> temp(first);

    return temp;
}

template <class T>
linkedListIterator<T> linkedListType<T>::end()
{
    linkedListIterator<T> temp(last);

    return temp;
}

template <class T>
linkedListType<T>::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class T>
linkedListType<T>::linkedListType(const linkedListType<T> &otherList)
{
    first = NULL;
    copyList(otherList);
}

template <class T>
linkedListType<T>::~linkedListType()
{
    destroyList();
}

template <class T>
void linkedListType<T>::copyList(const linkedListType<T> &otherList)
{
    nodeType<T> *newNode;
    nodeType<T> *current;

    if (first != NULL)
    {
        destroyList();
    }

    if (otherList->first == NULL)
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList->first;
        count = otherList->count;

        first = new nodeType<T>;
        first->info = current->info;
        first->link = NULL;
        last = first;
        current = current->link;

        while (current != NULL)
        {
            newNode = new nodeType<T>;
            newNode->info = current->info;
            newNode->link = NULL;

            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}
#endif // LINKEDLISTTYPE_H
