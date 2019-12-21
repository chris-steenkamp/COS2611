#include <iostream>

using namespace std;
const int SIZE = 10;
int min(int list[], int first, int last);
void swap(int list[], int lhs, int rhs);
void sort(int list[]);
void print(int list[]);

int main()
{
    int list[] = {10,2,9,1,8,4,7,5,3,6};
    print(list);
    sort(list);
    print(list);
    return 0;
}

void print(int list[])
{
    for (int i = 0; i < SIZE; ++i)
        cout << list[i] << ",";

    cout << endl;
}
int min(int list[], int first, int last)
{
    int min = first;

    for (int i = min + 1; i <= last; ++i)
    {
        if (list[i] < list[min])
            min = i;
    }

    return min;
}

void swap(int list[], int lhs, int rhs)
{
    int temp = list[lhs];
    list[lhs] = list[rhs];
    list[rhs ] = temp;
}

void sort(int list[])
{
    int firstOutOfOrder, location;
    int temp;

    for (firstOutOfOrder = 1; firstOutOfOrder < SIZE; ++firstOutOfOrder)
    {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                --location;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }

        print(list);
    }
}
