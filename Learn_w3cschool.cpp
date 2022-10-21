// Learn_w3cschool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "class.h"
using namespace std;



BigBox::BigBox(double len, double hei) :Box(len, hei)
{}

double BigBox::area()
{
    return this->length;
}

int Box::objectNumber = 0;  //静态成员需要在这初始化

Box::Box()
:name(""), length(0), height(0), p(new int)
{
    cout << "默认构造函数被调用" << endl;
    Box::objectNumber++;
}

Box::Box(double length , double height ) :length(length), height(height), name(""), p(new int)
{
    cout << "含两个参数的构造函数被调用" << endl;
    Box::objectNumber++;
}

Box::Box(string nam, double len, double hei):name(nam),length(len),height(hei)
{
}

//Box::Box(string name , double length , double height ) :name(name), length(length), height(height), p(new int)
//{
//    cout << "含三个参数的构造函数被调用" << endl;
//    Box::objectNumber++;
//}

Box::~Box()
{
    cout << "析构函数被调用" << endl;
    Box::objectNumber--;
    delete p;
}

void printLength(Box box)
{
    cout << box.length << endl;
}



int main()
{
    cout << "objectNumber : " << Box::objectNumber << endl;
    Box box0;
    box0.length = 2;
    box0.height = 4;
    Box box1("name",2,2);
    Box b = box0;
    Box* b_p = &box1;
    printLength(*b_p);
    printLength(b + *b_p);
    printLength(-b);
    cout << "objectNumber: " << Box::objectNumber << endl;
    
    BigBox bigbox(2.0,4.0);
    Box* box_p;
    box_p = &bigbox;
    cout << "bigbox's area : " << box_p->area() << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
