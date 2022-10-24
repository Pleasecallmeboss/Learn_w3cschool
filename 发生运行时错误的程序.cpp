#include <iostream>
#include <string>
#include <exception>
using namespace std;
int main(){
    string str = "http://c.biancheng.net";
  
    try{
        char ch1 = str[100000000];
        cout<<ch1<<endl;
    }catch(exception e){
        cout<<"[1]out of bound!"<<endl;
    }
    try{
        char ch2 = str.at(100);
        cout<<ch2<<endl;
    }catch(exception &e){  //exception类位于<exception>头文件中
        cout<<"[2]out of bound!"<<endl;
    }
    return 0;
}
// at() 是 string 类的一个成员函数，它会根据下标来返回字符串的一个字符。与[] 不同，at() 
// 会检查下标是否越界，如果越界就抛出一个异常；而[] 不做检查，不管下标是多少都会照常访问。
//     所谓抛出异常，就是报告一个运行时错误，程序员可以根据错误信息来进一步处理。
//     上面的代码中，下标 100 显然超出了字符串 str 的长度。由于第 6 行代码不会检查下标越界，
//     虽然有逻辑错误，但是程序能够正常运行。而第 8 行代码则不同，at() 函数检测到下标越界会
//     抛出一个异常，这个异常可以由程序员处理，但是我们在代码中并没有处理，所以系统只能执行默
//     认的操作，也即终止程序执行。