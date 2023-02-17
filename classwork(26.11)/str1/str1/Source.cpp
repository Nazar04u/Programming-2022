#include<iostream>
#include<string>
using namespace std;

int wordCounter(string str)
{
    int a = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',' || str[i] == '.')
        {
            a++;
        }
    }return a;
}

int main()
{
    string str, word;
    getline(cin, str);
    int wordsAmount = wordCounter(str);
    for (int i = 0; i < wordsAmount; i++)
    {
        int pos = str.find(',');
        if (pos == -1)
        {
            pos = str.find('.');
        }
        word = str;
        cout << word[pos - 1];
        str.erase(0, pos + 1);
    }
}