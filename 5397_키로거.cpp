#include<iostream>
#include<list>
using namespace std;
int main(void){
    int testcase;
    cin>>testcase;
    for(int t=0;t<testcase;t++){
        string s;
        cin>>s;
        list<char> l;
        auto cursor=l.begin();
        for(int i=0;i<s.size();i++){
            if(s[i]=='<'){
                if(cursor!=l.begin()){
                    cursor--;
                }
            }
            else if(s[i]=='>'){
                if(cursor!=l.end()){
                    cursor++;
                }
            }
            else if(s[i]=='-'){
                if(cursor!=l.begin()){
                    cursor--;
                    cursor=l.erase(cursor);
                }
            }
            else{
                l.insert(cursor,s[i]);
            }
        }
        for(auto j:l){
            cout<<j;
        }
        cout<<'\n';
    }
    return 0;
}