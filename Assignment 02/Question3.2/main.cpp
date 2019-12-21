#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isInLanguageLc(string w);
bool isInLanguageL(string w);
void test(string language, bool shouldBeValid);

int main()
{
    cout << "Test valid words" << endl;
    test("abcc", true);
    test("aabbccc", true);
    test("aaabbbcccc", true);
    test("aaaaabbbbbcccccc", true);

    cout << "Test invalid words" << endl;
    test("", false);
    test("abc", false);
    test("aabbcc", false);
    test("aabbccccccc", false);
    test("abcd", false);
    test("abccc", false);
    test("aabccc", false);
    test("abbccc", false);
    test("ccab", false);
    test("ccba", false);
    test("accb", false);
    test("acbc", false);
    test("ababccc", false);
    test("ababbacccc", false);
    test("ababbcaccc", false);
    test("ababcbaccc", false);
    test("c", false);
    test("cc", false);
    test("ccc", false);
    test("cccc", false);
    test("aaabbbccc", false);


    return 0;
}

void test(string language, bool shouldBeValid)
{
    cout << "Test whether " << language << " is " << (shouldBeValid? "valid" : "invalid") << ": ";
    if (isInLanguageLc(language) == shouldBeValid)
        cout << "Pass";
    else
        cout << "Fail";

    cout << endl;
}


bool isInLanguageLc(string w)
{
    //smallest word is abcc so length must be >= 4
    if (w.length() < 4)
        return false;

    stack<char> s1;
    stack<char> s2;
    char expected = 'a';

    for (int i = 0; i < w.length(); ++i)
    {
        if (w[i] == 'a')
        {
            if (w[i] == expected)
                s1.push(w[i]);
        }
        else if (w[i] == 'b')
        {
            //handle the first 'b' we receive
            if (s2.empty())
                expected = w[i];

            if (w[i] == expected)
                s2.push(w[i]);
        }
        else if (w[i] == 'c')
        {
            if (s1.size() != s2.size())
                return false; //unbalanced a's and b's

            if (s1.empty() && s2.empty() && i < w.length() - 1)
                return false; //run out of a's and b's

            if (s1.empty() && s2.empty() && i == w.length() - 1)
                return true; //the word is valid

            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
        }
        else
        {
            return false; //invalid input
        }
    }

    return false;
}
