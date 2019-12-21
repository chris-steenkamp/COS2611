#include <iostream>

using namespace std;

int find(int list[], int, int);

int main()
{
    int list[] = {2,6,7,12,15,21,25,31,32,36};

    cout << find(list, 10, 6) << endl;

    return 0;
}


int find(int list[], int size, int x)
{
    int first = 0;
    int last = size - 1;
    int mid;

    int iteration= 1;

    while (first <= last)
    {
        mid = (first + last) / 2;
        cout << "Iteration " << iteration++ << ": first " << first << ", last " << last << ", mid " << mid << ", value = " << list[mid] << endl;
        if (list[mid] == x)
            return mid;
        else if (list[mid] > x)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return -1;
}
