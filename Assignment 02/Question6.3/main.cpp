#include <iostream>

using namespace std;
const int SIZE = 10;

void swap(int list[], int lhs, int rhs);
void sort(int list[], int first, int last);
void print(int list[]);
int partition(int list[], int first, int last);

int main()
{
    int list[] = {10,2,9,1,8,4,7,5,3,6};

    cout << "Starting list: " << endl;
    print(list);

    cout << endl << "Sorting List: " << endl;
    sort(list, 0, SIZE-1);

    cout << endl << "Sorted List" << endl;
    print(list);
    return 0;
}

void print(int list[])
{
    for (int i = 0; i < SIZE; ++i)
        cout << list[i] << ",";

    cout << endl;
}

int partition(int list[], int first, int last)
{
    swap(list, first, (first + last) / 2);
    int pivot = list[first];
    int smallIndex = first;

    for (int i = first + 1; i <= last; ++i)
    {
        if (list[i] < pivot)
        {
            ++smallIndex;
            swap(list, smallIndex, i);
        }
    }

    swap(list, first, smallIndex);

    return smallIndex;
}

void swap(int list[], int lhs, int rhs)
{
    int temp = list[lhs];
    list[lhs] = list[rhs];
    list[rhs ] = temp;
}

void sort(int list[], int first, int last)
{
    int pivot;

    if (first < last)
    {
        pivot = partition(list, first, last);
        print(list);
        sort(list, first, pivot - 1);
        sort(list, pivot + 1, last);
    }
}
