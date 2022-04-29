//课后练习2.2
//和题目略用不同，练习了一下函数指针
//更像是2.4的答案

#include <iostream>
#include <vector>
using namespace std;

const vector<int>* Pentagonal(int size)
{
    const int max_size = 1024;
    static vector<int> elem;
    if(size<0 || size>max_size)
    {
        cout<<"Please enter correct size numbers";
        return 0;
    }
    for(int i = elem.size();i<size;i++)
    {
        elem.push_back((i+1)*(3*(i+1)-1)/2);
    }
    return &elem;
}

void printf_pentagonal(int pos,/*int &elem,*/const vector<int>* (*p)(int))
{
    const vector<int>* p_pentagonal;
    p_pentagonal = p(pos);
    //elem=(*p_pentagonal)[pos-1];
    for(int i=0;i<(*p_pentagonal).size();i++)
    {
        cout<<(*p_pentagonal)[i]<<"\n";
    }
}

int main()
{
    int num;
    cout<<"please enter your num:\n";
    cin>>num;
    printf_pentagonal(num,Pentagonal);
    return 0;
}