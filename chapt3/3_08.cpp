//Map的使用

#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> words;
    //words["key"]=1;word初始化的一种方式
    string key;
    while(cin>>key)
    {
        //words[key]++;//如果添加++，则每个key的默认value变为1；
        words[key];//此时为每个key的value默认值为0
    }
    map<string,int>::iterator iter = words.begin();
    for(;iter!=words.end();iter++)
    {
        cout<<"key: "<<iter->first
            <<" value: "<<iter->second<<endl;
    }

    //查询某个key-法一
    map<string,int> my_map;
    my_map["hu"]=123;
    my_map["hhh"]=456;
    map<string,int>::iterator iter2 ;
    iter2 = my_map.find("hhh");//用来查找某个key是否存在，存在会返回一个迭代器，不存在返回end()
    if(iter2 != my_map.end())
    {
        cout<<"value is: "<<iter2->second<<"\n";
    }

    //查询某个key-法二
    map<string,int> my_map2;
    my_map2["hu"]=123;
    my_map2["hhh"]=456;
    int count=0;
    if(my_map2.count("hu"))
        count=my_map2["hu"];//将key=hu的value赋值给count
    cout<<count<<"\n";
    return 0;
}