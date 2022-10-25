#include <iostream>
#include <algorithm>
using namespace std;

int global_num = 10;
int main()
{
    int num[]{7, 5, 4, 9, 5};
    sort(num, num + 5, [=](int x, int y)
         { return x <= y; });
    for (auto &i : num)
    {
        cout << i << endl;
    }
    // sort(起始地址，结束地址，比较器);
    //当比较器返回true时，第一个参数放在前面，第二个参数放在后面，即位置不变
    //当比较器返回false时，为两元素交换位置

    int local_num = 1;
    // auto display = [&]()        //引用传递
    auto display = [=]()mutable     //mutable能修改值传递的变量，但仅仅修改值的拷贝，相当于光解决报错不解决问题
    {
        local_num++;
        global_num++;
    };

    display();
    cout << "global_num : " << global_num << endl;
    cout << "local_num : " << local_num << endl;
}