//向vector中连续放入数，然后进行遍历求和
//cin时，输入\0来终止输入
//使用vector比使用arry要好，使用vector不用设置大小，可以从尾部进行数据补充
//使用arry需要考虑数组大小，同时还要防止数据溢出
#include <iostream>
#include <vector>

using  std::vector;//vector也是标准库里面的，所以要使用std来说明其空间。
using std::cin;
using std::cout;
int main()
{
    cout<<"Please input your numbers:\n";
    vector<int> vec;
    int val;
    int sum=0;
    while(cin >> val)//不断地输入，成功输入后返回1
    {
        vec.push_back(val);
    }
    for(int i=0;i<vec.size();i++)
    {
        sum = sum + vec[i];
    }
    cout << sum;
}