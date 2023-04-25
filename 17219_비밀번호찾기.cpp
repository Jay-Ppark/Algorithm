#include<iostream>
#include<unordered_map>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    unordered_map<string,string> um;
    for(int i=0;i<N;i++){
        string site, pwd;
        cin>>site>>pwd;
        um[site]=pwd;
    }
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        cout<<um[tmp]<<'\n';
    }
    return 0;
}