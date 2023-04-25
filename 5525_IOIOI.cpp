#include<iostream>
using namespace std;
int main(void){
    int N,M;
    cin>>N>>M;
    string s;
    cin>>s;
    int cnt=0;
    int answer=0;
    for(int i=1;i<M-1;i++){
        if(s[i-1]=='I'&&s[i]=='O'&&s[i+1]=='I'){
            cnt++;
            if(cnt==N){
                answer++;
                cnt--;
            }
            i++;
        }
        else{
            cnt=0;
        }
    }
    cout<<answer;
    return 0;
}