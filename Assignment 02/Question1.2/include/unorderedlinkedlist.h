#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H
#include "linkedlisttype.h"

template <class T>
class unorderedLinkedList: public linkedListType<T>
{
public:
    bool search(const T &item) const;

    void insertFirst(const T &item);

    void insertLast(const T &item);

    void deleteNode(const T &item);
};

template <class T>
bool unorderedLinkedList<T>::search(const T &item) const
{
    nodeType<T> *current;
    bool found = false;

    current = this->first;

    while (current != NULL && !found)
    {
        if (current->info == item)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }

    return found;
}

template <class T>
void unorderedLinkedList<T>::insertFirst(const T &item)
{
    nodeType<T> *newNode;

    newNode = new nodeType<T>;
    newNode->info = item;
    newNode->link = this->first;

    this->first = newNode;

    ++this->count;

    if (this->last == NULL)
    {
        this->last = newNode;
    }
}

template <class T>
void unorderedLinkedList<T>::insertLast(const T &item)
{
    nodeType<T> *newNode;

    newNode = new nodeType<T>;
    newNode->info = item;
    newNode->link = NULL;

    if (this->first == NULL)
    {
        this->first = newNode;
        this->last = newNode;
    }
    else
    {
        this->last->link = newNode;
        this->last = newNode;
    }

    ++this->count;
}

template <class T>
void unorderedLinkedList<T>::deleteNode(const T &item)
{
    nodeType<T> *current;
    nodeType<T> *trailCurrent;
    bool found;

    if (this->first == NULL)
    {
        cout << "List is already empty" << endl;
    }
    else
    {
        if (this->first->info == item)
        {
            current = this->first;
            this->first = this->first->link;
            --this->count;

            if (this->first == NULL)
            {
                this->last = NULL;
            }

            delete current;
        }
        else
        {
            found = false;
            trailCurrent = this->first;
            current = this->first->link;

            while (current != NULL && !found)
            {
                if (current->info != item)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                {
                    found = true;
                }
            }

            if (found)
            {
                trailCurrent->link = current->link;
                --this->count;

                if (this->last == current)
                {
                    this->last = trailCurrent;
                }

                delete current;
            }
            else
            {
                cout << "item is not in the list." << endl;
            }
        }
    }
}


#endif // UNORDEREDLINKEDLIST_H
