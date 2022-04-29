//设计泛型算法
//设计一个整型容器，可以将将其他容器中的的某个（大于小于等于）该元素的值拷贝到该容器中。
//采用函数指针

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// bool equal(int val1,int val2)
// {
//     return (va11 == val2) ? true :false;
// }
bool less1(int val1,int val2)
{
    return val1<val2?true:false;
}
bool big1(int val1,int val2)
{
    return val1>val2?true:false;
}

vector<int> filter_ver1(const vector<int> &vec,int value,bool (*p)(int,int))//函数指针
{
    vector<int> nvec;
    for(int i=0;i<vec.size();i++)
        if(p(vec[i],value))
            nvec.push_back(vec[i]);  
    return nvec;
}
//用来计算vector中重复的数据
int count_occurs(vector<int> &vec,int &value)
{
    vector<int>::iterator iter = vec.begin();
    int count = 0;
    // while((iter = find(vec.begin(),vec.end(),value)) !=  vec.end())
    //     {
    //         ++iter;
    //         ++count;
    //     }
        while((iter = find(iter,vec.end(),value)) !=  vec.end())//正确写法，上面为错误写法
        {
            ++iter;
            ++count;
        }
    return count;
}

int main()
{
    int a[8]={1,2,3,3,3,6,7,8};
    vector<int> ivec(a,a+8);
    vector<int> ivec1;
    ivec1 = filter_ver1(ivec,6,less1);//传递函数指针
    for(int i=0;i<ivec1.size();i++)
    {
        cout<<ivec[i]<<"\n";
    }
    ivec1 = filter_ver1(ivec,6,big1);//传递函数指针
    for(int i=0;i<ivec1.size();i++)
    {
        cout
        <<ivec1[i]<<"\n";
    }
    int b=0;
    int c=3;
    b = count_occurs(ivec,c);
    cout<<b<<"\n";
    return 0;
}