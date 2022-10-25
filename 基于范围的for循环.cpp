#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    char arc[] = "http://c.biancheng.net/cplus/11/";
    // for循环遍历普通数组
    int i = 0;
    for (const auto &ch : arc)
    {
        cout << ch;
        i++;
    }
    cout << '!' << i << endl; // i = 33 还包括了\0字符串结束字符

    vector<char> myvector(arc, arc + 33);
    // for循环遍历 vector 容器
    for (auto ch : myvector)
    {
        cout << ch;
    }
    cout << "!\0!";

    for (int num : {1, 2, 3, 4, 5})
    {
        cout << num << " ";
    }

    map<string, string> mmap{
        {"c++", "i can"},
        {"python", "i can too"},
        {"java", "i can a little"}};
    for (const pair<string,string>& c : mmap)
    {
        //这里的c是 pair<string,string> 类型
        cout << c.first << c.second << endl;
    }

    return 0;
}