// 常对象
// 作用：声明为常对象该对象就不能改变
// 用法：只能调用类的const变量和const函数
// 形式：常对象和常指针
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

    void show()
    {
        cout << "name, age, score is " << name << age << score << endl;
    }

    char* getname() const 
    {
        return name;
    }
    int
     getage() const
    {
        return age;
    }

    float getscore() const
    {
        return score;
    }

};

int main()
{
    const Student stu("小王",22,99);
    // stu.show(); 报错，常对象只能调用常变量和常函数
    cout << stu.getname() << stu.getage() << endl;

    const Student* pstu;
    pstu = new Student("小李",30,80);
    // pstu.shwo();
    cout << pstu->getname() << pstu->getage << endl;
    
}