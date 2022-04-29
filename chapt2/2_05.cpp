//函数指针

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

const vector<int>* fabonacci(int size)
{
    static vector<int> elem;//定义一个空的静态局部vector，确保其在函数执行完毕后不会消失
    const int max_size=1024;
    if(size<0 || size >max_size)
    {
        cout<<"size must > 0 and < 1024";
        return 0;
    }
        for(int i = elem.size();i<size;i++)//第一次循环为空的，所以elem.size = 0;
        {
            if(i==0 || i==1)
            {
                elem.push_back(1);
               // cout<<elem[i]<<endl;
            }
            else
            {
            elem.push_back(elem[i-1]+elem[i-2]);
           // cout<<elem[i]<<endl;
            }

        }

    return &elem;
}
const vector<int>* Lucas(int size)
{
static vector<int> elem;//定义一个空的vector
    const int max_size=1024;
    if(size<0 || size >max_size)
    {
        cout<<"size must > 0 and < 1024";
        return 0;
    }
        for(int i = elem.size();i<size;i++)//第一次循环为空的，所以elem.size = 0;
        {
            if(i==0)
            {
                elem.push_back(1);
               // cout<<elem[i]<<endl;
            }
            else if(i==1)
            {
                elem.push_back(3);
            }
            else
            {
            elem.push_back(elem[i-1]+elem[i-2]);
           // cout<<elem[i]<<endl;
            }

        }

    return &elem;
}
const vector<int>* Pell(int size)
{
static vector<int> elem;//定义一个空的vector
    const int max_size=1024;
    if(size<0 || size >max_size)
    {
        cout<<"size must > 0 and < 1024";
        return 0;
    }
        for(int i = elem.size();i<size;i++)//第一次循环为空的，所以elem.size = 0;
        {
            if(i==0)
            {
                elem.push_back(1);
               // cout<<elem[i]<<endl;
            }
            else if(i==1)
            {
                elem.push_back(2);
            }
            else
            {
            elem.push_back(2*elem[i-1]+elem[i-2]);
           // cout<<elem[i]<<endl;
            }

        }

    return &elem;
}
const vector<int>* Square(int size)
{
    static vector<int> elem;//定义一个空的静态局部vector
    const int max_size=1024;
    if(size<0 || size >max_size)
    {
        cout<<"size must > 0 and < 1024";
        return 0;
    }
        for(int i = elem.size();i<size;i++)//第一次循环为空的，所以elem.size = 0;
        {
            if(i==0)
            {
                elem.push_back(1);
               // cout<<elem[i]<<endl;
            }
            else
            {
            elem.push_back((i+1)*(i+1));
           // cout<<elem[i]<<endl;
            }

        }

    return &elem;
}

//这一块很关键:包括函数指针 枚举变量 函数指针数组

enum seq_type {seq_fabo,seq_lucas,seq_pell,seq_square};//枚举，里面放入我们想要指定的函数

const vector<int>* (*seq_arry[])(int) = {fabonacci,Lucas,Pell,Square};//定义一个函数指针数组

int get_seq_pos(int pos,int &elem,int choose,
                const vector<int>* (*seq_arry[])(int))//声明一个函数指针数组)
{
    const vector<int>* pseq;
    switch (choose)
    {
        case 1:
            cout<<"You have chose fabonacci seq"<<endl;
            pseq = seq_arry[seq_fabo](pos);//注意必须要添加上pos，这是函数的变量
            break;
        case 2:
            cout<<"You have chose Lucas seq"<<endl;
            pseq = seq_arry[seq_lucas](pos);
            break;
        case 3:
            cout<<"You have chose Pell seq"<<endl;
            pseq = seq_arry[seq_pell](pos);
            break;
        case 4:
            cout<<"You have chose Square seq"<<endl;
            pseq = seq_arry[seq_square](pos);
            break;
    }
    elem = (*pseq)[pos-1];
}

int main()
{
    int type;//用来确定输入哪种类型
    int pos;//用来确定想要知道的位置
    int elem;//用来读取pos处的数值
    char choose;//选择是否继续
    while(1)
    {
        cout<<"Please enter a seq which you want to konw:\n"
        <<"1-fabonacci\n"<<"2-lucas\n"<<"3-Pell\n"<<"4-Square\n";
        cin >> type;
        cout<<"Now,which posion do you want to konw?\n";
        cin >> pos;
        get_seq_pos(pos,elem,type,seq_arry);
        cout<<"The position num is :";
        cout<<elem<<endl;

        cout<<"Would you want to play again? Y/N?\n";
        cin>>choose;
        if(choose=='Y'||choose=='y')
        {
            cout<<"Now play again!!\n\n";
        }
        if(choose=='N'||choose=='n')
        {
            cout<<"exit the porgram\n";
            exit(0);
        }
    }
    return 0;
}