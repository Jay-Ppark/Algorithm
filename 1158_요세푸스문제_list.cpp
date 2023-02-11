#include<iostream>
#include<vector>
using namespace std;
int prv[5001],nxt[5001];
int main(void){
    int N,K;
    cin>>N>>K;
    vector<int> v;
    for(int i=1;i<=N;i++){
        if(i==N){
            nxt[i]=1;
        }
        else{
            nxt[i]=i+1;
        }
        if(i==1){
            prv[i]=N;
        }
        else{
            prv[i]=i-1;
        }
    }
    int len=N;
    int cur=1;
    int c=1;
    while(len!=0){
        if(c==K){
            v.push_back(cur);
            nxt[prv[cur]]=nxt[cur];
            prv[nxt[cur]]=prv[cur];
            c=1;
            len--;
            cur=nxt[cur];
        }
        if(K!=1){
            cur=nxt[cur];
            c++;
        }
    }
    cout<<'<';
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1){
            cout<<v[i]<<'>';
        }
        else{
            cout<<v[i]<<", ";
        }
    }
    return 0;
}