// 以引用的方式进行传值实现数据交换

#include<iostream>
#include <vector>
using namespace std;

void display(vector<int> vec)
{
    for(int ix=0; ix<vec.size(); ix++)
    {
        cout<<vec[ix]<<"\t";
    }
}
void buble_sort(vector<int> &vec)//by reference
{
    for(int ix=0;ix<vec.size();ix++)
    {
        for(int ij=ix+1;ij<vec.size();ij++)
        {
            if(vec[ix]>vec[ij])
            {
                int temp;//注意是int类型
                temp=vec[ix];//此时容器中的每个元素都为int类型
                vec[ix]=vec[ij];
                vec[ij]=temp;
            }
        }
    }
}
int main()
{
    int ia[8]={8,5,7,9,3,1,4,2};
    vector<int> vec(ia,ia+8);
    display(vec);
    buble_sort(vec);
    cout<<"\n";
    for(int ix=0;ix<vec.size();ix++)
    {
        cout<<vec[ix]<<"\t";
    }
    return 0;
}