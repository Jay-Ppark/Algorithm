#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
unordered_set<string> uset;
int main(void){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        for(int j=1;j<=s.length()-i;j++){
            uset.insert(s.substr(i,j));
            //cout<<s.substr(i,j)<<'\n';
        }
    }
    cout<<uset.size();
    return 0;
}