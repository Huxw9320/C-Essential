/*实现功能：读取practice_1_04_read中的内容
存放到vector中去，然后输出到终端，对vector中的string进行sort排序
然后放到新建的practice_1_04_write.txt中去*/

#include<fstream>//想要打开文件，需要该头文件
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>//泛型算法sort的头文件

using namespace std;


//ofstrem用于向文件写入
//ifstrem用于从文件读入
int main()
{
    string readstring;//用于读取文件中的数据
    vector<string> text;//用来存放读取连续中的字符串

    ifstream readfile("practice_1_04_read.txt");//不能是中文
    ofstream writefile("practice_1_04_write.txt");

    if(!readfile)//确保文件打开，打开返回1，打不开返回0
    {
        cout<<"file read failed";
    }
    else
    {
        while(readfile >> readstring)//当遇到空格的时候，字符串读取截至，产生一个字符串。如ab abc abcd，则产生三个string，分别为ab abc abcd
        {
            text.push_back(readstring);
        }
    }
    for(int i =0;i<text.size();i++)
    {
        cout<<text[i];
        cout<<"\n";
    }
    sort(text.begin(),text.end());//将text中的字符串进行文字排序
    for(int i=0;i<text.size();i++)
    {
        writefile << text[i];//将text中排好序的内容放到新的文件中去
    }
}