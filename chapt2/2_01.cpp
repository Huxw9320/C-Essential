//计算印斐波那契数列的第n个元素数值，并打印出前n个斐波那契数列
#include<iostream>
using namespace std;
bool fabo_n(int pos,unsigned int &val)
{
    int num_1=1;
    int num_2=1;//斐波那契数列的前两个元素为1
    if(pos < 0 || pos > 1024)
    {
        cout<<pos<<":cannot <1 or >1024";
        return -1;
    }
    val = 1;//pos=1/2时，直接输出1
    for(int i =3;i<=pos;i++)//只有当pos>=3时才打执行
    {
        val=num_1+num_2;
        num_1 = num_2;
        num_2 = val;
    }
    return 1;
}

bool print_fabo(int pos)
{
    int num_1=1;
    int num_2=1;//斐波那契数列的前两个元素为1
    unsigned int val;
    if(pos < 0 || pos > 1024)
    {
        cout<<"num must>0 and <1024";
        return -1;
    }
    switch(pos)
    {
        default:
        case 2:
            cout<<"1\n";//此处没有break，当pos=2，直接输出两个1.
        case 1:
            cout<<"1\n";
            break;
    }
    for(int i=3;i<=pos;i++)
    {
        val=num_1+num_2;
        num_1 = num_2;
        num_2 = val;
        cout<<val<<endl;
    }
    return 1;
}

int main()
{
    int pos;
    unsigned int val;
    cout<<"Please enter your num:\n";
    cin>>pos;
    if(fabo_n(pos,val))
    {
        cout<<"The position of "<<pos<<"is:\n";
        cout<<val<<endl;
        cout<<"The position behind the "<<pos<<" is:\n";
        print_fabo(pos);
    }

    return 0;
}

