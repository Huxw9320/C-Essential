//课后练习3-1
//妙啊
//可以用来查阅英文文本中出现的单词，但是不能带符号
#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>
using namespace std;
void initialize_exclusion_set(set<string>& );
void process_file(map<string,int> &,set<string>& ,ifstream& );
void user_query(map<string,int>& );
void display_wordcount(map<string,int>& ,ofstream& );

int main()
{
    ifstream readfile("3_11_read.txt");//不能是中文
    ofstream writefile("3_11_write.txt");
    if(!readfile || !writefile)//确保文件打开了
    {
        cout<<"file can not open\n";
        return -1;
    }
    set<string> exclude_set;
    initialize_exclusion_set(exclude_set);
    map<string,int> word_count;
    process_file(word_count,exclude_set,readfile);
    user_query(word_count);
    display_wordcount(word_count,writefile);
    return 0;
}

void initialize_exclusion_set(set<string>& exs)
{
    static string _exclude_word[25]={"the","and","but","that","then","are","been",
        "can","a","could","did","for","of",
        "had","have","him","his","her","its","is",
        "were","which","when","with","would"};
    exs.insert(_exclude_word,_exclude_word+25);
}

void process_file(map<string,int> &word_count,set<string>& exclude_set,ifstream& file)
{
    string word;
    while(file >> word)
    {
        if(exclude_set.count(word))
            continue;//如果出现排除的word，则跳出这一次循环，然后进入下一次while
        word_count[word]++;//若出现相同的key，会使value自动+1，用来记录key出现的次数
    }
}
void user_query(map<string,int>& word_map)
{
    string search_word;
    cout<<"Please enter a word to search : q to quir\n";
    cin>>search_word; 
    while(search_word.size() && (search_word!= "q"))
    {
        map<string,int>::iterator iter ;
        if((iter = word_map.find(search_word))
            !=word_map.end())//注意此处如何判断
        cout<<"Found"<<iter->first<<" "<<iter->second<<"times"<<endl;
        else
        cout<<search_word<<" was not found in text\n";
        cout<<"Another search?(q to quit)\n";
        cin>>search_word;
    }
}

void display_wordcount(map<string,int>& word_map,ofstream& os)
{
    map<string,int>::iterator iter = word_map.begin();//迭代器指向第一个元素
    for(;iter!=word_map.end();iter++)
    {
        os<<iter->first<<"("<<iter->second<<")\n";
    }
    os<<endl;
}

