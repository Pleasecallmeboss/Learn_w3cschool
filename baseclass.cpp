#include<iostream>

#include<string>
using namespace std;

//基类People
class People {
protected:
    string m_name;
    int m_age;
public:
    People(string, int);
};
People::People(string name, int age) : m_name(name), m_age(age) {}

//派生类Student
class Student : public People {
private:
    float m_score;
public:
    Student(string name, int age, float score);
    void display();
};
//People(name, age)就是调用基类的构造函数
Student::Student(string name, int age, float score) : People(name, age), m_score(score) { }
void Student::display() {
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << "。" << endl;
}

//int main() {
//    Student stu("小明", 16, 90.5);
//    stu.display();
//
//    return 0;
//}