#include<iostream>
#include<string>
using namespace std;
int warr[58];
int sarr[58];
bool check(){
    for(int i=0;i<58;i++){
        if(warr[i]!=sarr[i]){
            return false;
        }
    }
    return true;
}
int main(void){
    int wlen, glen;
    cin>>wlen>>glen;
    string w;
    string s;
    cin>>w>>s;
    for(int i=0;i<w.length();i++){
        warr[w[i]-'A']++;
    }
    int startindex=0;
    int result=0;
    for(int i=0;i<w.length() - 1;i++){
        sarr[s[i]-'A']++;
    }
    while(startindex+wlen<=glen){
        sarr[s[startindex+wlen-1]-'A']++;
        if(check()){
            result++;
        }
        sarr[s[startindex]-'A']--;
        startindex++;
    }
    cout<<result;
    return 0;
}