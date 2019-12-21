#include <iostream>
#include <stack>
#include <string>
#include "queueAsArray.h"

using namespace std;

bool isInLanguageL2(string w);
bool isInLanguageL(queueType<char> &w);
void test(string language, bool shouldBeValid);

int main()
{
    test("a", true);
    test("aab", true);
    test("aaabb", true);
    test("aaaaaaabbbbbb", true);

    test("", false);
    test("bab", false);
    test("aba", false);
    test("abb", false);
    test("123", false);
    test("aabaab", false);
    test("b", false);
    test("bba", false);
    test("abaaa", false);
    test("aaabbb", false);
    test("abaabba", false);
    test(" as aaabbb", false);


    return 0;
}

void test(string language, bool shouldBeValid)
{
    queueType<char> q;

    for (int i = 0; i < language.length(); ++i)
        q.addQueue(language[i]);

    cout << "Test whether " << language << " is " << (shouldBeValid? "valid" : "invalid") << ": ";
    if (isInLanguageL(q) == shouldBeValid)
        cout << "Pass";
    else
        cout << "Fail";

    cout << endl;
}

bool isInLanguageL2(string w)
{
    stack<char> s;
    char expecting = 'a';

    for (int i = 0; i < w.length(); ++i)
    {
        if (w[i] == 'a')
        {
            if (expecting == 'a')
                s.push(w[i]);
            else
                return false;
        }
        else if (w[i] == 'b')
        {
            //The first time we read a b we set expecting to 'b'
            if (expecting == 'a')
                expecting = 'b';

            if (expecting == 'b' && !s.empty())
                s.pop();
            else //If the stack is empty, it means we have more b's than a's
                return false;
        }
        else
        {
            return false;
        }
    }

    return (s.size() == 1);
}


bool isInLanguageL(queueType<char> &w)
{
    //smallest word is a so length must be >= 1
    if (w.size() < 1)
        return false;

    stack<char> s;
    char expecting = 'a';
    char current;

    while (!w.isEmptyQueue())
    {
        current = w.front();
        if (current == 'a')
        {
            if (expecting == 'a')
                s.push(current);
            else
                return false;
        }
        else if (current == 'b')
        {
            //The first time we read a b we set expecting to 'b'
            if (expecting == 'a')
                expecting = 'b';

            if (expecting == 'b' && !s.empty())
                s.pop();
            else //If the stack is empty, it means we have more b's than a's
                return false;
        }
        else
        {
            return false;
        }

        w.deleteQueue();
    }

    return (s.size() == 1);
}
