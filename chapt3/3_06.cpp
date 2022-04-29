//利用function object来实现3_05中所实现的功能
//同时需要配合 function object adapter
//利用function object 需要添加头文件functional

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> filter(const vector<int> &vec,int value,less<int> l)//less<int>是一个
{
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();//必须是const_iterator,不然会报错，因为函数开头为const vector，所以此处的iter也应该为const
    //bind2nd(less<int>,val)
    //会把val绑定于less<int>的第二元素
    while(
    (iter = find_if(iter,vec.end(),bind2nd(l,value)))!=vec.end())
    {
        
        nvec.push_back(*iter);
        iter++;
    }
    return nvec;
}

int main()
{
    int a[8]={1,2,3,3,3,6,7,8};
    vector<int> ivec(a,a+8);
    vector<int> ivec1;
    //less<int> c;
    ivec1=filter(ivec,7,less<int>());//注意function object调用的写法
    for(int i=0;i<ivec1.size();i++)
    {
        cout<<ivec1[i]<<"\n";
    }
    return 0;
}