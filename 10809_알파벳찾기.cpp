#include<iostream>
using namespace std;
int alpha[26];
int main(void){
    string s;
    cin>>s;
    fill(alpha,alpha+26,-1);
    for(int i=0;i<(int)s.size();i++){
        if(alpha[s[i]-'a']==-1){
            alpha[s[i]-'a']=i;
        }
    }
    for(int i=0;i<26;i++){
        cout<<alpha[i]<<" ";
    }
    return 0;
}