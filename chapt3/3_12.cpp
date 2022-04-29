//练习3.2
//比较字符串长度
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void display_vector(const vector<string>& vec ,ostream& os=cout, int len= 8 );//声明中声明了cout个8作为默认值

//仿照function object写了一个自己的function object，用来实现比较字符串长度
class LessThan
{
    public:
    bool operator()(const string& s1, const string& s2) const 
    {
        return s1.size() < s2.size();
    }
};

int main()
{
    ifstream readfile("3_12_read.txt");//不能是中文
    ofstream writefile("3_12_write.txt");
    if(!readfile || !writefile)//确保文件打开了
    {
        cout<<"file can not open\n";
        return -1;
    }
    vector<string> text;
    string word;
    while(readfile >> word)
        text.push_back(word);
    sort(text.begin(),text.end(),LessThan());
    display_vector(text);//绑定到cout
    display_vector(text,writefile);//绑定到输出文件
    return 0;
}
//注意ostream这种写法
void display_vector(const vector<string>& vec , ostream& os, int len)//cout和8都是默认值,其在最上面的声明中进行声明一次即可，不需要再定义中进行说明了
{
    vector<string>::const_iterator iter1 = vec.begin();//必须是const_iterator,因为上边输入的vec为const
    int elem_count=1;
    for(;iter1!=vec.end();iter1++)
    {
        os<<*iter1;
        os<<(!(elem_count++ % len)? '\n' :' ');
    }
    os<<endl;
}