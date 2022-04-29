/*对于之前的斐波那契，我们每次都是需要输入需要计算的位置来重新计算斐波数列
比如fabo_n(24);fabo_n(10);fabo_n(15);
我们计算完第一组后，起始第二组和第三组已经计算过了。这样就产生了重复
但因为函数的特点，函数里面都为局部变量，每次函数执行完毕便被释放了，不能保存
所以使用 局部静态变量 local static object，*/
#include <iostream>
#include <vector>

using namespace std;

bool fabo_size(int size)
{
    const int max_size=1024;
    if(size<0 || size >max_size)
    {
        cout<<"size must > 0 and < 1024";
        return false;
    }
    return true;
}

//const int* p 表明*p是一个定值，即值不能变，但是可以重新给p一个新的地址
const vector<int>* fabo_seq(int size)
{
    static vector<int> elem;//定义一个空的vector
    if(!fabo_size(size))
    {
       return 0; 
    }

        for(int i = elem.size();i<size;i++)//第一次循环为空的，所以elem.size = 0;
        {
            if(i==0 || i==1)
            {
                elem.push_back(1);
               // cout<<elem[i]<<endl;
            }
            else
            {
            elem.push_back(elem[i-1]+elem[i-2]);
           // cout<<elem[i]<<endl;
            }

        }

    return &elem;
}

int get_fabo_pos(int pos,int &elem)//by reference,需要修改传入的数据的数值
{
    const vector<int> *getposition = fabo_seq(pos);//不添加const会报错
    elem= (*getposition)[pos-1];
    return 0;
}

int main()
{
    // int a;
    // int pos;
    // cin>>pos;
    // get_fabo_pos(pos,a);
    //cout<<a;
    int a,b,c;
    get_fabo_pos(25,a);
    get_fabo_pos(12,b);
    get_fabo_pos(6,c);
    cout<<a<<"\n"<<b<<"\n"<<c<<"c";
    return 0;
}
