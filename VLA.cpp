//VLA类模拟变长数组
#include <iostream>
using namespace std;

class VLA
{
    private:
    const int m_len;
    int* m_arr;
    int* m_p;

    int* at(int i);

    public:
    void input();
    void show();
    VLA(int len);
    ~VLA();
};

VLA::VLA(int len):m_len(len)
{
    if(len > 0)
    {
        m_arr = new int[len];
    }
    else{m_arr = nullptr;}
}

VLA::~VLA()
{
    delete[] m_arr;
}

int * VLA::at(int i)
{
    if(!m_arr || i < 0 || i >= m_len)
    {
        return nullptr;
    }
    else{return m_arr + i;}
}

void VLA::input()
{
    for(int i = 0; at(i) != nullptr ;i++)
    {
        m_p = at(i);
        cin >> *m_p;
    }
}

void VLA::show()
{
    for(int i = 0; at(i) != nullptr; i++)
    {
        cout << *at(i) ;
    }
    cout << endl;
}

int main()
{
    VLA v = VLA(2);
    v.input();
    v.show();
}
