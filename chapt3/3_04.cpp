//顺序容器的定义方式
//每个容器的插入函数
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
    /*五种初始化方法*/
    
    // vector<int> ivec;
    // vector<int> ivec(10);
    // list<string> slist(10,"nihao");
    // int a[8]={1,2,3,4,5,6,7,8};
    // deque<int> ideque(a,a+8);
    // vector<int> ivec1(ivec);
   
    /*几种插入*/
    //1
    int a[8]={1,2,3,4,5,6,7,8};
    list<int> ilist(a,a+8);
    int value = 5;
    list<int>::iterator iter = ilist.begin();//第一个迭代指针用来插入
    list<int>::iterator iter2 = ilist.begin();//第二个迭代指针用来遍历
    while(iter != ilist.end())
    {
        if(*iter > value)
        {
            ilist.insert(iter,value);//在iter之前插入value
            break;//跳出while循环
        }
        ++iter;//别忘记添加，不然跳不出来
    }
    if(iter == ilist.end())
    {
        ilist.push_back(value);
    }
    while(iter2 != ilist.end())
    {
        cout<<*iter2<<"\n";
        ++iter2;
    }


    //2
    string b[8]={"aaa","bbb","ccc","ddd","eee","fff","ggg","zzz"};
    list<string> slist(b,b+8);
    string sval="zzz";
    list<string>::iterator siter = find(slist.begin(),slist.end(),sval);//此处利用的为泛型算法中的find，返回一个iter，为sval的地址。
    list<string>::iterator siter1 =  slist.begin();
    slist.insert(siter,8,string("nihaoya"));// 在siter指针之前插入8个nihao
    while(siter1 != slist.end())
    {
        cout<<*siter1<<"\n";
        ++siter1;
    }


    //3
    int c1[8]={1,2,3,4,5,6,7,8};
    int c2[4]={5,6,7,10};
    list<int> c3(c1,c1+8);
    list<int>::iterator t_iter1 = find(c3.begin(),c3.end(),6);
    list<int>::iterator t_iter2;
    c3.insert(t_iter1,c2,c2+4);//从迭代器的前面插入数据
    t_iter2=c3.begin();
    while(t_iter2 != c3.end())
    {
        cout<<*t_iter2<<"\n";
        ++t_iter2;
    }


}