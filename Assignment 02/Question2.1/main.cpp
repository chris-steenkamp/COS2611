#include <iostream>

using namespace std;

void printStars(int numStars)
{
    for (int i = 0; i < numStars; ++i)
        cout << "*";

    cout << endl;
}

void drawPattern(int num, int max)
{
    if (num > max)
        return;

    printStars(num);

    drawPattern(num + 1, max);

    printStars(num);
}

int main()
{
    int numStars;
    cout << "Enter the number of lines: ";
    cin >> numStars;
    drawPattern(1, numStars);
    return 0;
}
