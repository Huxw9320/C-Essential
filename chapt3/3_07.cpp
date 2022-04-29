//对306进行优化，实现可以对其它类型（vector）之外的也能进行操作。
//所以要使用模板

#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

template<typename InputIterator,typename OutputIterator,typename valuetype, typename comp>
OutputIterator filter(InputIterator first,InputIterator last,OutputIterator at,valuetype elem,comp pred)
{
    while(
        (first = find_if(first,last,bind2nd(pred,elem)))!= last)//仿函数适配器
    {
        *at++ = *first++;//这样写法更好
        //*at=*first;
        //at++;
        //first++;
    }
    return at;
}

int main()
{
    int a[8]={1,2,3,4,5,6,7,8};
    vector<int> b(a,a+8);
    int c[8];
    vector<int> d;
    filter(a,a+8,c,5,less<int>());
    for(int i=0;i<8;i++)
    {
        cout<<c[i]<<"\n";
    }
    filter(b.begin(),b.end(),d.begin(),3,greater<int>());//注意如何使用仿函数
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<"\n";
    }
    return 0;
}