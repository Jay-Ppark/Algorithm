#include<iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int cnt=0;
    bool found=true;
    while(true){
        if(cnt>N){
            found=false;
            break;
        }
        string s=to_string(cnt);
        int sum=cnt;
        for(int i=0;i<(int)s.size();i++){
            sum+=s[i]-'0';
        }
        if(sum==N){
            break;
        }
        cnt++;
    }
    if(found){
        cout<<cnt;
    }
    else{
        cout<<0;
    }
    return 0;
}