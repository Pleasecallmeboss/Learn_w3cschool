#pragma once

#include <string>
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
    Box(double length, double height);
    Box(string name, double length, double height);
    Box(const Box& b)
    {
        this->height = b.height;
        this->length = b.length;
        this->name = b.name;  //Ϊʲô˽�п�����.����
        this->p = new int;
        *p = *(b.p);
        Box::objectNumber++;
        cout << "���ƹ��캯��������" << endl;
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

    virtual double area()
    {
        return this->length * this->height;
    }
};
//����̳л���Ĺ��캯���������������������캯���������غ�������Ԫ������
class BigBox : public Box
{
public:
    BigBox(double, double);
    double area();
};