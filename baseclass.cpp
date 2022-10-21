#include<iostream>

#include<string>
using namespace std;

//����People
class People {
protected:
    string m_name;
    int m_age;
public:
    People(string, int);
};
People::People(string name, int age) : m_name(name), m_age(age) {}

//������Student
class Student : public People {
private:
    float m_score;
public:
    Student(string name, int age, float score);
    void display();
};
//People(name, age)���ǵ��û���Ĺ��캯��
Student::Student(string name, int age, float score) : People(name, age), m_score(score) { }
void Student::display() {
    cout << m_name << "��������" << m_age << "���ɼ���" << m_score << "��" << endl;
}

//int main() {
//    Student stu("С��", 16, 90.5);
//    stu.display();
//
//    return 0;
//}