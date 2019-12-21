#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isInLanguageL2(string w);
bool isInLanguageL(string w);
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
    cout << "Test whether " << language << " is " << (shouldBeValid? "valid" : "invalid") << ": ";
    if (isInLanguageL2(language) == shouldBeValid)
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


bool isInLanguageL(string w)
{
    //smallest word is a so length must be >= 1
    if (w.length() < 1)
        return false;

    stack<char> s;
    char expected = 'a';

    for (int i = 0; i < w.length(); ++i)
    {
        if (w[i] == 'a')
        {
            if (w[i] == expected)
                s.push(w[i]);
//            ELSE
//                RETURN FALSE;
        }
        else if (w[i] == 'b')
        {
            //handle the first b we receive
            if (expected == 'a')
                expected = w[i];

            if (s.empty())
                return false; //more b's than a's

            s.pop();
        }
        else
        {
            return false; //invalid input
        }
    }

    return (s.size() == 1);
}
