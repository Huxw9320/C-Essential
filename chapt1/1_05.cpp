#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int main()
{
    const int seq_size = 18;//队列长度总共18个，每三个一组，共6组
    string user_name;
    int user_val;
    int num_tries=0,num_right=0;
    double socer(0.0);
    vector<int>* p;
    
    int elem_val[seq_size]={
        1, 2, 3,    // Fibonacci
        3, 4, 7,    // Lucas
        2, 5, 12,   // Pell
        3, 6, 10,   // Triangular
        4, 9, 16,   // Square
        5, 12, 22   // Pentagonal
    };
    vector<int> elem_seq(elem_val,elem_val+seq_size);//vector的初始化方式

    for(int i=0;i<elem_seq.size();i++)
    {
        cout<<elem_seq[i];
    }

}
