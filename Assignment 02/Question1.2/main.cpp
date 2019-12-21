#include <iostream>
#include <cassert>
#include "unorderedlinkedlist.h"

using namespace std;

void test1();
void test2();
void test3();

int main()
{
    test1();
    test2();
    test3();
    return 0;
}

void test1()
{
    unorderedLinkedList<int> list;
    int testPos = 3;

    //item1
    list.insertLast(3);
    //item2
    list.insertLast(1);
    //item3
    list.insertLast(9);
    //item4
    list.insertLast(5);
    //item5
    list.insertLast(2);
    //item6
    list.insertLast(7);

    list.print();
    cout << endl << "Asserting that element " << testPos << " is equal to 9" << endl;
    assert(list.getItemAt(testPos) == 9);

    list.deleteItemAt(testPos);

    list.print();
    cout << endl << "Asserting that element " << testPos << " is equal to 5" << endl;
    assert(list.getItemAt(testPos) == 5);
}

void test2()
{
    unorderedLinkedList<int> list;
    int testPos = 1;

    //item1
    list.insertLast(3);
    //item2
    list.insertLast(1);
    //item3
    list.insertLast(9);
    //item4
    list.insertLast(5);
    //item5
    list.insertLast(2);
    //item6
    list.insertLast(7);

    list.print();
    cout << endl << "Asserting that element " << testPos << " is equal to 3" << endl;
    assert(list.getItemAt(testPos) == 3);

    list.deleteItemAt(testPos);

    list.print();
    cout << endl << "Asserting that element " << testPos << " is equal to 1" << endl;
    assert(list.getItemAt(testPos) == 1);
}

void test3()
{
    unorderedLinkedList<int> list;
    int testPos = 6;

    //item1
    list.insertLast(3);
    //item2
    list.insertLast(1);
    //item3
    list.insertLast(9);
    //item4
    list.insertLast(5);
    //item5
    list.insertLast(2);
    //item6
    list.insertLast(7);

    list.print();
    cout << endl << "Asserting that element " << testPos << " is equal to 7" << endl;
    assert(list.getItemAt(testPos) == 7);

    list.deleteItemAt(testPos);

    list.print();
    cout << endl << "Assertion should fail as last element no longer exists." << endl;
    assert(list.getItemAt(testPos) == 5);
}
