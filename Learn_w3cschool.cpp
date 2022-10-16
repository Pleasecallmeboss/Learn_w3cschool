// Learn_w3cschool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class Box
{
private:
    string name;
    
public:
    double height;
    double length;
    int* p;
    static int objectNumber;

    Box();
    Box(double length = 0, double height = 0);
    Box(string name, double length, double height);
    Box(const Box& b)
    {
        height = b.height;
        length = b.length;
        name = b.name;  //为什么私有可以用.访问
        p = new int;
        *p = *(b.p);
        Box::objectNumber++;
        cout << "复制构造函数被调用" << endl;
    }
    friend void printLength(Box box);
    ~Box();
    static int getCount()
    {
        return objectNumber;
    }

    Box operator+(const Box& box)
    {
        Box b;
        b.height = this->height + box.height;
        b.length = this->length + box.height;
        return b;
    }
    
    Box operator-()
    {
        this->length = -this->length;
        this->height = -this->height;
        return *this;
    }

    virtual int area()
    {
        return this->length * this->height;
    }
};

class BigBox :Box  //不会继承基类的构造函数（析构函数、拷贝构造函数）、重载函数、友元函数。
{
public:
    Bigbox(double len, double hei) :Box("", len, hei) {}
    double getarea()
    {
        return this->height * this->height * this->length * this->length;
    }
    
};

int Box::objectNumber = 0;  //静态成员需要在这初始化

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
    
    BigBox bigbox;
    Box* box_p;
    box_p = &bigbox;
    cont << "bigbox's area : " << box_p->area() << endl;

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


Box::Box()
    //:name(""), length(0), height(0), p(new int)
{
    cout << "默认构造函数被调用" << endl;
    Box::objectNumber++;
}

Box::Box(double length = 0, double height = 0):length(length), height(height), name(""), p(new int)
{
    cout << "含两个参数的构造函数被调用" << endl;
    Box::objectNumber++;
}

Box::Box(string name = "", double length = 0, double height = 0) :name(name), length(length), height(height), p(new int)
{
    cout << "含三个参数的构造函数被调用" << endl;
    Box::objectNumber++;
}

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

//BigBox::Bigbox(double len, double hei) :length(len), height(hei), name(""), p(new int)
//{
//}
