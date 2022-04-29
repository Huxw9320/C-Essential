/*
练习 3.4
编写一个程序，利用istream_iterator从标准输入设备读取一连串整数。利用 ostream_iterator
将其中的奇数写至某个文件，每个数值皆以空格分隔。再利用ostream_iterator将偶数写到另一个
文件，为各数值单独放一行。
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class even_elem//自己写的function object
{
    public:
    bool operator()( int elem )
        { return elem%2 ? false : true; }
};

int main()
{
    vector<int> input;
    istream_iterator<int> in(cin), eos;    // 英文原书有误，少了<int>

    copy( in, eos, back_inserter( input ) );

    //partition将一个数组分为三个部分，左部分为偶数，右部分为奇数
    vector<int>::iterator division = 
            partition( input.begin(), input.end(), even_elem() );  // 分为“偶-奇”
    
    // 输出文件位置
    ofstream even_file( "3_14_write_even.txt" ),
             odd_file( "3_14_write_odd.txt" );
    
    // 确定输出文件正常
    if ( !even_file || !odd_file ){
        cerr << "arghh! unable to open the output files. bailing out!";
        return -1;
    }

    // 第二个参数代表每个元素输出时的分隔符
    ostream_iterator<int> even_iter( even_file, "\n" ),
                          odd_iter( odd_file, " " );
    
    copy( input.begin(), division, even_iter );
    copy( division, input.end(), odd_iter );
}
