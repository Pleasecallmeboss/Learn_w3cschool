#include <iostream>
using namespace std;
void isnull(void *c){
    cout << "void*c" << endl;
}
void isnull(int n){
    cout << "int n" << endl;
}
int main() {
    isnull(NULL);   //输出：int n
    isnull((void*)NULL);    //void* c
    isnull(nullptr);    //void* c
    return 0;
}