//buble_sort新添打开文件向文件中写入数据功能
//注意，使用指针比使用reference好
//指针可以指向Null

#include<iostream>
#include <vector>
#include<fstream>

using namespace std;

void display(vector<int> vec,ostream &os = cout)//为display的输出提供默认参数，当不写时，该参数自动默认为cout输出，如果用户相对输出地方进行定义，则可补全第二参数
{
    for(int ix=0; ix<vec.size(); ix++)
    {
        os<<vec[ix]<<"\t";
    }
}
void buble_sort(vector<int> &vec,ofstream* writefile = 0)//该指针指向0，表示空指针
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
                if(writefile != 0)
                (*writefile) << "The Swap : "<<vec[ix]<<"   "<<vec[ij]<<endl;
            }
        }
    }
}
int main()
{
    int ia[8]={8,5,7,9,3,1,4,2};
    int ib[8]={9,8,7,6,6,5,3,1};
    vector<int> vec(ia,ia+8);
    vector<int> vec2(ib,ib+8);
    ofstream ofil("2_03.txt");
    display(vec);//默认使用cout输出
    buble_sort(vec);//不向文件中写入内容,此时指针指向NUll
    buble_sort(vec2,&ofil);//此时写入内容，将ofil的地址给到 ofstream
    cout<<"\n";
    for(int ix=0;ix<vec.size();ix++)
    {
        cout<<vec[ix]<<"\t";
    }
    return 0;
}