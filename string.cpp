#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1;
    string s2 = "hello world";
    string s3 = s2;
    string s4(5,'s');

    char c1 = 'a';
    // char* c2 = "abc ";
    char c3[] = "123";
    string s5 = s2 + c1 + c2 + c3;
    const char* c4 = s1.c_str();
    for(char i = 0, len = s2.length(); i < len; i++)
    {
        cout << s2[i] << endl;
    }
    cout << s1.length() << endl;
}