#include <iostream>
#include <cassert>

using namespace std;

int sumArray(int list[], int length)
{
    if (length < 1)
        return 0;

    return list[--length] + sumArray(list, length);
}

void test1()
{
    int list[] = {1, 2, 3, 4}; //10
    cout << "Assert that sum of array values is 10: ";
    assert(sumArray(list, 4) == 10);
    cout << "Pass" << endl;
}

void test2()
{
    int list[] = {1, 3, 5, 7, 9}; //25
    cout << "Assert that sum of array values is 25: ";
    assert(sumArray(list, 5) == 25);
    cout << "Pass" << endl;

}

int main()
{
    test1();
    test2();
    return 0;
}
