// 编译是从上往下编译的
// 友元函数
// 作用：使得其它类中的成员函数或者全局范围内的函数可以访问当前类的private成员

#include<iostream>
using namespace std;

class Address;
class Teacher;
class Student
{
    private:
    char* name;
    public:
    Student(char* name):name(name){}
    void showaddress(Address add);
};

void showaddress(Address add);

class Address
{
    private:
    char* address;
    public:
    Address(char* add):address(add)
    {

    }
    friend void Student::showaddress(Address add);
    friend void showaddress(Address add);
    friend class Teacher;
};

void Student::showaddress(Address add)
{
    cout << "address is : " << add.address << endl;
}

void showaddress(Address add)
{
    cout << "全局范围内showaddress函数:" << add.address << endl;
}

// 友元类
// A的友元类是B，那么类B中的所有成员函数都是类A的友元函数

class Teacher
{
    public:
    void showaddress(Address add)
    {
        cout << "teacher类的showaddress函数：" << add.address << endl;
    }
};
