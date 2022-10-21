//const成员变量
// 作用：成员不会被改变
// 用法：变量前加const
// 初始化：通过构造函数的初始化列表


// const 成员函数
// 作用：保证函数不会改变变量的值（可以访问类中的所有成员变量）
// 用法：声明和定义的时候在函数头部的结尾加上const
// 注意：在函数头部加const和不加是两种不同的函数
#include<iostream>
using namespace std;
class Student
{
    private:
    char* name;
    int age;
    float score;

    public:
    Student(char* name, int age, float score):name(name),age(age),score(score)
    {

    }
    void show();
    char* getname() const;
    int getage() const;
    float getscore() const;
};

void Student::show()
{
    cout << "name: " << name << " age: " << age << " score: " << score << endl;
}

char* Student::getname() const
{
    return name;
}

int Student::getage() const
{
    return age;
}

float Student::getscore() const
{
    return score;
}




