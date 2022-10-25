//如何简便的获取tuple对象的元素
//难点是get<1>(tuple) 传入的1不能是变量
#include<iostream>
#include<tuple>
#include<string>
#include<vector>
using namespace std;

int main()
{
    //定义tuple的两种方法
    auto tu_a = make_tuple(1,2,3,'a',"hello");
    vector<int> ve_a{1,2,3};
    tuple<int,char,string,vector<int>> tu_b(5,'a',"world",ve_a);

    // 获取tuple元素的个数
    int size;
    size = tuple_size<decltype(tu_a)>::value;

    // 获取tuple元素
    cout << get<0>(tu_a) << endl;
    cout << get<4>(tu_a) << endl;

    // 修改tuple元素
    get<1>(tu_a) = 10;
    cout << get<1>(tu_a) << endl;

    // 分别获取tuple元素
    string s;
    tie(ignore, ignore,ignore, ignore, s) = tu_a;
    cout << s << endl;

    // 整个tuple对象
    auto tu_c = tuple_cat(tu_a,tu_b);
    cout << tuple_size<decltype(tu_c)>::value << endl;
}