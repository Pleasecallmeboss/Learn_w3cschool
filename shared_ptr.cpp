#include <iostream>
#include<memory>
using namespace std;

int main()
{   //空的 shared_ptr 指针，其初始引用计数为 0，而不是 1。
    shared_ptr<int> s1;
    shared_ptr<int> s2 = nullptr;
    
    shared_ptr<int> s3(new int(10));
    shared_ptr<int> s4 = make_shared<int>(10);

    // 如果 p3 为空智能指针，则 p4 也为空智能指针，其引用计数初始值为 0；
    // 反之，则表明 p4 和 p3 指向同一块堆内存，同时该堆空间的引用计数会加 1。
    shared_ptr<int> s5 = s3;
    shared_ptr<int> s6(s4);
    cout << "同指向的智能指针个数" << s6.use_count() <<endl;
    s4.reset();
    cout << "同指向的智能指针个数" << s6.use_count() <<endl;

}








// shared_ptr<T>模板类常用成员方法
// 成员方法名	功 能
// operator=()	重载赋值号，使得同一类型的 shared_ptr 智能指针可以相互赋值。
// operator*()	重载 * 号，获取当前 shared_ptr 智能指针对象指向的数据。
// operator->()	重载 -> 号，当智能指针指向的数据类型为自定义的结构体时，通过 -> 运算符可以获取其内部的指定成员。
// swap()	交换 2 个相同类型 shared_ptr 智能指针的内容。
// reset()	当函数没有实参时，该函数会使当前 shared_ptr 所指堆内存的引用计数减 1，同时将当前对象重置为一个空指针；当为函数传递一个新申请的堆内存时，则调用该函数的 shared_ptr 对象会获得该存储空间的所有权，并且引用计数的初始值为 1。
// get()	获得 shared_ptr 对象内部包含的普通指针。
// use_count()	返回同当前 shared_ptr 对象（包括它）指向相同的所有 shared_ptr 对象的数量。
// unique()	判断当前 shared_ptr 对象指向的堆内存，是否不再有其它 shared_ptr 对象再指向它。
// operator bool()	判断当前 shared_ptr 对象是否为空智能指针，如果是空指针，返回 false；反之，返回 true。
//  除此之外，C++11 标准还支持同一类型的 shared_ptr 对象，或者 shared_ptr 和 nullptr 之间，进行 ==，!=，<，<=，>，>= 运算。