//将3_09更改为可以读取指定文件
//然后排序
//在读出到指定文件中
//其实很简单，就是修改一下绑定即可

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{

    ifstream readfile("3_10_read.txt");//不能是中文
    ofstream writefile("3_10_write.txt");
    if(!readfile || !writefile)
    {
        cout<<"file can not open\n";
        return -1;
    }
    vector<string> text;
    //利用 iostream iterator
    istream_iterator<string> is(readfile);//is绑定到readfile
    istream_iterator<string> eof;
    ostream_iterator<string> os(writefile," ");

    copy(is,eof,back_inserter(text));//利用了iterator insertor
    sort(text.begin(),text.end());

    copy(text.begin(),text.end(),os);
    return 0;
}