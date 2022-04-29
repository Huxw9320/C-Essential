/*
练习 3.3
定义一个map，以家族姓氏为key，value则是家族所有小孩的名字。令此map至少容纳六笔数据。
允许用户根据姓氏来查询，并得以打印map内的每一笔数据。
*/
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<istream>
#include<iostream>
using namespace std;
void populate_map(ifstream& ,map<string,vector<string>>& );
void display_map(map<string,vector<string>>& ,ostream& );
void query_map( const string &, 
                const map<string,vector<string>> &);
int main()
{
    map<string,vector<string>> families;
    ifstream nameFile( "3_13_read.txt");

    if ( !nameFile )
    {
        cerr << "Unable to find families.txt file. Bailing Out!\n";
        return -1;   // 英文原书未返回任何值，错误
    }
    populate_map( nameFile, families );

    string family_name;
    while ( 1 )
    {
        // 除非用户表示要离开，否则一直执行下去
        cout << "Please enter a family name or q to quit ";
        cin >> family_name;

        if ( family_name == "q" )
            break;
        query_map( family_name, families );
    }
    display_map( families, cout );     // 英文原书只有一个参数，错误
}
void populate_map(ifstream& namefile,map<string,vector<string>>& families)
{
    string textline;
    while(getline(namefile,textline))//将文件的一行放入textline中，当遇到回车，表明读取的一行结束
    {
        string fam_name;//key
        vector<string> children;//value
        string::size_type pos=0,pre_pos=0,text_size=textline.size();//size_type用来确定位置使用，其为string中的一个类型，string::size_type可以类比int，就是个类型定义
        //find_first_of:查找在字符串中第一个与指定字符串中的某个字符匹配的字符，返回它的位置。
        while((pos=textline.find_first_of(" ",pos))!=string::npos)//寻找所有和空格相等的字符的位置，存储到pos中
        {
            string::size_type end_pos = pos-pre_pos;//两个pos之间的大小便是一个字符串名字的大小
            if(!pre_pos)//如果prepos=0，则此时的end_pos为姓氏
            {
                fam_name = textline.substr(pre_pos,end_pos);//将textline中两个指定位置之间的字符串复制给fam-name
            }
            else
            {
                //否则，两个空格之间的便是孩子的名字，而不是姓氏
                children.push_back(textline.substr(pre_pos,end_pos));
            }
            pre_pos=pos++;//一定不要忘记这句话
        }
        //用来找最后一个名字
        if(pre_pos<text_size)
        {
            children.push_back(textline.substr(pre_pos,pos-pre_pos));//有点疑惑，应该和pos++有关系
        }
        if ( !families.count( fam_name ) )//判断姓氏key是否出现过，然后将未出现的姓氏key放入，同时配上其对应的children
            families[ fam_name ] = children;
        else
        //Cerr 一个iostream对象，关联到标准错误，通常写入到与标准输出相同的设备。
            cerr << "Oops! We already have a " << fam_name 
                 << " family in our map!\n";
    }
}

void display_map(map<string,vector<string>>& families,ostream& os)//使用ostream而不是ofstream，这点要注意，我们可以绑定到ofsream
{
    map<string,vector<string>>::iterator it=families.begin(),it_end=families.end();
    while(it != it_end)
    {
        os<<"The "<<it->first<<" family";
        if(it->second.empty())
            os<<"has no children\n";
        else
        {
            os<<"has "<<it->second.size()<<" childrens\n";
            vector<string>::iterator iter = it->second.begin();
            while(iter!=it->second.end())
            {
                cout<<*iter<<" ";
                ++iter;
            }
            os<<endl;
        }
        ++it;//别忘记了
    }
}
void query_map( const string &family, 
                const map<string,vector<string>> &families )
{
    map<string,vector<string>>::const_iterator it = families.find( family );

    if ( it == families.end() ){
        cout << "Sorry. The " << family 
             << " it not currently entered.\n";
        return;
    }
    
    cout << "The " << family;
    if ( !it->second.size() ){
        cout << "has no children\n";
    }
    else{
        // 打印出vector内的小孩名字
        cout << "has " << it->second.size() << " children: ";
        vector<string>::const_iterator 
               iter = it->second.begin(),
               end_iter = it->second.end();
        while ( iter != end_iter ){
            cout << *iter << " ";
            ++iter;
        }
        cout << endl;
    }
}
