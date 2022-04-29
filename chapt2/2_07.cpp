//练习2.5
//重载函数的练习
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>//不加这个头文件不能使用max_element函数
using namespace std;

inline int max(int a,int b)
{
    return a>b?a:b;
}
inline float max(float a,float b)
{
    return a > b? a:b;
}

inline string max(string& a,string& b)//按照引用传速度快，因为只占用4个字节
{
    return a>b?a:b;
}
/*写错了
inline vector<int> max(vector<int>& &vec)
{
    return 
}*/

inline float max(vector<float>& vec)
{
    return *max_element(vec.begin(),vec.end());
}

inline string max(vector<string>& vec)
{
    return *max_element(vec.begin(),vec.end());
}

inline int max(vector<int>& vec)
{
    return *max_element(vec.begin(),vec.end());//begin和end都是迭代器，相当于地址，所以要读取数值，应该*提领
}
/*这样写不对，参照下面
inline int max(int arry[],int n)//定义整数数组和数组的大小
{
    
}*/

//
inline int manx(int *parray,int size)
{
        return *max_element(parray,parray+size);
}

inline float max(float* parray,int size)
{
    return *max_element(parray,parray+size);
}