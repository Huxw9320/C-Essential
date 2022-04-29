//iterator inserter 和 iostream iterator

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
    vector<string> text;
    //利用 iostream iterator
    istream_iterator<string> is(cin);//is绑定到cin
    istream_iterator<string> eof;
    ostream_iterator<string> os(cout," ");

    copy(is,eof,back_inserter(text));//利用了iterator insertor
    sort(text.begin(),text.end());

    copy(text.begin(),text.end(),os);
    return 0;
}