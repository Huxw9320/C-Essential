//编写一个find函数，可以寻找array和vector中某个元素的值，然后返回该值
//采用泛编程风格，只需要一个函数，可以接收array类型和vector类型的元素

#include<iostream>
#include<vector>
using namespace std;

//可以都加上const，因为我们只是作比较，而不会修改值
//这样便完成了一个泛函数，对于数组没问题，但是对于vector可以为空，当vector为空时，会进入if而报错
//此处必须在函数处添加const，因为返回的first为const template*，所以函数的返回类型也需要为const template
template<typename elemType>
const elemType* find(const elemType *first,const elemType *last,const elemType &value)
{
    //对于数组不能为空
    if(!first || !last)
    {
        return 0;
    }
    for(;first!=last;++first)
    {
        if(*first==value)
        {
            return first;
        }
    }
    return 0;
}
//对于vector，将第一个元素的地址包装为函数进行操作
template<typename elemType>
inline const elemType* begin1(const vector<elemType> &vec)
{
    return vec.empty ? 0: &vec[0];
//    if(vec.empty)
//    {
//        return 0;
//    }
//    else{
//        return &vec[0];
//    }
}

template<typename elemType>
inline const elemType* end1(const vector<elemType> &vec)
{
    return vec.empty ? 0 : &vec[vec.size()];
//     if(vec.empty)
//    {
//        return 0;
//    }
//    else{
//        return &vec[vec.size()];
//    }
}


int main()
{
    int a[8]={0,1,2,3,4,5,6,7};
    const int* p;
    const int* p2;
    vector<int> b(a,a+8);
    p=find(a,a+8,5);
    p2=find(&b[0],&b[b.size()],4);//这样可以，下面的函数不行，以后学习知识丰富了再来解决
    //p2=find(begin1(b),end1(b),4);//暂时没跳出来
    cout<<*p<<"\n";
    cout<<*p2;
    return 0;
}