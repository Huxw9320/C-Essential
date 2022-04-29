#include <iostream>
#include <string>
using namespace std;

//C++风格的string和C style的string.h不同
//使用C++风格的string，可以直接对string类型的对象读取size
//对于C style 则需要使用strlen函数，还要防止溢出。
int main()
{
    string user_name;
    cout<<"What is your name?\n";
    cin >> user_name ;
    if(user_name.size() == 0)
    {
        cout<< "please enter your name\n";
        cin >>user_name;
    }
    else if (user_name.size() == 1 )
    {
        cout << "Please enter a correct name";
    }
    else
    {
        cout<<"Hello!! : "<<user_name<<endl;
    }
    return 0;
}
