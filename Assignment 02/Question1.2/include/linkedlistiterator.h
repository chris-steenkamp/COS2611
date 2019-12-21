#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR

template <class T>
class linkedListIterator
{
public:
    linkedListIterator();

    linkedListIterator(nodeType<T> *ptr);

    T operator*();

    linkedListIterator<T> operator++();

    bool operator==(const linkedListIterator<T> &rhs) const;

    bool operator!=(const linkedListIterator<T> &rhs) const;
protected:

private:
    nodeType<T> *current;
};

template <class T>
linkedListIterator<T>::linkedListIterator()
{
    current = NULL;
}

template <class T>
linkedListIterator<T>::linkedListIterator(nodeType<T> *ptr)
{
    current = ptr;
}

template <class T>
T linkedListIterator<T>::operator*()
{
    return current->info;
}

template <class T>
linkedListIterator<T> linkedListIterator<T>::operator++()
{
    current = current ->link;

    return *this;
}

template <class T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T> &rhs) const
{
    return (current == rhs.current);
}

template <class T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T> &rhs) const
{
    return (current != rhs.current);
}
#endif
