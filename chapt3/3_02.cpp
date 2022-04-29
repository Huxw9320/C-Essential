//迭代器的使用

#include<iostream>
#include<vector>

using namespace std;

template <typename elemType>
void dispaly(const vector<elemType> &vec,ostream& os = cout)
{
    //注意需要添加typename，不然会报错
    typename vector<elemType>::const_iterator iter = vec.begin();//P75页
    typename vector<elemType>::const_iterator end_it = vec.end();
    for(;iter != end_it;++iter)
    {
        os<<*iter<<" ";
        os<<endl;
    }
}

int main()
{
    int a[8]={0,1,2,3,4,5,6,7};
    vector<int> b(a,a+8);
    dispaly(b);
    return 0;
}
