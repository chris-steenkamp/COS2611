#include <iostream>
//#include "queueAsArray.h"
#include "queueAsLinkedList.h"

using namespace std;
void test(int list[], int size, int n);
void test2(int list[], int size, int n);
void print(queueADT<int> &q);

int main()
{
    const int SIZE = 6;
    int list[] = {5,11,34,67,43,55};

    cout << "Array List: " << endl;

//    test(list, SIZE, 1);
//    test(list, SIZE, 2);
//    test(list, SIZE, 3);
//    test(list, SIZE, 4);
//    test(list, SIZE, 5);
//    test(list, SIZE, 6);

    cout << "Linked List: " << endl;
    test2(list, SIZE, 1);
    test2(list, SIZE, 2);
    test2(list, SIZE, 3);
    test2(list, SIZE, 4);
    test2(list, SIZE, 5);
    test2(list, SIZE, 6);

    return 0;
}

//void test(int list[], int size, int n)
//{
//    queueType<int> q;
//
//    for (int i = 0; i < size; ++i)
//    {
//        q.addQueue(list[i]);
//    }
//
//    cout << "List before moving element " << n << ": ";
//    print(q);
//
//    q.moveNthFront(n);
//
//    cout << "List after moving element " << n << ":  ";
//    print(q);
//}

void test2(int list[], int size, int n)
{
    linkedQueueType<int> q;

    for (int i = 0; i < size; ++i)
    {
        q.addQueue(list[i]);
    }

    cout << "List before moving element " << n << ": ";
    print(q);

    q.moveNthFront(n);

    cout << "List after moving element " << n << ":  ";
    print(q);
}

void print(queueADT<int> &q)
{
    int temp = -1;
    int first = 0;
    q.addQueue(temp);

    cout << "{";
    while (first != temp)
    {
        first = q.front();
        q.deleteQueue();

        if (first == temp)
            break;

        cout << first << ", ";

        q.addQueue(first);
    }

    cout << "}" << endl;
}
