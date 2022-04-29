//重写3_01中的find函数，使其可以对链表进行查找
//奇了怪了，报了错，但是可以输出,把输出错误曲线禁用了
#include<iostream>
#include<vector>
#include<list>

using std::vector;
using std::list;
using std::cout;

template<typename IteratorType,typename elemType>
IteratorType find(IteratorType first,IteratorType last,const elemType& value)
{
    for(;first!=last;++first)
        {
            if(*first==value)   
                return first;
        }
    return last;
}

int main()
{
    int* p1;
    vector<int>::iterator viter;
    list<int>::iterator liter;
    const int size = 8;
    int ia[size]={1,1,5,6,8,35,96,40};
    vector<int> b(ia,ia+size);
    list<int> c(ia,ia+size);
    p1=find(ia,ia+size,5);//a为第一个元素的地址，所以IteratorType类型为int*
    cout<<*p1<<"\n";
    viter=find(b.begin(),b.end(),35);//b.begin()为int vector内嵌的iterator，所以类型为iterator
    cout<<*viter<<"\n";
    liter=find(c.begin(),c.end(),40);//c.begin()为int list内嵌的iterator，所以类型为iterator
    cout<<*liter<<"\n";
    return 0;
}